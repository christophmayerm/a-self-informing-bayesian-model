#ifndef EB_ADAM_GRADIENT_ASCENT_HPP_
#define EB_ADAM_GRADIENT_ASCENT_HPP_

#include <vector>

#ifdef EB_AGA_SAVE_ITERATIONS_TO
#include <fstream>
#include <type_traits>
#endif  // EB_AGA_SAVE_ITERATIONS_TO

#include <Eigen/Dense>

#include <dco.hpp>

#include "Hypercube.hpp"
#include "Macros.hpp"

namespace EB {

enum class GAGradientMethod {
  TANGENT,
  VECTOR_TANGENT,
  ADJOINT,
};

template <typename Function,
          int size                     = Eigen::Dynamic,
          GAGradientMethod grad_method = GAGradientMethod::TANGENT>
class AdamGradientAscent {
  static_assert(size > 0, "Dynamic Eigen Vectors are not supported.");

  Function m_function;

  double m_beta1 = 0.9;
  double m_beta2 = 0.999;
  double m_eps   = 1e-8;

 public:
  constexpr AdamGradientAscent(Function function) noexcept
      : m_function(std::move(function)) {}

  constexpr AdamGradientAscent(Function function, double beta1, double beta2, double eps) noexcept
      : m_function(std::move(function)),
        m_beta1(beta1),
        m_beta2(beta2),
        m_eps(eps) {}

  template <typename T>
  using Vector = Eigen::Vector<T, size>;

 private:
  /// Calculate gradient and function value of `Function` using dco/c++
  template <typename T>
  constexpr void
  gradient_driver(const Vector<T>& x, T& function_value, Vector<T>& gradient) const noexcept {
    if constexpr (size == Eigen::Dynamic) {
      assert(x.rows() == gradient.rows());
    }
    const Eigen::Index n = x.rows();

    if constexpr (grad_method == GAGradientMethod::TANGENT) {
      using dco_mode = dco::gt1s<T>;
      using dco_type = typename dco_mode::type;

      Vector<dco_type> dco_x(n);
      std::copy(std::cbegin(x), std::cend(x), std::begin(dco_x));

      dco_type dco_y;
      for (Eigen::Index i = 0; i < n; ++i) {
        dco::derivative(dco_x(i)) = 1.0;
        dco_y                     = m_function(dco_x);
        gradient(i)               = dco::derivative(dco_y);
        dco::derivative(dco_x(i)) = 0.0;
      }
      function_value = dco::value(dco_y);
    } else if constexpr (grad_method == GAGradientMethod::VECTOR_TANGENT) {
      using dco_mode = dco::gt1v<T, size>;
      using dco_type = typename dco_mode::type;

      Vector<dco_type> dco_x(n);
      std::copy(std::cbegin(x), std::cend(x), std::begin(dco_x));

      for (Eigen::Index i = 0; i < n; ++i) {
        dco::derivative(dco_x(i))[i] = 1.0;
      }

      dco_type dco_y = m_function(dco_x);

      function_value = dco::value(dco_y);
      for (Eigen::Index i = 0; i < n; ++i) {
        gradient(i) = dco::derivative(dco_y)[i];
      }
    } else {
      using dco_mode = dco::ga1s<T>;
      using dco_type = typename dco_mode::type;

      dco::smart_tape_ptr_t<dco_mode> tape;

      Vector<dco_type> dco_x(n);
      std::copy(std::cbegin(x), std::cend(x), std::begin(dco_x));
      tape->register_variable(std::cbegin(dco_x), std::cend(dco_x));

      dco_type dco_y = m_function(dco_x);

      dco::derivative(dco_y) = 1.0;
      tape->interpret_adjoint();

      function_value = dco::value(dco_y);
      for (Eigen::Index i = 0; i < n; ++i) {
        gradient(i) = dco::derivative(dco_x(i));
      }
    }
  }

 public:
  template <typename T>
  [[nodiscard]] constexpr auto calc(Vector<T>& x,
                                    T learning_rate,
                                    T& function_value,
                                    Vector<T>& gradient,
                                    const Hypercube<T, size>& boundaries,
                                    T tol           = std::sqrt(std::numeric_limits<T>::epsilon()),
                                    size_t max_iter = 50ul) const noexcept -> bool {
    if constexpr (size == Eigen::Dynamic) {
      assert(x.rows() == gradient.rows());
    }
    const auto n = x.rows();

    const auto update_x = [eps = m_eps, n](Vector<T>& local_x_new,
                                           const Vector<T>& local_x,
                                           T lr,
                                           const Vector<T>& bc_first_mom,
                                           const Vector<T>& bc_second_mom) {
      for (Eigen::Index i = 0; i < n; ++i) {
        local_x_new(i) = local_x(i) + lr * bc_first_mom(i) / (std::sqrt(bc_second_mom(i)) + eps);
      }
    };

    size_t iter              = 0ul;
    constexpr T diverged_tol = 1e8;

    Vector<T> first_momentum  = Vector<T>::Zero(n);
    Vector<T> second_momentum = Vector<T>::Zero(n);
    Vector<T> bias_corr_first_momentum(n);
    Vector<T> bias_corr_second_momentum(n);
    Vector<T> x_new(n);

    T alpha                         = 1.0;
    constexpr T alpha_adjust_factor = 2.0;
    constexpr T alpha_min           = std::pow(2.0, -8.0);
    bool adjust_alpha               = true;

#ifdef EB_AGA_SAVE_ITERATIONS_TO
    static_assert(std::is_convertible_v<decltype(EB_AGA_SAVE_ITERATIONS_TO), std::string>,
                  "`EB_AGA_SAVE_ITERATIONS_TO` should contain the name of the file in which the "
                  "iteration results are written.");
    std::ofstream out(EB_AGA_SAVE_ITERATIONS_TO);
    if (!out) {
      EB_PANIC("Could not open file " << EB_AGA_SAVE_ITERATIONS_TO << ": " << std::strerror(errno));
    }
#endif

    do {
      gradient_driver(x, function_value, gradient);

      first_momentum = m_beta1 * first_momentum + (1.0 - m_beta1) * gradient;
      second_momentum =
          m_beta2 * second_momentum + (1.0 - m_beta2) * gradient.cwiseProduct(gradient);

      ++iter;
      bias_corr_first_momentum  = first_momentum / (1.0 - std::pow(m_beta1, iter));
      bias_corr_second_momentum = second_momentum / (1.0 - std::pow(m_beta2, iter));

      alpha        = 1.0;
      adjust_alpha = true;
      while (adjust_alpha) {
        update_x(
            x_new, x, alpha * learning_rate, bias_corr_first_momentum, bias_corr_second_momentum);
        for (Eigen::Index i = 0; i < n; ++i) {
          if (x_new(i) < boundaries[i].min || x_new(i) > boundaries[i].max) {
            alpha /= alpha_adjust_factor;
            if (alpha < alpha_min) {
#ifdef EB_AGA_SAVE_ITERATIONS_TO
              EB_INFO("Saved Adam Gradient Ascent iterations to `" << EB_AGA_SAVE_ITERATIONS_TO
                                                                   << "`.");
#endif
              return false;
            }
            adjust_alpha = true;
            break;
          } else {
            adjust_alpha = false;
          }
        }
      }
      x = x_new;

#ifdef EB_AGA_SAVE_ITERATIONS_TO
      out << gradient.norm() << ' ' << function_value << '\n';
#endif
    } while (iter < max_iter && !std::isnan(function_value) && gradient.norm() > tol &&
             gradient.norm() < diverged_tol);

#ifdef EB_AGA_SAVE_ITERATIONS_TO
    EB_INFO("Saved Adam Gradient Ascent iterations to `" << EB_AGA_SAVE_ITERATIONS_TO << "`.");
#endif
    // EB_DEBUG_PRINT(iter);

    return iter < max_iter && !std::isnan(function_value) && gradient.norm() < diverged_tol;
  }

  template <typename T>
  [[nodiscard]] constexpr auto calc(Vector<T>& x,
                                    T learning_rate,
                                    const Hypercube<T, size>& boundaries,
                                    T tol           = std::sqrt(std::numeric_limits<T>::epsilon()),
                                    size_t max_iter = 50ul) const noexcept -> bool {
    T tmp_function_value;
    Vector<T> tmp_gradient;
    return calc(x, learning_rate, tmp_function_value, tmp_gradient, boundaries, tol, max_iter);
  }
};

}  // namespace EB

#endif  // EB_ADAM_GRADIENT_ASCENT_HPP_
