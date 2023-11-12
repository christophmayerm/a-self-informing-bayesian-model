#ifndef EB_DISTRIBUTION_RT_EXPR_HPP_
#define EB_DISTRIBUTION_RT_EXPR_HPP_

#include <string>

#include "../DistributionsConcepts.hpp"

namespace EB::Distribution::RT {

// - Ways to combine distributions -----------------------------------------------------------------
enum class Combinator {
  Mul,
  Add,
};

// - Base Expr -------------------------------------------------------------------------------------
template <Type LhsDist, Type RhsDist, Combinator COMBINATOR>
class Expr;

// - Expr for multiplication -----------------------------------------------------------------------
template <Type LhsDist, Type RhsDist>
class Expr<LhsDist, RhsDist, Combinator::Mul> {
  LhsDist m_lhs_dist;
  RhsDist m_rhs_dist;

 public:
  constexpr Expr(LhsDist lhs_dist, RhsDist rhs_dist)
      : m_lhs_dist(std::move(lhs_dist)),
        m_rhs_dist(std::move(rhs_dist)) {}

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    return m_lhs_dist.pdf(x) * m_rhs_dist.pdf(x);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return m_lhs_dist.log_pdf(x) + m_rhs_dist.log_pdf(x);
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "["s + m_lhs_dist.distribution_name() + " * "s + m_rhs_dist.distribution_name() + "]"s;
  }
};

// - Expr for addition -----------------------------------------------------------------------------
template <Type LhsDist, Type RhsDist>
class Expr<LhsDist, RhsDist, Combinator::Add> {
  LhsDist m_lhs_dist;
  RhsDist m_rhs_dist;

 public:
  constexpr Expr(LhsDist lhs_dist, RhsDist rhs_dist)
      : m_lhs_dist(std::move(lhs_dist)),
        m_rhs_dist(std::move(rhs_dist)) {}

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    return m_lhs_dist.pdf(x) + m_rhs_dist.pdf(x);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return std::log(pdf(x));
  }

  [[nodiscard]] auto distribution_name() const noexcept {
    using namespace std::string_literals;
    return "["s + m_lhs_dist.distribution_name() + " + "s + m_rhs_dist.distribution_name() + "]"s;
  }
};

// - Overload operator* for easier usage -----------------------------------------------------------
template <Type LhsDist, Type RhsDist>
[[nodiscard]] constexpr auto operator*(const LhsDist& lhs_dist, const RhsDist& rhs_dist) noexcept
    -> Expr<LhsDist, RhsDist, Combinator::Mul> {
  return Expr<LhsDist, RhsDist, Combinator::Mul>(lhs_dist, rhs_dist);
}

// - Overload operator+ for easier usage -----------------------------------------------------------
template <Type LhsDist, Type RhsDist>
[[nodiscard]] constexpr auto operator+(const LhsDist& lhs_dist, const RhsDist& rhs_dist) noexcept
    -> Expr<LhsDist, RhsDist, Combinator::Add> {
  return Expr<LhsDist, RhsDist, Combinator::Add>(lhs_dist, rhs_dist);
}

}  // namespace EB::Distribution::RT

#endif  // EB_DISTRIBUTION_RT_EXPR_HPP_