#ifndef EB_DISTRIBUTION_RT_CUTOFF_HPP_
#define EB_DISTRIBUTION_RT_CUTOFF_HPP_

#include <cassert>
#include <string>

namespace EB::Distribution::RT {

class Cutoff {
  double m_lower;
  double m_upper;

 public:
  constexpr Cutoff(double lower, double upper) noexcept
      : m_lower(lower),
        m_upper(upper) {
    assert(m_lower < m_upper && "`lower` must be less than `upper`.");
  }

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    if (x < static_cast<T>(m_lower) || x > static_cast<T>(m_upper)) {
      return static_cast<T>(0);
    }
    return static_cast<T>(1);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    if (x < static_cast<T>(m_lower) || x > static_cast<T>(m_upper)) {
      return std::numeric_limits<T>::quiet_NaN();
    }
    return static_cast<T>(0);
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "Cufoff("s + std::to_string(m_lower) + ", "s + std::to_string(m_upper) + ")"s;
  }
};

}  // namespace EB::Distribution::RT

#endif  // EB_DISTRIBUTION_RT_CUTOFF_HPP_