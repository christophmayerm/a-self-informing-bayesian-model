#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#define EB_RAND_SEED 42
#include "AdamGradientAscent.hpp"
#include "OptimisticSearch.hpp"

#include "LikelihoodFunctions/OnedimChen.hpp"

constexpr size_t DATA_SIZE = 1000;

// #include "Distributions.hpp"
// #include "Prior.hpp"

// - Find hypercubes around maxima of log-likelihood function --------------------------------------
template <typename Float>
constexpr void find_hypercubes(size_t num_iterations,
                               Float learning_rate,
                               Float tol,
                               size_t max_iter,
                               const std::string& maxima_file,
                               const std::string& hypercubes_file,
                               const std::string& merged_hypercubes_file) noexcept {
  const auto t_begin = std::chrono::high_resolution_clock::now();
  const auto maxima  = EB::optimistic_search<Float, OnedimChen<Float>, OnedimChen<Float>::SIZE>(
      OnedimChen<Float>(DATA_SIZE),
      num_iterations,
      learning_rate,
      OnedimChen<Float>::boundaries,
      tol,
      max_iter);
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("Calculation took " << t_dur.count() << 's');
  EB_INFO("Found " << maxima.size() << " maxima");

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

  const std::vector<EB::Hypercube<Float, OnedimChen<Float>::SIZE>> hypercubes =
      EB::get_hypercubes(maxima, OnedimChen<Float>::boundaries);
  EB_INFO("Found " << hypercubes.size() << " hypercubes");

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

  Float hc_volume = 0.0;
  for (const auto& hc : hypercubes) {
    hc_volume += EB::hypercube_volume(hc);
  }
  EB_INFO("Hypercube volume (including overlap) = " << hc_volume);
  EB_INFO("Boundary volume = " << EB::hypercube_volume(OnedimChen<Float>::boundaries));

  const std::vector<EB::Hypercube<Float, OnedimChen<Float>::SIZE>> merged_hypercubes =
      EB::merge_hypercubes(hypercubes);
  EB_INFO("Found " << merged_hypercubes.size() << " merged hypercubes");

  std::ofstream merged_hypercubes_out(merged_hypercubes_file);
  if (!merged_hypercubes_out) {
    EB_PANIC("Could not open `" << merged_hypercubes_file << "`: " << std::strerror(errno));
  }

  for (const auto& hc : merged_hypercubes) {
    merged_hypercubes_out << "{\n";
    for (auto [min, max] : hc) {
      merged_hypercubes_out << '{' << min << ", " << max << "}\n";
    }
    merged_hypercubes_out << "},\n\n";
  }
  EB_INFO("Wrote merged hypercubes to " << merged_hypercubes_file);

  Float merged_hc_volume = 0.0;
  for (const auto& hc : merged_hypercubes) {
    merged_hc_volume += EB::hypercube_volume(hc);
  }
  EB_INFO("Merged hypercube volume = " << merged_hc_volume);
}

// -------------------------------------------------------------------------------------------------
template <typename Float>
constexpr void find_contour(size_t res,
                            const std::string& x_file,
                            const std::string& y_file,
                            const std::string& z_file) noexcept {
  OnedimChen<Float> func(DATA_SIZE);

  std::ofstream x_out(x_file);
  if (!x_out) {
    EB_PANIC("Could not open `" << x_file << "`: " << std::strerror(errno));
  }

  std::ofstream y_out(y_file);
  if (!y_out) {
    EB_PANIC("Could not open `" << y_file << "`: " << std::strerror(errno));
  }

  std::ofstream z_out(z_file);
  if (!z_out) {
    EB_PANIC("Could not open `" << z_file << "`: " << std::strerror(errno));
  }

  const auto t_begin = std::chrono::high_resolution_clock::now();
  assert(res > 0);
  const Float x_step =
      (OnedimChen<Float>::boundaries[1].max - OnedimChen<Float>::boundaries[1].min) /
      static_cast<Float>(res);
  const Float y_step =
      (OnedimChen<Float>::boundaries[0].max - OnedimChen<Float>::boundaries[0].min) /
      static_cast<Float>(res);

  for (Float x = OnedimChen<Float>::boundaries[1].min; x <= OnedimChen<Float>::boundaries[1].max;
       x += x_step) {
    for (Float y = OnedimChen<Float>::boundaries[0].min; y <= OnedimChen<Float>::boundaries[0].max;
         y += y_step) {
      const Eigen::Vector<Float, OnedimChen<Float>::SIZE> theta = {y, x};
      x_out << x << ' ';
      y_out << y << ' ';
      z_out << func(theta) << ' ';
    }
    x_out << '\n';
    y_out << '\n';
    z_out << '\n';
  }
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);

  EB_INFO("Wrote x data to `" << x_file << "`.");
  EB_INFO("Wrote y data to `" << y_file << "`.");
  EB_INFO("Wrote z data to `" << z_file << "`.");
  EB_INFO("Calculation took " << t_dur.count() << 's');
}

// - Main ------------------------------------------------------------------------------------------
auto main(int argc, char** argv) -> int {
  using namespace std::string_literals;

  using Float = double;

  if (argc < 6) {
    std::cerr << "Usage: " << *argv
              << " <num_iterations> <learning_rate> <tol> <max_iter> <resolution>\n";
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
  const auto res            = parse_size_t(*(++argv));

  EB_INFO("num_iterations = " << num_iterations);
  EB_INFO("learning_rate  = " << learning_rate);
  EB_INFO("tol            = " << tol);
  EB_INFO("max_iter       = " << max_iter);
  EB_INFO("res            = " << res);

  if (res > 0ul) {
    const std::string x_file = "model2_x_"s + std::to_string(res) + ".txt"s;
    const std::string y_file = "model2_y_"s + std::to_string(res) + ".txt"s;
    const std::string z_file = "model2_z_"s + std::to_string(res) + ".txt"s;
    find_contour<Float>(res, x_file, y_file, z_file);
  } else {
    EB_INFO("Don't calculate contour data because res = 0.");
  }

  const std::string maxima_file = "model2_maxima_"s + std::to_string(num_iterations) + ".txt"s;
  const std::string hypercubes_file =
      "model2_hypercubes_"s + std::to_string(num_iterations) + ".txt"s;
  const std::string merged_hypercubes_file =
      "model2_merged_hypercubes_"s + std::to_string(num_iterations) + ".txt"s;
  find_hypercubes(num_iterations,
                  learning_rate,
                  tol,
                  max_iter,
                  maxima_file,
                  hypercubes_file,
                  merged_hypercubes_file);
}
