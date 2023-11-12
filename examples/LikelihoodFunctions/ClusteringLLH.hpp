#ifndef HARTH_CLUSTERING_LLH_HPP_
#define HARTH_CLUSTERING_LLH_HPP_

#include <chrono>
#include <numeric>
#include <vector>

#include <Eigen/Dense>

#include "Macros.hpp"
#include "Utility/ReadCSVFile.hpp"

// Data from http://archive.ics.uci.edu/dataset/779/harth
#ifndef CLUSTERING_INPUT_FILE
#define CLUSTERING_INPUT_FILE "../benchmarks/data/harth_dataset_1000.csv"
#else
static_assert(
    std::is_convertible_v<decltype(CLUSTERING_INPUT_FILE), std::string>,
    "`CLUSTERING_INPUT_FILE` has to be convertible to a std::string to qualify as a file name.");
#endif  // CLUSTERING_INPUT_FILE

template <typename PT, int DIM, int NUM_CLUSTERS>
requires(DIM > 0 && NUM_CLUSTERS > 0)
class ClusteringLLH {
 public:
  static std::vector<Eigen::Vector<PT, DIM>> data;

 private:
  template <typename AT>
  [[nodiscard]] constexpr auto sum_ln_multi_normal(const Eigen::Vector<AT, DIM>& mu) const noexcept
      -> AT {
    // Assume Sigma = diag(1 ... 1) => ln(det(Sigma)) = 0
    constexpr auto C = static_cast<PT>(2) * std::numbers::pi_v<PT> * static_cast<PT>(DIM);
    return std::transform_reduce(
               std::cbegin(data),
               std::cend(data),
               static_cast<AT>(0),
               std::plus{},
               [&](const Eigen::Vector<PT, DIM>& s) {
                 using BINOP = Eigen::internal::scalar_difference_op<PT, AT>;
                 if constexpr (Eigen::internal::has_ReturnType<
                                   Eigen::ScalarBinaryOpTraits<PT, AT, BINOP>>::value) {
                   return static_cast<PT>(-0.5) * (C + (s - mu).squaredNorm());
                 } else {
                   Eigen::Vector<AT, DIM> s_act;
                   std::copy(std::cbegin(s), std::cend(s), std::begin(s_act));
                   return static_cast<PT>(-0.5) * (C + (s_act - mu).squaredNorm());
                 }
               }) /
           static_cast<PT>(data.size());
  }

 public:
  template <typename T>
  using ThetaVector = Eigen::Vector<T, DIM * NUM_CLUSTERS>;

  template <typename AT>
  [[nodiscard]] constexpr auto operator()(const ThetaVector<AT>& theta) const noexcept -> AT {
    AT res = 0.0;
    Eigen::Vector<AT, DIM> mu;
    for (int cluster = 0; cluster < NUM_CLUSTERS; ++cluster) {
      for (int i = 0; i < DIM; ++i) {
        mu(i) = theta(i + cluster);
      }
      res += sum_ln_multi_normal(mu);
    }

    return res;
  }
};

template <typename PT, int DIM, int NUM_CLUSTERS>
requires(DIM > 0 && NUM_CLUSTERS > 0)
std::vector<Eigen::Vector<PT, DIM>> ClusteringLLH<PT, DIM, NUM_CLUSTERS>::data = [] {
  try {
    EB_INFO("Reading in `" << CLUSTERING_INPUT_FILE << '`');
    const auto t_begin = std::chrono::high_resolution_clock::now();
    const auto orig_d  = EB::Utility::read_csv_file<PT>(CLUSTERING_INPUT_FILE);
    const auto t_dur =
        std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - t_begin);
    EB_INFO("Reading csv file took " << t_dur.count() << "s");

    if (orig_d.size() < 1ul) {
      EB_PANIC("Must have at least one sample, has " << orig_d.size() << '.');
    }
    if (orig_d[0].size() != static_cast<size_t>(DIM)) {
      EB_PANIC("Expect each sample to have dimension " << DIM << ", but dimension is "
                                                       << orig_d[0].size() << '.');
    }

    std::vector<Eigen::Vector<PT, DIM>> d(orig_d.size());
    std::transform(
        std::cbegin(orig_d), std::cend(orig_d), std::begin(d), [](const std::vector<PT>& std_vec) {
          Eigen::Vector<PT, DIM> vec{};
          std::copy(std::cbegin(std_vec), std::cend(std_vec), std::begin(vec));
          return vec;
        });
    return d;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    std::exit(1);
  }
}();

#endif  // HARTH_CLUSTERING_LLH_HPP_