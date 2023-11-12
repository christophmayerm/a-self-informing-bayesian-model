#include <chrono>
#include <fstream>
#include <iostream>

#define EB_HMC_QUIET_FITTING
#include "EB.hpp"

#include "LikelihoodFunctions/OnedimChen.hpp"

using namespace std::string_literals;

// - Setup -------------—-------------—-------------—-------------—-------------—-------------—-----
const auto RESULT_PATH               = "chen_convergence/"s;
constexpr std::array num_steps_array = [] {
  constexpr size_t max  = 2'000'000ul;  // 200'000ul;  // 2000ul;
  constexpr size_t min  = 10'000ul;     // 1'000ul;    // 10ul;
  constexpr size_t step = 50'000ul;     // 5'000ul;    // 50ul;
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
  constexpr auto prior = EB::make_prior(EB::Distribution::RT::Cutoff(0.0, 1.0),
                                        EB::Distribution::RT::Cutoff(0.0, 5.0));

  for (size_t num_steps : num_steps_array) {
    EB::HMC<Float, SIZE, LLH, decltype(prior)> hmc(llh, prior);

    EB::HMCOptions<Float, SIZE> opt{
        .burn_in        = 0ul,
        .num_steps      = num_steps,
        .max_time       = 0.01,
        .num_time_steps = 10ul,
        .theta0         = {0.5, 2.5},
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
  std::array<Prior, 2ul> priors{
      EB::make_prior(EB::Distribution::RT::Cutoff(0.0, 0.11682917273740534),
                     EB::Distribution::RT::Cutoff(2.732132793365194, 3.2327355608715638)),

      EB::make_prior(EB::Distribution::RT::Cutoff(0.3160525276357454, 0.48725910880499895),
                     EB::Distribution::RT::Cutoff(0.9188771554940844, 1.3070215944139658)),
  };

  std::array<Eigen::Vector<Float, SIZE>, 6ul> theta0s{
      Eigen::Vector<Float, SIZE>{0.00528378, 2.97502},
      Eigen::Vector<Float, SIZE>{0.416379, 1.11147},
  };

  std::array<Float, 6ul> max_times{
      0.01,
      0.01,
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
  constexpr size_t data_size = 1000;
  OnedimChen<Float> llh(data_size);
  // - Setup log-likelihood function ---------------------------------------------------------------

  EB_INFO("Run convergence experiment without hypercubes...");
  std::cout << std::flush;
  convergence_no_hc<Float, OnedimChen<Float>::SIZE>(llh);

  EB_INFO("Run convergence experiment with hypercubes...");
  std::cout << std::flush;
  convergence_with_hc<Float, OnedimChen<Float>::SIZE>(llh);
}
