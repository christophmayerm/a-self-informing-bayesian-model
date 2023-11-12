#include <chrono>
#include <iostream>
#include <utility>
#include <vector>

#include "AdamGradientAscent.hpp"
#include "Distributions.hpp"
#include "OptimisticSearch.hpp"
#include "Prior.hpp"
#include "RandomValue.hpp"

#include "LikelihoodFunctions/LVLogLikelihood.hpp"

// #define USE_UNINFORMED_PRIOR

using Float = double;

// - Target function -------------------------------------------------------------------------------
static const std::vector<Float> g_ts{1900.0, 1901.0, 1902.0, 1903.0, 1904.0, 1905.0, 1906.0,
                                     1907.0, 1908.0, 1909.0, 1910.0, 1911.0, 1912.0, 1913.0,
                                     1914.0, 1915.0, 1916.0, 1917.0, 1918.0, 1919.0, 1920.0};

static const std::vector<Eigen::Vector<Float, LV::LV_SYSTEM_SIZE>> g_xs{
    {30.0, 4.0},  {47.2, 6.1},  {70.2, 9.8},  {77.4, 35.2}, {36.3, 59.4}, {20.6, 41.7},
    {18.1, 19.0}, {21.4, 13.0}, {22.0, 8.3},  {25.4, 9.1},  {27.1, 7.4},  {40.3, 8.0},
    {57.0, 12.3}, {76.6, 19.5}, {52.3, 45.7}, {19.5, 51.1}, {11.2, 29.7}, {7.6, 15.8},
    {14.6, 9.7},  {16.2, 10.1}, {24.7, 8.6}};

constexpr size_t g_step_factor = 5ul;

template <typename PT>
class Posterior {
  LV::LVLogLikelihood<PT> llh{g_ts, g_xs, g_step_factor};
#ifdef USE_UNINFORMED_PRIOR
  EB::Prior<EB::Distribution::CT::Uniform<0.0, 100.0>,
            EB::Distribution::CT::Uniform<0.0, 100.0>,
            EB::Distribution::CT::Uniform<0.0, 100.0>,
            EB::Distribution::CT::Uniform<0.0, 100.0>,
            EB::Distribution::CT::Uniform<0.0, 100.0>,
            EB::Distribution::CT::Uniform<0.0, 100.0>,
            EB::Distribution::CT::HalfNormal<5.0>>
      prior;
#else
  EB::Prior<decltype(EB::Distribution::CT::Normal<0.48, 0.1>{} *
                     EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{}),
            decltype(EB::Distribution::CT::Normal<0.02, 0.01>{} *
                     EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{}),
            decltype(EB::Distribution::CT::Normal<0.93, 0.1>{} *
                     EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{}),
            decltype(EB::Distribution::CT::Normal<0.03, 0.01>{} *
                     EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{}),
            decltype(EB::Distribution::CT::Normal<34.91, 1.0>{} *
                     EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{}),
            decltype(EB::Distribution::CT::Normal<3.86, 1.0>{} *
                     EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{}),
            EB::Distribution::CT::HalfNormal<1.0>>
      prior = EB::make_prior(
          EB::Distribution::CT::Normal<0.48, 0.1>{} *
              EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{},
          EB::Distribution::CT::Normal<0.02, 0.01>{} *
              EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{},
          EB::Distribution::CT::Normal<0.93, 0.1>{} *
              EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{},
          EB::Distribution::CT::Normal<0.03, 0.01>{} *
              EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{},
          EB::Distribution::CT::Normal<34.91, 1.0>{} *
              EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{},
          EB::Distribution::CT::Normal<3.86, 1.0>{} *
              EB::Distribution::CT::Cutoff<0.0, std::numeric_limits<double>::infinity()>{},
          EB::Distribution::CT::HalfNormal<1.0>{});
#endif  // USE_UNINFORMED_PRIOR

 public:
  template <typename T>
  using ThetaVector = Eigen::Vector<T, LV::LLH_SIZE>;

  template <typename AT>
  [[nodiscard]] constexpr auto operator()(const ThetaVector<AT>& theta) const noexcept -> AT {
    return llh.eval(theta) + prior.log_pdf(theta);
  }
};

// - Main ------------------------------------------------------------------------------------------
auto main(int argc, char** argv) -> int {
  if (argc < 5) {
    std::cerr << "Usage: " << *argv << " <num_iterations> <learning_rate> <tol> <max_iter>\n";
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

  const auto num_iterations = parse_size_t(*(++argv));
  const auto learning_rate  = parse_double(*(++argv));
  const auto tol            = parse_double(*(++argv));
  const auto max_iter       = parse_size_t(*(++argv));

  EB_INFO("num_iterations = " << num_iterations);
  EB_INFO("learning_rate  = " << learning_rate);
  EB_INFO("tol            = " << tol);
  EB_INFO("max_iter       = " << max_iter);

  const EB::Hypercube<Float, LV::LLH_SIZE> boundaries{
      EB::Interval{0.0, 0.98},
      EB::Interval{0.0, 0.07},
      EB::Interval{0.43, 1.43},
      EB::Interval{0.0, 0.08},
      EB::Interval{29.91, 39.91},
      EB::Interval{0.0, 8.86},
      EB::Interval{0.0, 50.0},
  };

  const auto t_begin = std::chrono::high_resolution_clock::now();
  const auto maxima  = EB::optimistic_search<Float, Posterior<Float>, LV::LLH_SIZE>(
      Posterior<Float>{}, num_iterations, learning_rate, boundaries, tol, max_iter);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("Calculation took " << t_dur.count() << 's');
  EB_INFO("Found " << maxima.size() << " maxima");

  if (maxima.size() < 10) {
    std::cout << "maxima: \n";
    for (size_t i = 0; i < maxima.size(); ++i) {
      const auto& m = maxima[i];
      std::cout << "Maximum " << i << '\n';

      std::cout << "  theta = [";
      for (auto e : m.theta) {
        std::cout << e << ", ";
      }
      std::cout << "]\n";

      std::cout << "  func_value = " << m.func_value << '\n';

      std::cout << "  grad = [";
      for (auto e : m.gradient) {
        std::cout << e << ", ";
      }
      std::cout << "]\n";

      std::cout << "----------------------------------------\n";
    }
  }

  const std::vector<EB::Hypercube<Float, LV::LLH_SIZE>> hypercubes =
      EB::get_hypercubes(maxima, boundaries);
  EB_INFO("Found " << hypercubes.size() << " hypercubes");

  if (hypercubes.size() < 10) {
    std::cout << "hypercubes: \n";
    for (const auto& hc : hypercubes) {
      std::cout << hc << ",\n\n";
    }
  }

  const std::vector<EB::Hypercube<Float, LV::LLH_SIZE>> merged_hypercubes =
      EB::merge_hypercubes(hypercubes);
  EB_INFO("Found " << merged_hypercubes.size() << " merged hypercubes");
  std::cout << "merged hypercubes: \n";
  for (const auto& hc : merged_hypercubes) {
    std::cout << hc << ",\n\n";
  }
}
