#ifndef EB_LOG_LIKELIHOOD_HPP_
#define EB_LOG_LIKELIHOOD_HPP_

#include <cassert>
#include <numeric>
#include <vector>

#include <Eigen/Dense>

#include <dco.hpp>

#include "Macros.hpp"

namespace LV {

constexpr int LV_SYSTEM_SIZE    = 2;
constexpr int LV_PARAMETER_SIZE = 4;

template <typename Float>
constexpr void lotka_volterra_system(const Eigen::Vector<Float, LV_SYSTEM_SIZE>& x,
                                     const Eigen::Vector<Float, LV_PARAMETER_SIZE>& p,
                                     Eigen::Vector<Float, LV_SYSTEM_SIZE>& y) noexcept {
  y(0) = p(0) * x(0) - p(1) * x(0) * x(1);
  y(1) = -p(2) * x(1) + p(3) * x(0) * x(1);
}

template <typename ActiveType, typename PassiveType>
constexpr void
solve_lotka_volterra_system(const Eigen::Vector<ActiveType, LV_SYSTEM_SIZE>& x0,
                            const Eigen::Vector<ActiveType, LV_PARAMETER_SIZE>& p,
                            std::vector<Eigen::Vector<ActiveType, LV_SYSTEM_SIZE>>& xs,
                            std::vector<PassiveType>& ts,
                            PassiveType t_end,
                            size_t num_steps) noexcept {
  assert(num_steps > 0ul);
  const PassiveType step_size = t_end / static_cast<PassiveType>(num_steps);

  xs.resize(num_steps + 1);
  xs[0ul] = x0;

  ts.resize(num_steps + 1);
  ts[0ul] = 0.0;

#ifdef EB_USE_EXPLICIT_EULER
  Eigen::Vector<ActiveType, LV_SYSTEM_SIZE> dxdt;
  for (size_t i = 1; i < num_steps + 1; ++i) {
    lotka_volterra_system(xs[i - 1ul], p, dxdt);
    xs[i] = xs[i - 1ul] + step_size * dxdt;
    ts[i] = ts[i - 1ul] + step_size;
  }
#else
  // Use explicit Runge-Kutta Scheme of order 4
  Eigen::Vector<ActiveType, LV_SYSTEM_SIZE> k1;
  Eigen::Vector<ActiveType, LV_SYSTEM_SIZE> k2;
  Eigen::Vector<ActiveType, LV_SYSTEM_SIZE> k3;
  Eigen::Vector<ActiveType, LV_SYSTEM_SIZE> k4;

  constexpr auto a21 = static_cast<PassiveType>(0.5);
  constexpr auto a32 = static_cast<PassiveType>(0.5);
  constexpr auto a43 = static_cast<PassiveType>(1.0);

  constexpr auto b1 = static_cast<PassiveType>(1.0 / 6.0);
  constexpr auto b2 = static_cast<PassiveType>(1.0 / 3.0);
  constexpr auto b3 = static_cast<PassiveType>(1.0 / 3.0);
  constexpr auto b4 = static_cast<PassiveType>(1.0 / 6.0);
  for (size_t i = 1; i < num_steps + 1; ++i) {
    lotka_volterra_system<ActiveType>(xs[i - 1ul], p, k1);
    lotka_volterra_system<ActiveType>(xs[i - 1ul] + a21 * k1 * step_size, p, k2);
    lotka_volterra_system<ActiveType>(xs[i - 1ul] + a32 * k2 * step_size, p, k3);
    lotka_volterra_system<ActiveType>(xs[i - 1ul] + a43 * k3 * step_size, p, k4);

    xs[i] = xs[i - 1ul] + step_size * (b1 * k1 + b2 * k2 + b3 * k3 + b4 * k4);
    ts[i] = ts[i - 1ul] + step_size;
  }
#endif  // EB_USE_EXPLICIT_EULER
}

template <typename ActiveType, typename PassiveType>
constexpr void
solve_lotka_volterra_system(const Eigen::Vector<ActiveType, LV_SYSTEM_SIZE>& x0,
                            const Eigen::Vector<ActiveType, LV_PARAMETER_SIZE>& p,
                            std::vector<Eigen::Vector<ActiveType, LV_SYSTEM_SIZE>>& xs,
                            PassiveType t_end,
                            size_t num_steps) noexcept {
  std::vector<PassiveType> tmp_ts{};
  solve_lotka_volterra_system(x0, p, xs, tmp_ts, t_end, num_steps);
}

constexpr auto LLH_SIZE = LV_PARAMETER_SIZE + LV_SYSTEM_SIZE + 1;

template <typename PassiveType>
class LVLogLikelihood {
  std::vector<Eigen::Vector<PassiveType, LV_SYSTEM_SIZE>> m_xs_data;
  PassiveType m_t_end;
  size_t m_num_steps;
  size_t m_step_factor;

 public:
  /// theta := [... p ..., ... x0 ..., sigma]
  template <typename T>
  using ThetaVector = Eigen::Vector<T, LLH_SIZE>;

  LVLogLikelihood(const std::vector<PassiveType>& ts_data,
                  std::vector<Eigen::Vector<PassiveType, LV_SYSTEM_SIZE>> xs_data,
                  size_t step_factor) noexcept
      : m_xs_data(std::move(xs_data)),
        m_step_factor(step_factor) {
    if (ts_data.size() != m_xs_data.size()) {
      EB_PANIC("ts and xs must have the same size, sizes are sizeof(ts)="
               << ts_data.size() << " and sizeof(xs)=" << m_xs_data.size() << '.');
    }

    if (ts_data.size() < 2ul) {
      EB_PANIC("ts and xs must contain at least two points, but contain only " << ts_data.size()
                                                                               << '.');
    }

    m_num_steps                 = (ts_data.size() - 1ul) * m_step_factor;
    const PassiveType init_diff = ts_data[1ul] - ts_data[0ul];
    if (init_diff == static_cast<PassiveType>(0)) {
      EB_PANIC("Data point cannot be all at the same time.");
    }

    for (size_t i = 0ul; i < ts_data.size() - 1ul; ++i) {
      if (std::abs(ts_data[i + 1ul] - ts_data[i + 0ul] - init_diff) > 1e-6) {
        EB_PANIC("Timesteps in ts must be equidistant and ordered.");
      }
    }

    m_t_end = ts_data.back() - ts_data.front();
  }

  template <typename ActiveType>
  [[nodiscard]] constexpr auto eval(const ThetaVector<ActiveType>& theta) const noexcept
      -> ActiveType {
    static_assert(std::is_same_v<PassiveType, typename dco::mode<ActiveType>::passive_t>,
                  "Expect PassiveType to be the same as the passive type of the ActiveType.");

    // - Unpack theta ----------------------------------------------------------
    Eigen::Vector<ActiveType, LV_PARAMETER_SIZE> p;
    for (int i = 0; i < LV_PARAMETER_SIZE; ++i) {
      p(i) = theta(i);
    }

    Eigen::Vector<ActiveType, LV_SYSTEM_SIZE> x0;
    for (int i = 0; i < LV_SYSTEM_SIZE; ++i) {
      x0(i) = theta(i + LV_PARAMETER_SIZE);
    }

    ActiveType sigma = theta(LV_PARAMETER_SIZE + LV_SYSTEM_SIZE);

    // - Solve Lotka Volterra System -------------------------------------------
    std::vector<Eigen::Vector<ActiveType, LV_SYSTEM_SIZE>> xs{};
    solve_lotka_volterra_system(x0, p, xs, m_t_end, m_num_steps);

    // -0.5 * [2*pi*n + ln(det(Sigma)) + (y - mu)^T Sigma^(-1) (y - mu)]
    //    Sigma := diag(... sigma ...)
    //     => Sigma^(-1) = diag(... 1/sigma ...)
    //     => ln(det(Sigma)) = ln(sigma^n) = n * ln(sigma)
    ActiveType llh_value = 0.0;

    // (y - mu)^T Sigma^(-1) (y - mu)
    size_t counter = 0ul;
    size_t i       = 0ul;
    for (; i < xs.size(); i += m_step_factor, ++counter) {
      llh_value += (xs[i](0) - m_xs_data[counter](0)) * (xs[i](0) - m_xs_data[counter](0)) +
                   (xs[i](1) - m_xs_data[counter](1)) * (xs[i](1) - m_xs_data[counter](1));
    }
    llh_value /= sigma;
    assert((i - m_step_factor + 1) == xs.size() && "Sanity check for loop");
    assert(counter == m_xs_data.size() && "Sanity check for loop");

    // n is two time xs_data size because each entry in xs_data is a two vector which we flatten
    const PassiveType n =
        static_cast<PassiveType>(2.0) * static_cast<PassiveType>(m_xs_data.size());
    // ln(det(Sigma))
    llh_value += n * std::log(sigma);

    // 2*pi*n
    llh_value += static_cast<PassiveType>(2.0) * std::numbers::pi_v<PassiveType> * n;

    // -0.5 *
    llh_value *= static_cast<PassiveType>(-0.5);

    return llh_value;
  }
};

}  // namespace LV

#endif  // EB_LOG_LIKELIHOOD_HPP_