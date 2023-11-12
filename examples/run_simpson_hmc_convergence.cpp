#include <chrono>
#include <fstream>
#include <iostream>

#define EB_HMC_QUIET_FITTING
#include "EB.hpp"

#define LR_LLH_USE_NEIGHBOURHOOD
#include "LikelihoodFunctions/LinearRegressionLLH.hpp"

using namespace std::string_literals;

// - Setup -------------—-------------—-------------—-------------—-------------—-------------—-----
const auto RESULT_PATH               = "simpson_convergence/"s;
constexpr std::array num_steps_array = [] {
  constexpr size_t max  = 2000ul;  // 200'000ul;
  constexpr size_t min  = 10ul;    // 1'000ul;
  constexpr size_t step = 50ul;    // 5'000ul;
  constexpr size_t n    = max / step + 1ul;
  std::array<size_t, n> arr;
  std::generate(std::begin(arr), std::end(arr), [i = 0ul]() mutable {
    return (i > 0ul) ? step * i++ : min * ++i;
  });
  return arr;
}();

const auto log_file = RESULT_PATH + "run.log"s;
auto log_out        = [] {
  try {
    return std::ofstream(log_file);
  } catch (const std::exception& e) {
    EB_PANIC("Could not open file `" << log_file << "` for reading: " << std::strerror(errno));
  }
}();
// - Setup -------------—-------------—-------------—-------------—-------------—-------------—-----

// - Convergence test without hypercubes -------------—-------------—-------------—-------------—---
template <typename Float, int SIZE, typename LLH>
void convergence_no_hc(const LLH& llh) noexcept {
  constexpr auto prior = EB::make_prior(EB::Distribution::RT::Cutoff(-1.5, 1.5),
                                        EB::Distribution::RT::Cutoff(0.0, 55.0));

  for (size_t num_steps : num_steps_array) {
    EB::HMC<Float, SIZE, LLH, decltype(prior)> hmc(llh, prior);

    EB::HMCOptions<Float, SIZE> opt{
        .burn_in        = 0ul,
        .num_steps      = num_steps,
        .max_time       = 0.05,
        .num_time_steps = 10ul,
        .theta0         = {0.0, 27.5},
    };

    const auto t_begin = std::chrono::high_resolution_clock::now();
    hmc.fit_parameters(opt);
    const auto t_dur =
        std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

    log_out << "No hc (num_steps = " << num_steps << "): Fitting took " << t_dur.count() << "s\n";

    try {
      const auto chains_file = RESULT_PATH + "no_hc_"s + std::to_string(num_steps) + ".txt"s;
      hmc.dump_chains(chains_file);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      std::exit(1);
    }
  }
}

// - Convergence test with hypercubes -------------—-------------—-------------—-------------—------
template <typename Float, int SIZE, typename LLH>
void convergence_with_hc(const LLH& llh) noexcept {
  // - Setup uninformed priors; values calculated in `run_simpson_opt_search.cpp` ------------------
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
  // - Setup uninformed priors; values calculated in `run_simpson_opt_search.cpp` ------------------

  for (size_t num_steps : num_steps_array) {
#pragma omp parallel for
    for (size_t i = 0ul; i < priors.size(); ++i) {
      // Setup Sampler
      EB::HMC<Float, SIZE, decltype(llh), Prior> hmc(llh, priors[i]);

      // Options for fitting the parameters
      EB::HMCOptions<Float, SIZE> opt{
          .burn_in        = 0ul,
          .num_steps      = num_steps,
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
        log_out << "With hc (num_steps = " << num_steps << ", hc = " << i << "): Fitting took "
                << t_dur.count() << "s\n";
        try {
          const auto chains_file = RESULT_PATH + "with_hc_"s + std::to_string(num_steps) + "_"s +
                                   std::to_string(i) + ".txt"s;
          hmc.dump_chains(chains_file);
        } catch (const std::exception& e) {
          std::cerr << e.what() << '\n';
          std::exit(1);
        }
      }
    }
  }
}

// - Main ------------------------------------------------------------------------------------------
auto main() -> int {
  using Float = double;

  // - Setup log-likelihood function ---------------------------------------------------------------
  constexpr auto input_file       = "../benchmarks/data/simpson/test_data.txt";
  constexpr Float sd              = 0.5;
  constexpr Float dist_tol_factor = 12.0;
  constexpr Float n_tol           = 75.0;
  const auto llh                  = [&] {
    try {
      return LinearRegressionLLH<Float>(input_file, sd, dist_tol_factor, n_tol);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      std::exit(1);
    }
  }();
  constexpr auto SIZE = decltype(llh)::SIZE;
  // - Setup log-likelihood function ---------------------------------------------------------------

  EB_INFO("Run convergence experiment without hypercubes...");
  std::cout << std::flush;
  convergence_no_hc<Float, SIZE>(llh);

  EB_INFO("Run convergence experiment with hypercubes...");
  std::cout << std::flush;
  convergence_with_hc<Float, SIZE>(llh);
}
