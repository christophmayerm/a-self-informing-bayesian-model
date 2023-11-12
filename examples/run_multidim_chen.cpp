#include <chrono>
#include <cmath>
#include <iostream>
#include <span>

#define EB_HMC_PERF_COUNTERS
#define EB_HMC_QUIET_FITTING
#include "EB.hpp"

#include "LikelihoodFunctions/MultidimChen.hpp"

using namespace std::string_literals;

#if 1

template <typename Float, typename Func, int SIZE>
void run_without_hypercubes(const Func& func,
                            const EB::Hypercube<Float, SIZE>& boundaries,
                            size_t burn_in,
                            size_t num_steps) noexcept {
  EB_INFO("Run HMC without preprocessing");

  const auto prior =
      EB::make_prior(EB::Distribution::RT::Cutoff(boundaries[0].min, boundaries[0].max),
                     EB::Distribution::RT::Cutoff(boundaries[1].min, boundaries[1].max),
                     EB::Distribution::RT::Cutoff(boundaries[2].min, boundaries[2].max));
  EB::HMC<Float, SIZE, decltype(func), decltype(prior)> hmc(func, prior);

  EB::HMCOptions<Float, SIZE> opts{
      .burn_in   = burn_in,
      .num_steps = num_steps,
      .max_time  = 0.01,
      .theta0 =
          {
              (boundaries[0].max + boundaries[0].min) / 2.0,
              (boundaries[1].max + boundaries[1].min) / 2.0,
              (boundaries[2].max + boundaries[2].min) / 2.0,
          },
  };

  const auto t_begin = std::chrono::high_resolution_clock::now();
  hmc.fit_parameters(opts);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("HMC without hypercubes took " << t_dur.count() << 's');
  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);

  EB::HMCPerfCounters::num_param_accept = 0ul;
  EB::HMCPerfCounters::num_param_reject = 0ul;
  EB::HMCPerfCounters::num_path_failure = 0ul;

  const std::string filename = "multidim_chen_no_hc.txt"s;
  hmc.dump_chains(filename);
}

template <typename Float, typename Func, int SIZE>
void run_with_hypercubes(const Func& func,
                         size_t num_iterations,
                         Float learning_rate,
                         Float tol,
                         size_t max_iter,
                         const EB::Hypercube<Float, SIZE>& boundaries,
                         size_t burn_in,
                         size_t num_steps) noexcept {
  EB_INFO("Run HMC with preprocessing");
  auto t_begin      = std::chrono::high_resolution_clock::now();
  const auto maxima = EB::optimistic_search<Float, decltype(func), SIZE, true>(
      func, num_iterations, learning_rate, boundaries, tol, max_iter);
  auto t_dur = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("Optimistic search took " << t_dur.count() << "s");
  EB_INFO("Found " << maxima.size() << " maxima");
  // for (const auto& maximum : maxima) {
  //   std::cout << maximum.theta.transpose() << '\n';
  // }

  const std::vector<EB::Hypercube<Float, SIZE>> hypercubes = EB::get_hypercubes(maxima, boundaries);
  EB_INFO("Found " << hypercubes.size() << " hypercubes");

  const std::vector<EB::Hypercube<Float, SIZE>> merged_hypercubes =
      EB::merge_hypercubes(hypercubes);
  EB_INFO("Found " << merged_hypercubes.size() << " merged hypercubes");
  // for (const auto& hc : merged_hypercubes) {
  //   std::cout << hc << '\n';
  // }

  t_begin = std::chrono::high_resolution_clock::now();
#pragma omp parallel for
  for (size_t hc_num = 0ul; hc_num < merged_hypercubes.size(); ++hc_num) {
    const auto& hc   = merged_hypercubes[hc_num];
    const auto prior = EB::make_prior(EB::Distribution::RT::Cutoff(hc[0].min, hc[0].max),
                                      EB::Distribution::RT::Cutoff(hc[1].min, hc[1].max),
                                      EB::Distribution::RT::Cutoff(hc[2].min, hc[2].max));
    EB::HMC<Float, SIZE, decltype(func), decltype(prior)> hmc(func, prior);

    EB::HMCOptions<Float, SIZE> opts{
        .burn_in   = burn_in,
        .num_steps = num_steps,
        .max_time  = 0.01,
        .theta0 =
            {
                (hc[0].max + hc[0].min) / 2.0,
                (hc[1].max + hc[1].min) / 2.0,
                (hc[2].max + hc[2].min) / 2.0,
            },
    };

    hmc.fit_parameters(opts);

    const std::string filename = "multidim_chen_hc_"s + std::to_string(hc_num) + ".txt"s;
    hmc.dump_chains(filename);
  }
  t_dur = std::chrono::high_resolution_clock::now() - t_begin;
  EB_INFO("HMC with hypercubes took " << t_dur.count() << 's');
  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);

  EB::HMCPerfCounters::num_param_accept = 0ul;
  EB::HMCPerfCounters::num_param_reject = 0ul;
  EB::HMCPerfCounters::num_path_failure = 0ul;
}

auto main(int argc, char** argv) -> int {
  using Float                  = double;
  constexpr int DIM            = 5;
  constexpr size_t num_samples = 10'000;

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

  EB_INFO("DIM = " << DIM);
  EB_INFO("num_samples = " << num_samples);

  const size_t num_iterations = parse_size_t(args[1]);
  const double learning_rate  = parse_double(args[2]);
  const double tol            = parse_double(args[3]);
  const size_t max_iter       = parse_size_t(args[4]);
  const size_t burn_in        = parse_size_t(args[5]);
  const size_t num_steps      = parse_size_t(args[6]);

  const MultidimChen<Float, DIM> llh(num_samples);
  constexpr auto SIZE = decltype(llh)::SIZE - 1;

  constexpr EB::Hypercube<Float, SIZE> boundaries{
      EB::Interval<Float>{0.0, 1.0},
      EB::Interval<Float>{0.0, 5.0},
      EB::Interval<Float>{0.001, 0.5},
  };

  auto func = [llh = std::move(llh)]<typename AT>(const Eigen::Vector<AT, SIZE>& theta) {
    // theta = [rho, mu, lambda, beta]
    Eigen::Vector<AT, decltype(llh)::SIZE> theta_ext;
    theta_ext(0) = theta(0);
    theta_ext(1) = theta(1);
    theta_ext(2) = theta(2);
    theta_ext(3) = llh.beta();
    return llh(theta_ext);
  };

  std::cout << "\n------------------------------------------------------------\n\n";
  run_without_hypercubes<Float, decltype(func), SIZE>(func, boundaries, burn_in, num_steps);
  std::cout << "\n------------------------------------------------------------\n\n";
  run_with_hypercubes<Float, decltype(func), SIZE>(
      func, num_iterations, learning_rate, tol, max_iter, boundaries, burn_in, num_steps);
}

#else

auto main() -> int {
  using Float                  = double;
  constexpr int DIM            = 5;
  constexpr size_t num_samples = 10'000;

  EB_INFO("DIM = " << DIM);
  EB_INFO("num_samples = " << num_samples);

  MultidimChen<Float, DIM> llh(num_samples);
  constexpr auto SIZE = decltype(llh)::SIZE - 1;

  auto func = [llh = std::move(llh)]<typename AT>(const Eigen::Vector<AT, SIZE>& theta) {
    // theta = [rho, mu, lambda, beta]
    Eigen::Vector<AT, decltype(llh)::SIZE> theta_ext;
    theta_ext(0) = theta(0);
    theta_ext(1) = theta(1);
    theta_ext(2) = theta(2);
    theta_ext(3) = llh.beta();
    return llh(theta_ext);
  };

  constexpr size_t num_runs = 20;
  std::array<Float, num_runs> res{};
  const auto t_begin = std::chrono::high_resolution_clock::now();
  for (auto& resi : res) {
    const Eigen::Vector<Float, SIZE> theta{
        EB::Random::uniform_real<Float>(0.0, 1.0),
        EB::Random::uniform_real<Float>(0.0, 5.0),
        EB::Random::uniform_real<Float>(0.001, 0.2),
    };
    resi = func(theta);
    // std::cout << "llh(" << theta.transpose() << ") = " << y << '\n';
  }
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("Evaluation of the log-likelihood function with "
          << DIM << " dimensions took " << t_dur.count() / static_cast<double>(num_runs)
          << "s on average.");

  EB_INFO("Average value of log-likelihood is "
          << std::reduce(std::cbegin(res), std::cend(res)) / static_cast<Float>(num_runs) << '.');
}

#endif
