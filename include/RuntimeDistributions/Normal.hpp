#ifndef EB_DISTRIBUTION_RT_NORMAL_HPP_
#define EB_DISTRIBUTION_RT_NORMAL_HPP_

#include <cassert>
#include <cmath>
#include <numbers>
#include <string>

#include "Utility/Helper.hpp"

namespace EB::Distribution::RT {

class Normal {
  double m_mu;
  double m_sigma;

 public:
  constexpr Normal(double mu, double sigma) noexcept
      : m_mu(mu),
        m_sigma(sigma) {
    assert(m_sigma > 0.0 && "Standard deviation `sigma` must be greater than zero.");
  }

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    const double inv_root_two_pi_sigma =
        (1.0 / (std::numbers::sqrt2 * m_sigma)) * std::numbers::inv_sqrtpi;

    return static_cast<T>(inv_root_two_pi_sigma) *
           static_cast<T>(exp(-static_cast<T>(0.5) *
                              pow((x - static_cast<T>(m_mu)) / static_cast<T>(m_sigma), 2)));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    const double scale_factor =
        -std::log((std::numbers::sqrt2 * m_sigma) / std::numbers::inv_sqrtpi);

    return static_cast<T>(scale_factor) -
           static_cast<T>(0.5) *
               static_cast<T>(std::pow((x - static_cast<T>(m_mu)) / static_cast<T>(m_sigma), 2));
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "Normal("s + std::to_string(m_mu) + ", "s + std::to_string(m_sigma) + ")"s;
  }
};

}  // namespace EB::Distribution::RT

#endif  // EB_DISTRIBUTION_RT_NORMAL_HPP_