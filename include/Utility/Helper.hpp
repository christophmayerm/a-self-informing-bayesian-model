#ifndef EB_HELPER_HPP_
#define EB_HELPER_HPP_

#include <cerrno>
#include <cstring>
#include <fstream>
#include <limits>
#include <unistd.h>
#include <vector>

#include "Macros.hpp"

namespace EB::Utility {

// ------------------------------------------------------------------------------------------------
/// Consteval version of the square root.
/// Has to be evaluated at compile time, because it is much slower than the STL version.
/// From https://stackoverflow.com/questions/8622256/in-c11-is-sqrt-defined-as-constexpr
// TODO: Add `requires` statement that allows for floating-point and dco/c++ types
// old: requires std::is_floating_point_v<T>
template <typename T>
[[nodiscard]] consteval auto constexpr_sqrt(const T& x) noexcept -> T {
  constexpr auto sqrt_newton_raphson = [](const auto& local_sqrt_newton_raphson,
                                          const T& local_x,
                                          const T& curr,
                                          const T& prev) -> T {
    return curr == prev ? curr
                        : local_sqrt_newton_raphson(local_sqrt_newton_raphson,
                                                    local_x,
                                                    static_cast<T>(0.5) * (curr + local_x / curr),
                                                    curr);
  };

  return x >= static_cast<T>(0) && x < std::numeric_limits<T>::infinity()
             ? sqrt_newton_raphson(sqrt_newton_raphson, x, x, static_cast<T>(0))
             : std::numeric_limits<T>::quiet_NaN();
}

#ifdef __linux__

// - Struct containg virtual and physical memory usage ---------------------------------------------
struct MemoryUsage {
  uint64_t virtual_memory;
  uint64_t physical_memory;
};

// - Returns {virtual memory, physical memory} -----------------------------------------------------
[[nodiscard]] auto get_memory_usage() -> MemoryUsage {
  using namespace std::string_literals;

  std::ifstream stats("/proc/self/stat");
  if (!stats) {
    throw std::runtime_error("Could not open `/proc/self/stat` for reading: "s +
                             std::strerror(errno));
  }

  constexpr size_t num_skip = 22ul;
  for (size_t i = 0ul; i < num_skip; ++i) {
    std::string unused{};
    if (!(stats >> unused)) {
      throw std::runtime_error("Could not skip value in stream: "s + std::strerror(errno));
    }
  }

  uint64_t vsize = 0;
  int64_t rss    = 0;
  if (!(stats >> vsize >> rss)) {
    throw std::runtime_error(
        "Could not read info about virtual and physical memory usage from stream: "s +
        std::strerror(errno));
  }

  if (rss < 0) {
    throw std::runtime_error("Could not get valid value for `rss`; is less than zero ("s +
                             std::to_string(rss) + ")."s);
  }

  const auto page_size_bytes = sysconf(_SC_PAGESIZE);
  if (page_size_bytes < 1) {
    throw std::runtime_error("Could not get page size from `sysconf`: "s + std::strerror(errno));
  }

  return MemoryUsage{
      .virtual_memory  = vsize,
      .physical_memory = static_cast<uint64_t>(rss) * static_cast<uint64_t>(page_size_bytes),
  };
}

#endif  // __linux__

// - Transforms memory in bytes to a human readable string -----------------------------------------
[[nodiscard]] auto memory_to_string(uint64_t mem_in_bytes) noexcept -> std::string {
  using namespace std::string_literals;
  constexpr uint64_t step_factor = 1024;

  if (mem_in_bytes < step_factor) {
    return std::to_string(mem_in_bytes) + " B"s;
  }
  if (mem_in_bytes < step_factor * step_factor) {
    return std::to_string(mem_in_bytes / step_factor) + " kB"s;
  }
  if (mem_in_bytes < step_factor * step_factor * step_factor) {
    return std::to_string(mem_in_bytes / (step_factor * step_factor)) + " MB"s;
  }
  return std::to_string(mem_in_bytes / (step_factor * step_factor * step_factor)) + " GB"s;
}

// - Split string by given delimiter ---------------------------------------------------------------
void split_string(const std::string& str, char delimiter, std::vector<std::string>& result) {
  result.clear();
  std::stringstream str_stream(str);

  for (std::string sub_str{}; str_stream.good();) {
    std::getline(str_stream, sub_str, delimiter);
    result.push_back(sub_str);
  }
}

}  // namespace EB::Utility

#endif  // EB_HELPER_HPP_