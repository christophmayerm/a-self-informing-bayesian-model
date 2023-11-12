#ifndef EB_TARGET_FUNCTION_2_HPP_
#define EB_TARGET_FUNCTION_2_HPP_

#include <algorithm>
#include <vector>

#include "Hypercube.hpp"
#include "RandomValue.hpp"

/*******************\
| theta = [rho, mu] |
\*******************/

// - Target function -------------------------------------------------------------------------------
template <typename PT>
class OnedimChen {
  std::vector<PT> m_data;

 public:
  static constexpr size_t SIZE = 2;

  template <typename T>
  using ThetaVector = Eigen::Vector<T, SIZE>;

  static constexpr EB::Hypercube<PT, SIZE> boundaries{
      EB::Interval<PT>{0.0, 1.0},
      EB::Interval<PT>{0.0, 5.0},
  };

 private:
  template <typename AT>
  constexpr void normal_pdf(AT mean, PT sd, std::vector<AT>& res) const noexcept {
    assert(res.size() == m_data.size());
    std::transform(std::cbegin(m_data), std::cend(m_data), std::begin(res), [&](const AT& x) {
      const PT inv_root_two_pi_sd = (1.0 / (std::numbers::sqrt2 * sd)) * std::numbers::inv_sqrtpi;
      return inv_root_two_pi_sd * std::exp(-0.5 * std::pow((x - mean) / sd, 2));
    });
  }

 public:
  constexpr OnedimChen(size_t data_size) noexcept
      : m_data([=] {
          std::vector<PT> local_data(data_size);
          std::generate(std::begin(local_data), std::end(local_data), [] {
            constexpr PT p0 = 0.5;
            constexpr PT p1 = 0.45;
            constexpr PT p2 = 0.05;
            static_assert(std::abs(p0 + p1 + p2 - 1.0) < 1e-8);

            constexpr PT m0 = 0.0;
            constexpr PT m1 = 0.75;
            constexpr PT m2 = 3.0;
            constexpr PT sd = 0.2;

            const PT choice = EB::Random::uniform_real(0.0, 1.0);
            if (choice <= p0) {
              return EB::Random::normal_real(m0, sd);
            } else if (choice <= p0 + p1) {
              return EB::Random::normal_real(m1, sd);
            } else /* if (choice <= p0 + p1 + p2) */ {
              return EB::Random::normal_real(m2, sd);
            }
          });
          return local_data;
        }()) {}

  template <typename AT>
  [[nodiscard]] constexpr auto operator()(const ThetaVector<AT>& theta) const noexcept -> AT {
    std::vector<AT> xs0(m_data.size());
    normal_pdf<AT>(0.0, 0.2, xs0);

    std::vector<AT> xs1(m_data.size());
    normal_pdf<AT>(theta(1), 0.2, xs1);

    return std::transform_reduce(std::cbegin(xs0),
                                 std::cend(xs0),
                                 std::cbegin(xs1),
                                 static_cast<AT>(0),
                                 std::plus{},
                                 [&](const AT& x0, const AT& x1) {
                                   return std::log((1.0 - theta(0)) * x0 + theta(0) * x1);
                                 }) /
           static_cast<PT>(m_data.size());
  }
};

#endif  // EB_TARGET_FUNCTION_2_HPP_
