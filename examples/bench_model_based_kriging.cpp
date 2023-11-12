#include <chrono>
#include <iostream>
#include <vector>

#include "dco.hpp"

#include "EB.hpp"

// #define MBK_APPROX_LLH
#include "LikelihoodFunctions/ModelBasedKriging.hpp"

constexpr int SIZE = 4;

template <typename Float>
constexpr auto get_theta() -> Eigen::Vector<Float, SIZE> {
  return Eigen::Vector<Float, SIZE>{
      std::min(static_cast<Float>(2),
               std::max(static_cast<Float>(0), EB::Random::normal_real<Float>(0.3, 0.1))),
      std::min(static_cast<Float>(2),
               std::max(static_cast<Float>(-2), EB::Random::normal_real<Float>(-0.1, 0.1))),
      std::min(static_cast<Float>(2),
               std::max(static_cast<Float>(0), EB::Random::normal_real<Float>(0.0025, 0.1))),
      std::min(static_cast<Float>(2),
               std::max(static_cast<Float>(0), EB::Random::normal_real<Float>(0.99, 0.1))),
  };
}

template <typename Float, typename LLH>
[[nodiscard]] auto bench_eval(const LLH& llh,
                              const std::vector<Eigen::Vector<Float, SIZE>>& tests) noexcept
    -> std::vector<Float> {
  std::vector<Float> results(tests.size());

  const auto t_begin = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < tests.size(); ++i) {
    results[i] = llh(tests[i]);
  }
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("Evaluation of log-likelihood took " << t_dur.count() / static_cast<double>(tests.size())
                                               << "s on average (entire run took " << t_dur.count()
                                               << "s)");
  return results;
}

template <typename PT, typename LLH>
[[nodiscard]] auto bench_tanget(const LLH& llh,
                                const std::vector<Eigen::Vector<PT, SIZE>>& tests) noexcept
    -> std::pair<std::vector<PT>, std::vector<Eigen::Vector<PT, SIZE>>> {
  using AT = typename dco::gt1s<PT>::type;

  std::vector<PT> val_results(tests.size());
  std::vector<Eigen::Vector<PT, SIZE>> der_results(tests.size());

  const auto t_begin = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < tests.size(); ++i) {
    auto& val = val_results[i];
    auto& der = der_results[i];
    Eigen::Vector<AT, SIZE> theta;
    std::copy(std::cbegin(tests[i]), std::cend(tests[i]), std::begin(theta));
    AT active_res;
    for (int j = 0; j < SIZE; ++j) {
      dco::derivative(theta(j)) = 1.0;
      active_res                = llh(theta);
      der(j)                    = dco::derivative(active_res);
      dco::derivative(theta(j)) = 0.0;
    }
    val = dco::value(active_res);
  }
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("Tangent derivative of log-likelihood took "
          << t_dur.count() / static_cast<double>(tests.size()) << "s on average (entire run took "
          << t_dur.count() << "s)");

  return std::pair{val_results, der_results};
}

template <typename PT, typename LLH>
[[nodiscard]] auto bench_adjoint(const LLH& llh,
                                 const std::vector<Eigen::Vector<PT, SIZE>>& tests) noexcept
    -> std::pair<std::vector<PT>, std::vector<Eigen::Vector<PT, SIZE>>> {
  using dco_mode = typename dco::ga1s<PT>;
  using AT       = typename dco_mode::type;

  std::vector<PT> val_results(tests.size());
  std::vector<Eigen::Vector<PT, SIZE>> der_results(tests.size());

  const auto t_begin = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < tests.size(); ++i) {
    auto& val = val_results[i];
    auto& der = der_results[i];

    dco::smart_tape_ptr_t<dco_mode> tape{};
    Eigen::Vector<AT, SIZE> theta;
    std::copy(std::cbegin(tests[i]), std::cend(tests[i]), std::begin(theta));
    tape->register_variable(std::cbegin(theta), std::cend(theta));

    AT active_res               = llh(theta);
    dco::derivative(active_res) = 1.0;
    tape->interpret_adjoint();

    val = dco::value(active_res);
    for (int j = 0; j < SIZE; ++j) {
      der(j) = dco::derivative(theta(j));
    }
  }
  const auto t_dur =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
  EB_INFO("Adjoint derivative of log-likelihood took "
          << t_dur.count() / static_cast<double>(tests.size()) << "s on average (entire run took "
          << t_dur.count() << "s)");

  return std::pair{val_results, der_results};
}

auto main(int argc, char** argv) -> int {
  using Float = double;

  if (argc < 2) {
    std::cerr << "Usage: " << *argv << " <num_runs>\n";
    std::exit(1);
  }

  const size_t num_runs = [cstr = argv[1]] {
    try {
      return std::stoul(cstr);
    } catch (const std::exception&) {
      std::cerr << "Could not parse c-string `" << cstr << "` to unsigned long.\n";
      std::exit(1);
    }
  }();

  const auto llh = [] {
    try {
      constexpr auto input_file        = "../data/apt_price_berlin_train.txt";
      constexpr size_t max_num_samples = 512;
      return ModelBasedKrigingLLH<Float>(input_file, max_num_samples);
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      std::exit(1);
    }
  }();
  static_assert(decltype(llh)::SIZE == SIZE);

  std::vector<Eigen::Vector<Float, SIZE>> tests(num_runs);
  std::generate(std::begin(tests), std::end(tests), get_theta<Float>);

  const auto vals                         = bench_eval<Float, decltype(llh)>(llh, tests);
  const auto [tangent_vals, tangent_ders] = bench_tanget<Float, decltype(llh)>(llh, tests);
  const auto [adjoint_vals, adjoint_ders] = bench_adjoint<Float, decltype(llh)>(llh, tests);

  EB_INFO("Tangent values correct: " << std::boolalpha
                                     << std::transform_reduce(std::cbegin(vals),
                                                              std::cend(vals),
                                                              std::cbegin(tangent_vals),
                                                              true,
                                                              std::logical_and<>{},
                                                              [](Float val, Float t_val) {
                                                                return std::abs(val - t_val) <=
                                                                       1e-8;
                                                              }));
  EB_INFO("Adjoint values correct: " << std::boolalpha
                                     << std::transform_reduce(std::cbegin(vals),
                                                              std::cend(vals),
                                                              std::cbegin(adjoint_vals),
                                                              true,
                                                              std::logical_and<>{},
                                                              [](Float val, Float a_val) {
                                                                return std::abs(val - a_val) <=
                                                                       1e-8;
                                                              }));
  EB_INFO(
      "Derivatives equal: " << std::boolalpha
                            << std::transform_reduce(std::cbegin(tangent_ders),
                                                     std::cend(tangent_ders),
                                                     std::cbegin(adjoint_ders),
                                                     true,
                                                     std::logical_and<>{},
                                                     [](const Eigen::Vector<Float, SIZE>& val,
                                                        const Eigen::Vector<Float, SIZE>& a_val) {
                                                       return (val - a_val).norm() <= 1e-8;
                                                     }));
}
