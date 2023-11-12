#include <chrono>
#include <iostream>

#define EB_HMC_PERF_COUNTERS
#include "EB.hpp"

#define LR_LLH_USE_NEIGHBOURHOOD
#include "LikelihoodFunctions/LinearRegressionLLH.hpp"

auto main() -> int {
  using Float = double;

  // Setup log-likelihood function
  constexpr auto input_file       = "../benchmarks/data/simpson/test_data.txt";
  constexpr Float sd              = 0.5;
  constexpr Float dist_tol_factor = 12.0;
  constexpr Float n_tol           = 75.0;

  const auto llh = [&] {
    try {
      return LinearRegressionLLH<Float>(input_file, sd, dist_tol_factor, n_tol);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      std::exit(1);
    }
  }();
  constexpr auto SIZE = decltype(llh)::SIZE;

  // Setup uninformed prior
  constexpr auto prior = EB::make_prior(EB::Distribution::RT::Cutoff(-1.5, 1.5),
                                        EB::Distribution::RT::Cutoff(0.0, 55.0));

  // Setup Sampler
  EB::HMC<Float, SIZE, decltype(llh), decltype(prior)> hmc(llh, prior);

  EB::HMCOptions<Float, SIZE> opt{
      .burn_in        = 10'000ul,
      .num_steps      = 200'000ul,
      .max_time       = 0.05,
      .num_time_steps = 10ul,
      .theta0         = {0.0, 27.5},
  };

  const auto t_begin = std::chrono::high_resolution_clock::now();
  hmc.fit_parameters(opt);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("Fitting took " << t_dur.count() << "s");

  constexpr auto chains_file = "simpson_no_hc_chains.txt";
  hmc.dump_chains(chains_file);

  hmc.chain_postprocessing(std::cout);

  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);
}
