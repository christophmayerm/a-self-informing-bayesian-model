#ifndef MODEL_BASED_KRIGING_HPP_
#define MODEL_BASED_KRIGING_HPP_

#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>

#include "dco.hpp"

#include "Macros.hpp"

template <typename PT>
class ModelBasedKrigingLLH {
  Eigen::Index m_num_samples{};
  Eigen::MatrixX<PT> m_distance_mat{};
  Eigen::VectorX<PT> m_values{};

 public:
  enum : int { TAU, BETA, SIGMA, PHI, SIZE };

  ModelBasedKrigingLLH(const std::string& input_file,
                       size_t max_num_samples = std::numeric_limits<size_t>::max()) {
    using namespace std::string_literals;

    struct Sample {
      PT x;
      PT y;
      PT value;
    };

    std::ifstream in(input_file);
    if (!in) {
      throw std::runtime_error(EB_ERROR_LOC() + ": Could not open file `"s + input_file +
                               "` for reading: "s + std::strerror(errno));
    }

    std::vector<Sample> samples{};
    Sample tmp{};
    while ((in >> tmp.x) && (in >> tmp.y) && (in >> tmp.value) &&
           (samples.size() < max_num_samples)) {
      samples.push_back(std::move(tmp));
    }
    m_num_samples = static_cast<Eigen::Index>(samples.size());

    m_distance_mat.resize(m_num_samples, m_num_samples);
    for (Eigen::Index i = 0; i < m_num_samples; ++i) {
      for (Eigen::Index j = 0; j <= i; ++j) {
        const auto dist      = std::sqrt(std::pow(samples[i].x - samples[j].x, 2) +
                                    std::pow(samples[i].y - samples[j].y, 2));
        m_distance_mat(i, j) = dist;
        m_distance_mat(j, i) = dist;
      }
    }

    m_values.resize(m_num_samples);
    std::transform(std::cbegin(samples),
                   std::cend(samples),
                   std::begin(m_values),
                   [](const Sample& s) { return s.value; });
  }

  template <typename AT>
  [[nodiscard]] auto operator()(const Eigen::Vector<AT, SIZE>& theta) const noexcept -> AT {
    assert(m_values.rows() == m_num_samples && m_distance_mat.rows() == m_num_samples &&
           m_distance_mat.cols() == m_num_samples);

    // Calculate covariance matrix: S = D + h*B
    const Eigen::MatrixX<AT> D =
        theta(TAU) * theta(TAU) * Eigen::MatrixX<AT>::Identity(m_num_samples, m_num_samples);

    const AT h = theta(SIGMA) * theta(SIGMA);

    const Eigen::MatrixX<AT> B = [this, &theta] {
      Eigen::MatrixX<AT> local_B(m_num_samples, m_num_samples);
      for (Eigen::Index i = 0; i < m_num_samples; ++i) {
        for (Eigen::Index j = i; j < m_num_samples; ++j) {
          // Use exppnential correlation model
          const AT corr = std::exp(-m_distance_mat(i, j) / theta(PHI));
          local_B(i, j) = corr;
          local_B(j, i) = corr;
        }
      }
      return local_B;
    }();

    const Eigen::MatrixX<AT> cov_mat = D + h * B;

    // Use the passive values `m_values` if possible, else make copy
    const Eigen::VectorX<AT> residual = [this, &theta]() -> Eigen::VectorX<AT> {
      using BINOP = Eigen::internal::scalar_difference_op<PT, AT>;
      if constexpr (Eigen::internal::has_ReturnType<
                        Eigen::ScalarBinaryOpTraits<PT, AT, BINOP>>::value) {
        return m_values - Eigen::VectorX<AT>::Constant(m_num_samples, theta(BETA));
      } else {
        Eigen::VectorX<AT> y(m_num_samples);
        std::copy(std::cbegin(m_values), std::cend(m_values), std::begin(y));
        return y - Eigen::VectorX<AT>::Constant(m_num_samples, theta(BETA));
      }
    }();

#ifdef MBK_APPROX_LLH
    Eigen::ConjugateGradient<Eigen::MatrixX<AT>, Eigen::Lower | Eigen::Upper> cg(cov_mat);
    const Eigen::VectorX<AT> cov_inv_times_res = cg.solve(residual);
    const auto log_det_cov                     = [&, this] {
      AT log_det_D = 0.0;
      AT trace     = 0.0;
      for (Eigen::Index i = 0; i < m_num_samples; ++i) {
        log_det_D += std::log(D(i, i));
        trace += B(i, i) / D(i, i);
      }

      return std::log(1 + h * trace) + log_det_D;
    }();
#else
    // const auto llt = cov_mat.llt();
    // if (llt.info() != Eigen::Success) {
    //   // TODO: Gracefully fail here
    //   // EB_PANIC("Decomposition failed!");
    //   return std::numeric_limits<AT>::quiet_NaN();
    // }
    // const Eigen::VectorX<AT> cov_inv_times_res = llt.solve(residual);

    // const auto L   = llt.matrixL();
    // AT log_det_cov = 0;
    // for (Eigen::Index i = 0; i < m_num_samples; ++i) {
    //   log_det_cov += std::log(L(i, i));
    // }
    // log_det_cov *= 2;

    const auto [cov_inv_times_res, log_det_cov] = calc_lse_and_log_det_llt<AT>(cov_mat, residual);
#endif  // MBK_APPROX_LLH

    constexpr PT log_two_pi = std::log(static_cast<PT>(2) * std::numbers::pi_v<PT>);
    return static_cast<PT>(-0.5) * (static_cast<PT>(m_num_samples) * log_two_pi + log_det_cov +
                                    cov_inv_times_res.dot(residual));
  }

  // - Solve linear system of equations lhs^(-1) * rhs and calculate log(det(lhs)) -----------------
  //   -> Regular method without modifications, should be used for tangent and fundamental types
  template <typename AT>
  constexpr auto calc_lse_and_log_det_llt(const Eigen::MatrixX<AT>& lhs,
                                          const Eigen::VectorX<AT>& rhs) const noexcept
      -> std::pair<Eigen::VectorX<AT>, AT> {
    assert(lhs.rows() == lhs.cols() && "`lhs` must be square.");
    assert(lhs.rows() == rhs.rows() && "`lhs` and `rhs` must have same size.");
    const Eigen::Index n = lhs.rows();

    const auto llt = lhs.llt();
    if (llt.info() != Eigen::Success) {
      // TODO: Gracefully fail here
      // EB_PANIC("decomposition failed!");
      return std::pair{
          Eigen::VectorX<AT>::Constant(n, std::numeric_limits<AT>::quiet_NaN()),
          std::numeric_limits<AT>::quiet_NaN(),
      };
    }
    Eigen::VectorX<AT> sol = llt.solve(rhs);

    const auto L = llt.matrixL();
    AT log_det   = 0;
    for (Eigen::Index i = 0; i < n; ++i) {
      log_det += log(L(i, i));
    }
    log_det *= 2;

    return std::pair{sol, log_det};
  }

  // - Solve linear system of equations lhs^(-1) * rhs and calculate log(det(lhs)) -----------------
  //   -> Adjoint callback version, should be used with adjoint types
  template <typename AT>
  constexpr auto calc_lse_and_log_det_llt(const Eigen::MatrixX<AT>& lhs,
                                          const Eigen::VectorX<AT>& rhs) const noexcept
      -> std::pair<Eigen::VectorX<AT>, AT>
  requires dco::mode<AT>::is_adjoint_type {
    static_assert(std::is_same_v<PT, typename dco::mode<AT>::passive_t>,
                  "Expect PT of class and underlying type of AT to be the same.");

    // Turn off tape; solve system using llt decomposition
    auto* tape = dco::tape(rhs(0));
    tape->switch_to_passive();

    assert(lhs.rows() == lhs.cols() && "`lhs` must be square.");
    assert(lhs.rows() == rhs.rows() && "`lhs` and `rhs` must have same size.");
    auto n = lhs.rows();

    // - Create passive versions of lhs and rhs ----------------------------------
    Eigen::MatrixX<PT> passive_lhs(n, n);
    for (Eigen::Index i = 0; i < n; ++i) {
      for (Eigen::Index j = 0; j < n; ++j) {
        passive_lhs(i, j) = dco::value(lhs(i, j));
      }
    }

    Eigen::VectorX<PT> passive_rhs(n);
    for (Eigen::Index i = 0; i < n; ++i) {
      passive_rhs(i) = dco::value(rhs(i));
    }
    // - Create passive versions of lhs and rhs ----------------------------------

    const auto llt = passive_lhs.llt();
    const auto L   = llt.matrixL();

    PT passive_log_det = 0.0;
    for (Eigen::Index i = 0; i < n; ++i) {
      passive_log_det += std::log(L(i, i));
    }
    passive_log_det *= 2;

    Eigen::VectorX<PT> passive_sol = llt.solve(passive_rhs);

    tape->switch_to_active();

    Eigen::VectorX<AT> sol(n);
    for (Eigen::Index i = 0; i < n; ++i) {
      sol(i) = passive_sol(i);
    }
    tape->register_variable(std::begin(sol), std::end(sol));

    AT log_det = passive_log_det;
    tape->register_variable(log_det);

    // From: Giles, M. B. "Collected matrix derivative results for forward and reverse mode AD."
    //
    // For solving linear system:
    //
    //      lhs * sol = rhs
    //  <=> sol = lhs^(-1) * rhs
    //
    //      rhs_adj = lhs^(-T) * sol_adj
    //      lhs_adj = -rhs_adj * sol^T
    //
    // For calculating log(det(lhs)):
    //
    //          det = det(lhs)
    //      log_det = log(det)
    //
    //      det_adj = (1 / det) * log_det_adj
    //      lhs_adj = det_adj * det * lhs^(-T)
    //
    //   => lhs_adj = log_det_adj * lhs^(-T)
    auto callback = [=, llt = std::move(llt)] {
      // TODO: Maybe the tape has to be switched to passive
      // For solving linear system:
      {
        // Get input `sol`:
        // sol is output of function -> input in adjoint interpretation
        Eigen::VectorX<PT> sol_adj(n);
        for (Eigen::Index i = 0; i < n; ++i) {
          sol_adj(i) = dco::derivative(sol(i));
        }

        // Calculate adjoints
        Eigen::VectorX<PT> rhs_adj = llt.solve(sol_adj);
        Eigen::MatrixX<PT> lhs_adj = -rhs_adj * passive_sol.transpose();

        // Set output `lhs`:
        // lhs is input of function -> output in adjoint interpretation
        for (Eigen::Index i = 0; i < n; ++i) {
          for (Eigen::Index j = 0; j <= i; ++j) {
            // Eigen llt uses only the lower triangular part of matrix
            dco::derivative(lhs(i, j)) += lhs_adj(i, j) + (i != j ? lhs_adj(j, i) : 0.0);
          }
        }

        // Set output `rhs`:
        // rhs is input of function -> output in adjoint interpretation
        for (Eigen::Index i = 0; i < n; ++i) {
          dco::derivative(rhs(i)) += rhs_adj(i);
        }
      }

      // For calculating log(det(lhs)):
      {
        PT log_det_adj = dco::derivative(log_det);

        Eigen::MatrixX<PT> lhs_adj = log_det_adj * llt.solve(Eigen::MatrixX<PT>::Identity(n, n));

        for (Eigen::Index i = 0; i < n; ++i) {
          for (Eigen::Index j = 0; j <= i; ++j) {
            dco::derivative(lhs(i, j)) += lhs_adj(i, j) + (i != j ? lhs_adj(j, i) : 0.0);
          }
        }
      }
    };
    tape->insert_callback(std::move(callback));

    return std::pair{sol, log_det};
  }
};

#endif  // MODEL_BASED_KRIGING_HPP_
