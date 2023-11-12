#ifndef EB_DISTRIBUTION_CT_HALF_NORMAL_HPP_
#define EB_DISTRIBUTION_CT_HALF_NORMAL_HPP_

#include <cmath>
#include <numbers>

namespace EB::Distribution::CT {

template <double sigma>
class HalfNormal {
  static_assert(sigma > 0.0, "Standard deviation `sigma` must be greater than zero.");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    if (x < 0) {
      return static_cast<T>(0);
    }

    constexpr double scale_factor      = std::numbers::inv_sqrtpi * std::numbers::sqrt2 / sigma;
    constexpr double inv_two_sigma_sqr = 1.0 / (2.0 * sigma * sigma);
    return static_cast<T>(scale_factor) * static_cast<T>(exp(-(x * x) * inv_two_sigma_sqr));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    if (x < 0) {
      return std::numeric_limits<T>::quiet_NaN();
    }

    // ln(pdf(x)) = -ln(sigma * sqrt(2pi)) - 0.5 * x^2/sigma^2
    constexpr double scale_factor =
        -std::log(sigma / (std::numbers::inv_sqrtpi * std::numbers::sqrt2));
    constexpr double inv_two_sigma_sqr = 1.0 / (2.0 * sigma * sigma);
    return static_cast<T>(scale_factor) - static_cast<T>(x * x * inv_two_sigma_sqr);
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "HalfNormal("s + std::to_string(sigma) + ")"s;
  }
};

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_HALF_NORMAL_HPP_