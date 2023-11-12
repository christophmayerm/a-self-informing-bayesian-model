#ifndef EB_DISTRIBUTION_CT_BETA_HPP_
#define EB_DISTRIBUTION_CT_BETA_HPP_

#include <cmath>
#include <numbers>

namespace EB::Distribution::CT {

template <double alpha, double beta>
class Beta {
  static_assert(alpha > 0.0 && beta > 0.0, "`alpha` and `beta` must be greater than zero.");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    if constexpr (alpha < 1.0 && beta < 1.0) {
      if (x <= static_cast<T>(0) || x >= static_cast<T>(1)) {
        return static_cast<T>(std::numeric_limits<double>::quiet_NaN());
      }
    } else {
      if (x < static_cast<T>(0) || x > static_cast<T>(1)) {
        return static_cast<T>(std::numeric_limits<double>::quiet_NaN());
      }
    }

    constexpr double norm_const_inv =
        std::tgamma(alpha + beta) / (std::tgamma(alpha) * std::tgamma(beta));
    return static_cast<T>(norm_const_inv) * static_cast<T>(pow(x, alpha - 1)) *
           static_cast<T>(pow(1 - x, beta - 1));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return std::log(pdf(x));
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "Beta("s + std::to_string(alpha) + ", "s + std::to_string(beta) + ")"s;
  }
};

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_BETA_HPP_