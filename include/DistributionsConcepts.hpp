#ifndef EB_DISTRIBUTION_CONCEPTS_HPP_
#define EB_DISTRIBUTION_CONCEPTS_HPP_

#include <concepts>
#include <string>
#include <type_traits>

#include <dco.hpp>

namespace EB::Distribution {

template <typename DT>
concept Type = requires(DT d) {
  std::is_same_v<decltype(d.pdf(std::declval<float>())), float>;
  std::is_same_v<decltype(d.pdf(std::declval<double>())), double>;
  std::is_same_v<decltype(d.pdf(std::declval<dco::gt1s<float>::type>())), dco::gt1s<float>::type>;
  std::is_same_v<decltype(d.pdf(std::declval<dco::ga1s<float>::type>())), dco::ga1s<float>::type>;
  std::is_same_v<decltype(d.pdf(std::declval<dco::gt1s<double>::type>())), dco::gt1s<double>::type>;
  std::is_same_v<decltype(d.pdf(std::declval<dco::ga1s<double>::type>())), dco::ga1s<double>::type>;

  std::is_same_v<decltype(d.log_pdf(std::declval<float>())), float>;
  std::is_same_v<decltype(d.log_pdf(std::declval<double>())), double>;
  std::is_same_v<decltype(d.log_pdf(std::declval<dco::gt1s<float>::type>())),
                 dco::gt1s<float>::type>;
  std::is_same_v<decltype(d.log_pdf(std::declval<dco::ga1s<float>::type>())),
                 dco::ga1s<float>::type>;
  std::is_same_v<decltype(d.log_pdf(std::declval<dco::gt1s<double>::type>())),
                 dco::gt1s<double>::type>;
  std::is_same_v<decltype(d.log_pdf(std::declval<dco::ga1s<double>::type>())),
                 dco::ga1s<double>::type>;

  std::is_convertible_v<decltype(d.distribution_name()), std::string>;
};

}  // namespace EB::Distribution

#endif  // EB_DISTRIBUTION_CONCEPTS_HPP_