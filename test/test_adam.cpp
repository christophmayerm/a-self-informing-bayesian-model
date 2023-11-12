#include <gtest/gtest.h>

#include "AdamGradientAscent.hpp"

TEST(TestAdam, ParabolaTangent) {
  constexpr int SIZE = 100;
  auto f = []<typename AT>(const Eigen::Vector<AT, SIZE>& x) { return -x.squaredNorm(); };

  EB::AdamGradientAscent<decltype(f), SIZE, EB::GAGradientMethod::TANGENT> ga(f);

  Eigen::Vector<double, SIZE> x = Eigen::Vector<double, SIZE>::Constant(10.0);

  double learning_rate = 1.0;
  double function_value;
  Eigen::Vector<double, SIZE> gradient;
  EB::Hypercube<double, SIZE> boundaries;
  for (auto& interval : boundaries) {
    interval = EB::Interval{-100.0, 100.0};
  }
  double tol      = std::sqrt(std::numeric_limits<double>::epsilon());
  size_t max_iter = 500ul;

  const auto success =
      ga.calc(x, learning_rate, function_value, gradient, boundaries, tol, max_iter);

  EXPECT_TRUE(success);
  EXPECT_NEAR(x.norm(), 0.0, 1e-6);
  EXPECT_NEAR(function_value, 0.0, 1e-6);
  EXPECT_LE(gradient.norm(), std::sqrt(std::numeric_limits<double>::epsilon()));
}

TEST(TestAdam, ParabolaVectorTangent) {
  constexpr int SIZE = 100;
  auto f = []<typename AT>(const Eigen::Vector<AT, SIZE>& x) { return -x.squaredNorm(); };

  EB::AdamGradientAscent<decltype(f), SIZE, EB::GAGradientMethod::VECTOR_TANGENT> ga(f);

  Eigen::Vector<double, SIZE> x = Eigen::Vector<double, SIZE>::Constant(10.0);

  double learning_rate = 1.0;
  double function_value;
  Eigen::Vector<double, SIZE> gradient;
  EB::Hypercube<double, SIZE> boundaries;
  for (auto& interval : boundaries) {
    interval = EB::Interval{-100.0, 100.0};
  }
  double tol      = std::sqrt(std::numeric_limits<double>::epsilon());
  size_t max_iter = 500ul;

  const auto success =
      ga.calc(x, learning_rate, function_value, gradient, boundaries, tol, max_iter);

  EXPECT_TRUE(success);
  EXPECT_NEAR(x.norm(), 0.0, 1e-6);
  EXPECT_NEAR(function_value, 0.0, 1e-6);
  EXPECT_LE(gradient.norm(), std::sqrt(std::numeric_limits<double>::epsilon()));
}

TEST(TestAdam, ParabolaAdjoint) {
  constexpr int SIZE = 100;
  auto f = []<typename AT>(const Eigen::Vector<AT, SIZE>& x) { return -x.squaredNorm(); };

  EB::AdamGradientAscent<decltype(f), SIZE, EB::GAGradientMethod::ADJOINT> ga(f);

  Eigen::Vector<double, SIZE> x = Eigen::Vector<double, SIZE>::Constant(10.0);

  double learning_rate = 1.0;
  double function_value;
  Eigen::Vector<double, SIZE> gradient;
  EB::Hypercube<double, SIZE> boundaries;
  for (auto& interval : boundaries) {
    interval = EB::Interval{-100.0, 100.0};
  }
  double tol      = std::sqrt(std::numeric_limits<double>::epsilon());
  size_t max_iter = 500ul;

  const auto success =
      ga.calc(x, learning_rate, function_value, gradient, boundaries, tol, max_iter);

  EXPECT_TRUE(success);
  EXPECT_NEAR(x.norm(), 0.0, 1e-6);
  EXPECT_NEAR(function_value, 0.0, 1e-6);
  EXPECT_LE(gradient.norm(), std::sqrt(std::numeric_limits<double>::epsilon()));
}