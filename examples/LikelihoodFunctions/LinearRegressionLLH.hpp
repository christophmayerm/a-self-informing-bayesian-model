#ifndef LINEAR_REGRESSION_LLH_HPP_
#define LINEAR_REGRESSION_LLH_HPP_

#include <cstring>
#include <fstream>

#include <Eigen/Dense>

#include <dco.hpp>

#include "Macros.hpp"
#include "Utility/Helper.hpp"

template <typename PT>
class LinearRegressionLLH {
  PT m_sigma{};
  PT m_dist_tol_factor = 12.0;
  PT m_n_tol           = 1e-6;

  std::vector<PT> m_x{};
  std::vector<PT> m_y{};
  size_t m_data_size{};

 public:
  static constexpr int SIZE = 2;

 private:
  constexpr void read_data(const std::string& input_file) {
    using namespace std::string_literals;

    std::ifstream in(input_file);
    if (!in) {
      throw std::runtime_error(EB_ERROR_LOC() + ": Could not open file `"s + input_file +
                               "` for reading: " + std::strerror(errno));
    }

    std::string line{};
    std::stringstream str_stream{};
    PT tmp;

    // Read x data; should be in one line
    {
      if (!std::getline(in, line)) {
        throw std::runtime_error(EB_ERROR_LOC() + ": Could not read x data from file `"s +
                                 input_file + "`: " + std::strerror(errno));
      }
      if (line.empty()) {
        throw std::runtime_error(EB_ERROR_LOC() + ": File `"s + input_file + "` has no x data");
      }
      str_stream = std::stringstream(line);
      while (str_stream >> tmp) {
        m_x.push_back(std::move(tmp));
      }
    }

    // Read y data; should be in one line
    {
      if (!std::getline(in, line)) {
        throw std::runtime_error(EB_ERROR_LOC() + ": Could not read y data from file `"s +
                                 input_file + "`: " + std::strerror(errno));
      }
      if (line.empty()) {
        throw std::runtime_error(EB_ERROR_LOC() + ": File `"s + input_file + "` has no y data");
      }
      str_stream = std::stringstream(line);
      while (str_stream >> tmp) {
        m_y.push_back(std::move(tmp));
      }
    }

    if (m_x.size() != m_y.size()) {
      throw std::runtime_error(
          EB_ERROR_LOC() + ": x and y need to have the same size, but sizes are size(x) = "s +
          std::to_string(m_x.size()) + " and size(y) = "s + std::to_string(m_y.size()));
    }
    m_data_size = m_x.size();
  }

 public:
  constexpr LinearRegressionLLH(const std::string& input_file, PT sigma)
      : m_sigma(sigma) {
    read_data(input_file);
  }

  constexpr LinearRegressionLLH(const std::string& input_file,
                                PT sigma,
                                PT dist_tol_factor,
                                PT n_tol)
      : m_sigma(sigma),
        m_dist_tol_factor(dist_tol_factor),
        m_n_tol(n_tol) {
    read_data(input_file);
  }

  template <typename AT>
  [[nodiscard]] constexpr auto operator()(const Eigen::Vector<AT, 2>& theta) const noexcept -> AT {
    // theta = [ slope, intersect ]

#if defined(LR_LLH_USE_NEIGHBOURHOOD) && defined(LR_LLH_USE_MULT_UNINORMAL)
#error "You can only use one method, either LR_LLH_USE_NEIGHBOURHOOD or LR_LLH_USE_MULT_UNINORMAL"
#endif  // defined(LR_LLH_USE_NEIGHBOURHOOD) && defined(LR_LLH_USE_MULT_UNINORMAL)

#if defined(LR_LLH_USE_NEIGHBOURHOOD)
    constexpr auto sigmoid = [](const auto& x) {
      const auto exp_x = std::exp(x);
      return exp_x / (exp_x + 1.0);
    };
    const auto sqr_dist_tol = std::pow(m_dist_tol_factor * m_sigma, 2);

    AT y_minus_mu_sqr = 0.0;
    PT n              = 0.0;
    AT sqr_dist;
    AT sig;
    for (size_t i = 0ul; i < m_data_size; ++i) {
      const auto mu = theta(0) * m_x[i] + theta(1);
      sqr_dist      = (m_y[i] - mu) * (m_y[i] - mu);
      sig           = sigmoid(sqr_dist_tol - sqr_dist);
      y_minus_mu_sqr += sqr_dist * sig;

      if constexpr (dco::mode<AT>::is_dco_type) {
        n += dco::value(sig);
      } else {
        n += sig;
      }
    }

    if (n < m_n_tol) {
      return std::numeric_limits<AT>::quiet_NaN();
    }

    const PT two_pi_n     = static_cast<PT>(2) * std::numbers::pi_v<PT> * n;
    const PT ln_det_Sigma = n * m_sigma;

    return static_cast<AT>(-0.5) * (two_pi_n + ln_det_Sigma + (y_minus_mu_sqr / m_sigma));
#elif defined(LR_LLH_USE_MULT_UNINORMAL)
    // Optional other LLH: Sum of univariate normal distributions
    AT sum_of_pdf = 0.0;
    for (size_t i = 0ul; i < m_data_size; ++i) {
      const auto mu = theta(0) * m_x[i] + theta(1);
      sum_of_pdf += std::exp(static_cast<PT>(-0.5) * std::pow((m_y[i] - mu) / m_sigma, 2));
    }
    sum_of_pdf *=
        static_cast<PT>(1) / (m_sigma * std::sqrt(static_cast<PT>(2) * std::numbers::pi_v<PT>));

    return std::log(sum_of_pdf);
#else
    //    -0.5 * ( 2*pi*m_data_size + ln(det(Sigma))    + (y - mu)^T * Sigma^-1 * (y - mu) )
    // => -0.5 * ( 2*pi*m_data_size + m_data_size*sigma + (y - mu)^T * Sigma^-1 * (y - mu) )
    // => -0.5 * ( 2*pi*m_data_size + m_data_size*sigma + (y - mu)^T * Sigma^-1 * (y - mu) )
    // => -0.5 * ( 2*pi*m_data_size + m_data_size*sigma + 1/sigma * (y - mu)^T * (y - mu) )

    AT y_minus_mu_sqr = 0.0;
    AT sqr_dist;
    for (size_t i = 0ul; i < m_data_size; ++i) {
      // Use "regular" distance of point to curve
      const auto mu = theta(0) * m_x[i] + theta(1);
      sqr_dist      = (m_y[i] - mu) * (m_y[i] - mu);
      y_minus_mu_sqr += sqr_dist;
    }

    const PT two_pi_n = static_cast<PT>(2) * std::numbers::pi_v<PT> * static_cast<PT>(m_data_size);
    const PT ln_det_Sigma = static_cast<PT>(m_data_size) * m_sigma;

    return static_cast<AT>(-0.5) * (two_pi_n + ln_det_Sigma + (y_minus_mu_sqr / m_sigma));
#endif
  }
};

#endif  // LINEAR_REGRESSION_LLH_HPP_
