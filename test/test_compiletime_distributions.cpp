#include <gtest/gtest.h>

#include <cmath>

#include "Distributions.hpp"

TEST(TestCompiletimeDistributions, Constant) {
  EB::Distribution::CT::Constant<0.5> d;

  EXPECT_FLOAT_EQ(d.pdf(0.0f), 0.5f);
  EXPECT_DOUBLE_EQ(d.pdf(0.0), 0.5);

  EXPECT_FLOAT_EQ(d.log_pdf(0.0f), std::log(0.5f));
  EXPECT_DOUBLE_EQ(d.log_pdf(0.0), std::log(0.5));
}

TEST(TestCompiletimeDistributions, Uniform) {
  EB::Distribution::CT::Uniform<-0.6, 0.6> d;

  EXPECT_FLOAT_EQ(d.pdf(0.0f), 0.8333333333333333333333333333333f);
  EXPECT_DOUBLE_EQ(d.pdf(0.0), 0.8333333333333333333333333333333);

  EXPECT_FLOAT_EQ(d.log_pdf(0.0f), std::log(0.8333333333333333333333333333333f));
  EXPECT_DOUBLE_EQ(d.log_pdf(0.0), std::log(0.8333333333333333333333333333333));

  EXPECT_FLOAT_EQ(d.pdf(0.7f), 0.0f);
  EXPECT_DOUBLE_EQ(d.pdf(0.7), 0.0);

  EXPECT_TRUE(std::isnan(d.log_pdf(0.7f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(0.7)));
}

TEST(TestCompiletimeDistributions, Cutoff) {
  EB::Distribution::CT::Cutoff<-0.5, 0.5> d;

  EXPECT_FLOAT_EQ(d.pdf(0.0f), 1.0f);
  EXPECT_DOUBLE_EQ(d.pdf(0.0), 1.0);

  EXPECT_FLOAT_EQ(d.log_pdf(0.0f), 0.0f);
  EXPECT_DOUBLE_EQ(d.log_pdf(0.0), 0.0);

  EXPECT_FLOAT_EQ(d.pdf(0.6f), 0.0f);
  EXPECT_DOUBLE_EQ(d.pdf(0.6), 0.0);

  EXPECT_TRUE(std::isnan(d.log_pdf(0.6f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(0.6)));
}

TEST(TestCompiletimeDistributions, Normal) {
  EB::Distribution::CT::Normal<1.0, 2.0> d;

  EXPECT_FLOAT_EQ(d.pdf(2.0f), 0.17603266338214976f);
  EXPECT_DOUBLE_EQ(d.pdf(2.0), 0.17603266338214976);

  EXPECT_FLOAT_EQ(d.log_pdf(2.0f), -1.7370857137646178f);
  EXPECT_DOUBLE_EQ(d.log_pdf(2.0), -1.7370857137646178);
}

TEST(TestCompiletimeDistributions, HalfNormal) {
  EB::Distribution::CT::HalfNormal<2.0> d;
  EB::Distribution::CT::Normal<0.0, 2.0> d2;

  EXPECT_FLOAT_EQ(d.pdf(2.0f), 0.241970724519143349797830192935561f);
  EXPECT_DOUBLE_EQ(d.pdf(2.0), 0.241970724519143349797830192935561);

  EXPECT_FLOAT_EQ(d.log_pdf(2.0f), -1.4189385332046727417803297364056f);
  EXPECT_DOUBLE_EQ(d.log_pdf(2.0), -1.4189385332046727417803297364056);

  EXPECT_FLOAT_EQ(d.pdf(0.0f), 2.0f * d2.pdf(0.0f));
  EXPECT_DOUBLE_EQ(d.pdf(0.0), 2.0 * d2.pdf(0.0));

  EXPECT_FLOAT_EQ(d.log_pdf(0.0f), std::log(2.0f) + d2.log_pdf(0.0f));
  EXPECT_DOUBLE_EQ(d.log_pdf(0.0), std::log(2.0) + d2.log_pdf(0.0));

  EXPECT_FLOAT_EQ(d.pdf(-2.0f), 0.0f);
  EXPECT_DOUBLE_EQ(d.pdf(-2.0), 0.0);

  EXPECT_TRUE(std::isnan(d.log_pdf(-2.0f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(-2.0)));
}

TEST(TestCompiletimeDistributions, Beta) {
  EB::Distribution::CT::Beta<2.0, 5.0> d;

  EXPECT_FLOAT_EQ(d.pdf(0.75f), 0.08789062499999999f);
  EXPECT_DOUBLE_EQ(d.pdf(0.75), 0.08789062499999999);

  EXPECT_FLOAT_EQ(d.log_pdf(0.75f), -2.431662135269188f);
  EXPECT_DOUBLE_EQ(d.log_pdf(0.75), -2.431662135269188);

  EXPECT_TRUE(std::isnan(d.log_pdf(2.0f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(2.0)));

  EXPECT_TRUE(std::isnan(d.log_pdf(-1.0f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(-1.0)));
}

TEST(TestCompiletimeDistributions, StudentT) {
  EB::Distribution::CT::StudentT<2.0> d;

  EXPECT_FLOAT_EQ(d.pdf(0.75f), 0.24378343319197043f);
  EXPECT_DOUBLE_EQ(d.pdf(0.75), 0.24378343319197043);

  EXPECT_FLOAT_EQ(d.log_pdf(0.75f), -1.4114750166967898f);
  EXPECT_DOUBLE_EQ(d.log_pdf(0.75), -1.4114750166967898);
}

TEST(TestCompiletimeDistributions, ExprMultiplication) {
  EB::Distribution::CT::Normal<1.0, 2.0> d1;
  EB::Distribution::CT::Uniform<0.0, 3.0> d2;
  auto d3 = d1 * d2;

  EXPECT_FLOAT_EQ(d3.pdf(1.0f), d1.pdf(1.0f) * d2.pdf(1.0f));
  EXPECT_DOUBLE_EQ(d3.pdf(1.0), d1.pdf(1.0) * d2.pdf(1.0));

  EXPECT_FLOAT_EQ(d3.pdf(-0.1f), 0.0f);
  EXPECT_DOUBLE_EQ(d3.pdf(-0.1), 0.0);

  EXPECT_FLOAT_EQ(d3.pdf(3.1f), 0.0f);
  EXPECT_DOUBLE_EQ(d3.pdf(3.1), 0.0);

  auto d4 = d3 * EB::Distribution::CT::Beta<2.0, 5.0>{};
  EB::Distribution::CT::Beta<2.0, 5.0> d5;

  EXPECT_FLOAT_EQ(d4.pdf(0.75f), d3.pdf(0.75f) * d5.pdf(0.75f));
  EXPECT_DOUBLE_EQ(d4.pdf(0.75), d3.pdf(0.75) * d5.pdf(0.75));
}

TEST(TestCompiletimeDistributions, ExprAddition) {
  EB::Distribution::CT::Normal<1.0, 2.0> d1;
  EB::Distribution::CT::Uniform<0.0, 3.0> d2;
  auto d3 = d1 + d2;

  EXPECT_FLOAT_EQ(d3.pdf(1.0f), d1.pdf(1.0f) + d2.pdf(1.0f));
  EXPECT_DOUBLE_EQ(d3.pdf(1.0), d1.pdf(1.0) + d2.pdf(1.0));

  EXPECT_FLOAT_EQ(d3.pdf(-0.1f), d1.pdf(-0.1f));
  EXPECT_DOUBLE_EQ(d3.pdf(-0.1), d1.pdf(-0.1));

  EXPECT_FLOAT_EQ(d3.pdf(3.1f), d1.pdf(3.1f));
  EXPECT_DOUBLE_EQ(d3.pdf(3.1), d1.pdf(3.1));

  auto d4 = d3 + EB::Distribution::CT::Beta<2.0, 5.0>{};
  EB::Distribution::CT::Beta<2.0, 5.0> d5;

  EXPECT_FLOAT_EQ(d4.pdf(0.75f), d3.pdf(0.75f) + d5.pdf(0.75f));
  EXPECT_DOUBLE_EQ(d4.pdf(0.75), d3.pdf(0.75) + d5.pdf(0.75));
}

TEST(TestCompiletimeDistributions, ExprOrderOfOperation) {
  EB::Distribution::CT::Beta<2.0, 5.0> d1;
  EB::Distribution::CT::Constant<0.2> d2;
  EB::Distribution::CT::HalfNormal<3.0> d3;
  EB::Distribution::CT::Normal<2.0, 3.0> d4;
  EB::Distribution::CT::StudentT<2.3> d5;
  EB::Distribution::CT::Uniform<-1.0, 2.3> d6;
  auto d7 = d1 + d2 * d3 + d4 * d5 + d6;

  EXPECT_FLOAT_EQ(d7.pdf(0.5f),
                  d1.pdf(0.5f) + d2.pdf(0.5f) * d3.pdf(0.5f) + d4.pdf(0.5f) * d5.pdf(0.5f) +
                      d6.pdf(0.5f));

  EXPECT_DOUBLE_EQ(d7.pdf(0.5),
                   d1.pdf(0.5) + d2.pdf(0.5) * d3.pdf(0.5) + d4.pdf(0.5) * d5.pdf(0.5) +
                       d6.pdf(0.5));
}
