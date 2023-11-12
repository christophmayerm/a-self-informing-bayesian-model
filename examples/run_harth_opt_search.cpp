#include <cassert>
#include <chrono>
#include <iostream>

#include <Eigen/Dense>

#include "OptimisticSearch.hpp"

#define CLUSTERING_INPUT_FILE "../benchmarks/data/harth_4d_dataset_1000.csv"
#include "LikelihoodFunctions/ClusteringLLH.hpp"

// -------------------------------------------------------------------------------------------------
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

// -------------------------------------------------------------------------------------------------
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

// -------------------------------------------------------------------------------------------------
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
      hypercubes_out << '{' << min << ", " << max << "}\n";
    }
    hypercubes_out << "},\n\n";
  }
  EB_INFO("Wrote hypercubes to " << hypercubes_file);
}

// - Main ------------------------------------------------------------------------------------------
auto main(int argc, char** argv) -> int {
  // - Setup -------------------------------------------------------------------
  constexpr int DIM          = 4;  // 6
  constexpr int NUM_CLUSTERS = 5;  // 12
  constexpr int SIZE         = DIM * NUM_CLUSTERS;

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

  const auto boundaries = get_boundaries<double, DIM, NUM_CLUSTERS>();
  // - Setup -------------------------------------------------------------------

  // - Find maxima with optimistic search --------------------------------------
  const auto t_begin = std::chrono::high_resolution_clock::now();
  auto maxima        = EB::optimistic_search<double,
                                      ClusteringLLH<double, DIM, NUM_CLUSTERS>,
                                      SIZE,
                                      false,
                                      EB::GAGradientMethod::TANGENT>(
      ClusteringLLH<double, DIM, NUM_CLUSTERS>{},
      num_iterations,
      learning_rate,
      boundaries,
      tol,
      max_iter);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("Found " << maxima.size() << " maxima");
  EB_INFO("Calculation took " << t_dur.count() << "s");

  constexpr auto maxima_file = "harth_maxima.txt";
  write_maxima(maxima_file, maxima);
  // - Find maxima with optimistic search --------------------------------------

  // - Find hypercubes around maxima -------------------------------------------
  const std::vector<EB::Hypercube<double, SIZE>> hypercubes =
      EB::get_hypercubes(maxima, boundaries);
  EB_INFO("Found " << hypercubes.size() << " hypercubes");

  constexpr auto hypercubes_file = "harth_hypercubes.txt";
  write_hypercubes(hypercubes_file, hypercubes);
  // - Find hypercubes around maxima -------------------------------------------

  // - Merge hypercubes --------------------------------------------------------
  const std::vector<EB::Hypercube<double, SIZE>> merged_hypercubes =
      EB::merge_hypercubes(hypercubes);
  EB_INFO("Found " << merged_hypercubes.size() << " merged hypercubes");

  constexpr auto merged_hypercubes_file = "harth_merged_hypercubes.txt";
  write_hypercubes(merged_hypercubes_file, hypercubes);
  // - Merge hypercubes --------------------------------------------------------
}
