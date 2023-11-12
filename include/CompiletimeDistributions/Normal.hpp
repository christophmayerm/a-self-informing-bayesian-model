#ifndef EB_DISTRIBUTION_CT_NORMAL_HPP_
#define EB_DISTRIBUTION_CT_NORMAL_HPP_

#include <cmath>
#include <numbers>

namespace EB::Distribution::CT {

template <double mu, double sigma>
class Normal {
  static_assert(sigma > 0.0, "Standard deviation `sigma` must be greater than zero.");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    constexpr double inv_root_two_pi_sigma =
        (1.0 / (std::numbers::sqrt2 * sigma)) * std::numbers::inv_sqrtpi;

    return static_cast<T>(inv_root_two_pi_sigma) *
           static_cast<T>(exp(-static_cast<T>(0.5) *
                              pow((x - static_cast<T>(mu)) / static_cast<T>(sigma), 2)));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    constexpr double scale_factor =
        -std::log((std::numbers::sqrt2 * sigma) / std::numbers::inv_sqrtpi);

    return static_cast<T>(scale_factor) -
           static_cast<T>(0.5) *
               static_cast<T>(std::pow((x - static_cast<T>(mu)) / static_cast<T>(sigma), 2));
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "Normal("s + std::to_string(mu) + ", "s + std::to_string(sigma) + ")"s;
  }
};

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_NORMAL_HPP_