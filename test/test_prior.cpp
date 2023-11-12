#include <gtest/gtest.h>

#include <type_traits>

#include <Eigen/Dense>

#include "Distributions.hpp"
#include "Prior.hpp"

TEST(TestPrior, EmptyPrior) {
  EB::Prior p;

  Eigen::Vector<float, p.size> xf;
  Eigen::Vector<double, p.size> xd;

  EXPECT_FLOAT_EQ(p.pdf(xf), 1.0f);
  EXPECT_DOUBLE_EQ(p.pdf(xd), 1.0);

  EXPECT_FLOAT_EQ(p.log_pdf(xf), 0.0f);
  EXPECT_DOUBLE_EQ(p.log_pdf(xd), 0.0);
}

TEST(TestPrior, SevenDimensionalCompiletimePrior) {
  EB::Distribution::CT::Beta<2.0, 5.0> d1;
  EB::Distribution::CT::Constant<0.2> d2;
  EB::Distribution::CT::HalfNormal<3.0> d3;
  EB::Distribution::CT::Normal<2.0, 3.0> d4;
  EB::Distribution::CT::StudentT<2.3> d5;
  EB::Distribution::CT::Uniform<-1.0, 2.3> d6;
  auto d7 = d1 + d2 * d3 + d4 * d5 + d6;

  EB::Prior p(d1, d2, d3, d4, d5, d6, d7);

  {
    auto p2                  = EB::make_prior(d1, d2, d3, d4, d5, d6, d7);
    constexpr bool condition = std::is_same_v<decltype(p), decltype(p2)>;
    EXPECT_TRUE(condition);
  }

  Eigen::Vector<float, p.size> xf  = Eigen::Vector<float, p.size>::Constant(0.5f);
  Eigen::Vector<double, p.size> xd = Eigen::Vector<double, p.size>::Constant(0.5);

  EXPECT_FLOAT_EQ(p.pdf(xf),
                  d1.pdf(0.5f) * d2.pdf(0.5f) * d3.pdf(0.5f) * d4.pdf(0.5f) * d5.pdf(0.5f) *
                      d6.pdf(0.5f) * d7.pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.pdf(xd),
                   d1.pdf(0.5) * d2.pdf(0.5) * d3.pdf(0.5) * d4.pdf(0.5) * d5.pdf(0.5) *
                       d6.pdf(0.5) * d7.pdf(0.5));

  EXPECT_FLOAT_EQ(p.log_pdf(xf),
                  d1.log_pdf(0.5f) + d2.log_pdf(0.5f) + d3.log_pdf(0.5f) + d4.log_pdf(0.5f) +
                      d5.log_pdf(0.5f) + d6.log_pdf(0.5f) + d7.log_pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.log_pdf(xd),
                   d1.log_pdf(0.5) + d2.log_pdf(0.5) + d3.log_pdf(0.5) + d4.log_pdf(0.5) +
                       d5.log_pdf(0.5) + d6.log_pdf(0.5) + d7.log_pdf(0.5));
}

TEST(TestPrior, SevenDimensionalRuntimePrior) {
  EB::Distribution::RT::Beta d1(2.0, 5.0);
  EB::Distribution::RT::Constant d2(0.2);
  EB::Distribution::RT::HalfNormal d3(3.0);
  EB::Distribution::RT::Normal d4(2.0, 3.0);
  EB::Distribution::RT::StudentT d5(2.3);
  EB::Distribution::RT::Uniform d6(-1.0, 2.3);
  auto d7 = d1 + d2 * d3 + d4 * d5 + d6;

  EB::Prior p(d1, d2, d3, d4, d5, d6, d7);

  {
    auto p2                  = EB::make_prior(d1, d2, d3, d4, d5, d6, d7);
    constexpr bool condition = std::is_same_v<decltype(p), decltype(p2)>;
    EXPECT_TRUE(condition);
  }

  Eigen::Vector<float, p.size> xf  = Eigen::Vector<float, p.size>::Constant(0.5f);
  Eigen::Vector<double, p.size> xd = Eigen::Vector<double, p.size>::Constant(0.5);

  EXPECT_FLOAT_EQ(p.pdf(xf),
                  d1.pdf(0.5f) * d2.pdf(0.5f) * d3.pdf(0.5f) * d4.pdf(0.5f) * d5.pdf(0.5f) *
                      d6.pdf(0.5f) * d7.pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.pdf(xd),
                   d1.pdf(0.5) * d2.pdf(0.5) * d3.pdf(0.5) * d4.pdf(0.5) * d5.pdf(0.5) *
                       d6.pdf(0.5) * d7.pdf(0.5));

  EXPECT_FLOAT_EQ(p.log_pdf(xf),
                  d1.log_pdf(0.5f) + d2.log_pdf(0.5f) + d3.log_pdf(0.5f) + d4.log_pdf(0.5f) +
                      d5.log_pdf(0.5f) + d6.log_pdf(0.5f) + d7.log_pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.log_pdf(xd),
                   d1.log_pdf(0.5) + d2.log_pdf(0.5) + d3.log_pdf(0.5) + d4.log_pdf(0.5) +
                       d5.log_pdf(0.5) + d6.log_pdf(0.5) + d7.log_pdf(0.5));
}

TEST(TestPrior, MixedPrior) {
  EB::Distribution::CT::Beta<2.0, 5.0> d1;
  EB::Distribution::RT::Constant d2(0.2);

  EB::Prior p(d1, d2);

  {
    auto p2                  = EB::make_prior(d1, d2);
    constexpr bool condition = std::is_same_v<decltype(p), decltype(p2)>;
    EXPECT_TRUE(condition);
  }

  Eigen::Vector<float, p.size> xf  = Eigen::Vector<float, p.size>::Constant(0.5f);
  Eigen::Vector<double, p.size> xd = Eigen::Vector<double, p.size>::Constant(0.5);

  EXPECT_FLOAT_EQ(p.pdf(xf), d1.pdf(0.5f) * d2.pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.pdf(xd), d1.pdf(0.5) * d2.pdf(0.5));

  EXPECT_FLOAT_EQ(p.log_pdf(xf), d1.log_pdf(0.5f) + d2.log_pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.log_pdf(xd), d1.log_pdf(0.5) + d2.log_pdf(0.5));
}

TEST(TestPrior, TempDist) {
  EB::Prior p(EB::Distribution::CT::Beta<2.0, 5.0>{} * EB::Distribution::CT::Normal<1.0, 2.0>{},
              EB::Distribution::RT::Constant{0.2});

  {
    auto p2 = EB::make_prior(EB::Distribution::CT::Beta<2.0, 5.0>{} *
                                 EB::Distribution::CT::Normal<1.0, 2.0>{},
                             EB::Distribution::RT::Constant{0.2});

    constexpr bool condition = std::is_same_v<decltype(p), decltype(p2)>;
    EXPECT_TRUE(condition);
  }

  Eigen::Vector<float, p.size> xf  = Eigen::Vector<float, p.size>::Constant(0.5f);
  Eigen::Vector<double, p.size> xd = Eigen::Vector<double, p.size>::Constant(0.5);

  const auto d1 = EB::Distribution::CT::Beta<2.0, 5.0>{} * EB::Distribution::CT::Normal<1.0, 2.0>{};
  const auto d2 = EB::Distribution::RT::Constant{0.2};

  EXPECT_FLOAT_EQ(p.pdf(xf), d1.pdf(0.5f) * d2.pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.pdf(xd), d1.pdf(0.5) * d2.pdf(0.5));

  EXPECT_FLOAT_EQ(p.log_pdf(xf), d1.log_pdf(0.5f) + d2.log_pdf(0.5f));

  EXPECT_DOUBLE_EQ(p.log_pdf(xd), d1.log_pdf(0.5) + d2.log_pdf(0.5));
}

TEST(TestPrior, ExtractDistribution) {
  const auto d0 =
      EB::Distribution::CT::Normal<1.0, 2.0>{} * EB::Distribution::CT::HalfNormal<3.0>{};
  const auto d1    = EB::Distribution::RT::Beta(0.5, 0.7) * EB::Distribution::RT::StudentT(3.0);
  const auto prior = EB::make_prior(d0, d1);

  const auto extracted_d0 = prior.get<0>();
  const auto extracted_d1 = prior.get<1>();

  EXPECT_TRUE((std::is_same_v<decltype(d0), decltype(extracted_d0)>));
  EXPECT_TRUE((std::is_same_v<decltype(d1), decltype(extracted_d1)>));
  EXPECT_DOUBLE_EQ(d1.pdf(0.5), extracted_d1.pdf(0.5));
  EXPECT_DOUBLE_EQ(d1.log_pdf(0.5), extracted_d1.log_pdf(0.5));
}
