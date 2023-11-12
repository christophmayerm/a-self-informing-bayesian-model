#ifndef EB_MACROS_HPP_
#define EB_MACROS_HPP_

#include <iostream>
#include <filesystem>

#if __has_include(<source_location>)
#include <source_location>
#endif

#if __cpp_lib_source_location >= 201907L

[[nodiscard]] inline auto
EB_ERROR_LOC(const std::source_location loc = std::source_location::current()) -> std::string {
  using namespace std::literals;
  return "`"s + std::string{loc.function_name()} + "` (\033[95m"s +
         std::string{std::filesystem::path(loc.file_name()).filename()} + ":"s +
         std::to_string(loc.line()) + ":"s + std::to_string(loc.column()) + "\033[0m)"s;
}

#else

// NOLINTBEGIN(cppcoreguidelines-macro-usage,cppcoreguidelines-pro-bounds-array-to-pointer-decay)
#define EB_ERROR_LOC()                                                                             \
  ("`" + std::string(__func__) + "` (\033[95m" +                                                   \
   std::string(std::filesystem::path(__FILE__).filename()) + ":" + std::to_string(__LINE__) +      \
   "\033[0m)")
// NOLINTEND(cppcoreguidelines-macro-usage,cppcoreguidelines-pro-bounds-array-to-pointer-decay)

#endif

// NOLINTBEGIN(cppcoreguidelines-macro-usage,cppcoreguidelines-pro-bounds-array-to-pointer-decay,bugprone-macro-parentheses)
#define EB_INFO(msg) std::cout << "\033[32m[INFO]\033[0m " << msg << '\n'

#define EB_TODO(msg)                                                                               \
  do {                                                                                             \
    std::cerr << "\033[35m[TODO]\033[0m " << EB_ERROR_LOC() << ": " << msg << '\n';                \
    std::exit(2);                                                                                  \
  } while (false)

#define EB_PANIC(msg)                                                                              \
  do {                                                                                             \
    std::cerr << "\033[31m[ERROR]\033[0m " << EB_ERROR_LOC() << ": " << msg << '\n';               \
    std::exit(1);                                                                                  \
  } while (false)

#define EB_DEBUG_PRINT(x) std::cerr << "\033[94m[DEBUG]\033[0m " << #x << " = " << (x) << '\n'

#define EB_STRINGIFY(s) EB_XSTRINGIFY(s)
#define EB_XSTRINGIFY(s) #s
// NOLINTEND(cppcoreguidelines-macro-usage,cppcoreguidelines-pro-bounds-array-to-pointer-decay,bugprone-macro-parentheses)

#endif  // EB_MACROS_HPP_
