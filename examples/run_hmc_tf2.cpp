#include <chrono>
#include <iostream>

// #define EB_RAND_SEED 42
#define EB_HMC_PERF_COUNTERS
#include "Distributions.hpp"
#include "HMCSampler.hpp"
#include "Prior.hpp"

#include "LikelihoodFunctions/OnedimChen.hpp"

auto main() -> int {
  using Float = double;

  const auto prior = EB::make_prior(EB::Distribution::CT::Cutoff<0.0, 1.0>{},
                                    EB::Distribution::CT::Cutoff<0.0, 5.0>{});

  EB::HMCOptions<Float, OnedimChen<Float>::SIZE> opt{
      .burn_in   = 10'000,
      .num_steps = 140'000,
      .max_time  = 0.01,
      .theta0    = {0.5, 3.0},
  };

  constexpr size_t data_size = 1000;
  EB::HMC<Float, OnedimChen<Float>::SIZE, OnedimChen<Float>, decltype(prior)> hmc(
      OnedimChen<Float>(data_size), prior);
  const auto t_begin = std::chrono::high_resolution_clock::now();
  hmc.fit_parameters(opt);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  hmc.chain_postprocessing(std::cout);
  try {
    hmc.dump_chains("tf2_chains.txt");
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    std::exit(1);
  }

  EB_INFO("Calculation took " << t_dur.count() << 's');

  EB_INFO("burn_in   = " << opt.burn_in);
  EB_INFO("num_steps = " << opt.num_steps);
  EB_INFO("max_time  = " << opt.max_time);

  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);
}
