#include <gtest/gtest.h>

#include <cmath>
#include <numeric>

#include <Eigen/Dense>

#define EB_HMC_QUIET_FITTING
#include "Distributions.hpp"
#include "HMCSampler.hpp"
#include "Prior.hpp"

template <typename PT>
[[nodiscard]] constexpr auto calc_mean(const std::vector<PT>& vec) -> PT {
  return std::reduce(std::cbegin(vec), std::cend(vec), static_cast<PT>(0), std::plus{}) /
         static_cast<PT>(vec.size());
};

template <typename PT>
[[nodiscard]] constexpr auto calc_sd(const std::vector<PT>& vec, PT mean) -> PT {
  return std::sqrt(
      std::transform_reduce(std::cbegin(vec),
                            std::cend(vec),
                            static_cast<PT>(0),
                            std::plus{},
                            [&mean](const auto& a) { return (a - mean) * (a - mean); }) /
      static_cast<PT>(vec.size()));
};

TEST(TestHMCTangent, RunHMC) {
  using Float         = double;
  constexpr auto SIZE = 2;

  constexpr Float mu1    = 2.0;
  constexpr Float sigma1 = 0.5;
  constexpr Float mu2    = 1.0;
  constexpr Float sigma2 = 0.25;

  const auto prior = EB::make_prior(EB::Distribution::CT::Cutoff<-10.0, 10.0>{},
                                    EB::Distribution::RT::Cutoff(-10.0, 10.0));

  const auto llh = [=]<typename AT>(const Eigen::Vector<AT, SIZE>& theta) {
    return -(std::pow((theta(0) - mu1) / sigma1, 2) + std::pow((theta(1) - mu2) / sigma2, 2));
  };

  EB::HMC<Float, SIZE, decltype(llh), decltype(prior)> hmc(llh, prior);

  const EB::HMCOptions<Float, SIZE> opt{
      .burn_in   = 25'000ul,
      .num_steps = 100'000ul,
  };
  hmc.fit_parameters(opt);

  const auto& chains = hmc.chains();
  ASSERT_EQ(chains.size(), SIZE);

  const auto mean1 = calc_mean(chains[0]);
  const auto sd1   = calc_sd(chains[0], mean1);

  const auto mean2 = calc_mean(chains[1]);
  const auto sd2   = calc_sd(chains[1], mean2);

  std::cout << "Chain 1:\n";
  std::cout << "  mean = " << mean1 << " (Expected " << mu1 << ")\n";
  std::cout << "  sd   = " << sd1 << " (Expected " << sigma1 << ")\n";

  std::cout << "Chain 2:\n";
  std::cout << "  mean = " << mean2 << " (Expected " << mu2 << ")\n";
  std::cout << "  sd   = " << sd2 << " (Expected " << sigma2 << ")\n";

  EXPECT_NEAR(mu1, mean1, sigma1)
      << "Expected mean of chain of parameter 1 to be approximately mu1 = " << mu1 << ", but is "
      << mean1;

  // TODO: Chose appropriate value for error (not just 3/4 * sigma)
  EXPECT_NEAR(sigma1, sd1, 3.0 * sigma1 / 4.0)
      << "Expected standard deviation of chain of parameter 1 to be approximately sigma1 = "
      << sigma1 << ", but is " << sd1;

  EXPECT_NEAR(mu2, mean2, sigma2)
      << "Expected mean of chain of parameter 2 to be approximately mu2 = " << mu2 << ", but is "
      << mean2;

  // TODO: Chose appropriate value for error (not just 3/4 * sigma)
  EXPECT_NEAR(sigma2, sd2, 3.0 * sigma2 / 4.0)
      << "Expected standard deviation of chain of parameter 2 to be approximately sigma2 = "
      << sigma2 << ", but is " << sd2;
}
