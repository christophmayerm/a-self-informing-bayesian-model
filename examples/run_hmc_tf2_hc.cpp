#include <chrono>
#include <future>
#include <iostream>

// #define EB_RAND_SEED 42
#define EB_HMC_PERF_COUNTERS
#define EB_HMC_QUIET_FITTING
#include "Distributions.hpp"
#include "HMCSampler.hpp"
#include "Prior.hpp"

#include "LikelihoodFunctions/OnedimChen.hpp"

/*
HC1 = {
  {0, 0.11682917273740534},
  {2.732132793365194, 3.2327355608715638},
};
Start1 = {0.00528378, 2.97502};
Expected1 = {0.056, 2.97779};

HC2 = {
  {0.3160525276357454, 0.48725910880499895},
  {0.9188771554940844, 1.3070215944139658},
};
Start2 = {0.416379, 1.11147};
Expected2 = {0.410194, 1.12494};
*/

auto main() -> int {
  using Float = double;

  const auto priorHC1 =
      EB::make_prior(EB::Distribution::CT::Cutoff<0.0, 0.11682917273740534>{},
                     EB::Distribution::CT::Cutoff<2.732132793365194, 3.2327355608715638>{});

  constexpr size_t burn_in   = 5'000ul;
  constexpr size_t num_steps = 70'000ul;
  constexpr Float max_time   = 0.01;

  EB::HMCOptions<Float, OnedimChen<Float>::SIZE> opt_hc_1{
      .burn_in   = burn_in,
      .num_steps = num_steps,
      .max_time  = max_time,
      .theta0    = {0.00528378, 2.97502},
  };

  const auto priorHC2 =
      EB::make_prior(EB::Distribution::CT::Cutoff<0.3160525276357454, 0.48725910880499895>{},
                     EB::Distribution::CT::Cutoff<0.9188771554940844, 1.3070215944139658>{});
  EB::HMCOptions<Float, OnedimChen<Float>::SIZE> opt_hc_2{
      .burn_in   = burn_in,
      .num_steps = num_steps,
      .max_time  = max_time,
      .theta0    = {0.416379, 1.11147},
  };

  constexpr size_t data_size = 1000;
  EB::HMC<Float, OnedimChen<Float>::SIZE, OnedimChen<Float>, decltype(priorHC1)> hmc_hc_1(
      OnedimChen<Float>(data_size), priorHC1);
  EB::HMC<Float, OnedimChen<Float>::SIZE, OnedimChen<Float>, decltype(priorHC2)> hmc_hc_2(
      OnedimChen<Float>(data_size), priorHC2);

  const auto t_begin = std::chrono::high_resolution_clock::now();
  std::future future_hc_1 =
      std::async(std::launch::async, &decltype(hmc_hc_1)::fit_parameters, &hmc_hc_1, opt_hc_1);
  std::future future_hc_2 =
      std::async(std::launch::async, &decltype(hmc_hc_2)::fit_parameters, &hmc_hc_2, opt_hc_2);

  future_hc_1.wait();
  future_hc_2.wait();
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("Calculation took " << t_dur.count() << 's');

  std::cout << "Hypercube 1:\n";
  hmc_hc_1.chain_postprocessing(std::cout);
  {
    Eigen::Vector<Float, OnedimChen<Float>::SIZE> expected = {0.056, 2.97779};
    EB_INFO("Start theta for hypercube 1: " << opt_hc_1.theta0.transpose());
    EB_INFO("Expected theta for hypercube 1: " << expected.transpose());
  }
  std::cout << "\n\n";

  std::cout << "Hypercube 2:\n";
  hmc_hc_2.chain_postprocessing(std::cout);
  {
    Eigen::Vector<Float, OnedimChen<Float>::SIZE> expected = {0.410194, 1.12494};
    EB_INFO("Start theta for hypercube 2: " << opt_hc_2.theta0.transpose());
    EB_INFO("Expected theta for hypercube 2: " << expected.transpose());
  }
  std::cout << "\n\n";

  try {
    hmc_hc_1.dump_chains("tf2_chains_hc_1.txt");
    hmc_hc_2.dump_chains("tf2_chains_hc_2.txt");
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    std::exit(1);
  }

  EB_INFO("burn_in   = " << burn_in);
  EB_INFO("num_steps = " << num_steps);
  EB_INFO("max_time  = " << max_time);

  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);
}
