#ifndef EB_PROGRESS_BAR_HPP_
#define EB_PROGRESS_BAR_HPP_

#include <cmath>
#include <iomanip>
#include <iostream>

namespace EB::Utility {

class ProgressBar {
  size_t m_max_progress;
  size_t m_length;

  size_t m_progress{0ul};

  char m_done_char{'#'};
  char m_not_done_char{'.'};

 public:
  constexpr ProgressBar(size_t max_prog, size_t len) noexcept
      : m_max_progress(max_prog),
        m_length(len) {}

  void update() noexcept {
    m_progress = std::min(m_progress + 1, m_max_progress);
    show();
  }

  void show() const noexcept {
    const size_t done_length = (m_length * m_progress) / m_max_progress;
    const size_t done_prct   = (100ul * m_progress) / m_max_progress;
    std::cout << "\r[";
    std::cout << std::string(done_length, m_done_char);
    std::cout << std::string(m_length - done_length, m_not_done_char);
    std::cout << "] ";
    std::cout << done_prct << "%" << std::flush;
  }

  constexpr void set_chars(char done_c, char not_done_c) noexcept {
    m_done_char     = done_c;
    m_not_done_char = not_done_c;
  }
};

}  // namespace EB::Utility

#endif  // EB_PROGRESS_BAR_HPP_