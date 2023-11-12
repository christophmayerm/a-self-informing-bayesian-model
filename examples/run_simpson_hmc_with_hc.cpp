#include <chrono>
#include <iostream>

#define EB_HMC_QUIET_FITTING
#define EB_HMC_PERF_COUNTERS
#include "EB.hpp"

#define LR_LLH_USE_NEIGHBOURHOOD
#include "LikelihoodFunctions/LinearRegressionLLH.hpp"

auto main() -> int {
  using namespace std::string_literals;

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

  // Setup uninformed priors; values calculated in `run_simpson_opt_search.cpp`
  using Prior = EB::Prior<EB::Distribution::RT::Cutoff, EB::Distribution::RT::Cutoff>;
  std::array<Prior, 6ul> priors{
      EB::make_prior(EB::Distribution::RT::Cutoff(-0.424187, 1.5),
                     EB::Distribution::RT::Cutoff(0, 43.7996)),

      EB::make_prior(EB::Distribution::RT::Cutoff(-1.1075, -0.795778),
                     EB::Distribution::RT::Cutoff(29.089, 34.7161)),

      EB::make_prior(EB::Distribution::RT::Cutoff(-1.12152, -0.805832),
                     EB::Distribution::RT::Cutoff(48.9361, 54.6801)),

      EB::make_prior(EB::Distribution::RT::Cutoff(-1.11902, -0.810205),
                     EB::Distribution::RT::Cutoff(18.9818, 24.5577)),

      EB::make_prior(EB::Distribution::RT::Cutoff(-1.21249, -0.897819),
                     EB::Distribution::RT::Cutoff(39.224, 44.9173)),

      EB::make_prior(EB::Distribution::RT::Cutoff(-1.16866, -0.862749),
                     EB::Distribution::RT::Cutoff(9.38049, 14.9198)),
  };

  std::array<Eigen::Vector<Float, SIZE>, 6ul> theta0s{
      Eigen::Vector<Float, SIZE>{0.626879, 10.6119},
      Eigen::Vector<Float, SIZE>{-0.955955, 31.949},
      Eigen::Vector<Float, SIZE>{-0.955935, 51.6877},
      Eigen::Vector<Float, SIZE>{-0.960211, 21.7318},
      Eigen::Vector<Float, SIZE>{-1.04854, 41.9836},
      Eigen::Vector<Float, SIZE>{-1.01301, 12.134},
  };

  std::array<Float, 6ul> max_times{
      0.025,
      0.05,
      0.05,
      0.05,
      0.05,
      0.05,
  };

#pragma omp parallel for
  for (size_t i = 0ul; i < priors.size(); ++i) {
    // Setup Sampler
    EB::HMC<Float, SIZE, decltype(llh), Prior> hmc(llh, priors[i]);

    // Options for fitting the parameters
    EB::HMCOptions<Float, SIZE> opt{
        .burn_in        = 10'000ul,
        .num_steps      = 200'000ul,
        .max_time       = max_times[i],
        .num_time_steps = 10ul,
        .theta0         = theta0s[i],
    };

    const auto t_begin = std::chrono::high_resolution_clock::now();
    hmc.fit_parameters(opt);
    const auto t_dur =
        std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

#pragma omp critical
    {
      EB_INFO("Hypercube " << i << ':');
      EB_INFO("Fitting took " << t_dur.count() << "s");
      hmc.chain_postprocessing(std::cout);
      const std::string chains_file = "simpson_chains_hc_"s + std::to_string(i) + ".txt"s;
      hmc.dump_chains(chains_file);
      std::cout << "============================================================\n";
    }
  }

  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);
}
