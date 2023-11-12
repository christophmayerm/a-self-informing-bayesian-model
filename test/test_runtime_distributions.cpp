#include <gtest/gtest.h>

#include <cmath>

#include "Distributions.hpp"

TEST(TestRuntimeDistributions, Constant) {
  EB::Distribution::RT::Constant d(0.5);

  EXPECT_FLOAT_EQ(d.pdf(0.0f), 0.5f);
  EXPECT_DOUBLE_EQ(d.pdf(0.0), 0.5);

  EXPECT_FLOAT_EQ(d.log_pdf(0.0f), std::log(0.5f));
  EXPECT_DOUBLE_EQ(d.log_pdf(0.0), std::log(0.5));
}

TEST(TestRuntimeDistributions, Uniform) {
  EB::Distribution::RT::Uniform d(-0.6, 0.6);

  EXPECT_FLOAT_EQ(d.pdf(0.0f), 0.8333333333333333333333333333333f);
  EXPECT_DOUBLE_EQ(d.pdf(0.0), 0.8333333333333333333333333333333);

  EXPECT_FLOAT_EQ(d.log_pdf(0.0f), std::log(0.8333333333333333333333333333333f));
  EXPECT_DOUBLE_EQ(d.log_pdf(0.0), std::log(0.8333333333333333333333333333333));

  EXPECT_FLOAT_EQ(d.pdf(0.7f), 0.0f);
  EXPECT_DOUBLE_EQ(d.pdf(0.7), 0.0);

  EXPECT_TRUE(std::isnan(d.log_pdf(0.7f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(0.7)));
}

TEST(TestRuntimeDistributions, Cutoff) {
  EB::Distribution::RT::Cutoff d(-0.5, 0.5);

  EXPECT_FLOAT_EQ(d.pdf(0.0f), 1.0f);
  EXPECT_DOUBLE_EQ(d.pdf(0.0), 1.0);

  EXPECT_FLOAT_EQ(d.log_pdf(0.0f), 0.0f);
  EXPECT_DOUBLE_EQ(d.log_pdf(0.0), 0.0);

  EXPECT_FLOAT_EQ(d.pdf(0.6f), 0.0f);
  EXPECT_DOUBLE_EQ(d.pdf(0.6), 0.0);

  EXPECT_TRUE(std::isnan(d.log_pdf(0.6f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(0.6)));
}

TEST(TestRuntimeDistributions, Normal) {
  EB::Distribution::RT::Normal d(1.0, 2.0);

  EXPECT_FLOAT_EQ(d.pdf(2.0f), 0.17603266338214976f);
  EXPECT_DOUBLE_EQ(d.pdf(2.0), 0.17603266338214976);

  EXPECT_FLOAT_EQ(d.log_pdf(2.0f), -1.7370857137646178f);
  EXPECT_DOUBLE_EQ(d.log_pdf(2.0), -1.7370857137646178);
}

TEST(TestRuntimeDistributions, HalfNormal) {
  EB::Distribution::RT::HalfNormal d(2.0);
  EB::Distribution::RT::Normal d2(0.0, 2.0);

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

TEST(TestRuntimeDistributions, Beta) {
  EB::Distribution::RT::Beta d(2.0, 5.0);

  EXPECT_FLOAT_EQ(d.pdf(0.75f), 0.08789062499999999f);
  EXPECT_DOUBLE_EQ(d.pdf(0.75), 0.08789062499999999);

  EXPECT_FLOAT_EQ(d.log_pdf(0.75f), -2.431662135269188f);
  EXPECT_DOUBLE_EQ(d.log_pdf(0.75), -2.431662135269188);

  EXPECT_TRUE(std::isnan(d.log_pdf(2.0f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(2.0)));

  EXPECT_TRUE(std::isnan(d.log_pdf(-1.0f)));
  EXPECT_TRUE(std::isnan(d.log_pdf(-1.0)));
}

TEST(TestRuntimeDistributions, StudentT) {
  EB::Distribution::RT::StudentT d(2.0);

  EXPECT_FLOAT_EQ(d.pdf(0.75f), 0.24378343319197043f);
  EXPECT_DOUBLE_EQ(d.pdf(0.75), 0.24378343319197043);

  EXPECT_FLOAT_EQ(d.log_pdf(0.75f), -1.4114750166967898f);
  EXPECT_DOUBLE_EQ(d.log_pdf(0.75), -1.4114750166967898);
}

TEST(TestRuntimeDistributions, ExprMultiplication) {
  EB::Distribution::RT::Normal d1(1.0, 2.0);
  EB::Distribution::RT::Uniform d2(0.0, 3.0);
  auto d3 = d1 * d2;

  EXPECT_FLOAT_EQ(d3.pdf(1.0f), d1.pdf(1.0f) * d2.pdf(1.0f));
  EXPECT_DOUBLE_EQ(d3.pdf(1.0), d1.pdf(1.0) * d2.pdf(1.0));

  EXPECT_FLOAT_EQ(d3.pdf(-0.1f), 0.0f);
  EXPECT_DOUBLE_EQ(d3.pdf(-0.1), 0.0);

  EXPECT_FLOAT_EQ(d3.pdf(3.1f), 0.0f);
  EXPECT_DOUBLE_EQ(d3.pdf(3.1), 0.0);

  auto d4 = d3 * EB::Distribution::RT::Beta(2.0, 5.0);
  EB::Distribution::RT::Beta d5(2.0, 5.0);

  EXPECT_FLOAT_EQ(d4.pdf(0.75f), d3.pdf(0.75f) * d5.pdf(0.75f));
  EXPECT_DOUBLE_EQ(d4.pdf(0.75), d3.pdf(0.75) * d5.pdf(0.75));
}

TEST(TestRuntimeDistributions, ExprAddition) {
  EB::Distribution::RT::Normal d1(1.0, 2.0);
  EB::Distribution::RT::Uniform d2(0.0, 3.0);
  auto d3 = d1 + d2;

  EXPECT_FLOAT_EQ(d3.pdf(1.0f), d1.pdf(1.0f) + d2.pdf(1.0f));
  EXPECT_DOUBLE_EQ(d3.pdf(1.0), d1.pdf(1.0) + d2.pdf(1.0));

  EXPECT_FLOAT_EQ(d3.pdf(-0.1f), d1.pdf(-0.1f));
  EXPECT_DOUBLE_EQ(d3.pdf(-0.1), d1.pdf(-0.1));

  EXPECT_FLOAT_EQ(d3.pdf(3.1f), d1.pdf(3.1f));
  EXPECT_DOUBLE_EQ(d3.pdf(3.1), d1.pdf(3.1));

  auto d4 = d3 + EB::Distribution::RT::Beta(2.0, 5.0);
  EB::Distribution::RT::Beta d5(2.0, 5.0);

  EXPECT_FLOAT_EQ(d4.pdf(0.75f), d3.pdf(0.75f) + d5.pdf(0.75f));
  EXPECT_DOUBLE_EQ(d4.pdf(0.75), d3.pdf(0.75) + d5.pdf(0.75));
}

TEST(TestRuntimeDistributions, ExprOrderOfOperation) {
  EB::Distribution::RT::Beta d1(2.0, 5.0);
  EB::Distribution::RT::Constant d2(0.2);
  EB::Distribution::RT::HalfNormal d3(3.0);
  EB::Distribution::RT::Normal d4(2.0, 3.0);
  EB::Distribution::RT::StudentT d5(2.3);
  EB::Distribution::RT::Uniform d6(-1.0, 2.3);
  auto d7 = d1 + d2 * d3 + d4 * d5 + d6;

  EXPECT_FLOAT_EQ(d7.pdf(0.5f),
                  d1.pdf(0.5f) + d2.pdf(0.5f) * d3.pdf(0.5f) + d4.pdf(0.5f) * d5.pdf(0.5f) +
                      d6.pdf(0.5f));

  EXPECT_DOUBLE_EQ(d7.pdf(0.5),
                   d1.pdf(0.5) + d2.pdf(0.5) * d3.pdf(0.5) + d4.pdf(0.5) * d5.pdf(0.5) +
                       d6.pdf(0.5));
}
