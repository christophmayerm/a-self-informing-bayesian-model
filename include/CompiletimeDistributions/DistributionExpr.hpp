#ifndef EB_DISTRIBUTION_CT_EXPR_HPP_
#define EB_DISTRIBUTION_CT_EXPR_HPP_

#include "../DistributionsConcepts.hpp"

namespace EB::Distribution::CT {

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
class Expr<LhsDist, RhsDist, Combinator::Mul> : private LhsDist, private RhsDist {
 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    return LhsDist::pdf(x) * RhsDist::pdf(x);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return LhsDist::log_pdf(x) + RhsDist::log_pdf(x);
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "["s + LhsDist::distribution_name() + " * "s + RhsDist::distribution_name() + "]"s;
  }
};

// - Expr for addition -----------------------------------------------------------------------------
template <Type LhsDist, Type RhsDist>
class Expr<LhsDist, RhsDist, Combinator::Add> : private LhsDist, private RhsDist {
 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const T& x) const noexcept -> T {
    return LhsDist::pdf(x) + RhsDist::pdf(x);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const T& x) const noexcept -> T {
    return std::log(pdf(x));
  }

  [[nodiscard]] static constexpr auto distribution_name() noexcept {
    using namespace std::string_literals;
    return "["s + LhsDist::distribution_name() + " + "s + RhsDist::distribution_name() + "]"s;
  }
};

// - Overload operator* for easier usage -----------------------------------------------------------
template <Type LhsDist, Type RhsDist>
[[nodiscard]] constexpr auto operator*(const LhsDist&, const RhsDist&) noexcept
    -> Expr<LhsDist, RhsDist, Combinator::Mul> {
  return {};
}

// - Overload operator+ for easier usage -----------------------------------------------------------
template <Type LhsDist, Type RhsDist>
[[nodiscard]] constexpr auto operator+(const LhsDist&, const RhsDist&) noexcept
    -> Expr<LhsDist, RhsDist, Combinator::Add> {
  return {};
}

}  // namespace EB::Distribution::CT

#endif  // EB_DISTRIBUTION_CT_EXPR_HPP_