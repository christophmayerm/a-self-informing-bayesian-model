#ifndef EB_DISTRIBUTION_RT_STUDENT_T_HPP_
#define EB_DISTRIBUTION_RT_STUDENT_T_HPP_

#include <cassert>
#include <cmath>
#include <numbers>
#include <string>

#include "Utility/Helper.hpp"

namespace EB::Distribution::RT {

class StudentT {
  double m_nu;

 public:
  constexpr StudentT(double nu)
      : m_nu(nu) {
    assert(m_nu > 0.0 && "`nu` must be greater than zero");
  }

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    const double factor = std::tgamma((m_nu + 1.0) / 2.0) /
                          (std::sqrt(m_nu * std::numbers::pi) * std::tgamma(m_nu / 2.0));
    const double exponent = -(m_nu + 1.0) / 2.0;

    return static_cast<T>(factor) * static_cast<T>(pow(1.0 + (x * x) / m_nu, exponent));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return std::log(pdf(x));
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "StudentT("s + std::to_string(m_nu) + ")"s;
  }
};

}  // namespace EB::Distribution::RT

#endif  // EB_DISTRIBUTION_RT_STUDENT_T_HPP_