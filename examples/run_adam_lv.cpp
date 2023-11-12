#include <chrono>
#include <iostream>

#include <Eigen/Dense>

#include <dco.hpp>

#define EB_AGA_SAVE_ITERATIONS_TO "ga_iterations.txt"
#include "AdamGradientAscent.hpp"
#include "Distributions.hpp"
#include "Macros.hpp"
#include "Prior.hpp"

#include "LikelihoodFunctions/LVLogLikelihood.hpp"

using Float = double;

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

 public:
  template <typename T>
  using ThetaVector = Eigen::Vector<T, LV::LLH_SIZE>;

  template <typename AT>
  [[nodiscard]] constexpr auto operator()(const ThetaVector<AT>& theta) const noexcept -> AT {
    return llh.eval(theta) + prior.log_pdf(theta);
  }
};

auto main(int argc, char** argv) -> int {
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0] << " <learning rate> <tolerance> <max. number iterations>\n";
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

  const auto learning_rate = parse_double(argv[1]);
  const auto tol           = parse_double(argv[2]);
  const auto max_iter      = parse_size_t(argv[3]);

  EB_INFO("learning_rate  = " << learning_rate);
  EB_INFO("tol            = " << tol);
  EB_INFO("max_iter       = " << max_iter);

  EB::AdamGradientAscent<Posterior<Float>, LV::LLH_SIZE> ga(Posterior<Float>{});

  EB::Hypercube<Float, LV::LLH_SIZE> boundaries{
      EB::Interval<Float>{0.0, 0.98},
      EB::Interval<Float>{0.0, 0.07},
      EB::Interval<Float>{0.43, 1.43},
      EB::Interval<Float>{0.0, 0.08},
      EB::Interval<Float>{29.91, 39.91},
      EB::Interval<Float>{0.0, 8.86},
      EB::Interval<Float>{0.0, 50.0},
  };

  Eigen::Vector<Float, LV::LLH_SIZE> theta = {0.5, 0.04, 0.9, 0.05, 35.0, 4.0, 1.0};
  // {0.48, 0.02, 0.93, 0.03, 34.91, 3.86, 10.0};
  EB_INFO("theta0         = " << theta.transpose());

  Float function_value;
  Eigen::Vector<Float, LV::LLH_SIZE> gradient;

  const auto t_begin = std::chrono::high_resolution_clock::now();
  const auto success =
      ga.calc(theta, learning_rate, function_value, gradient, boundaries, tol, max_iter);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("success        = " << std::boolalpha << success);
  EB_INFO("theta          = " << theta.transpose());
  EB_INFO("function_value = " << function_value);
  EB_INFO("gradient       = " << gradient.transpose());
  EB_INFO("||gradient||   = " << gradient.norm());
  EB_INFO("Calculation took " << t_dur.count() << 's');
}
