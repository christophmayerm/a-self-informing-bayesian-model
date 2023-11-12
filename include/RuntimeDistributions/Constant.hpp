#ifndef EB_DISTRIBUTION_RT_CONSTANT_HPP_
#define EB_DISTRIBUTION_RT_CONSTANT_HPP_

#include <cassert>
#include <string>

namespace EB::Distribution::RT {

class Constant {
  double m_value = 0.0;

 public:
  constexpr Constant(double value) noexcept
      : m_value(value) {
    assert(m_value >= 0.0 && "`value` must be greater or equal to zero.");
  }

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& /*x*/) const noexcept -> T {
    return static_cast<T>(m_value);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& /*x*/) const noexcept -> T {
    return std::log(static_cast<T>(m_value));
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "Constant("s + std::to_string(m_value) + ")"s;
  }
};

}  // namespace EB::Distribution::RT

#endif  // EB_DISTRIBUTION_RT_CONSTANT_HPP_