#include <chrono>
#include <iostream>

#define EB_HMC_PERF_COUNTERS
#define EB_NO_COMPILETIME_DISTRIBUTIONS
#include "Distributions.hpp"
#include "HMCSampler.hpp"
#include "Prior.hpp"

#include "LikelihoodFunctions/LVLogLikelihood.hpp"

template <typename PT>
class LLH {
  LV::LVLogLikelihood<PT> llh;

 public:
  constexpr LLH(const std::vector<PT>& ts,
                const std::vector<Eigen::Vector<PT, LV::LV_SYSTEM_SIZE>>& xs,
                size_t step_factor)
      : llh(LV::LVLogLikelihood<PT>(ts, xs, step_factor)) {}

  template <typename AT>
  [[nodiscard]] constexpr auto
  operator()(const Eigen::Vector<AT, LV::LLH_SIZE>& theta) const noexcept -> AT {
    return llh.eval(theta);
  }
};

auto main() -> int {
  using Float = double;

  const std::vector<Float> ts{1900.0, 1901.0, 1902.0, 1903.0, 1904.0, 1905.0, 1906.0,
                              1907.0, 1908.0, 1909.0, 1910.0, 1911.0, 1912.0, 1913.0,
                              1914.0, 1915.0, 1916.0, 1917.0, 1918.0, 1919.0, 1920.0};

  const std::vector<Eigen::Vector<Float, LV::LV_SYSTEM_SIZE>> xs{
      {30.0, 4.0},  {47.2, 6.1},  {70.2, 9.8},  {77.4, 35.2}, {36.3, 59.4}, {20.6, 41.7},
      {18.1, 19.0}, {21.4, 13.0}, {22.0, 8.3},  {25.4, 9.1},  {27.1, 7.4},  {40.3, 8.0},
      {57.0, 12.3}, {76.6, 19.5}, {52.3, 45.7}, {19.5, 51.1}, {11.2, 29.7}, {7.6, 15.8},
      {14.6, 9.7},  {16.2, 10.1}, {24.7, 8.6}};

  constexpr size_t step_factor = 5ul;

  const auto prior =
      EB::make_prior(EB::Distribution::RT::Normal(0.48, 0.1) *
                         EB::Distribution::RT::Cutoff(0.0, std::numeric_limits<double>::infinity()),
                     EB::Distribution::RT::Normal(0.02, 0.01) *
                         EB::Distribution::RT::Cutoff(0.0, std::numeric_limits<double>::infinity()),
                     EB::Distribution::RT::Normal(0.93, 0.1) *
                         EB::Distribution::RT::Cutoff(0.0, std::numeric_limits<double>::infinity()),
                     EB::Distribution::RT::Normal(0.03, 0.01) *
                         EB::Distribution::RT::Cutoff(0.0, std::numeric_limits<double>::infinity()),
                     EB::Distribution::RT::Normal(34.91, 1.0) *
                         EB::Distribution::RT::Cutoff(0.0, std::numeric_limits<double>::infinity()),
                     EB::Distribution::RT::Normal(3.86, 1.0) *
                         EB::Distribution::RT::Cutoff(0.0, std::numeric_limits<double>::infinity()),
                     EB::Distribution::RT::HalfNormal(10.0));

  EB::HMCOptions<Float, LV::LLH_SIZE> opt{
      .burn_in   = 1'000,
      .num_steps = 75'000,
      .max_time  = 0.0025,
      .theta0    = {0.6, 0.08, 0.8, 0.08, 36.0, 5.0, 5.0},
  };
  EB::HMC<Float, LV::LLH_SIZE, LLH<Float>, decltype(prior)> hmc(LLH<Float>(ts, xs, step_factor),
                                                                prior);

  const auto t_begin = std::chrono::high_resolution_clock::now();
  hmc.fit_parameters(opt);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  hmc.chain_postprocessing(std::cout);
  try {
    hmc.dump_chains("lv_chains.txt");
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    std::exit(1);
  }

  {
    std::array theta_expected = {
        0.478991, 0.0247188, 0.930701, 0.0276712, 34.9335, 3.84048, 13.0939};
    static_assert(theta_expected.size() == LV::LLH_SIZE);
    for (size_t i = 0; i < theta_expected.size(); ++i) {
      EB_INFO("Expected value theta" << i << ": " << theta_expected[i]);
    }
  }

  EB_INFO("Calculation took " << t_dur.count() << 's');
  EB_INFO("num_param_accept = " << EB::HMCPerfCounters::num_param_accept);
  EB_INFO("num_param_reject = " << EB::HMCPerfCounters::num_param_reject);
  EB_INFO("num_path_failure = " << EB::HMCPerfCounters::num_path_failure);
}
