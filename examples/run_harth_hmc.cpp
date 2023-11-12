#include <iostream>

#define EB_HMC_QUIET_FITTING
#define EB_HMC_PERF_COUNTERS
#define CLUSTERING_INPUT_FILE "../benchmarks/data/harth_4d_dataset_1000.csv"
#include "Distributions.hpp"
#include "HMCSampler.hpp"
#include "Hypercube.hpp"
#include "Prior.hpp"

#include "LikelihoodFunctions/ClusteringLLH.hpp"

#if 1

// TODO: Reduce DIM to 4 (PCA on data) and N_CLUSTER to 5
auto main() -> int {
  using Float             = double;
  constexpr int DIM       = 4;  // 6
  constexpr int N_CLUSTER = 5;  // 12
  constexpr int SIZE      = DIM * N_CLUSTER;

  const auto prior = EB::make_prior(EB::Distribution::CT::Cutoff<-2.20176, 3.21971>{},
                                    EB::Distribution::CT::Cutoff<-2.36482, 3.97441>{},
                                    EB::Distribution::CT::Cutoff<-1.6871, 2.80791>{},
                                    EB::Distribution::CT::Cutoff<-1.10667, 1.86762>{},
                                    EB::Distribution::CT::Cutoff<-2.20176, 3.21971>{},
                                    EB::Distribution::CT::Cutoff<-2.36482, 3.97441>{},
                                    EB::Distribution::CT::Cutoff<-1.6871, 2.80791>{},
                                    EB::Distribution::CT::Cutoff<-1.10667, 1.86762>{},
                                    EB::Distribution::CT::Cutoff<-2.20176, 3.21971>{},
                                    EB::Distribution::CT::Cutoff<-2.36482, 3.97441>{},
                                    EB::Distribution::CT::Cutoff<-1.6871, 2.80791>{},
                                    EB::Distribution::CT::Cutoff<-1.10667, 1.86762>{},
                                    EB::Distribution::CT::Cutoff<-2.20176, 3.21971>{},
                                    EB::Distribution::CT::Cutoff<-2.36482, 3.97441>{},
                                    EB::Distribution::CT::Cutoff<-1.6871, 2.80791>{},
                                    EB::Distribution::CT::Cutoff<-1.10667, 1.86762>{},
                                    EB::Distribution::CT::Cutoff<-2.20176, 3.21971>{},
                                    EB::Distribution::CT::Cutoff<-2.36482, 3.97441>{},
                                    EB::Distribution::CT::Cutoff<-1.6871, 2.80791>{},
                                    EB::Distribution::CT::Cutoff<-1.10667, 1.86762>{});

  EB::HMCOptions<Float, SIZE> opt{.burn_in   = 1'000,
                                  .num_steps = 9'000,
                                  .max_time  = 0.01,
                                  .theta0    = {
                                      -0.1, -0.1, -0.1, 0.1,   //
                                      0.1,  0.1,  0.1,  0.1,   //
                                      -0.3, -0.8, 1.2,  0.5,   //
                                      2.1,  -2.1, 0.6,  -0.8,  //
                                      3.1,  1.6,  -1.1, 1.5,
                                  }};

  EB_INFO("burn_in   = " << opt.burn_in);
  EB_INFO("num_steps = " << opt.num_steps);
  EB_INFO("max_time  = " << opt.max_time);

  const auto t_begin = std::chrono::high_resolution_clock::now();
  EB::HMC<Float, SIZE, ClusteringLLH<Float, DIM, N_CLUSTER>, decltype(prior)> hmc(
      ClusteringLLH<Float, DIM, N_CLUSTER>{}, prior);
  hmc.fit_parameters(opt);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("Calculation took " << t_dur.count() << "s");

  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);

  hmc.chain_postprocessing(std::cout);
  try {
    hmc.dump_chains("harth_chains.txt");
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

#else

template <typename Float, int DIM, int NUM_CLUSTERS>
[[nodiscard]] constexpr auto get_boundaries() noexcept -> EB::Hypercube<Float, DIM * NUM_CLUSTERS> {
  constexpr auto SIZE = DIM * NUM_CLUSTERS;
  EB::Hypercube<Float, SIZE> boundaries;

  const auto mins =
      std::reduce(std::cbegin(ClusteringLLH<Float, DIM, NUM_CLUSTERS>::data),
                  std::cend(ClusteringLLH<Float, DIM, NUM_CLUSTERS>::data),
                  ClusteringLLH<Float, DIM, NUM_CLUSTERS>::data[0],
                  [](const Eigen::Vector<Float, DIM>& a, const Eigen::Vector<Float, DIM>& b) {
                    Eigen::Vector<Float, DIM> r;
                    for (int i = 0; i < DIM; ++i) {
                      r(i) = std::min(a(i), b(i));
                    }
                    return r;
                  });

  const auto maxs =
      std::reduce(std::cbegin(ClusteringLLH<Float, DIM, NUM_CLUSTERS>::data),
                  std::cend(ClusteringLLH<Float, DIM, NUM_CLUSTERS>::data),
                  ClusteringLLH<Float, DIM, NUM_CLUSTERS>::data[0],
                  [](const Eigen::Vector<Float, DIM>& a, const Eigen::Vector<Float, DIM>& b) {
                    Eigen::Vector<Float, DIM> r;
                    for (int i = 0; i < DIM; ++i) {
                      r(i) = std::max(a(i), b(i));
                    }
                    return r;
                  });

  for (int i = 0; i < SIZE; ++i) {
    boundaries[i].min = mins(i % DIM);
    boundaries[i].max = maxs(i % DIM);
  }

  return boundaries;
}

auto main() -> int {
  using Float             = double;
  constexpr int DIM       = 4;  // 6
  constexpr int N_CLUSTER = 5;  // 12

  const auto bounds = get_boundaries<Float, DIM, N_CLUSTER>();

  for (const auto& bound : bounds) {
    std::cout << "EB::Distribution::CT::Cutoff<" << bound.min << ", " << bound.max << ">\n";
  }
}

#endif
/*
  using Prior = EB::Prior<EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>,
                          EB::Distribution::CT::Cutoff<-6.72388, 0.788323>,
                          EB::Distribution::CT::Cutoff<-1.22168, 1.14014>,
                          EB::Distribution::CT::Cutoff<-1.09457, 0.99332>,
                          EB::Distribution::CT::Cutoff<-5.35205, 1.21031>,
                          EB::Distribution::CT::Cutoff<-4.21704, 2.28086>,
                          EB::Distribution::CT::Cutoff<-2.26454, 3.86426>>;

      .theta0 =
          {
              -0.8, -0.4, -0.3, -0.5, -0.2, -0.1,  //
              -0.1, -0.1, -0.1, -0.1, -0.1, -0.1,  //
              -0.0, -0.0, -0.0, 0.2,  0.4,  0.4,   //
              0.7,  -0.6, -0.2, -1.0, 2.0,  3.1,   //
              -4.7, -0.1, 0.3,  -4.5, -1.2, -2.0,  //
              -5.3, -0.5, 0.3,  0.2,  -2.8, -2.2,  //
              -5.2, -0.4, -1.0, 0.5,  -1.5, -1.8,  //
              -4.8, -0.7, -0.8, 1.0,  0.8,  1.5,   //
              -2.6, 0.5,  -0.0, -3.5, 1.5,  0.2,   //
              -2.3, 0.4,  0.3,  -0.6, -2.1, -0.8,  //
              -1.2, 1.0,  0.4,  0.2,  -2.1, -0.8,  //
              -4.5, 0.8,  0.8,  -4.3, 1.8,  0.8,   //
          },
*/