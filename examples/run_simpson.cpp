#include <iostream>
#include <span>
#include <vector>

using namespace std::string_literals;

#define EB_HMC_QUIET_FITTING
#define EB_HMC_PERF_COUNTERS
#include "EB.hpp"

#define LR_LLH_USE_NEIGHBOURHOOD
#include "LikelihoodFunctions/LinearRegressionLLH.hpp"

auto main(int argc, char** argv) -> int {
  // - Setup -------------------------------------------------------------------
  using Float = double;

  std::span args(argv, static_cast<size_t>(argc));
  if (args.size() < 7) {
    std::cerr << "Usage: " << args[0]
              << " <num_iterations> <learning_rate> <tol> <max_iter> <burn_in> <num_steps>\n";
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

  const auto llh = [&] {
    try {
      const std::string input_file    = "../benchmarks/data/simpson/test_data.txt";
      constexpr Float sd              = 0.5;
      constexpr Float dist_tol_factor = 12.0;
      constexpr Float n_tol           = 75.0;

      return LinearRegressionLLH<Float>(input_file, sd, dist_tol_factor, n_tol);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      std::exit(1);
    }
  }();
  constexpr auto SIZE = decltype(llh)::SIZE;
  EB::Hypercube<Float, SIZE> boundaries{
      EB::Interval<Float>{-1.5, 1.5},
      EB::Interval<Float>{0.0, 55.0},
  };

  // - Search space pruning ----------------------------------------------------
  const auto maxima =
      EB::optimistic_search(llh, num_iterations, learning_rate, boundaries, tol, max_iter);
  EB_INFO("Found " << maxima.size() << " maxima");

  const std::vector<EB::Hypercube<Float, SIZE>> hypercubes = EB::get_hypercubes(maxima, boundaries);
  EB_INFO("Found " << hypercubes.size() << " hypercubes");

  const std::vector<EB::Hypercube<Float, SIZE>> merged_hypercubes =
      EB::merge_hypercubes(hypercubes);
  EB_INFO("Found " << merged_hypercubes.size() << " merged hypercubes");

  // - Running samplers --------------------------------------------------------
#pragma omp parallel for
  for (size_t i = 0; i < merged_hypercubes.size(); ++i) {
    const auto& hc = merged_hypercubes[i];

    // Setup prior
    auto prior = EB::make_prior(EB::Distribution::RT::Cutoff(hc[0].min, hc[0].max),
                                EB::Distribution::RT::Cutoff(hc[1].min, hc[1].max));

    EB::HMC<Float, SIZE, decltype(llh), decltype(prior)> hmc(llh, prior);

    EB::HMCOptions<Float, SIZE> opt{
        .burn_in        = burn_in,
        .num_steps      = num_steps,
        .max_time       = 0.05,
        .num_time_steps = 10ul,
        .theta0 =
            {
                (hc[0].min + hc[0].max) / 2.0,
                (hc[1].min + hc[1].max) / 2.0,
            },
    };
    const auto t_begin = std::chrono::high_resolution_clock::now();
    hmc.fit_parameters(opt);
    const auto t_dur =
        std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

#pragma omp critical
    {
      EB_INFO("Fitting for hypercube " << i << " took " << t_dur.count() << "s");
      const std::string chains_file = "simpson_chains_hc_"s + std::to_string(i) + ".txt"s;
      hmc.dump_chains(chains_file);
    }
  }

  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);
}
