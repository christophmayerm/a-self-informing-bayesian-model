#ifndef EB_DISTRIBUTION_CT_CONSTANT_HPP_
#define EB_DISTRIBUTION_CT_CONSTANT_HPP_

namespace EB::Distribution::CT {

template <double value>
class Constant {
  static_assert(value >= 0.0, "`value` must be greater or equal to zero.");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& /*x*/) const noexcept -> T {
    return static_cast<T>(value);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& /*x*/) const noexcept -> T {
    return std::log(static_cast<T>(value));
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "Constant("s + std::to_string(value) + ")"s;
  }
};

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_CONSTANT_HPP_