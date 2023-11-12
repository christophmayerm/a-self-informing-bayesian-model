#ifndef EB_PRIOR_HPP_
#define EB_PRIOR_HPP_

#include <Eigen/Dense>

#include "DistributionsConcepts.hpp"
#include "Macros.hpp"

namespace EB {

namespace internal {

// - Base case -------------------------------------------------------------------------------------
template <size_t, size_t, Distribution::Type...>
class PriorImpl;

// - Case no distribution --------------------------------------------------------------------------
template <size_t size, size_t idx>
class PriorImpl<size, idx> {
  static_assert(size == idx,
                "Expect size to be equal to idx. If this fails the implementation has a bug.");

 public:
  template <typename T>
  [[nodiscard]] constexpr auto pdf(const Eigen::Vector<T, size>&) const noexcept -> T {
    return static_cast<T>(1);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const Eigen::Vector<T, size>&) const noexcept -> T {
    return static_cast<T>(0);
  }
};

// - Case one or more distributions ----------------------------------------------------------------
template <size_t size, size_t idx, Distribution::Type Dist, Distribution::Type... Dists>
class PriorImpl<size, idx, Dist, Dists...> {
  static_assert(idx < size,
                "Expect idx to be less than the size. If this fails the implementation has a bug.");

  Dist m_dist;
  PriorImpl<size, idx + 1, Dists...> m_other_dists;

 public:
  constexpr PriorImpl(Dist dist, Dists... other_dists) noexcept
      : m_dist(std::move(dist)),
        m_other_dists(PriorImpl<size, idx + 1, Dists...>(std::move(other_dists)...)) {}

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const Eigen::Vector<T, size>& x) const noexcept -> T {
    return m_dist.pdf(x(idx)) * m_other_dists.pdf(x);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const Eigen::Vector<T, size>& x) const noexcept -> T {
    return m_dist.log_pdf(x(idx)) + m_other_dists.log_pdf(x);
  }

  template <size_t lookup_idx>
  [[nodiscard]] constexpr auto get() const noexcept {
    if constexpr (lookup_idx == idx) {
      return m_dist;
    } else {
      return m_other_dists.template get<lookup_idx>();
    }
  }
};

}  // namespace internal

// - Generic prior that combines multiple distributins by multiplication ---------------------------
template <Distribution::Type... Dists>
class Prior {
  using Impl = internal::PriorImpl<sizeof...(Dists), 0, Dists...>;
  Impl m_impl;

 public:
  static constexpr size_t size = sizeof...(Dists);

  constexpr Prior(Dists... dists) noexcept
      : m_impl(Impl(std::move(dists)...)) {}

  template <typename T>
  [[nodiscard]] constexpr auto pdf(const Eigen::Vector<T, size>& x) const noexcept -> T {
    return m_impl.pdf(x);
  }

  template <typename T>
  [[nodiscard]] constexpr auto log_pdf(const Eigen::Vector<T, size>& x) const noexcept -> T {
    return m_impl.log_pdf(x);
  }

  template <size_t idx>
  [[nodiscard]] constexpr auto get() const noexcept {
    static_assert(idx < size, "Index for distribution has be be less than size.");
    return m_impl.template get<idx>();
  }
};

// - Helper function to create prior ---------------------------------------------------------------
template <Distribution::Type... Dists>
[[nodiscard]] constexpr auto make_prior(Dists... dists) noexcept -> Prior<Dists...> {
  return Prior(std::move(dists)...);
}

}  // namespace EB

#endif  // EB_PRIOR_HPP_
