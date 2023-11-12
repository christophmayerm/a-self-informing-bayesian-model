#ifndef EB_DISTRIBUTION_RT_HALF_NORMAL_HPP_
#define EB_DISTRIBUTION_RT_HALF_NORMAL_HPP_

#include <cassert>
#include <cmath>
#include <numbers>
#include <string>

namespace EB::Distribution::RT {

class HalfNormal {
  double m_sigma;

 public:
  constexpr HalfNormal(double sigma) noexcept
      : m_sigma(sigma) {
    assert(m_sigma > 0.0 && "Standard deviation `sigma` must be greater than zero.");
  }

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    if (x < 0) {
      return static_cast<T>(0);
    }

    const double scale_factor      = std::numbers::inv_sqrtpi * std::numbers::sqrt2 / m_sigma;
    const double inv_two_sigma_sqr = 1.0 / (2.0 * m_sigma * m_sigma);
    return static_cast<T>(scale_factor) * static_cast<T>(exp(-(x * x) * inv_two_sigma_sqr));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    if (x < 0) {
      return std::numeric_limits<T>::quiet_NaN();
    }

    // ln(pdf(x)) = -ln(sigma * sqrt(2pi)) - 0.5 * x^2/sigma^2
    const double scale_factor =
        -std::log(m_sigma / (std::numbers::inv_sqrtpi * std::numbers::sqrt2));
    const double inv_two_sigma_sqr = 1.0 / (2.0 * m_sigma * m_sigma);
    return static_cast<T>(scale_factor) - static_cast<T>(x * x * inv_two_sigma_sqr);
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "HalfNormal("s + std::to_string(m_sigma) + ")"s;
  }
};

}  // namespace EB::Distribution::RT

#endif  // EB_DISTRIBUTION_RT_HALF_NORMAL_HPP_