#include <fstream>
#include <iostream>

#include <Eigen/Dense>

#include <dco.hpp>

// #define EB_USE_EXPLICIT_EULER
#include "Macros.hpp"
#include "RandomValue.hpp"
#include "Utility/Helper.hpp"

#include "LikelihoodFunctions/LVLogLikelihood.hpp"

#if 1

auto main() -> int {
  using Float    = double;
  using dco_mode = dco::ga1s<Float>;
  using dco_type = dco_mode::type;

  dco::smart_tape_ptr_t<dco_mode> tape;

  const Eigen::Vector<dco_type, LV::LV_SYSTEM_SIZE> x0 = {34.91, 3.86};
  tape->register_variable(std::cbegin(x0), std::cend(x0));

  const Eigen::Vector<dco_type, LV::LV_PARAMETER_SIZE> p = {0.48, 0.02, 0.93, 0.03};
  tape->register_variable(std::cbegin(p), std::cend(p));

  const Float t_end      = 100.0;
  const size_t num_steps = 1'000ul;

  std::vector<Eigen::Vector<dco_type, LV::LV_SYSTEM_SIZE>> xs{};
  std::vector<Float> ts{};
  LV::solve_lotka_volterra_system(x0, p, xs, ts, t_end, num_steps);

  std::cout << "x0         = " << x0.transpose() << '\n';
  std::cout << "p          = " << p.transpose() << '\n';
  std::cout << "t_end      = " << t_end << '\n';
  std::cout << "num_steps  = " << num_steps << '\n';
  const auto& x_end = xs.back();
  std::cout << "x_end      = " << xs.back().transpose() << '\n';

  std::cout << "------------------------------------------------------------\n";

  // auto pos = tape->get_position();
  {
    dco::derivative(x_end(0)) = 1.0;
    tape->interpret_adjoint();
    std::cout << "dx_end(0)/dx0 = " << dco::derivative(x0(0)) << ' ' << dco::derivative(x0(1))
              << '\n';
    std::cout << "dx_end(0)/dp  = " << dco::derivative(p(0)) << ' ' << dco::derivative(p(1)) << ' '
              << dco::derivative(p(2)) << ' ' << dco::derivative(p(3)) << '\n';

    std::cout << "sizeof tape stack: "
              << EB::Utility::memory_to_string(dco::size_of(tape, tape->size_of_stack)) << '\n';
    std::cout << "capacity tape stack: "
              << EB::Utility::memory_to_string(dco::size_of(tape, tape->size_of_stack)) << '\n';
    std::cout << "sizeof adjoint vector: "
              << EB::Utility::memory_to_string(
                     dco::size_of(tape, tape->size_of_internal_adjoint_vector))
              << '\n';

    tape->zero_adjoints();
  }
  std::cout << "------------------------------------------------------------\n";
  {
    dco::derivative(x_end(1)) = 1.0;
    tape->interpret_adjoint();
    std::cout << "dx_end(1)/dx0 = " << dco::derivative(x0(0)) << ' ' << dco::derivative(x0(1))
              << '\n';
    std::cout << "dx_end(1)/dp  = " << dco::derivative(p(0)) << ' ' << dco::derivative(p(1)) << ' '
              << dco::derivative(p(2)) << ' ' << dco::derivative(p(3)) << '\n';

    std::cout << "sizeof tape stack: "
              << EB::Utility::memory_to_string(dco::size_of(tape, tape->size_of_stack)) << '\n';
    std::cout << "capacity tape stack: "
              << EB::Utility::memory_to_string(dco::size_of(tape, tape->size_of_stack)) << '\n';
    std::cout << "sizeof adjoint vector: "
              << EB::Utility::memory_to_string(
                     dco::size_of(tape, tape->size_of_internal_adjoint_vector))
              << '\n';
  }

  constexpr auto filename = "lv_results.txt";
  std::ofstream out(filename);
  if (!out) {
    EB_PANIC("Could not open file `" << filename << "`: " << std::strerror(errno));
  }

  for (size_t i = 0; i < xs.size(); ++i) {
    out << ts.at(i) << ' ' << xs.at(i).transpose() << '\n';
  }

  std::cout << "Dumped results to `" << filename << "`\n";
}

#else

auto main() -> int {
  using Float = double;

  const Eigen::Vector<Float, LV::LV_SYSTEM_SIZE> x0   = {34.91, 3.86};
  const Eigen::Vector<Float, LV::LV_PARAMETER_SIZE> p = {0.48, 0.02, 0.93, 0.03};

  const Float t_end      = 100.0;
  const size_t num_steps = 1'000ul;

  std::vector<Eigen::Vector<Float, LV::LV_SYSTEM_SIZE>> xs{};
  std::vector<Float> ts{};

  LV::solve_lotka_volterra_system(x0, p, xs, ts, t_end, num_steps);

  std::cout << "x0         = " << x0.transpose() << '\n';
  std::cout << "p          = " << p.transpose() << '\n';
  std::cout << "t_end      = " << t_end << '\n';
  std::cout << "num_steps  = " << num_steps << '\n';
  std::cout << "x_end      = " << xs.back().transpose() << '\n';

  constexpr auto filename = "lv_results.txt";
  std::ofstream out(filename);
  if (!out) {
    EB_PANIC("Could not open file `" << filename << "`: " << std::strerror(errno));
  }

  for (size_t i = 0; i < xs.size(); ++i) {
    out << ts.at(i) << ' ' << xs.at(i).transpose() << '\n';
  }

  std::cout << "Dumped results to `" << filename << "`\n";
}

#endif
