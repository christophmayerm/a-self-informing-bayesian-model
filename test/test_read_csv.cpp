#include <gtest/gtest.h>

#include <cstdio>
#include <filesystem>

#include "Macros.hpp"
#include "Utility/ReadCSVFile.hpp"

using namespace std::string_literals;

TEST(TestReadCSV, SplitString) {
  std::string str = "hello,world,abc,123,456"s;
  std::vector<std::string> split_str;
  {
    EB::Utility::split_string(str, ',', split_str);
    ASSERT_EQ(split_str.size(), 5ul);
    EXPECT_EQ(split_str[0], "hello"s);
    EXPECT_EQ(split_str[1], "world"s);
    EXPECT_EQ(split_str[2], "abc"s);
    EXPECT_EQ(split_str[3], "123"s);
    EXPECT_EQ(split_str[4], "456"s);
  }

  {
    EB::Utility::split_string(str, 'o', split_str);
    ASSERT_EQ(split_str.size(), 3ul);
    EXPECT_EQ(split_str[0], "hell"s);
    EXPECT_EQ(split_str[1], ",w"s);
    EXPECT_EQ(split_str[2], "rld,abc,123,456"s);
  }

  {
    EB::Utility::split_string(str, 'z', split_str);
    ASSERT_EQ(split_str.size(), 1ul);
    EXPECT_EQ(split_str[0], "hello,world,abc,123,456"s);
  }
}

TEST(TestReadCSV, SplitStringEmpty) {
  std::string str{};
  std::vector<std::string> split_str;

  EB::Utility::split_string(str, ',', split_str);

  ASSERT_EQ(split_str.size(), 1ul);
  EXPECT_TRUE(split_str[0].empty());
}

TEST(TestReadCSV, ReadCSVFile) {
  const std::string tmp_file = std::filesystem::temp_directory_path() / std::tmpnam(nullptr);

  {
    {
      std::ofstream out(tmp_file);
      ASSERT_TRUE(out) << "Could not open temporary file `" << tmp_file
                       << "`: " << std::strerror(errno);
      out << "a,b,c,d,e,f\n";
      out << '\n';
      out << "1,2,3,4,5,6\n";
      out << '\n';
      out << "-1,-2,-3,-4,-5,-6\n";
      out << '\n';
    }

    auto data = EB::Utility::read_csv_file<int>(tmp_file);

    ASSERT_EQ(data.size(), 2ul);
    const auto line0 = std::vector<int>{1, 2, 3, 4, 5, 6};
    EXPECT_EQ(data[0], line0);
    const auto line1 = std::vector<int>{-1, -2, -3, -4, -5, -6};
    EXPECT_EQ(data[1], line1);
  }

  {
    {
      std::ofstream out(tmp_file);
      ASSERT_TRUE(out) << "Could not open temporary file `" << tmp_file
                       << "`: " << std::strerror(errno);
      out << "a,b,c,d,e,f\n";
      out << '\n';
      out << "1.0,2.0,3.0,4.0,5.0,6.0\n";
      out << '\n';
      out << '\n';
      out << '\n';
      out << "-1.0,-2.0,-3.0,-4.0,-5.0,-6.0\n";
      out << '\n';
    }

    auto data = EB::Utility::read_csv_file<double>(tmp_file);

    ASSERT_EQ(data.size(), 2ul);
    const auto line0 = std::vector<double>{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    EXPECT_EQ(data[0], line0);
    const auto line1 = std::vector<double>{-1.0, -2.0, -3.0, -4.0, -5.0, -6.0};
    EXPECT_EQ(data[1], line1);
  }
}

TEST(TestReadCSV, ReadCSVFileToString) {
  const std::string tmp_file = std::filesystem::temp_directory_path() / std::tmpnam(nullptr);

  {
    {
      std::ofstream out(tmp_file);
      ASSERT_TRUE(out) << "Could not open temporary file `" << tmp_file
                       << "`: " << std::strerror(errno);
      out << "a,b,c,d,e,f\n";
      out << '\n';
      out << "1.0,2.0,abcdef,4.0,5.0,6.0\n";
      out << '\n';
      out << "-1.0,-2.0,-3.0,-4.0,-5.0,-6.0\n";
      out << '\n';
    }

    auto data = EB::Utility::read_csv_file<std::string>(tmp_file);
    ASSERT_EQ(data.size(), 2ul);
    const auto line0 = std::vector<std::string>{"1.0"s, "2.0"s, "abcdef"s, "4.0"s, "5.0"s, "6.0"s};
    EXPECT_EQ(data[0], line0);
    const auto line1 =
        std::vector<std::string>{"-1.0"s, "-2.0"s, "-3.0"s, "-4.0"s, "-5.0"s, "-6.0"s};
    EXPECT_EQ(data[1], line1);
  }
}

TEST(TestReadCSV, ReadCSVFileInvalidNumCols) {
  const std::string tmp_file = std::filesystem::temp_directory_path() / std::tmpnam(nullptr);

  {
    {
      std::ofstream out(tmp_file);
      ASSERT_TRUE(out) << "Could not open temporary file `" << tmp_file
                       << "`: " << std::strerror(errno);
      out << "a,b,c,d,e,f\n";
      out << '\n';
      out << "1,2,3,4,5\n";
      out << '\n';
      out << "-1,-2,-3,-4,-5,-6\n";
      out << '\n';
    }

    EXPECT_THROW(auto data = EB::Utility::read_csv_file<int>(tmp_file);, std::runtime_error);
  }
}

TEST(TestReadCSV, ReadCSVFileInvalidData) {
  const std::string tmp_file = std::filesystem::temp_directory_path() / std::tmpnam(nullptr);
  {
    std::ofstream out(tmp_file);
    ASSERT_TRUE(out) << "Could not open temporary file `" << tmp_file
                     << "`: " << std::strerror(errno);
    out << "a,b,c,d,e,f\n";
    out << '\n';
    out << "abc,2,3,4,5,6\n";
    out << '\n';
    out << "-1,-2,-3,-4,-5,-6\n";
    out << '\n';
  }

  {
    auto data = EB::Utility::read_csv_file<int>(tmp_file);
    ASSERT_EQ(data.size(), 2ul);
    const auto line0 = std::vector<int>{0, 2, 3, 4, 5, 6};
    EXPECT_EQ(data[0], line0);
    const auto line1 = std::vector<int>{-1, -2, -3, -4, -5, -6};
    EXPECT_EQ(data[1], line1);
  }

  {
    auto data = EB::Utility::read_csv_file<double>(tmp_file);
    ASSERT_EQ(data.size(), 2ul);
    const auto line0 = std::vector<double>{0.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    EXPECT_EQ(data[0], line0);
    const auto line1 = std::vector<double>{-1.0, -2.0, -3.0, -4.0, -5.0, -6.0};
    EXPECT_EQ(data[1], line1);
  }
}

TEST(TestReadCSV, ReadCSVFileInvalidFile) {
  const std::string invalid_file = std::filesystem::temp_directory_path() / std::tmpnam(nullptr) /
                                   std::tmpnam(nullptr) / std::tmpnam(nullptr);

  EXPECT_THROW(auto data = EB::Utility::read_csv_file<int>(invalid_file);, std::runtime_error);
}

TEST(TestReadCSV, ReadCSVFileMissingHeader) {
  const std::string tmp_file = std::filesystem::temp_directory_path() / std::tmpnam(nullptr);

  {
    {
      std::ofstream out(tmp_file);
      ASSERT_TRUE(out) << "Could not open temporary file `" << tmp_file
                       << "`: " << std::strerror(errno);
      out << "1,2,3,4,5,6\n";
      out << '\n';
      out << "-1,-2,-3,-4,-5,-6\n";
      out << '\n';
    }

    auto data = EB::Utility::read_csv_file<int>(tmp_file);

    ASSERT_EQ(data.size(), 1ul);
    const auto line0 = std::vector<int>{-1, -2, -3, -4, -5, -6};
    EXPECT_EQ(data[0], line0);
  }
}

TEST(TestReadCSV, ReadCSVFileStartsWithEmptyLine) {
  const std::string tmp_file = std::filesystem::temp_directory_path() / std::tmpnam(nullptr);

  {
    {
      std::ofstream out(tmp_file);
      ASSERT_TRUE(out) << "Could not open temporary file `" << tmp_file
                       << "`: " << std::strerror(errno);
      out << '\n';
      out << '\n';
      out << '\n';
      out << '\n';
      out << "a,b,c,d,e,f\n";
      out << '\n';
      out << "1,2,3,4,5,6\n";
      out << '\n';
      out << "-1,-2,-3,-4,-5,-6\n";
      out << '\n';
    }

    auto data = EB::Utility::read_csv_file<int>(tmp_file);

    ASSERT_EQ(data.size(), 2ul);
    const auto line0 = std::vector<int>{1, 2, 3, 4, 5, 6};
    EXPECT_EQ(data[0], line0);
    const auto line1 = std::vector<int>{-1, -2, -3, -4, -5, -6};
    EXPECT_EQ(data[1], line1);
  }
}
