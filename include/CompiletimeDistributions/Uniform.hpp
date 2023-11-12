#ifndef EB_DISTRIBUTION_CT_UNIFORM_HPP_
#define EB_DISTRIBUTION_CT_UNIFORM_HPP_

#include <cmath>

namespace EB::Distribution::CT {

template <double lower, double upper>
class Uniform {
  static_assert(lower < upper, "`lower` must be less than `upper`.");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    if (x < static_cast<T>(lower) || x > static_cast<T>(upper))
      return static_cast<T>(0);

    constexpr double value = 1.0 / (upper - lower);
    return static_cast<T>(value);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    if (x < static_cast<T>(lower) || x > static_cast<T>(upper))
      return std::numeric_limits<T>::quiet_NaN();

    constexpr double value = std::log(1.0 / (upper - lower));
    return static_cast<T>(value);
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "Uniform("s + std::to_string(lower) + ", "s + std::to_string(upper) + ")"s;
  }
};

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_UNIFORM_HPP_