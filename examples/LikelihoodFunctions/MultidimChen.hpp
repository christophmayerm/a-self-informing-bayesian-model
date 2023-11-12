#ifndef MULTIDIM_CHEN_HPP_
#define MULTIDIM_CHEN_HPP_

#include <type_traits>
#include <vector>

#include <Eigen/Dense>

#include "Macros.hpp"
#include "RandomValue.hpp"

/*************************************\
 * theta = [ rho, mu, lambda, beta ] *
\*************************************/

template <typename PT, int DIM>
class MultidimChen {
  static_assert(DIM > 0, "DIM has to be greater than 0");

  static constexpr bool m_use_stack = DIM < 100;

 public:
  template <typename T>
  using Vector =
      std::conditional_t<m_use_stack, Eigen::Vector<T, DIM>, Eigen::Vector<T, Eigen::Dynamic>>;

  template <typename T>
  using Matrix = std::conditional_t<m_use_stack,
                                    Eigen::Matrix<T, DIM, DIM>,
                                    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>>;

  static constexpr int SIZE = 4;

 private:
  static constexpr PT m_rho0 = 0.5;
  static constexpr PT m_rho1 = 0.45;
  static constexpr PT m_rho2 = 0.05;
  static_assert(std::abs(m_rho0 + m_rho1 + m_rho2 - 1.0) < 1e-8);

  Vector<PT> m_mu0 = Vector<PT>::Constant(DIM, 0.0);
  Vector<PT> m_mu1 = Vector<PT>::Constant(DIM, 0.75);
  Vector<PT> m_mu2 = Vector<PT>::Constant(DIM, 3.0);

  static constexpr PT m_lambda = 0.1;
  static constexpr PT m_beta   = 0.001;

  std::vector<Vector<PT>> m_data{};

 public:
  constexpr MultidimChen(size_t n) noexcept {
    m_data.resize(n);

    std::generate(std::begin(m_data), std::end(m_data), [this] {
      // p0 = rho0 * N(x | mu0, sigma) + rho1 * N(x | mu1, sigma) + rho2 * N(x | mu2, sigma)

      const Matrix<PT> sigma =
          m_lambda * Matrix<PT>::Identity(DIM, DIM) +
          m_beta * (Matrix<PT>::Constant(DIM, DIM, 1.0) - Matrix<PT>::Identity(DIM, DIM));

      const PT choice = EB::Random::uniform_real(static_cast<PT>(0), static_cast<PT>(1));
      if (choice <= m_rho0) {
        return EB::Random::multivariate_normal_real(m_mu0, sigma);
      } else if (choice <= m_rho0 + m_rho1) {
        return EB::Random::multivariate_normal_real(m_mu1, sigma);
      } else /* if (choice <= m_rho0 + m_rho1 + m_rho2) */ {
        return EB::Random::multivariate_normal_real(m_mu2, sigma);
      }
    });

#ifdef MULTIDIM_CHEN_CALC_DATA_STAT
    const Vector<PT> mean = std::reduce(std::cbegin(m_data),
                                        std::cend(m_data),
                                        static_cast<Vector<PT>>(Vector<PT>::Zero(DIM)),
                                        std::plus{}) /
                            static_cast<PT>(n);
    EB_INFO("mean = " << mean.transpose());

    const Matrix<PT> cov =
        std::transform_reduce(
            std::cbegin(m_data),
            std::cend(m_data),
            static_cast<Matrix<PT>>(Matrix<PT>::Zero(DIM, DIM)),
            std::plus{},
            [&mean](const auto& x) { return (x - mean) * (x - mean).transpose(); }) /
        static_cast<PT>(n);
    EB_INFO("cov =\n" << cov);
#endif  // MULTIDIM_CHEN_CALC_DATA_STAT
  }

 private:
  template <typename AT>
  [[nodiscard]] constexpr auto multivariate_normal_pdf(const Vector<PT>& x,
                                                       const Vector<AT>& mu,
                                                       const Matrix<AT>& sigma) const noexcept
      -> AT {
    Eigen::LLT<Matrix<AT>> llt(sigma);
    if (llt.info() == Eigen::NumericalIssue) {
      return std::numeric_limits<AT>::quiet_NaN();
    }

    const Vector<AT> residual           = x - mu;
    const Vector<AT> sigma_inv_residual = llt.solve(residual);

    const auto& L = llt.matrixL();
    AT det_sigma  = 1.0;
    for (int i = 0; i < DIM; ++i) {
      det_sigma *= L(i, i);
    }
    det_sigma *= det_sigma;

    return std::exp(static_cast<PT>(-0.5) * residual.dot(sigma_inv_residual)) /
           std::sqrt(std::pow(static_cast<PT>(2) * std::numbers::pi_v<PT>, DIM) * det_sigma);
  }

 public:
  template <typename AT>
  [[nodiscard]] constexpr auto operator()(const Eigen::Vector<AT, SIZE>& theta) const noexcept
      -> AT {
    // theta = [ rho, mu, lambda, beta ]
    // sigma = lambda * I + beta * (1 - I)
    // llh = E[ln( (1 - rho) * N(x | 0, sigma) + rho * N(x | mu, sigma) )]
    enum { RHO, MU, LAMBDA, BETA };

    const Vector<AT> zero_vec = Vector<AT>::Zero(DIM);
    const Vector<AT> mu       = Vector<AT>::Constant(DIM, theta(MU));
    const Matrix<AT> sigma =
        theta(LAMBDA) * Matrix<PT>::Identity(DIM, DIM) +
        theta(BETA) * (Matrix<PT>::Constant(DIM, DIM, 1.0) - Matrix<PT>::Identity(DIM, DIM));

    AT sum = 0.0;
    for (const auto& x : m_data) {
      sum += std::log((1.0 - theta(RHO)) * multivariate_normal_pdf<AT>(x, zero_vec, sigma) +
                      theta(RHO) * multivariate_normal_pdf<AT>(x, mu, sigma));
    }

    return sum / static_cast<PT>(m_data.size());
  }

  [[nodiscard]] constexpr auto beta() const noexcept -> PT { return m_beta; }
};

#endif  // MULTIDIM_CHEN_HPP_
