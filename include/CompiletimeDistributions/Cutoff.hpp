#ifndef EB_DISTRIBUTION_CT_CUTOFF_HPP_
#define EB_DISTRIBUTION_CT_CUTOFF_HPP_

namespace EB::Distribution::CT {

template <double lower, double upper>
class Cutoff {
  static_assert(lower < upper, "`lower` must be less than `upper`.");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    if (x < static_cast<T>(lower) || x > static_cast<T>(upper)) {
      return static_cast<T>(0);
    }
    return static_cast<T>(1);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    if (x < static_cast<T>(lower) || x > static_cast<T>(upper)) {
      return std::numeric_limits<T>::quiet_NaN();
    }
    return static_cast<T>(0);
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "Cufoff("s + std::to_string(lower) + ", "s + std::to_string(upper) + ")"s;
  }
};

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_CUTOFF_HPP_