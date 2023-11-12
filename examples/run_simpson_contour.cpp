#include <fstream>
#include <iostream>
#include <vector>

#include "Hypercube.hpp"

#define LR_LLH_USE_NEIGHBOURHOOD
// #define LR_LLH_USE_MULT_UNINORMAL
#include "LikelihoodFunctions/LinearRegressionLLH.hpp"

template <typename Float>
void dump_matrix(const std::vector<std::vector<Float>>& mat, const std::string& filename) noexcept {
  std::ofstream out(filename);
  if (!out) {
    EB_PANIC("Could not open file `" << filename << "` for writing: " << std::strerror(errno));
  }

  for (const auto& row : mat) {
    for (const auto& entry : row) {
      out << entry << ' ';
    }
    out << '\n';
  }
}

auto main(int argc, char** argv) -> int {
  using Float = double;

  if (argc < 2) {
    std::cerr << "Usage: " << *argv << " <res>\n";
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

  const auto res = [cstr = *(++argv)]() {
    try {
      return std::stoull(cstr);
    } catch (const std::exception&) {
      std::cerr << "Could not parse string `" << cstr << "` to unsigned long long.\n";
      std::exit(1);
    }
  }();
  if (res < 2) {
    EB_PANIC("Resolution has to be >= 2, is " << res);
  }
  EB_INFO("res = " << res);

  EB::Hypercube<Float, SIZE> boundaries{
      EB::Interval<Float>{-1.5, 1.5},
      EB::Interval<Float>{0.0, 55.0},
  };

  const auto theta0_step = (boundaries[0].max - boundaries[0].min) / static_cast<Float>(res - 1ul);
  const auto theta1_step = (boundaries[1].max - boundaries[1].min) / static_cast<Float>(res - 1ul);

  std::vector<std::vector<Float>> X(res, std::vector<Float>(res));
  std::vector<std::vector<Float>> Y(res, std::vector<Float>(res));
  std::vector<std::vector<Float>> Z(res, std::vector<Float>(res));

#pragma omp parallel for
  for (size_t i0 = 0ul; i0 < res; ++i0) {
    for (size_t i1 = 0ul; i1 < res; ++i1) {
      const Eigen::Vector<Float, SIZE> theta{
          boundaries[0].min + static_cast<Float>(i0) * theta0_step,
          boundaries[1].min + static_cast<Float>(i1) * theta1_step,
      };

      X[i0][i1] = theta(0);
      Y[i0][i1] = theta(1);
      Z[i0][i1] = llh(theta);
    }
  }

  dump_matrix(X, "simpson_contour_x.txt");
  dump_matrix(Y, "simpson_contour_y.txt");
  dump_matrix(Z, "simpson_contour_z.txt");
}
