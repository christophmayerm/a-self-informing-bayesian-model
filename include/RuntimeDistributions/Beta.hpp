#ifndef EB_DISTRIBUTION_RT_BETA_HPP_
#define EB_DISTRIBUTION_RT_BETA_HPP_

#include <cassert>
#include <cmath>
#include <numbers>
#include <string>

namespace EB::Distribution::RT {

class Beta {
  double m_alpha;
  double m_beta;

 public:
  constexpr Beta(double alpha, double beta)
      : m_alpha(alpha),
        m_beta(beta) {
    assert(m_alpha > 0.0 && m_beta > 0.0 && "`alpha` and `beta` must be greater than zero.");
  }

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    if (m_alpha < 1.0 && m_beta < 1.0) {
      if (x <= static_cast<T>(0) || x >= static_cast<T>(1)) {
        return static_cast<T>(std::numeric_limits<double>::quiet_NaN());
      }
    } else {
      if (x < static_cast<T>(0) || x > static_cast<T>(1)) {
        return static_cast<T>(std::numeric_limits<double>::quiet_NaN());
      }
    }

    const double norm_const_inv =
        std::tgamma(m_alpha + m_beta) / (std::tgamma(m_alpha) * std::tgamma(m_beta));
    return static_cast<T>(norm_const_inv) * static_cast<T>(pow(x, m_alpha - 1)) *
           static_cast<T>(pow(1 - x, m_beta - 1));
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return std::log(pdf(x));
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "Beta("s + std::to_string(m_alpha) + ", "s + std::to_string(m_beta) + ")"s;
  }
};

}  // namespace EB::Distribution::RT

#endif  // EB_DISTRIBUTION_RT_BETA_HPP_