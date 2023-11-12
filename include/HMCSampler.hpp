#ifndef EB_HMC_SAMPLER_HPP_
#define EB_HMC_SAMPLER_HPP_

#include <array>
#include <fstream>
#include <iosfwd>
#include <vector>
#ifdef EB_HMC_PERF_COUNTERS
#include <atomic>
#endif  // EB_HMC_PERF_COUNTERS

#include <Eigen/Dense>

#include <dco.hpp>

#include "Macros.hpp"
#include "RandomValue.hpp"
#include "Utility/ProgressBar.hpp"

namespace EB {

#ifdef EB_HMC_PERF_COUNTERS
namespace HMCPerfCounters {
std::atomic<size_t> num_path_failure = 0ul;
std::atomic<size_t> num_param_accept = 0ul;
std::atomic<size_t> num_param_reject = 0ul;
}  // namespace HMCPerfCounters
#endif  // EB_HMC_PERF_COUNTERS

// - Options for Hamiltionian Monte Carlo Sampler --------------------------------------------------
template <typename Float, int SIZE>
requires(SIZE > 0) struct HMCOptions {
  size_t burn_in                    = 1000ul;
  size_t num_steps                  = 2000ul;
  Float max_time                    = 0.01;
  size_t num_time_steps             = 10ul;
  Eigen::Vector<Float, SIZE> theta0 = Eigen::Vector<Float, SIZE>::Zero();
};

// - Hamiltionian Monte Carlo Sampler --------------------------------------------------------------
template <typename PassiveType, int SIZE, typename LogLikelihood, typename Prior>
class HMC {
  static_assert(SIZE > 0, "Dynamic Eigen Vectors are not supported.");

  template <typename T>
  using m_ThetaVector = Eigen::Vector<T, SIZE>;

  LogLikelihood m_log_likelihood;
  Prior m_prior;

  std::array<std::vector<PassiveType>, static_cast<size_t>(SIZE)> m_chains{};

  std::vector<PassiveType> m_log_posterior_chain{};

 public:
  constexpr HMC(LogLikelihood log_likelihood, Prior prior)
      : m_log_likelihood(std::move(log_likelihood)),
        m_prior(std::move(prior)) {}

  // - Fit parameters using the Hamiltonian Monte Carlo Sampler ------------------------------------
  constexpr void fit_parameters(const HMCOptions<PassiveType, SIZE>& opt) noexcept {
    if (opt.num_steps <= 0) {
      EB_PANIC("`opt.num_steps` must be greater than 0, is " << opt.num_steps << ".");
    }
    check_initial_theta(opt.theta0);

    // Prepare chains
    for (auto& chain : m_chains) {
      chain.resize(opt.num_steps);
    }
    m_log_posterior_chain.resize(opt.num_steps);
    size_t chain_idx = 0ul;

    const auto get_random_momentum = []() -> m_ThetaVector<PassiveType> {
      return m_ThetaVector<PassiveType>::NullaryExpr([] {
        return Random::normal_real(static_cast<PassiveType>(0), static_cast<PassiveType>(1));
      });
    };

    const auto calc_log_posterior = [this](const auto& theta_, const auto& momentum_) {
      return m_log_likelihood(theta_) +  //
             m_prior.log_pdf(theta_) +   //
             log_standard_normal_pdf(momentum_);
    };

    bool first                                      = true;
    const m_ThetaVector<PassiveType> first_momentum = get_random_momentum();

    m_ThetaVector<PassiveType> theta      = opt.theta0;
    m_ThetaVector<PassiveType> last_theta = opt.theta0;
    PassiveType log_posterior             = calc_log_posterior(last_theta, first_momentum);
    PassiveType last_log_posterior{};

#ifndef EB_HMC_QUIET_FITTING
    constexpr size_t prog_bar_size = 50ul;
    Utility::ProgressBar bar(opt.burn_in + opt.num_steps, prog_bar_size);
#endif  // EB_HMC_QUIET_FITTING
    size_t burn_in   = opt.burn_in;
    size_t num_steps = opt.num_steps;
    auto delta_time  = opt.max_time / static_cast<PassiveType>(opt.num_time_steps);
    while (burn_in + num_steps > 0) {
      last_theta         = theta;
      last_log_posterior = log_posterior;

      m_ThetaVector<PassiveType> momentum = [&]() -> m_ThetaVector<PassiveType> {
        if (first) {
          first = false;
          return first_momentum;
        } else {
          return get_random_momentum();
        }
      }();

      const auto success = calculate_particle_path(theta, momentum, opt.max_time, delta_time);

      if (!success) {
        theta         = last_theta;
        log_posterior = last_log_posterior;
#ifdef EB_HMC_PERF_COUNTERS
        ++HMCPerfCounters::num_path_failure;
#endif  // EB_HMC_PERF_COUNTERS
        continue;
      }

      log_posterior                          = calc_log_posterior(theta, momentum);
      const PassiveType log_metropolis_ratio = log_posterior - last_log_posterior;

      const auto log_random_U01 = std::log(Random::uniform_real(
          std::numeric_limits<PassiveType>::epsilon(), static_cast<PassiveType>(1)));
      if (log_metropolis_ratio > log_random_U01) {
        if (burn_in > 0) {
          --burn_in;
        } else {
          for (Eigen::Index i = 0; i < SIZE; ++i) {
            m_chains[static_cast<size_t>(i)][chain_idx] = theta(i);
          }
          m_log_posterior_chain[chain_idx] = log_posterior;
          ++chain_idx;
          --num_steps;
        }
#ifdef EB_HMC_PERF_COUNTERS
        ++HMCPerfCounters::num_param_accept;
#endif  // EB_HMC_PERF_COUNTERS
#ifndef EB_HMC_QUIET_FITTING
        bar.update();
#endif  // EB_HMC_QUIET_FITTING
      } else {
        theta         = last_theta;
        log_posterior = last_log_posterior;
#ifdef EB_HMC_PERF_COUNTERS
        ++HMCPerfCounters::num_param_reject;
#endif  // EB_HMC_PERF_COUNTERS
        continue;
      }
    }
#ifndef EB_HMC_QUIET_FITTING
    std::cout << '\n';
#endif  // EB_HMC_QUIET_FITTING
  }

 private:
  // - Check if initial theta is a valid state -----------------------------------------------------
  constexpr void check_initial_theta(const m_ThetaVector<PassiveType>& theta0) const noexcept {
    // if (m_prior.pdf(theta0) < std::numeric_limits<PassiveType>::epsilon()) {
    //   EB_PANIC("Invalid initial theta ["
    //            << theta0.transpose() << "]: prior(theta) = 0. Choose a different initial
    //            theta.");
    // }
    if (std::isnan(m_prior.log_pdf(theta0))) {
      EB_PANIC("Invalid initial theta ["
               << theta0.transpose()
               << "]: log_prior(theta) = nan. Choose a different initial theta.");
    }
    if (std::isnan(potential_energy(theta0))) {
      EB_PANIC("Invalid initial theta ["
               << theta0.transpose()
               << "]: potential_energy(theta) = nan. Choose a different initial theta.");
    }
  }

  // - Calculate the potential energy for the Hamiltonian Monte Carlo Sampler ----------------------
  template <typename ActiveType>
  [[nodiscard]] constexpr auto
  potential_energy(const m_ThetaVector<ActiveType>& theta) const noexcept -> ActiveType {
    return -(m_log_likelihood(theta) + m_prior.log_pdf(theta));
  }

  // - Probability density funtion of multivariate standard normal distribution N(0,1) -------------
  [[nodiscard]] constexpr auto
  log_standard_normal_pdf(const m_ThetaVector<PassiveType>& x) const noexcept -> PassiveType {
    constexpr PassiveType log_two_pi =
        std::log(static_cast<PassiveType>(2) * std::numbers::pi_v<PassiveType>);
    return static_cast<PassiveType>(-0.5) *
           (static_cast<PassiveType>(SIZE) * log_two_pi + x.squaredNorm());
  }

  // -----------------------------------------------------------------------------------------------
  // Calculate the path of the imagined particle through the parameter space using the Leap-Frog
  // integrator, updates theta and momentum
  [[nodiscard]] constexpr auto calculate_particle_path(m_ThetaVector<PassiveType>& theta,
                                                       m_ThetaVector<PassiveType>& momentum,
                                                       PassiveType max_time,
                                                       PassiveType delta_time) const noexcept
      -> bool {
    // Leap frog algorithm:
    //
    //    0.0   0.5   1.0   1.5   2.0   2.5   3.0
    // a   0           3           4           5
    // v   0     1           3           4     6
    // x   0           2           3           4

    // Step 0:
    m_ThetaVector<PassiveType> acceleration = calculate_acceleration(theta);
    m_ThetaVector<PassiveType>& velocity =
        momentum;  // Assumes that the mass of the particle is one

    // Step 1:
    // Perform a single step of the explicit euler method the get velocity at time (delta_time/2)
    velocity += static_cast<PassiveType>(0.5) * delta_time * acceleration;

    // Step 2:
    // Update the position for the first time
    theta += velocity * delta_time;

    // Steps 3 and 4 (repeated more often, this is just for illustration purposes):
    for (PassiveType current_time = delta_time; current_time < max_time;
         current_time += delta_time) {
      acceleration = calculate_acceleration(theta);
      velocity += acceleration * delta_time;
      theta += velocity * delta_time;
    }

    // Step 5:
    // Update acceleration on last time
    acceleration = calculate_acceleration(theta);

    // Step 6:
    // Perform a last step of the implicit euler method to get the velocity at the last time step
    velocity += static_cast<PassiveType>(0.5) * delta_time * acceleration;

    return std::none_of(std::cbegin(acceleration), std::cend(acceleration), [](const auto& a) {
      return std::isnan(a);
    });
  }

  // - Calculate the acceleration at a given position theta ----------------------------------------
  [[nodiscard]] constexpr auto
  calculate_acceleration(const m_ThetaVector<PassiveType>& theta) const noexcept
      -> m_ThetaVector<PassiveType> {
#ifndef EB_HMC_USE_ADJOINT
    using dco_mode   = dco::gt1s<PassiveType>;
    using ActiveType = typename dco_mode::type;

    m_ThetaVector<ActiveType> active_theta;
    std::copy(std::cbegin(theta), std::cend(theta), std::begin(active_theta));

    m_ThetaVector<PassiveType> acceleration;
    for (int i = 0; i < SIZE; ++i) {
      dco::derivative(active_theta(i)) = 1.0;

      const auto active_res = potential_energy(active_theta);
      if (std::isnan(dco::value(active_res))) {
        return m_ThetaVector<PassiveType>::Constant(std::numeric_limits<PassiveType>::quiet_NaN());
      }
      acceleration(i) = -dco::derivative(active_res);

      dco::derivative(active_theta(i)) = 0.0;
    }

    return acceleration;
#else
    using dco_mode   = dco::ga1s<PassiveType>;
    using ActiveType = typename dco_mode::type;

    dco::smart_tape_ptr_t<dco_mode> tape{};

    m_ThetaVector<ActiveType> active_theta;
    std::copy(std::cbegin(theta), std::cend(theta), std::begin(active_theta));
    tape->register_variable(std::cbegin(active_theta), std::cend(active_theta));

    m_ThetaVector<PassiveType> acceleration;
    const auto active_res = potential_energy(active_theta);
    if (std::isnan(dco::value(active_res))) {
      return m_ThetaVector<PassiveType>::Constant(std::numeric_limits<PassiveType>::quiet_NaN());
    }

    std::transform(std::cbegin(active_theta),
                   std::cend(active_theta),
                   std::begin(acceleration),
                   [](const ActiveType& theta_i) { return -dco::derivative(theta_i); });

    return acceleration;
#endif  // EB_HMC_USE_ADJOINT
  }

 public:
  // - Access chains -------------------------------------------------------------------------------
  [[nodiscard]] constexpr auto chains() const noexcept
      -> const std::array<std::vector<PassiveType>, static_cast<size_t>(SIZE)>& {
    return m_chains;
  }

  // - Access log-posterior chain ------------------------------------------------------------------
  [[nodiscard]] constexpr auto log_posterior_chain() const noexcept
      -> const std::vector<PassiveType>& {
    return m_log_posterior_chain;
  }

  // - Simple chain postprocessing calculating some statistical properties -------------------------
  constexpr void chain_postprocessing(std::ostream& out) const noexcept {
    auto calc_mean = [](const auto& vec) {
      return std::reduce(
                 std::cbegin(vec), std::cend(vec), static_cast<PassiveType>(0), std::plus{}) /
             static_cast<PassiveType>(vec.size());
    };

    auto calc_sd = [](const auto& vec, const auto& mean) {
      return std::sqrt(
          std::transform_reduce(std::cbegin(vec),
                                std::cend(vec),
                                static_cast<PassiveType>(0),
                                std::plus{},
                                [&mean](const auto& a) { return (a - mean) * (a - mean); }) /
          static_cast<PassiveType>(vec.size()));
    };

    auto calc_skew = [](const auto& vec, const auto& mean, const auto& sd) {
      return std::sqrt(std::transform_reduce(
                           std::cbegin(vec),
                           std::cend(vec),
                           static_cast<PassiveType>(0),
                           std::plus{},
                           [&mean, &sd](const auto& a) { return std::pow((a - mean) / sd, 3); }) /
                       static_cast<PassiveType>(vec.size()));
    };

    auto print = [&](const auto& chain, const auto& name) {
      const auto mean = calc_mean(chain);
      const auto sd   = calc_sd(chain, mean);
      const auto skew = calc_skew(chain, mean, sd);
      out << name << " mean = " << mean << '\n';
      out << name << " sd   = " << sd << '\n';
      out << name << " skew = " << skew << '\n';
      out << '\n';
    };

    for (size_t i = 0; i < static_cast<size_t>(SIZE); ++i) {
      print(m_chains[i], "theta" + std::to_string(i));
    }
    print(m_log_posterior_chain, "log_posterior");
  }

  // - Dump chains to file -------------------------------------------------------------------------
  void dump_chains(const std::string& filename) const {
    using namespace std::string_literals;
    std::ofstream out(filename);
    if (!out) {
      throw std::runtime_error(EB_ERROR_LOC() + "Could not open file `"s + filename + "`: "s +
                               std::strerror(errno));
    }

    // Dump theta
    for (size_t i = 0; i < static_cast<size_t>(SIZE); ++i) {
      out << "theta" << i;
      for (PassiveType e : m_chains[i]) {
        out << std::setprecision(std::numeric_limits<PassiveType>::digits10 + 1) << ' ' << e;
      }
      out << '\n';
    }
    // Dump log-posterior
    out << "log_posterior";
    for (PassiveType e : m_log_posterior_chain) {
      out << std::setprecision(std::numeric_limits<PassiveType>::digits10 + 1) << ' ' << e;
    }
    out << '\n';

    EB_INFO("Dumped chains to `" << filename << "`");
  }
};

}  // namespace EB

#endif  // EB_HMC_SAMPLER_HPP_
