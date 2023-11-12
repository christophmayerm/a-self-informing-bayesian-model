#include <iostream>

#include <dco.hpp>

#include "AdamGradientAscent.hpp"
#include "OptimisticSearch.hpp"

#define LR_LLH_USE_NEIGHBOURHOOD
// #define LR_LLH_USE_MULT_UNINORMAL
#include "LikelihoodFunctions/LinearRegressionLLH.hpp"

#if 1

// ---------------—---------------—---------------—---------------—---------------—---------------—-
template <typename Float, int SIZE>
void write_maxima(const std::string& maxima_file,
                  const std::vector<EB::Maximum<Float, SIZE>>& maxima) noexcept {
  std::ofstream maxima_out(maxima_file);
  if (!maxima_out) {
    EB_PANIC("Could not open `" << maxima_file << "`: " << std::strerror(errno));
  }

  for (size_t i = 0; i < maxima.size(); ++i) {
    const auto& m = maxima[i];
    maxima_out << "Maximum " << i << '\n';

    maxima_out << "  theta = [";
    for (auto e : m.theta) {
      maxima_out << e << ", ";
    }
    maxima_out << "]\n";

    maxima_out << "  func_value = " << m.func_value << '\n';

    maxima_out << "  grad = [";
    for (auto e : m.gradient) {
      maxima_out << e << ", ";
    }
    maxima_out << "]\n\n";
  }
  EB_INFO("Wrote maxima to " << maxima_file);
}

// ---------------—---------------—---------------—---------------—---------------—---------------—-
template <typename Float, int SIZE>
void write_hypercubes(const std::string& hypercubes_file,
                      const std::vector<EB::Hypercube<Float, SIZE>>& hypercubes) noexcept {
  std::ofstream hypercubes_out(hypercubes_file);
  if (!hypercubes_out) {
    EB_PANIC("Could not open `" << hypercubes_file << "`: " << std::strerror(errno));
  }

  for (const auto& hc : hypercubes) {
    hypercubes_out << "{\n";
    for (auto [min, max] : hc) {
      hypercubes_out << '{' << min << ", " << max << "},\n";
    }
    hypercubes_out << "},\n\n";
  }
  EB_INFO("Wrote hypercubes to " << hypercubes_file);
}

// ---------------—---------------—---------------—---------------—---------------—---------------—-
auto main(int argc, char** argv) -> int {
  using Float = double;

  if (argc < 5) {
    std::cerr << "Usage: " << *argv << " <num_iterations> <learning_rate> <tol> <max_iter>\n";
    std::exit(1);
  }

  const std::string input_file    = "../benchmarks/data/simpson/test_data.txt";
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

  EB::Hypercube<Float, SIZE> boundaries{
      EB::Interval<Float>{-1.5, 1.5},
      EB::Interval<Float>{0.0, 55.0},
  };

  const auto maxima = EB::optimistic_search<Float, decltype(llh), SIZE>(
      llh, num_iterations, learning_rate, boundaries, tol, max_iter);
  EB_INFO("Found " << maxima.size() << " maxima");
  write_maxima("simpson_maxima.txt", maxima);

  const std::vector<EB::Hypercube<Float, SIZE>> hypercubes =
      EB::get_hypercubes(maxima, boundaries, 0.1);
  EB_INFO("Found " << hypercubes.size() << " hypercubes");
  write_hypercubes("simpson_hypercubes.txt", hypercubes);

  const std::vector<EB::Hypercube<Float, SIZE>> merged_hypercubes =
      EB::merge_hypercubes(hypercubes);
  EB_INFO("Found " << merged_hypercubes.size() << " merged hypercubes");
  write_hypercubes("simpson_merged_hypercubes.txt", merged_hypercubes);

  const std::vector<size_t> num_contained_maxima =
      EB::count_contained_maxima(maxima, merged_hypercubes);
  for (size_t i = 0ul; i < num_contained_maxima.size(); ++i) {
    std::cout << "Merged hypercube " << i << ":\n";
    std::cout << "  Contains " << num_contained_maxima[i] << " maxima\n";
    std::cout << "  Volume of " << EB::hypercube_volume(merged_hypercubes[i]) << '\n';
    std::cout << "  Desity of "
              << static_cast<Float>(num_contained_maxima[i]) /
                     EB::hypercube_volume(merged_hypercubes[i])
              << '\n';
    std::cout << "------------------------------------------------------------\n";
  }
}

#else

auto main() -> int {
  using Float = double;

  const std::string input_file    = "../benchmarks/data/simpson/test_data.txt";
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

  std::array<Eigen::Vector<Float, SIZE>, 6ul> tests = {
      Eigen::Vector<Float, 2>{-1.0131994994102715, 12.10490214219407},
      Eigen::Vector<Float, 2>{-0.9830126283202988, 21.952287862046717},
      Eigen::Vector<Float, 2>{-0.9701539671910838, 32.041331137016655},
      Eigen::Vector<Float, 2>{-1.0563025848476086, 42.05891543712361},
      Eigen::Vector<Float, 2>{-0.9766557206768839, 51.95570631772517},
      Eigen::Vector<Float, 2>{1.38251686140521, 8.220364181451163},
  };

  constexpr EB::Hypercube<Float, SIZE> boundaries{
      EB::Interval<Float>{-1.5, 1.5},
      EB::Interval<Float>{0.0, 52.0},
  };

  constexpr Float learning_rate = 1e-2;
  constexpr Float tol           = 1e-8;
  constexpr size_t max_iter     = 25'000;

  for (auto theta : tests) {
    Float res = llh(theta);
    std::cout << "llh(" << theta(0) << ", " << theta(1) << ")  = " << res << '\n';

    Float func_value;
    Eigen::Vector<Float, SIZE> gradient;

    EB::AdamGradientAscent<decltype(llh), SIZE> ga(llh);
    const auto success =
        ga.calc(theta, learning_rate, func_value, gradient, boundaries, tol, max_iter);

    std::cout << "Successfully found maximum: " << std::boolalpha << success << '\n';
    std::cout << "Nearest maximum: [" << theta(0) << ", " << theta(1) << "]\n";
    std::cout << "llh(" << theta(0) << ", " << theta(1) << ")  = " << func_value << '\n';
    std::cout << "llh'(" << theta(0) << ", " << theta(1) << ")  = [" << gradient(0) << ", "
              << gradient(1) << "]\n";
    std::cout << "--------------------------------------------------\n";
  }
}

#endif
