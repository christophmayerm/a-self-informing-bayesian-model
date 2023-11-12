#ifndef EB_DISTRIBUTION_CT_STUDENT_T_HPP_
#define EB_DISTRIBUTION_CT_STUDENT_T_HPP_

#include <cmath>
#include <numbers>

#include "Utility/Helper.hpp"

namespace EB::Distribution::CT {

template <double nu>
class StudentT {
  static_assert(nu > 0.0, "`nu` must be greater than zero");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    constexpr double factor =
        std::tgamma((nu + 1.0) / 2.0) /
        (Utility::constexpr_sqrt(nu * std::numbers::pi) * std::tgamma(nu / 2.0));
    constexpr double exponent = -(nu + 1.0) / 2.0;

    return static_cast<T>(factor) * static_cast<T>(pow(1.0 + (x * x) / nu, exponent));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return std::log(pdf(x));
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "StudentT("s + std::to_string(nu) + ")"s;
  }
};

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_STUDENT_T_HPP_