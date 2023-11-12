#include <gtest/gtest.h>

#include <vector>

#include "RandomValue.hpp"

TEST(TestRandom, UniformInt) {
  using Int = int;

  const Int lower = -35;
  const Int upper = 45;

  const size_t n = 1'000'000;
  std::vector<Int> xs(n);
  std::generate(
      std::begin(xs), std::end(xs), [&] { return EB::Random::uniform_int(lower, upper); });

  const double mean =
      static_cast<double>(std::reduce(std::cbegin(xs), std::cend(xs))) / static_cast<double>(n);
  const double var = std::transform_reduce(std::cbegin(xs),
                                           std::cend(xs),
                                           0.0,
                                           std::plus{},
                                           [&mean](Int x) -> double {
                                             return (static_cast<double>(x) - mean) *
                                                    (static_cast<double>(x) - mean);
                                           }) /
                     static_cast<double>(n);

  EXPECT_NEAR(mean, (upper + lower) / static_cast<double>(2), 1e-1);
  EXPECT_NEAR(var,
              (std::pow(static_cast<double>(upper) - static_cast<double>(lower) + 1.0, 2) - 1.0) /
                  static_cast<double>(12),
              1.0);
}

TEST(TestRandom, UniformReal) {
  using Float = double;

  const Float lower = -3.5;
  const Float upper = 4.5;

  const size_t n = 10'000;
  std::vector<Float> xs(n);
  std::generate(
      std::begin(xs), std::end(xs), [&] { return EB::Random::uniform_real(lower, upper); });

  const Float mean = std::reduce(std::cbegin(xs), std::cend(xs)) / static_cast<Float>(n);
  const Float var =
      std::transform_reduce(std::cbegin(xs),
                            std::cend(xs),
                            static_cast<Float>(0),
                            std::plus{},
                            [&mean](const auto& x) { return (x - mean) * (x - mean); }) /
      static_cast<Float>(n);

  EXPECT_NEAR(mean, (upper + lower) / static_cast<Float>(2), 1e-1);
  EXPECT_NEAR(var, std::pow(upper - lower, 2) / static_cast<Float>(12), 1e-1);
}

TEST(TestRandom, NormalReal) {
  using Float = double;

  const Float mu    = -3.5;
  const Float sigma = 1.5;

  const size_t n = 10'000;
  std::vector<Float> xs(n);
  std::generate(std::begin(xs), std::end(xs), [&] { return EB::Random::normal_real(mu, sigma); });

  const Float mean = std::reduce(std::cbegin(xs), std::cend(xs)) / static_cast<Float>(n);
  const Float var =
      std::transform_reduce(std::cbegin(xs),
                            std::cend(xs),
                            static_cast<Float>(0),
                            std::plus{},
                            [&mean](const auto& x) { return (x - mean) * (x - mean); }) /
      static_cast<Float>(n);

  EXPECT_NEAR(mean, mu, 1e-1);
  EXPECT_NEAR(var, sigma * sigma, 1e-1);
}

TEST(TestRandom, MultivariateNormal1D) {
  using Float       = double;
  constexpr int DIM = 1;

  const size_t n = 10'000ul;
  const Eigen::Vector<Float, DIM> mu{2.0};
  const Eigen::Matrix<Float, DIM, DIM> sigma{
      {0.25},
  };

  std::vector<Eigen::Vector<Float, DIM>> xs(n);
  std::generate(std::begin(xs), std::end(xs), [&] {
    return EB::Random::multivariate_normal_real(mu, sigma);
  });

  const Eigen::Vector<Float, DIM> mean =
      std::reduce(std::cbegin(xs),
                  std::cend(xs),
                  static_cast<Eigen::Vector<Float, DIM>>(Eigen::Vector<Float, DIM>::Zero()),
                  std::plus{}) /
      static_cast<Float>(n);

  EXPECT_TRUE((mean - mu).norm() < 1e-1)
      << "Expect mean to be approximately mu, but mean=" << mean.transpose()
      << " and mu=" << mu.transpose() << " (||mean - mu|| = " << (mean - mu).norm() << ")";

  const Eigen::Matrix<Float, DIM, DIM> cov =
      std::transform_reduce(
          std::cbegin(xs),
          std::cend(xs),
          static_cast<Eigen::Matrix<Float, DIM, DIM>>(Eigen::Matrix<Float, DIM, DIM>::Zero()),
          std::plus{},
          [&mean](const auto& x) { return (x - mean) * (x - mean).transpose(); }) /
      static_cast<Float>(n);

  EXPECT_TRUE((cov - sigma).norm() < 1e-1)
      << "Expect cov to be approximately sigma, but cov= " << cov << " and sigma= " << sigma
      << " (||cov - sigma|| = " << (cov - sigma).norm() << ")";
}

TEST(TestRandom, MultivariateNormalRealStack) {
  using Float       = double;
  constexpr int DIM = 3;

  const size_t n = 10'000ul;
  const Eigen::Vector<Float, DIM> mu{1.0, 2.0, -1.0};
  const Eigen::Matrix<Float, DIM, DIM> sigma{
      {1.0, 0.5, 0.25},
      {0.5, 1.2, 0.12},
      {0.25, 0.12, 0.8},
  };

  std::vector<Eigen::Vector<Float, DIM>> xs(n);
  std::generate(std::begin(xs), std::end(xs), [&] {
    return EB::Random::multivariate_normal_real(mu, sigma);
  });

  const Eigen::Vector<Float, DIM> mean =
      std::reduce(std::cbegin(xs),
                  std::cend(xs),
                  static_cast<Eigen::Vector<Float, DIM>>(Eigen::Vector<Float, DIM>::Zero()),
                  std::plus{}) /
      static_cast<Float>(n);

  EXPECT_TRUE((mean - mu).norm() < 1e-1)
      << "Expect mean to be approximately mu, but mean=" << mean.transpose()
      << " and mu=" << mu.transpose() << " (||mean - mu|| = " << (mean - mu).norm() << ")";

  const Eigen::Matrix<Float, DIM, DIM> cov =
      std::transform_reduce(
          std::cbegin(xs),
          std::cend(xs),
          static_cast<Eigen::Matrix<Float, DIM, DIM>>(Eigen::Matrix<Float, DIM, DIM>::Zero()),
          std::plus{},
          [&mean](const auto& x) { return (x - mean) * (x - mean).transpose(); }) /
      static_cast<Float>(n);

  EXPECT_TRUE((cov - sigma).norm() < 1e-1)
      << "Expect cov to be approximately sigma, but cov=\n"
      << cov << "\nand sigma=\n"
      << sigma << "\n(||cov - sigma|| = " << (cov - sigma).norm() << ")";
}

TEST(TestRandom, MultivariateNormalRealHeap) {
  using Float       = double;
  constexpr int DIM = 3;

  const size_t n = 10'000ul;
  Eigen::Vector<Float, Eigen::Dynamic> mu(DIM);
  mu << 1.0, 2.0, -1.0;

  Eigen::Matrix<Float, Eigen::Dynamic, Eigen::Dynamic> sigma(DIM, DIM);
  sigma << 1.0, 0.5, 0.25,  //
      0.5, 1.2, 0.12,       //
      0.25, 0.12, 0.8;

  std::vector<Eigen::Vector<Float, Eigen::Dynamic>> xs(n);
  std::generate(std::begin(xs), std::end(xs), [&] {
    return EB::Random::multivariate_normal_real(mu, sigma);
  });

  const Eigen::Vector<Float, Eigen::Dynamic> mean =
      std::reduce(std::cbegin(xs),
                  std::cend(xs),
                  static_cast<Eigen::Vector<Float, Eigen::Dynamic>>(
                      Eigen::Vector<Float, Eigen::Dynamic>::Zero(DIM)),
                  std::plus{}) /
      static_cast<Float>(n);

  EXPECT_TRUE((mean - mu).norm() < 1e-1)
      << "Expect mean to be approximately mu, but mean=" << mean.transpose()
      << " and mu=" << mu.transpose() << " (||mean - mu|| = " << (mean - mu).norm() << ")";

  const Eigen::Matrix<Float, Eigen::Dynamic, Eigen::Dynamic> cov =
      std::transform_reduce(
          std::cbegin(xs),
          std::cend(xs),
          static_cast<Eigen::Matrix<Float, Eigen::Dynamic, Eigen::Dynamic>>(
              Eigen::Matrix<Float, Eigen::Dynamic, Eigen::Dynamic>::Zero(DIM, DIM)),
          std::plus{},
          [&mean](const auto& x) { return (x - mean) * (x - mean).transpose(); }) /
      static_cast<Float>(n);

  EXPECT_TRUE((cov - sigma).norm() < 1e-1)
      << "Expect cov to be approximately sigma, but cov=\n"
      << cov << "\nand sigma=\n"
      << sigma << "\n(||cov - sigma|| = " << (cov - sigma).norm() << ")";
}
