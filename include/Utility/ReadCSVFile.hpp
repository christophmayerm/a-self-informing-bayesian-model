#ifndef EB_READ_CSV_FILE_HPP_
#define EB_READ_CSV_FILE_HPP_

#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Macros.hpp"
#include "Utility/Helper.hpp"

namespace EB::Utility {

// - Read csv file into 2D array; discard header ---------------------------------------------------
template <typename T>
[[nodiscard]] auto read_csv_file(const std::string& filename, char delimiter = ',')
    -> std::vector<std::vector<T>> {
  using namespace std::string_literals;

  std::ifstream in(filename);
  if (!in) {
    throw std::runtime_error(EB_ERROR_LOC() + ": Could not open file `"s + filename + "`: "s +
                             std::strerror(errno));
  }

  std::string line{};
  std::vector<std::string> split_line{};

  // Read header
  while (line.empty()) {
    std::getline(in, line);
  }
  split_string(line, delimiter, split_line);
  const auto num_cols = split_line.size();

  std::vector<std::vector<T>> data{};

  std::stringstream str_stream{};
  for (size_t line_counter = 2; in; ++line_counter) {
    std::getline(in, line);
    if (line.empty()) {
      continue;
    }

    split_string(line, delimiter, split_line);
    if (split_line.size() != num_cols) {
      throw std::runtime_error(EB_ERROR_LOC() + ": Invalid number of columns in line "s +
                               std::to_string(line_counter) + " of file `"s + filename +
                               "`. Expected "s + std::to_string(num_cols) + " columns, but got "s +
                               std::to_string(split_line.size()) + "."s);
    }

    data.emplace_back(num_cols);
    for (size_t i = 0; i < num_cols; ++i) {
      str_stream = std::stringstream(split_line[i]);
      str_stream >> data.back()[i];
    }
  }

  return data;
}

}  // namespace EB::Utility

#endif  // EB_READ_CSV_FILE_HPP_