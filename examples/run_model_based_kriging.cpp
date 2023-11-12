#include <chrono>
#include <iostream>
#include <span>

#define EB_HMC_PERF_COUNTERS
#define EB_HMC_QUIET_FITTING
#include "EB.hpp"

#define EB_HMC_USE_ADJOINT
// #define MBK_APPROX_LLH
#include "LikelihoodFunctions/ModelBasedKriging.hpp"

// - Without hypercubes ----------------------------------------------------------------------------
template <typename Float, int SIZE, typename LLH, typename Prior>
void run_without_hypercubes(LLH llh,
                            Prior prior,
                            size_t burn_in,
                            size_t num_steps,
                            const Eigen::Vector<Float, SIZE>& theta0) noexcept {
  EB::HMCPerfCounters::num_param_accept = 0;
  EB::HMCPerfCounters::num_param_reject = 0;
  EB::HMCPerfCounters::num_path_failure = 0;

  EB::HMC<Float, SIZE, LLH, Prior> hmc(std::move(llh), std::move(prior));

  EB::HMCOptions<Float, SIZE> opt{
      .burn_in        = burn_in,
      .num_steps      = num_steps,
      .max_time       = 0.01,
      .num_time_steps = 10ul,
      .theta0         = theta0,
  };

  const auto t_begin = std::chrono::high_resolution_clock::now();
  hmc.fit_parameters(opt);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("Fitting without hypercubes took " << t_dur.count() << "s");
  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);

  try {
    constexpr auto filename = "chain_mbk_no_hc.txt";
    hmc.dump_chains(filename);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    std::exit(1);
  }
}

// - With hypercubes -------------------------------------------------------------------------------
template <typename Float, int SIZE, typename LLH, typename Prior>
void run_with_hypercubes(LLH llh,
                         Prior prior,
                         size_t burn_in,
                         size_t num_steps,
                         size_t num_iterations,
                         Float learning_rate,
                         Float tol,
                         size_t max_iter) noexcept {
  EB::HMCPerfCounters::num_param_accept = 0;
  EB::HMCPerfCounters::num_param_reject = 0;
  EB::HMCPerfCounters::num_path_failure = 0;

  const auto posterior = [&]<typename AT>(const Eigen::Vector<AT, SIZE>& theta) {
    return llh(theta) + prior.log_pdf(theta);
  };

  const EB::Hypercube<Float, SIZE> boundaries{
      EB::Interval<Float>{.min = 0.0, .max = 2.0},
      EB::Interval<Float>{.min = -2.0, .max = 2.0},
      EB::Interval<Float>{.min = 0.0, .max = 2.0},
      EB::Interval<Float>{.min = 0.0, .max = 2.0},
  };

  const auto t_begin = std::chrono::high_resolution_clock::now();
  const auto maxima =
      EB::optimistic_search<Float, decltype(posterior), SIZE, true, EB::GAGradientMethod::ADJOINT>(
          posterior, num_iterations, learning_rate, boundaries, tol, max_iter);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("Optimistic search took " << t_dur.count() << "s");
  EB_INFO("Found " << maxima.size() << " maxima");

  const auto hypercubes = EB::get_hypercubes(maxima, boundaries);
  EB_INFO("Found " << hypercubes.size() << " hypercubes");

  const auto merged_hypercubes = EB::merge_hypercubes(hypercubes);
  EB_INFO("Found " << merged_hypercubes.size() << " merged hypercubes");

#pragma omp parallel for
  for (size_t i = 0; i < merged_hypercubes.size(); ++i) {
    const auto& hc           = merged_hypercubes[i];
    const auto updated_prior = EB::make_prior(
        prior.template get<0>() * EB::Distribution::RT::Cutoff(hc[0].min, hc[0].max),
        prior.template get<1>() * EB::Distribution::RT::Cutoff(hc[1].min, hc[1].max),
        prior.template get<2>() * EB::Distribution::RT::Cutoff(hc[2].min, hc[2].max),
        prior.template get<3>() * EB::Distribution::RT::Cutoff(hc[3].min, hc[3].max));

    EB::HMC<Float, SIZE, LLH, decltype(updated_prior)> hmc(std::move(llh),
                                                           std::move(updated_prior));

    EB::HMCOptions<Float, SIZE> opt{
#ifdef SAME_NUM_STEPS_PER_HC
        .burn_in   = burn_in,
        .num_steps = num_steps,
#else
        .burn_in   = burn_in / merged_hypercubes.size(),
        .num_steps = num_steps / merged_hypercubes.size(),
#endif  // SAME_OVERALL_STEPS
        .max_time       = 0.01,
        .num_time_steps = 10ul,
        .theta0 =
            {
                std::midpoint(hc[0].min, hc[0].max),
                std::midpoint(hc[1].min, hc[1].max),
                std::midpoint(hc[2].min, hc[2].max),
                std::midpoint(hc[3].min, hc[3].max),
            },
    };

    const auto t_begin_local = std::chrono::high_resolution_clock::now();
    hmc.fit_parameters(opt);
    const auto t_dur_local =
        std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin_local);

#pragma omp critical
    {
      EB_INFO("Fitting hypercube " << i << " took " << t_dur_local.count() << "s");

      try {
        using namespace std::string_literals;
        const auto filename = "chain_mbk_hc_"s + std::to_string(i) + ".txt"s;
        hmc.dump_chains(filename);
      } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::exit(1);
      }
    }
  }
  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);
}

// - Main ------------------------------------------------------------------------------------------
auto main(int argc, char** argv) -> int {
  using Float = double;

  std::span args(argv, static_cast<size_t>(argc));
  if (args.size() < 7) {
    std::cerr << "Usage: " << args[0]
              << " <num_iterations> <learning_rate> <tolerance> <max_iter> <burn_in> <num_steps>\n";
    std::exit(1);
  }

  auto parse_size_t = [](const char* cstr) {
    try {
      return std::stoull(cstr);
    } catch (const std::exception&) {
      std::cerr << "Could not parse string `" << cstr << "` to unsigned long long.\n";
      std::exit(1);
    }
  };
  auto parse_double = [](const char* cstr) {
    try {
      return std::stod(cstr);
    } catch (const std::exception&) {
      std::cerr << "Could not parse string `" << cstr << "` to double.\n";
      std::exit(1);
    }
  };

  const size_t num_iterations = parse_size_t(args[1]);
  const double learning_rate  = parse_double(args[2]);
  const double tol            = parse_double(args[3]);
  const size_t max_iter       = parse_size_t(args[4]);
  const size_t burn_in        = parse_size_t(args[5]);
  const size_t num_steps      = parse_size_t(args[6]);

  const auto llh = [] {
    try {
      const std::string input_file     = "../data/apt_price_berlin_train.txt";
      constexpr size_t max_num_samples = 512;
      return ModelBasedKrigingLLH<Float>(input_file, max_num_samples);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      std::exit(1);
    }
  }();
  constexpr auto SIZE = decltype(llh)::SIZE;

  const auto prior = EB::make_prior(
      EB::Distribution::RT::Normal(0.3, 0.1) * EB::Distribution::RT::Cutoff(0.0, 2.0),
      EB::Distribution::RT::Normal(-0.1, 0.1) * EB::Distribution::RT::Cutoff(-2.0, 2.0),
      EB::Distribution::RT::Normal(0.0025, 0.1) * EB::Distribution::RT::Cutoff(0.0, 2.0),
      EB::Distribution::RT::Normal(0.99, 0.1) * EB::Distribution::RT::Cutoff(0.0, 2.0));

  run_without_hypercubes<Float, SIZE, decltype(llh), decltype(prior)>(
      llh, prior, burn_in, num_steps, {0.3, -0.1, 0.0025, 0.99});

  run_with_hypercubes<Float, SIZE, decltype(llh), decltype(prior)>(
      llh, prior, burn_in, num_steps, num_iterations, learning_rate, tol, max_iter);
}
