/**
dco/c++ v3.7.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

namespace dco {
typedef index_t_DEFINE index_t;
typedef index_t DCO_TAPE_INT;
inline index_t& stce_9752(index_t& stce_9753) { return stce_9753; }
inline const index_t& stce_9752(const index_t& stce_9753) { return stce_9753; }
typedef index_t_DEFINE DCO_INTEGRAL_TAPE_INT;
static const bool stce_9754 = true;
static const bool HAS_TAPE_ACTIVITY_CHECK = true;
static const bool stce_9755 = true;
static const bool stce_9756 = false;
static const bool stce_9757 = true;
template <class stce_9758, class stce_9759 = stce_9758, class stce_9760 = stce_9758> struct types_config_t {
  typedef stce_9758 value_t;
  typedef stce_9759 stce_9761;
  typedef stce_9760 stce_9762;
};
} // namespace dco

namespace dco {
typedef unsigned long mem_long_t;
inline size_t get_allocation_size(size_t stce_9763);
struct memory_model {
  enum TYPE { stce_9764, BLOB_TAPE, BLOB_TAPE_SPLINT, CHUNK_TAPE, stce_9765, stce_9766, stce_9767, stce_9768 };
};
namespace internal {
template <class stce_9769, class stce_9770> struct active_type;
template <class stce_9769, class DATA_TYPE> struct stce_9771;
template <class stce_9769, class stce_9772, class stce_9773, typename = void> struct stce_9774;
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename = void> struct stce_9777;
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename = void> struct stce_9778;
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename = void> struct stce_9779;
template <typename stce_9780, typename enable_if = void> struct trait_value;
template <typename stce_9780, typename stce_9781 = void, typename enable_if = void> struct stce_9782;
template <typename stce_9780, typename stce_9781 = void, typename enable_if = void> struct stce_9783;
template <typename stce_9780, typename stce_9781 = void, typename enable_if = void> struct stce_9784;
template <typename stce_9780, typename enable_if = void> struct stce_9785;
template <typename stce_9780, typename enable_if = void> struct stce_9786;
template <typename stce_9780, typename enable_if = void> struct stce_9787;
template <enum memory_model::TYPE MEMORY_MODEL, class stce_9788,
          enum memory_model::TYPE stce_9789 = memory_model::stce_9764>
class tape;
template <typename stce_9780> struct stce_9790 {};
template <memory_model::TYPE MEMORY_MODEL, typename stce_9788, memory_model::TYPE stce_9789>
struct stce_9790<tape<MEMORY_MODEL, stce_9788, stce_9789>> {
  typedef typename stce_9788::stce_9761 type;
};
template <class stce_9791, typename stce_9792> class adjoint_vector_lazy;
template <class stce_9793> struct jacobian_preaccumulator_t;
} // namespace internal
template <typename stce_9780> struct mode;
enum stce_9794 { stce_9795, stce_9796, stce_9797, stce_9798, stce_9799, stce_9800, stce_9801, stce_9802 };
template <typename stce_9780> typename internal::stce_9786<stce_9780>::stce_9803 tape(const stce_9780&);
template <typename stce_9769> struct stce_9804 {
  typedef stce_9769 active_value_t;
  typedef stce_9769 value_t;
  typedef value_t scalar_value_t;
  typedef stce_9769 passive_t;
  typedef stce_9769 scalar_passive_t;
  static const int order = 0;
};
namespace vector_ns {
template <typename stce_9805, size_t stce_9806> struct alignas(alignof(stce_9805[stce_9806])) vector_t;
}
namespace folding {
template <typename stce_9780, typename enable_if = void> struct is_zero_trait;
template <typename stce_9780> bool is_zero(const stce_9780& stce_9807);
} // namespace folding
} // namespace dco

extern "C" {
extern int stce_1000002(int stce_9808 = false);
extern void* stce_1000001(size_t* stce_9809, int);
extern void* stce_999999(size_t, int);
extern DCO_INT32 stce_1000003(DCO_INT32* stce_9810);
extern DCO_INT64 stce_1000004(DCO_INT64* stce_9810);
extern void stce_1000000(void* stce_9811);
}
template <typename stce_9780> inline stce_9780 stce_9812(stce_9780& stce_9810);
template <> inline DCO_INT32 stce_9812<DCO_INT32>(DCO_INT32& stce_9810) { return stce_1000003(&stce_9810); }
template <> inline DCO_INT64 stce_9812<DCO_INT64>(DCO_INT64& stce_9810) { return stce_1000004(&stce_9810); }

namespace dco {
class exception {
public:
  template <typename stce_9813>
  static stce_9813 create(std::string stce_9814, std::string stce_9815 = "", int stce_9816 = 0) {
    std::stringstream stce_9817;
    stce_9817 << "--- dco/c++ --- " << stce_9814;
    if (stce_9815 != "")
      stce_9817 << " --- " << stce_9815 << ":" << stce_9816 << ".";
    DCO_LOG(dco::logERROR) << "EXCEPTION thrown: " << stce_9817.str();
    return stce_9813(stce_9817.str());
  }
  template <typename stce_9813>
  static stce_9813 stce_9818(std::string stce_9814, std::string stce_9815 = "", int stce_9816 = 0) {
    std::stringstream stce_9817;
    stce_9817 << "--- dco/c++ --- " << stce_9814;
    if (stce_9815 != "")
      stce_9817 << " --- " << stce_9815 << ":" << stce_9816 << ".";
    DCO_LOG(dco::logERROR) << "EXCEPTION thrown: " << stce_9817.str();
    return stce_9813();
  }
};
} // namespace dco
namespace dco {
template <memory_model::TYPE MEMORY_MODEL, class stce_9788, memory_model::TYPE stce_9789>
bool is_null(internal::tape<MEMORY_MODEL, stce_9788, stce_9789>* tape) {
  return (tape == NULL);
}
static unsigned int stce_9819 = 0xABCDE;
static unsigned int stce_9820(unsigned int* stce_9821, unsigned int stce_9822) {
  unsigned int stce_9823;
  stce_9823 = *stce_9821 & 1;
  *stce_9821 >>= 1;
  if (stce_9823 == 1)
    *stce_9821 = stce_9822;
  return *stce_9821;
}
static inline double stce_9824() {
  stce_9820(&stce_9819, 0xB4BCD35C);
  unsigned int stce_9825 = stce_9820(&stce_9819, 0xB4BCD35C);
  return double(stce_9825) / RAND_MAX;
}
template <class stce_9780> std::string type_name() {
  typedef typename std::remove_reference<stce_9780>::type stce_9826;
  std::unique_ptr<char, void (*)(void*)> stce_9827(
      abi::__cxa_demangle(typeid(stce_9826).name(), nullptr, nullptr, nullptr), std::free);
  std::string stce_9828 = stce_9827 != nullptr ? stce_9827.get() : typeid(stce_9826).name();
  if (std::is_const<stce_9826>::value)
    stce_9828 += " const";
  if (std::is_volatile<stce_9826>::value)
    stce_9828 += " volatile";
  if (std::is_lvalue_reference<stce_9780>::value)
    stce_9828 += "&";
  else if (std::is_rvalue_reference<stce_9780>::value)
    stce_9828 += "&&";
  return stce_9828;
}
namespace internal {
template <typename stce_9780, bool> struct stce_9829 { typedef stce_9780 type; };
template <typename stce_9780> struct stce_9829<stce_9780, true> { typedef stce_9780& type; };
} // namespace internal
namespace helper {
template <typename> struct stce_9830 { static constexpr bool value = false; };
template <typename stce_9831, typename... stce_9832> void stce_9833(int64_t, stce_9831&&, stce_9832&&...) {
  stce_9834(stce_9830<stce_9831>::value, "--- dco/c++ --- The user-supplied callable provided as an argument to "
                                         "interpret_adjoint*() has wrong interface.");
}
template <typename stce_9831, typename... stce_9832>
auto stce_9833(int, stce_9831&& stce_9835, stce_9832&&... stce_9836)
    -> decltype(stce_9835(std::forward<stce_9832>(stce_9836)...)) {
  stce_9835(stce_9836...);
}
static bool stce_9837 = true;
template <typename stce_9780> struct stce_9838 { static const bool stce_9753 = true; };
template <typename stce_9780> struct type_identity { typedef stce_9780 type; };
template <class stce_9839, const size_t stce_9840 = 1> struct valvec {
  static const size_t stce_9841 = stce_9840;
  typedef stce_9839 value_t;
  stce_9839 stce_9842[stce_9840];
  void stce_9843(const stce_9839& stce_9844) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] = stce_9844;
  }
  template <typename stce_9780>
  valvec(const stce_9780& stce_9807, typename std::enable_if<std::is_fundamental<stce_9780>::value, int>::type = 0) {
    stce_9843(stce_9807);
  }
  template <typename stce_9780 = stce_9839>
  valvec(const stce_9839& stce_9807, typename std::enable_if<!std::is_fundamental<stce_9780>::value, int>::type = 0) {
    stce_9843(stce_9807);
  }
  valvec() { stce_9843(0); }
  stce_9839& operator[](const size_t stce_9810) { return stce_9842[stce_9810]; }
  const stce_9839& operator[](const size_t stce_9810) const { return stce_9842[stce_9810]; }
  valvec& operator=(const std::array<stce_9839, stce_9840>& stce_9846) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] = stce_9846[stce_9845];
    return *this;
  }
  valvec& operator=(const std::vector<stce_9839>& stce_9846) {
    if (stce_9846.size() != stce_9840) {
      throw exception::create<std::runtime_error>("Assignment from std::vector not possible, non-matching sizes.",
                                                  "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                  "dco_cpp_make_release/dco_cpp_dev/src/dco_helper.hpp",
                                                  151);
    }
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] = stce_9846[stce_9845];
    return *this;
  }
  template <typename stce_9780>
  typename std::enable_if<std::is_fundamental<stce_9780>::value, valvec>::type& operator=(const stce_9780& stce_9846) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] = stce_9846;
    return *this;
  }
  template <typename stce_9780 = stce_9839>
  typename std::enable_if<!std::is_fundamental<stce_9780>::value, valvec>::type& operator=(const stce_9839& stce_9846) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] = stce_9846;
    return *this;
  }
  valvec& operator+=(const valvec& stce_9846) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] += stce_9846.stce_9842[stce_9845];
    return *this;
  }
  valvec& operator+=(const std::array<stce_9839, stce_9840>& stce_9846) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] += stce_9846[stce_9845];
    return *this;
  }
  valvec& operator+=(const std::vector<stce_9839>& stce_9846) {
    if (stce_9846.size() != stce_9840) {
      throw exception::create<std::runtime_error>("Increment with std::vector not possible, non-matching sizes.",
                                                  "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                  "dco_cpp_make_release/dco_cpp_dev/src/dco_helper.hpp",
                                                  180);
    }
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9842[stce_9845] += stce_9846[stce_9845];
    return *this;
  }
  operator std::array<stce_9839, stce_9840>() {
    std::array<stce_9839, stce_9840> stce_9847;
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9847[stce_9845] = stce_9842[stce_9845];
    return stce_9847;
  }
  operator std::vector<stce_9839>() {
    std::vector<stce_9839> stce_9847(stce_9840);
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
      stce_9847[stce_9845] = stce_9842[stce_9845];
    return stce_9847;
  }
};
template <typename stce_9839, typename stce_9848, const size_t stce_9840>
bool operator==(valvec<stce_9839, stce_9840> const& stce_9849, valvec<stce_9848, stce_9840> const& stce_9850) {
  for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845) {
    if (stce_9849[stce_9845] != stce_9850[stce_9845]) {
      return false;
    }
  }
  return true;
}
template <class stce_9780> struct vecsize_info {
  static const size_t vecsize;
  typedef stce_9780 stce_9851;
};
template <class stce_9780> const size_t vecsize_info<stce_9780>::vecsize = 1;
template <class stce_9839, size_t stce_9840> struct vecsize_info<valvec<stce_9839, stce_9840>> {
  static const size_t vecsize;
  typedef stce_9839 stce_9851;
};
template <class stce_9839, size_t stce_9840>
const size_t vecsize_info<valvec<stce_9839, stce_9840>>::vecsize = stce_9840;
template <class stce_9839, size_t stce_9840>
static inline valvec<stce_9839, stce_9840> operator+(const valvec<stce_9839, stce_9840>& stce_9852,
                                                     const valvec<stce_9839, stce_9840>& stce_9853) {
  valvec<stce_9839, stce_9840> stce_9847;
  for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
    stce_9847.stce_9842[stce_9845] = stce_9852.stce_9842[stce_9845] + stce_9853.stce_9842[stce_9845];
  return stce_9847;
}
template <class stce_9839, size_t stce_9840>
static inline valvec<stce_9839, stce_9840> operator*(const valvec<stce_9839, stce_9840>& stce_9852,
                                                     const valvec<stce_9839, stce_9840>& stce_9853) {
  valvec<stce_9839, stce_9840> stce_9847;
  for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
    stce_9847.stce_9842[stce_9845] = stce_9852.stce_9842[stce_9845] * stce_9853.stce_9842[stce_9845];
  return stce_9847;
}
template <class stce_9839, class stce_9848, size_t stce_9840>
static inline valvec<stce_9839, stce_9840> operator*(const stce_9848& stce_9854,
                                                     const valvec<stce_9839, stce_9840>& stce_9855) {
  valvec<stce_9839, stce_9840> stce_9847;
  for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
    stce_9847.stce_9842[stce_9845] = static_cast<stce_9839>(stce_9855.stce_9842[stce_9845] * stce_9854);
  return stce_9847;
}
template <class stce_9839, class stce_9848, size_t stce_9840>
static inline valvec<stce_9839, stce_9840> operator*(const valvec<stce_9839, stce_9840>& stce_9852,
                                                     const stce_9848& stce_9853) {
  valvec<stce_9839, stce_9840> stce_9847;
  for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845)
    stce_9847.stce_9842[stce_9845] = static_cast<stce_9839>(stce_9852.stce_9842[stce_9845] * stce_9853);
  return stce_9847;
}
template <class stce_9839, size_t stce_9840>
static inline std::ostream& operator<<(std::ostream& out, const valvec<stce_9839, stce_9840>& stce_9807) {
  out << "(";
  for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845) {
    out << stce_9807.stce_9842[stce_9845];
    if (stce_9845 != stce_9840 - 1) {
      out << ";";
    }
  }
  out << ")";
  return out;
}
} // namespace helper
template <typename TYPE> class stce_9856 {
  const TYPE& stce_9780;

public:
  stce_9856(const TYPE& stce_9857) : stce_9780(stce_9857) {}
  template <typename stce_9858> stce_9858* create() const { return new stce_9858(stce_9780); }
};
template <> class stce_9856<void*> {
public:
  stce_9856(void* stce_9846) { (void)stce_9846; }
  template <typename stce_9858> stce_9858* create() const { return new stce_9858(); }
};
class stce_9859 {
  std::ofstream stce_9860;
  std::string stce_9861;
  std::string stce_9862;
  std::stringstream stce_9863;
  std::stringstream stce_9864;

public:
  stce_9859(const std::string& filename) : stce_9861("digraph {\n"), stce_9862("\n}\n") {
    stce_9863.clear();
    stce_9864.clear();
    stce_9860.open(filename.c_str());
  }
  void stce_9865(std::vector<index_t>& stce_9866, std::vector<index_t>& stce_9867, index_t stce_9868) {
    stce_9863 << stce_9868 + 1 << "[shape=box,label=\"(" << stce_9868 + 1 << ", ext. function)\",color=\"red\"]\n";
    for (std::vector<index_t>::iterator stce_9845 = stce_9866.begin(); stce_9845 != stce_9866.end(); ++stce_9845) {
      stce_9864 << *stce_9845 << " -> " << stce_9868 << "[label=\"unknown"
                << "\",color=\"red\"]\n";
    }
    for (std::vector<index_t>::iterator stce_9845 = stce_9867.begin(); stce_9845 != stce_9867.end(); ++stce_9845) {
      stce_9864 << stce_9868 << " -> " << *stce_9845 << "[label=\"unknown"
                << "\",color=\"red\"]\n";
    }
  }
  void stce_9869(index_t stce_9868) {
    if (stce_9868 == 0) {
      return;
    }
    stce_9863 << stce_9868 << "[shape=box,label=\"" << stce_9868 << "\", color=\"green\"]\n";
  }
  template <typename stce_9870> void stce_9869(index_t stce_9868, stce_9870 adjoint) {
    if (stce_9868 == 0) {
      return;
    }
    stce_9863 << stce_9868 << "[shape=box,label=\"(" << stce_9868 << ", " << adjoint << ")\", color=\"green\"]\n";
  }
  template <typename stce_9870> void stce_9871(index_t stce_9872, index_t stce_9873, stce_9870 stce_9874) {
    if (stce_9872 == 0 || stce_9873 == 0) {
      return;
    }
    stce_9864 << stce_9872 << " -> " << stce_9873 << "[label=\"" << stce_9874 << "\"]\n";
  }
  ~stce_9859() {
    stce_9860 << stce_9861;
    stce_9860 << stce_9863.str();
    stce_9860 << stce_9864.str();
    stce_9860 << stce_9862;
    stce_9860.close();
  }
};
template <bool stce_9875, class stce_9780, class stce_9831> struct stce_9876 { typedef stce_9780 type; };
template <class stce_9780, class stce_9831> struct stce_9876<false, stce_9780, stce_9831> { typedef stce_9831 type; };
template <bool stce_9875, typename stce_9780 = void> struct enable_if {};
template <typename stce_9780> struct enable_if<true, stce_9780> { typedef stce_9780 type; };
template <class stce_9780, class stce_9877> struct is_same { static const bool value = false; };
template <class stce_9780> struct is_same<stce_9780, stce_9780> { static const bool value = true; };
template <typename stce_9780> struct type_identity { typedef stce_9780 type; };
template <class stce_9780> struct remove_const { typedef stce_9780 type; };
template <class stce_9780> struct remove_const<const stce_9780> { typedef stce_9780 type; };
template <class stce_9780> struct remove_const<const stce_9780&> { typedef stce_9780& type; };
template <class stce_9780> struct remove_const<const stce_9780&&> { typedef stce_9780&& type; };
template <class stce_9780> struct stce_9878 { typedef stce_9780 type; };
template <class stce_9780> struct stce_9878<stce_9780&> { typedef stce_9780 type; };
template <class stce_9780> struct stce_9878<const stce_9780&> { typedef const stce_9780 type; };
template <class stce_9780> struct stce_9878<stce_9780&&> { typedef stce_9780 type; };
template <typename stce_9780> struct remove_all { typedef stce_9780 type; };
template <typename stce_9780> struct remove_all<const stce_9780> { typedef typename remove_all<stce_9780>::type type; };
template <typename stce_9780> struct remove_all<stce_9780 const&> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct remove_all<stce_9780&> { typedef typename remove_all<stce_9780>::type type; };
template <typename stce_9780> struct remove_all<stce_9780 const*> {
  typedef typename remove_all<stce_9780>::type type;
};
template <typename stce_9780> struct remove_all<stce_9780*> { typedef typename remove_all<stce_9780>::type type; };
template <typename stce_9780> struct remove_all<stce_9780&&> { typedef typename remove_all<stce_9780>::type type; };
template <typename stce_9780> struct stce_9879 {
  enum { value = false };
};
template <typename stce_9780> struct stce_9879<stce_9780*> {
  enum { value = true };
};
template <typename stce_9880, typename stce_9881> struct stce_9882 {
  static const bool value = (stce_9880::order < stce_9881::order);
};
template <> struct stce_9882<void, void> { static const bool value = false; };
static inline void* alloc(size_t size, bool stce_9883 = false) {
  return stce_999999(size, static_cast<int>(stce_9883));
}
static inline void dealloc(void* stce_9811) { stce_1000000(stce_9811); }
namespace folding {
template <class stce_9839, const size_t stce_9840> struct is_zero_trait<helper::valvec<stce_9839, stce_9840>> {
  static bool get(const helper::valvec<stce_9839, stce_9840>& stce_9807) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9840; ++stce_9845) {
      if (!is_zero(stce_9807[stce_9845])) {
        return false;
      }
    }
    return true;
  }
};
} // namespace folding
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9884 = void> struct trait_size_of;
template <typename stce_9780> mem_long_t size_of(const stce_9780& stce_9807) {
  return trait_size_of<stce_9780>::get(stce_9807);
}
template <typename stce_9780> mem_long_t size_of(const stce_9780& stce_9807, int stce_9885) {
  return trait_size_of<stce_9780>::get(stce_9807, stce_9885);
}
template <typename stce_9780, typename stce_9884> struct trait_size_of {
  static mem_long_t get(const stce_9780&) {
    if (helper::stce_9837) {
      throw dco::exception::create<std::runtime_error>(
          "You're trying to compute the size of the checkpoint, but a type (" + type_name<stce_9780>() +
          ") you checkpointed does not have a correct specialization:\n\n" +
          "template <typename T> struct trait_size_of {\n" + "   static mem_long_t get(const T&) { ... }\n" + "};\n\n");
    }
    return 0;
  }
};
template <memory_model::TYPE MEMORY_MODEL, class stce_9788, memory_model::TYPE stce_9789>
struct trait_size_of<dco::internal::tape<MEMORY_MODEL, stce_9788, stce_9789>*> {
  typedef dco::internal::tape<MEMORY_MODEL, stce_9788, stce_9789> tape_t;
  static mem_long_t get(const tape_t* tape, const int stce_9885 = tape_t::stce_9886) {
    return tape->stce_9887(stce_9885);
  }
};
template <typename stce_9780> struct trait_size_of<std::vector<stce_9780>> {
  static mem_long_t get(const std::vector<stce_9780>& stce_9807) {
    return stce_9807.size() * sizeof(stce_9780) + sizeof(stce_9807);
  }
};
template <> struct trait_size_of<char> {
  static mem_long_t get(const char&) { return sizeof(char); }
};
template <> struct trait_size_of<wchar_t> {
  static mem_long_t get(const wchar_t&) { return sizeof(wchar_t); }
};
template <> struct trait_size_of<signed char> {
  static mem_long_t get(const signed char&) { return sizeof(signed char); }
};
template <> struct trait_size_of<short> {
  static mem_long_t get(const short&) { return sizeof(short); }
};
template <> struct trait_size_of<int> {
  static mem_long_t get(const int&) { return sizeof(int); }
};
template <> struct trait_size_of<long> {
  static mem_long_t get(const long&) { return sizeof(long); }
};
template <> struct trait_size_of<unsigned char> {
  static mem_long_t get(const unsigned char&) { return sizeof(unsigned char); }
};
template <> struct trait_size_of<unsigned short> {
  static mem_long_t get(const unsigned short&) { return sizeof(unsigned short); }
};
template <> struct trait_size_of<unsigned int> {
  static mem_long_t get(const unsigned int&) { return sizeof(unsigned int); }
};
template <> struct trait_size_of<unsigned long> {
  static mem_long_t get(const unsigned long&) { return sizeof(unsigned long); }
};
template <> struct trait_size_of<long long> {
  static mem_long_t get(const long long&) { return sizeof(long long); }
};
template <> struct trait_size_of<unsigned long long> {
  static mem_long_t get(const unsigned long long&) { return sizeof(unsigned long long); }
};
template <> struct trait_size_of<float> {
  static mem_long_t get(const float&) { return sizeof(float); }
};
template <> struct trait_size_of<double> {
  static mem_long_t get(const double&) { return sizeof(double); }
};
template <> struct trait_size_of<long double> {
  static mem_long_t get(const long double&) { return sizeof(long double); }
};
template <> struct trait_size_of<bool> {
  static mem_long_t get(const bool&) { return sizeof(bool); }
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9888> struct stce_9889 {
  typedef stce_9888 type;
  typedef stce_9888& stce_9890;
  typedef const stce_9888 stce_9891;
};
template <typename stce_9780> struct stce_9889<std::vector<stce_9780>> {
  typedef std::vector<stce_9780>& type;
  typedef std::vector<stce_9780>& stce_9890;
  typedef std::vector<stce_9780> const& stce_9891;
};
template <stce_9794 stce_9892, typename stce_9780, typename stce_9893 = void> struct stce_9894 {};
template <typename stce_9780> struct stce_9894<stce_9795, stce_9780> {
  typedef typename dco::mode<stce_9780>::value_t value_t;
  typedef typename trait_value<stce_9780>::stce_9803 stce_9803;
  typedef typename trait_value<stce_9780>::stce_9895 stce_9895;
  stce_9803 get(stce_9780& stce_9807) { return trait_value<stce_9780>::value(stce_9807); };
  stce_9895 get(const stce_9780& stce_9807) const { return trait_value<stce_9780>::value(stce_9807); };
};
template <typename stce_9780> struct stce_9894<stce_9801, stce_9780> {
  typedef typename dco::mode<stce_9780>::passive_t value_t;
  typedef typename stce_9785<stce_9780>::stce_9803 stce_9803;
  typedef typename stce_9785<stce_9780>::stce_9895 stce_9895;
  stce_9803 get(stce_9780& stce_9807) { return stce_9785<stce_9780>::value(stce_9807); };
  stce_9895 get(const stce_9780& stce_9807) const { return stce_9785<stce_9780>::value(stce_9807); };
};
template <typename stce_9780> struct stce_9894<stce_9796, stce_9780> {
  typedef typename dco::mode<stce_9780>::derivative_t value_t;
  typedef typename stce_9782<stce_9780>::stce_9803 stce_9803;
  typedef typename stce_9782<stce_9780>::stce_9803 stce_9895;
  stce_9803 get(const stce_9780& stce_9807) const { return stce_9782<stce_9780>::value(stce_9807); };
};
template <typename stce_9780> struct stce_9894<stce_9802, stce_9780> {
  typedef typename stce_9787<stce_9780>::stce_9803 stce_9803;
  typedef typename stce_9787<stce_9780>::stce_9803 stce_9895;
  typedef typename stce_9878<stce_9803>::type value_t;
  stce_9803 get(const stce_9780& stce_9807) const { return stce_9787<stce_9780>::value(stce_9807); };
};
template <typename stce_9780, typename stce_9893> struct stce_9894<stce_9797, stce_9780, stce_9893> {
  typedef typename dco::mode<stce_9780>::derivative_t value_t;
  typedef typename stce_9782<stce_9780, stce_9893>::stce_9896 stce_9803;
  typedef typename stce_9782<stce_9780, stce_9893>::stce_9896 stce_9895;
  stce_9893* stce_9897;
  stce_9894(stce_9893* adjoints) : stce_9897(adjoints) {}
  auto get(stce_9780& stce_9807) -> decltype(stce_9782<stce_9780, stce_9893>::value(stce_9807, stce_9897)) {
    return stce_9782<stce_9780, stce_9893>::value(stce_9807, stce_9897);
  };
  auto get(const stce_9780& stce_9807) const -> decltype(stce_9782<stce_9780, stce_9893>::value(stce_9807, stce_9897)) {
    return stce_9782<stce_9780, stce_9893>::value(stce_9807, stce_9897);
  };
};
template <stce_9794 stce_9892, class stce_9780, typename stce_9888, typename stce_9781 = void>
struct stce_9898 : stce_9894<stce_9892, stce_9780, stce_9781> {
  typedef typename stce_9889<stce_9888>::type stce_9899;
  typedef typename stce_9889<stce_9888>::stce_9890 stce_9900;
  typedef typename stce_9889<stce_9888>::stce_9891 stce_9901;
  typedef stce_9894<stce_9892, stce_9780, stce_9781> stce_9902;
  typedef typename stce_9902::value_t value_t;
  stce_9899 stce_9903;
  stce_9898(stce_9901 stce_9855) : stce_9903(const_cast<stce_9900>(stce_9855)) {}
  stce_9898(stce_9901 stce_9855, stce_9781* stce_9904)
      : stce_9902(stce_9904), stce_9903(const_cast<stce_9900>(stce_9855)) {}
  stce_9898& operator=(const std::vector<value_t>& stce_9905) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9903.size(); ++stce_9845) {
      stce_9902::get(stce_9903[stce_9845]) = stce_9905[stce_9845];
    }
    return *this;
  }
  stce_9898& operator+=(const std::vector<value_t>& stce_9905) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9903.size(); ++stce_9845) {
      stce_9902::get(stce_9903[stce_9845]) += stce_9905[stce_9845];
    }
    return *this;
  }
  stce_9898& operator=(value_t const& stce_9905) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9903.size(); ++stce_9845) {
      stce_9902::get(stce_9903[stce_9845]) = stce_9905;
    }
    return *this;
  }
  operator std::vector<value_t>() const {
    std::vector<value_t> stce_9847(stce_9903.size());
    for (size_t stce_9845 = 0; stce_9845 < stce_9903.size(); ++stce_9845) {
      stce_9847[stce_9845] = stce_9902::get(stce_9903[stce_9845]);
    }
    return stce_9847;
  }
  typename stce_9902::stce_9803 operator[](size_t stce_9845) { return stce_9902::get(stce_9903[stce_9845]); }
  typename stce_9902::stce_9895 operator[](size_t stce_9845) const { return stce_9902::get(stce_9903[stce_9845]); }
  size_t size() const { return stce_9903.size(); }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9906> struct stce_9907 : public dco::mode<typename stce_9906::binary_t>::data_t {
  typedef stce_9906 mode_t;
  static const int gbcp_order = mode_t::gbcp_order;
  static const int order = mode_t::order;
  template <class stce_9908> DCO_ALWAYS_INLINE void stce_9909(stce_9908 const&) {}
  void clear() {}
  stce_9907() {}
  stce_9907(stce_9907 const&) : dco::mode<typename stce_9906::binary_t>::data_t() {}
  stce_9907& operator=(stce_9907 const&) { return *this; }
  index_t& _tape_index() const { return static_cast<const typename mode_t::type&>(*this).stce_9910._tape_index(); }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9877>
stce_9780& create_gbcp(stce_9877& stce_9911, typename enable_if<!stce_9879<stce_9780>::value, stce_9780>::type* = 0) {
  return reinterpret_cast<stce_9780&>(stce_9911);
}
template <typename stce_9780, typename stce_9877>
stce_9780 create_gbcp(stce_9877& stce_9911, typename enable_if<stce_9879<stce_9780>::value, stce_9780>::type* = 0) {
  return reinterpret_cast<stce_9780>(&stce_9911);
}
namespace internal {
template <typename stce_9780, typename enable_if = void> struct stce_9912 { static const bool value = false; };
template <typename mode_t> struct stce_9912<stce_9907<mode_t>> { static const bool value = true; };
template <typename stce_9780>
struct stce_9912<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  static const bool value = stce_9912<typename dco::mode<stce_9780>::data_t>::value;
};
template <typename stce_9780> struct is_gbcp_type {
  static const bool value = stce_9912<typename dco::remove_all<stce_9780>::type>::value;
};
template <typename stce_9780, int stce_9807> struct stce_9913;
template <typename stce_9780> struct stce_9913<stce_9780, 1> {
  typedef typename mode<stce_9780>::active_value_t& stce_9803;
  typedef const typename mode<stce_9780>::active_value_t& stce_9895;
  static stce_9803 value(stce_9780& at) { return at._value(); }
  static stce_9895 value(const stce_9780& at) { return at._value(); }
};
template <typename stce_9780, int stce_9807> struct stce_9913 {
  typedef typename stce_9913<typename mode<stce_9780>::active_value_t, stce_9807 - 1>::stce_9803 stce_9803;
  typedef typename stce_9913<typename mode<stce_9780>::active_value_t, stce_9807 - 1>::stce_9895 stce_9895;
  static stce_9803 value(stce_9780& at) {
    return stce_9913<typename mode<stce_9780>::active_value_t, stce_9807 - 1>::value(at._value());
  }
  static stce_9895 value(const stce_9780& at) {
    return stce_9913<typename mode<stce_9780>::active_value_t, stce_9807 - 1>::value(at._value());
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780> inline typename internal::trait_value<stce_9780>::stce_9803 value(stce_9780& stce_9807) {
  return internal::trait_value<stce_9780>::value(stce_9807);
}
template <typename stce_9780>
inline typename internal::trait_value<stce_9780>::stce_9895 value(const stce_9780& stce_9807) {
  return internal::trait_value<stce_9780>::value(stce_9807);
}
namespace internal {
template <typename stce_9780, typename enable_if> struct trait_value {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type& stce_9803;
  typedef const type& stce_9895;
  static inline stce_9803 value(type& value) { return value; }
  static inline stce_9895 value(const type& value) { return value; }
};
template <typename stce_9780>
struct trait_value<stce_9780,
                   typename dco::enable_if<dco::mode<stce_9780>::is_dco_type && !is_gbcp_type<stce_9780>::value &&
                                           !dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9803;
  typedef typename dco::mode<type>::value_t const& stce_9895;
  static inline stce_9803 value(type& value) { return value._value(); }
  static inline stce_9895 value(const type& value) { return value._value(); }
};
template <typename stce_9780>
struct trait_value<stce_9780, typename dco::enable_if<!is_gbcp_type<stce_9780>::value &&
                                                      dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t const& stce_9803;
  typedef typename dco::mode<type>::value_t const& stce_9895;
  static inline stce_9803 value(type& value) { return value._value(); }
  static inline stce_9895 value(const type& value) { return value._value(); }
};
template <typename stce_9780>
struct trait_value<stce_9780, typename dco::enable_if<is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9803;
  typedef typename dco::mode<type>::value_t const& stce_9895;
  static inline stce_9803 value(type& stce_9914) { return dco::value(stce_9914._value()); }
  static inline stce_9895 value(const type& stce_9914) { return dco::value(stce_9914._value()); }
};
template <typename stce_9780>
struct trait_value<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9795, stce_9780, stce_9899> stce_9803;
  typedef const stce_9898<stce_9795, stce_9780, stce_9899> stce_9895;
  static inline stce_9803 value(stce_9899& stce_9855) { return stce_9803(stce_9855); }
  static inline stce_9895 value(const stce_9899& stce_9855) { return stce_9895(stce_9855); }
};
template <stce_9794 stce_9892, class stce_9780, typename stce_9915, typename stce_9916>
struct trait_value<stce_9898<stce_9892, stce_9780, stce_9915, stce_9916>, void> {
  typedef stce_9898<stce_9892, stce_9780, stce_9915, stce_9916> stce_9899;
  typedef stce_9898<stce_9795, typename stce_9899::value_t, stce_9899> stce_9803;
  typedef stce_9898<stce_9795, typename stce_9899::value_t, stce_9899> stce_9895;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780>
inline typename internal::stce_9785<stce_9780>::stce_9803 passive_value(stce_9780& stce_9807) {
  return internal::stce_9785<stce_9780>::value(stce_9807);
}
template <typename stce_9780>
inline typename internal::stce_9785<stce_9780>::stce_9895 passive_value(const stce_9780& stce_9807) {
  return internal::stce_9785<stce_9780>::value(stce_9807);
}
namespace internal {
template <typename stce_9780, typename enable_if> struct stce_9785 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type& stce_9803;
  typedef type const& stce_9895;
  static inline stce_9803 value(type& value) { return value; }
  static inline stce_9895 value(const type& value) { return value; }
};
template <typename stce_9780>
struct stce_9785<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type &&
                                                    !dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::active_value_t active_value_t;
  typedef typename dco::mode<type>::value_t value_t;
  typedef typename dco::mode<type>::passive_t passive_t;
  typedef passive_t& stce_9803;
  typedef passive_t const& stce_9895;
  static inline stce_9803 value(type& value) { return stce_9785<value_t>::value(dco::value(value)); }
  static inline stce_9895 value(const type& value) { return stce_9785<value_t>::value(dco::value(value)); }
};
template <typename stce_9780>
struct stce_9785<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_intermediate_type>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::active_value_t active_value_t;
  typedef typename dco::mode<type>::value_t value_t;
  typedef typename dco::mode<type>::passive_t passive_t;
  typedef passive_t const& stce_9803;
  typedef passive_t const& stce_9895;
  static inline stce_9803 value(type& value) { return stce_9785<value_t>::value(dco::value(value)); }
  static inline stce_9895 value(const type& value) { return stce_9785<value_t>::value(dco::value(value)); }
};
template <typename stce_9780>
struct stce_9785<std::vector<stce_9780>, typename dco::enable_if<!dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9899& stce_9803;
  typedef const stce_9899& stce_9895;
  static inline stce_9803 value(stce_9899& value) { return value; }
  static inline stce_9895 value(const stce_9899& value) { return value; }
};
template <typename stce_9780>
struct stce_9785<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9801, stce_9780, stce_9899> stce_9803;
  typedef const stce_9898<stce_9801, stce_9780, stce_9899> stce_9895;
  static inline stce_9803 value(stce_9899& stce_9855) { return stce_9803(stce_9855); }
  static inline stce_9895 value(const stce_9899& stce_9855) { return stce_9895(stce_9855); }
};
template <stce_9794 stce_9892, class stce_9780, typename stce_9915, typename stce_9916>
struct stce_9785<stce_9898<stce_9892, stce_9780, stce_9915, stce_9916>, void> {
  typedef stce_9898<stce_9892, stce_9780, stce_9915, stce_9916> stce_9899;
  typedef stce_9898<stce_9801, typename stce_9899::value_t, stce_9899> stce_9803;
  typedef stce_9898<stce_9801, typename stce_9899::value_t, stce_9899> stce_9895;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
struct interpretation_settings {
  bool reset;
  bool stce_9917;
  interpretation_settings(bool stce_9918 = false, bool stce_9919 = false) : reset(stce_9918), stce_9917(stce_9919) {}
};
} // namespace internal
} // namespace dco

namespace dco {
template <class stce_9760> struct adjoint_vector_abstract;
template <typename stce_9760> struct stce_9920 {
  adjoint_vector_abstract<stce_9760>& adjoints;
  index_t stce_9810;
  stce_9920(adjoint_vector_abstract<stce_9760>& adjoints, index_t stce_9810)
      : adjoints(adjoints), stce_9810(stce_9810) {}
  operator stce_9760() const { return adjoints._read_adjoint(stce_9810); }
  template <typename stce_9780> stce_9920& operator+=(stce_9780 const& stce_9921) {
    adjoints._increment_adjoint(stce_9810, stce_9921);
    return *this;
  }
};
template <class stce_9760> struct adjoint_vector_abstract {
  virtual ~adjoint_vector_abstract(){};
  stce_9920<stce_9760> stce_9922(const index_t stce_9810) { return stce_9920<stce_9760>(*this, stce_9810); }
  virtual stce_9760 _read_adjoint(const index_t stce_9810) = 0;
  virtual void _increment_adjoint(const index_t stce_9810, const stce_9760& stce_9923) = 0;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9924> class stce_9925 {
protected:
  stce_9924& stce_9926;

public:
  stce_9925(stce_9924& stce_9927) : stce_9926(stce_9927) {}
  stce_9924& stce_9927() { return stce_9926; }
};
} // namespace internal
} // namespace dco

namespace dco {
class tape_options {
private:
  size_t stce_9928, stce_9929;
  bool stce_9930;
  std::string stce_9931;
  bool stce_9932;
  bool stce_9933;

public:
  tape_options()
      : stce_9928(128 * 1024 * 1024), stce_9929(0), stce_9930(false), stce_9931("dco_tape_data.bin"), stce_9932(false),
        stce_9933(false) {}
  bool operator==(const tape_options& stce_9934) {
    return stce_9928 == stce_9934.stce_9928 && stce_9929 == stce_9934.stce_9929 && stce_9930 == stce_9934.stce_9930 &&
           stce_9932 == stce_9934.stce_9932 && stce_9931 == stce_9934.stce_9931 && stce_9933 == stce_9934.stce_9933;
  }
  bool operator!=(const tape_options& stce_9934) { return !operator==(stce_9934); }
  index_t chunk_size() const {
    if (helper::stce_9837) {
      throw dco::exception::create<std::runtime_error>("chunk_size removed; use chunk_size_in_byte() instead");
    }
    return -1;
  }
  size_t chunk_size_in_byte() const { return stce_9928; }
  size_t& chunk_size_in_byte() { return stce_9928; }
  void set_chunk_size_in_byte(mem_long_t size) {
    if (static_cast<double>(size) / static_cast<double>(std::numeric_limits<size_t>::max()) > 1.0) {
      DCO_LOG(logWARNING) << "set_chunk_size: requesting too much memory for your system (size_t too small). Resetting "
                             "to std::numeric_limits<size_t>::max()";
      stce_9928 = std::numeric_limits<size_t>::max();
    } else {
      stce_9928 = static_cast<size_t>(size);
    }
  }
  void set_chunk_size_in_kbyte(double size) { set_chunk_size_in_byte(1024 * static_cast<mem_long_t>(size)); }
  void set_chunk_size_in_mbyte(double size) { set_chunk_size_in_kbyte(1024. * size); }
  void set_chunk_size_in_gbyte(double size) { set_chunk_size_in_mbyte(1024. * size); }
  size_t blob_size_in_byte() const { return stce_9929; }
  size_t& blob_size_in_byte() { return stce_9929; }
  void set_blob_size_in_byte(mem_long_t size) {
    if (static_cast<double>(size) / static_cast<double>(std::numeric_limits<size_t>::max()) > 1.0) {
      DCO_LOG(logWARNING) << "set_blob_size: requesting too much memory for your system (size_t too small). Resetting "
                             "to std::numeric_limits<size_t>::max()";
      stce_9929 = std::numeric_limits<size_t>::max();
    } else {
      stce_9929 = static_cast<size_t>(size);
    }
  }
  void set_blob_size_in_kbyte(double size) { set_blob_size_in_byte(1024 * static_cast<mem_long_t>(size)); }
  void set_blob_size_in_mbyte(double size) { set_blob_size_in_kbyte(1024. * size); }
  void set_blob_size_in_gbyte(double size) { set_blob_size_in_mbyte(1024. * size); }
  bool& deallocation_on_reset() { return stce_9930; }
  const bool& deallocation_on_reset() const { return stce_9930; }
  std::string& filename() { return stce_9931; }
  const std::string& filename() const { return stce_9931; }
  bool& write_to_file() { return stce_9932; }
  bool write_to_file() const { return stce_9932; }
  bool& alloc_use_huge_pages() { return stce_9933; }
  bool alloc_use_huge_pages() const { return stce_9933; }
};
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9760, typename stce_9924> class adjoint_vector_lazy : public stce_9925<stce_9924> {
  typedef stce_9925<stce_9924> stce_9935;

public:
  typedef typename helper::vecsize_info<stce_9760>::stce_9851 stce_9936;
  typedef stce_9760 stce_9762;

protected:
  std::vector<stce_9762> stce_9897;
  index_t stce_9937;
  index_t stce_9938;
  index_t stce_9939;
  int stce_9940;
  tape_options stce_9941;

public:
  typedef stce_9762 value_t;
  void init() {}
  adjoint_vector_lazy(index_t size, stce_9924& tape, tape_options stce_9942)
      : stce_9935(tape), stce_9897(0), stce_9937(0), stce_9938(0), stce_9939(size), stce_9940(0), stce_9941(stce_9942) {
  }
  DCO_ALWAYS_INLINE ~adjoint_vector_lazy() {}
  index_t size() const { return stce_9939; }
  bool stce_9943(index_t stce_9944) const { return stce_9937 > stce_9944; }
  mem_long_t stce_9945() const { return static_cast<mem_long_t>(stce_9938) * sizeof(stce_9762); }
  stce_9762& operator[](index_t stce_9810) { return stce_9897[stce_9810]; }
  stce_9762 operator[](index_t stce_9810) const { return stce_9897[stce_9810]; }
  void stce_9946(typename stce_9924::iterator& stce_9825) {
    (*this)[stce_9825->arg()] += static_cast<stce_9762>(stce_9825->pval() * (*this)[stce_9825.index()]);
  }
  void resize(index_t stce_9947) {
    DCO_LOG(logDEBUG2) << "Resizing internal adjoint vector to " << stce_9947;
    if (stce_9947 < stce_9939) {
      stce_9948(stce_9939, stce_9947 - 1);
    }
    stce_9939 = stce_9947;
  }
  void stce_9949(index_t stce_9947) {
    if (stce_9947 <= stce_9937) {
      return;
    }
    if (++stce_9940 % 100 == 0) {
      DCO_LOG(logWARNING) << "dco_adjoint_vector: resizing adjoint vector quite often (#=" << stce_9940
                          << ") -- might have severe performance impact (reallocation / initialization / copy)";
    }
    stce_9897.resize(static_cast<size_t>(stce_9947));
    stce_9937 = stce_9947;
    stce_9938 = static_cast<index_t>(stce_9897.capacity());
  }
  void stce_9950(index_t stce_9810) { stce_9949(stce_9810); }
  stce_9762 at(index_t stce_9810) const { return stce_9943(stce_9810) ? stce_9897[stce_9810] : 0; }
  stce_9762& at(const index_t stce_9810) {
    stce_9949(stce_9810 + 1);
    return stce_9897[stce_9810];
  }
  void stce_9948(index_t stce_9872, index_t stce_9873) {
    if (stce_9872 < stce_9873) {
      std::swap(stce_9872, stce_9873);
    }
    if (!stce_9943(stce_9873)) {
      return;
    }
    stce_9949(stce_9939);
    for (index_t stce_9845 = std::min(stce_9872, stce_9939 - 1); stce_9845 > stce_9873; --stce_9845) {
      stce_9897[stce_9845] = 0;
    }
  }
  void stce_9951() { stce_9949(stce_9939); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <class stce_9924, class stce_9760, int stce_9952 = -1>
struct adjoint_vector : dco::adjoint_vector_abstract<typename stce_9924::tape_t::stce_9762>,
                        public internal::stce_9925<stce_9924> {
  static const size_t vecsize = stce_9952 < 0 ? static_cast<size_t>(-stce_9952) : static_cast<size_t>(stce_9952);
  typedef internal::stce_9925<stce_9924> stce_9935;

public:
  typedef dco::helper::valvec<stce_9760, vecsize> value_t;
  typedef stce_9760 adjoint_real_t;
  typedef stce_9760 stce_9936;
  typedef typename stce_9924::stce_9762 stce_9762;

private:
  std::vector<value_t> stce_9897;
  index_t stce_9953;

public:
  int stce_9954;
  void init() {}
  adjoint_vector(stce_9924* tape) : stce_9935(*tape), stce_9953(0), stce_9954(0) {}
  virtual ~adjoint_vector() {}
  template <class stce_9793> value_t& derivative(const stce_9793& stce_9955) {
    stce_9956();
    const index_t stce_9810 = stce_9955._tape_index();
    return stce_9897[stce_9810];
  }
  void interpret_adjoint() {
    typename stce_9924::iterator stce_9873 = stce_9935::stce_9927().start();
    internal::interpretation_settings stce_9957;
    stce_9958(stce_9935::stce_9927().current(), stce_9873, stce_9957);
  }
  void interpret_adjoint_to(const typename stce_9924::iterator& stce_9873) {
    internal::interpretation_settings stce_9957;
    if (stce_9873 > stce_9935::stce_9927().current())
      throw dco::exception::create<std::runtime_error>("adjoint interpretation: from < to.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_adjoint_vector.hpp",
                                                       59);
    else
      stce_9958(stce_9935::stce_9927().current(), stce_9873, stce_9957);
  }
  void interpret_adjoint_from(const typename stce_9924::iterator& stce_9872) {
    typename stce_9924::iterator stce_9873 = stce_9935::stce_9927().start();
    assert(!(stce_9872 < stce_9873));
    typename internal::interpretation_settings stce_9957;
    stce_9958(stce_9872, stce_9873, stce_9957);
  }
  void interpret_adjoint_from_to(const typename stce_9924::iterator& stce_9872,
                                 const typename stce_9924::iterator& stce_9873) {
    typename internal::interpretation_settings stce_9957;
    if (stce_9873 > stce_9872)
      throw dco::exception::create<std::runtime_error>("adjoint interpretation: from < to.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_adjoint_vector.hpp",
                                                       75);
    else
      stce_9958(stce_9872, stce_9873, stce_9957);
  }
  void interpret_adjoint_and_zero_adjoints_to(const typename stce_9924::iterator& stce_9873) {
    typename stce_9924::iterator stce_9872(stce_9935::stce_9927().current());
    typename internal::interpretation_settings stce_9957;
    stce_9957.reset = false;
    stce_9957.stce_9917 = true;
    stce_9958(stce_9872, stce_9873, stce_9957);
  }
  void interpret_adjoint_and_zero_adjoints_from_to(const typename stce_9924::iterator& stce_9872,
                                                   const typename stce_9924::iterator& stce_9873) {
    typename internal::interpretation_settings stce_9957;
    stce_9957.reset = false;
    stce_9957.stce_9917 = true;
    stce_9958(stce_9872, stce_9873, stce_9957);
  }
  void zero_adjoints() {
    typename stce_9924::iterator stce_9873 = stce_9935::stce_9927().start();
    stce_9959(stce_9935::stce_9927().current(), stce_9873);
  }
  void zero_adjoints_to(const typename stce_9924::iterator& stce_9873) {
    stce_9959(stce_9935::stce_9927().current(), stce_9873);
  }
  void zero_adjoints_from(const typename stce_9924::iterator& stce_9872) {
    typename stce_9924::iterator stce_9873 = stce_9935::stce_9927().start();
    stce_9959(stce_9872, stce_9873);
  }
  void zero_adjoints_from_to(const typename stce_9924::iterator& stce_9872,
                             const typename stce_9924::iterator& stce_9873) {
    stce_9959(stce_9872, stce_9873);
  }
  value_t& operator[](index_t stce_9810) { return stce_9897[stce_9810]; }
  value_t at(index_t stce_9810) const { return (stce_9810 < stce_9953) ? stce_9897[stce_9810] : 0; }
  value_t& at(index_t stce_9810) {
    stce_9950(stce_9810);
    return stce_9897[stce_9810];
  }
  void stce_9950(index_t stce_9810) { stce_9956(stce_9810 + 1); }
  void stce_9946(typename stce_9924::iterator& stce_9825) {
    (*this)[stce_9825->arg()] += stce_9825->pval() * (*this)[stce_9825.index()];
  }
  value_t& stce_9960(const index_t stce_9810) { return stce_9897[stce_9810]; }
  stce_9760& stce_9960(const index_t stce_9810, int stce_9961) { return stce_9897[stce_9810][stce_9961]; }
  template <class stce_9962>
  void _increment_adjoint(const index_t& stce_9810, const stce_9962& stce_9963, const value_t& stce_9923) {
    stce_9897[stce_9810] += (stce_9963 * stce_9923);
  }
  virtual typename stce_9924::stce_9762 _read_adjoint(const index_t stce_9810) {
    return static_cast<typename stce_9924::stce_9762>(stce_9960(stce_9810)[stce_9954]);
  }
  virtual void _increment_adjoint(const index_t stce_9810, const typename stce_9924::stce_9762& stce_9923) {
    stce_9897[stce_9810][stce_9954] += static_cast<adjoint_real_t>(stce_9923);
  }
  void stce_9959(const typename stce_9924::iterator& stce_9872, const typename stce_9924::iterator& stce_9873) {
    stce_9948(stce_9872.index(), stce_9873.index());
  }
  void stce_9948(index_t stce_9872, index_t stce_9873) {
    if (stce_9872 < stce_9873) {
      std::swap(stce_9872, stce_9873);
    }
    if (stce_9897.size() == 0) {
      return;
    }
    for (index_t stce_9845 = stce_9873 + 1; stce_9845 <= stce_9872; stce_9845++) {
      stce_9897[stce_9845] = 0;
    }
  }
  void stce_9958(const typename stce_9924::iterator& stce_9872, const typename stce_9924::iterator& stce_9873,
                 typename internal::interpretation_settings stce_9957) {
    stce_9956();
    stce_9935::stce_9927().stce_9964(*this, *this, stce_9872, stce_9873, stce_9957, [](dco::index_t, value_t) {});
  }
  void stce_9956(index_t stce_9965 = -1) {
    index_t stce_9966;
    if (stce_9965 != -1)
      stce_9966 = stce_9965;
    else
      stce_9966 = stce_9935::stce_9927().current().index() + 1;
    if (static_cast<size_t>(stce_9966) > stce_9897.size()) {
      stce_9953 = stce_9966;
      stce_9897.resize(static_cast<size_t>(stce_9953));
    }
  }
};
} // namespace dco
namespace dco {
template <typename stce_9780>
inline typename internal::stce_9782<stce_9780>::stce_9803 derivative(const stce_9780& stce_9807) {
  return internal::stce_9782<stce_9780>::value(stce_9807);
}
template <typename stce_9780, typename stce_9781>
inline auto derivative(const stce_9780& stce_9807, stce_9781& adjoints)
    -> decltype(internal::stce_9782<stce_9780, stce_9781>::value(stce_9807, &adjoints)) {
  return internal::stce_9782<stce_9780, stce_9781>::value(stce_9807, &adjoints);
}
namespace internal {
template <typename stce_9780, typename stce_9781, typename enable_if> struct stce_9782 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type stce_9803;
  static inline stce_9803 value(const type&) { return type(); }
  static inline stce_9803 value(const type&, stce_9781*) { return type(); }
};
template <typename stce_9780>
struct stce_9782<
    stce_9780, void,
    typename dco::enable_if<dco::mode<stce_9780>::is_dco_type &&
                            !(dco::mode<stce_9780>::is_adjoint_type && dco::mode<stce_9780>::is_tangent_type) &&
                            !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9803;
  static inline stce_9803 value(type const& value) { return value.stce_9967(); }
};
template <typename stce_9780>
struct stce_9782<
    stce_9780, void,
    typename dco::enable_if<(dco::mode<stce_9780>::is_adjoint_type && dco::mode<stce_9780>::is_tangent_type) &&
                            !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9803;
  template <typename stce_9877 = stce_9780> static inline stce_9803 value(type const&) {
    stce_9834(!helper::stce_9838<stce_9877>::stce_9753,
              "Please use dco::tangent or dco::adjoint for this data type. dco::derivative is ambiguous.");
    static typename std::remove_reference<stce_9803>::type stce_9968;
    return stce_9968;
  }
};
template <typename stce_9780>
struct stce_9782<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order > 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9803;
  static inline stce_9803 value(const type& value) { return dco::derivative(value._value()); }
};
template <typename stce_9780>
struct stce_9782<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order == 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t stce_9803;
  static inline stce_9803 value(const type&) { return stce_9803(); }
};
template <typename stce_9780, typename stce_9969, typename stce_9970, int stce_9971>
struct stce_9782<stce_9780, adjoint_vector<stce_9969, stce_9970, stce_9971>,
                 typename dco::enable_if<(stce_9971 == -1)>::type> {
  typedef adjoint_vector<stce_9969, stce_9970, stce_9971> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9970& stce_9896;
  static inline stce_9896 value(const type& value, stce_9916* adjoints) { return adjoints->derivative(value)[0]; }
};
template <typename stce_9780, typename stce_9969, typename stce_9970, int stce_9971>
struct stce_9782<stce_9780, adjoint_vector<stce_9969, stce_9970, stce_9971>,
                 typename dco::enable_if<(stce_9971 > 0)>::type> {
  typedef adjoint_vector<stce_9969, stce_9970, stce_9971> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename stce_9916::value_t& stce_9896;
  static inline stce_9896 value(const type& value, stce_9916* adjoints) { return adjoints->derivative(value); }
};
template <typename stce_9780, typename stce_9760, typename stce_9924>
struct stce_9782<stce_9780, adjoint_vector_lazy<stce_9760, stce_9924>> {
  typedef adjoint_vector_lazy<stce_9760, stce_9924> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9760& stce_9896;
  static inline stce_9896 value(const type& value, stce_9916* adjoints) {
    return (*adjoints)[value.data()._tape_index()];
  }
};
template <typename stce_9780, typename stce_9760> struct stce_9782<stce_9780, adjoint_vector_abstract<stce_9760>> {
  typedef adjoint_vector_abstract<stce_9760> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9760& stce_9896;
  static inline auto value(const type& value, stce_9916* adjoints)
      -> decltype(adjoints->stce_9922(value.data()._tape_index())) {
    return adjoints->stce_9922(value.data()._tape_index());
  }
};
template <typename stce_9780>
struct stce_9782<std::vector<stce_9780>, void, typename dco::enable_if<!dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9899 stce_9803;
  static inline stce_9803 value(const stce_9899& value) { return stce_9803(value.size(), 0.0); }
};
template <typename stce_9780>
struct stce_9782<std::vector<stce_9780>, void, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9796, stce_9780, stce_9899> stce_9803;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
template <typename stce_9780, typename stce_9969, typename stce_9970, int stce_9971>
struct stce_9782<std::vector<stce_9780>, adjoint_vector<stce_9969, stce_9970, stce_9971>,
                 typename dco::enable_if<(stce_9971 == -1)>::type> {
  typedef adjoint_vector<stce_9969, stce_9970, stce_9971> stce_9916;
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9796, stce_9780, stce_9899> stce_9803;
  typedef stce_9898<stce_9797, stce_9780, stce_9899, stce_9916> stce_9896;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
  static inline stce_9896 value(const stce_9899& stce_9855, stce_9916* adjoints) {
    return stce_9896(stce_9855, adjoints);
  }
};
template <typename stce_9780, typename stce_9760>
struct stce_9782<std::vector<stce_9780>, adjoint_vector_abstract<stce_9760>> {
  typedef adjoint_vector_abstract<stce_9760> stce_9916;
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9796, stce_9780, stce_9899> stce_9803;
  typedef stce_9898<stce_9797, stce_9780, stce_9899, stce_9916> stce_9896;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
  static inline stce_9896 value(const stce_9899& stce_9855, stce_9916* adjoints) {
    return stce_9896(stce_9855, adjoints);
  }
};
template <stce_9794 stce_9892, class stce_9780, typename stce_9915, typename stce_9916>
struct stce_9782<stce_9898<stce_9892, stce_9780, stce_9915, stce_9916>, void> {
  typedef stce_9898<stce_9892, stce_9780, stce_9915, stce_9916> stce_9899;
  typedef stce_9898<stce_9796, typename stce_9899::value_t, stce_9899> stce_9803;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780>
inline typename internal::stce_9784<stce_9780>::stce_9803 adjoint(const stce_9780& stce_9807) {
  return internal::stce_9784<stce_9780>::value(stce_9807);
}
template <typename stce_9780, typename stce_9781>
inline auto adjoint(const stce_9780& stce_9807, stce_9781& adjoints)
    -> decltype(internal::stce_9784<stce_9780, stce_9781>::value(stce_9807, &adjoints)) {
  return internal::stce_9784<stce_9780, stce_9781>::value(stce_9807, &adjoints);
}
namespace internal {
template <typename stce_9780, typename stce_9781, typename enable_if> struct stce_9784 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type stce_9803;
  static inline stce_9803 value(const type&) { return type(); }
  static inline stce_9803 value(const type&, stce_9781*) { return type(); }
};
template <typename stce_9780>
struct stce_9784<
    stce_9780, void,
    typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9803;
  static inline stce_9803 value(type const& value) { return value._adjoint(); }
};
template <typename stce_9780>
struct stce_9784<
    stce_9780, void,
    typename dco::enable_if<!dco::mode<stce_9780>::is_adjoint_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t stce_9803;
  template <typename stce_9877 = stce_9780> static inline stce_9803 value(type const&) {
    stce_9834(!helper::stce_9838<stce_9877>::stce_9753, "dco::adjoint called on a non-adjoint data type.");
    static stce_9803 stce_9968;
    return stce_9968;
  }
};
template <typename stce_9780>
struct stce_9784<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order > 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9803;
  static inline stce_9803 value(const type& value) { return dco::adjoint(value._value()); }
};
template <typename stce_9780>
struct stce_9784<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order == 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t stce_9803;
  static inline stce_9803 value(const type&) { return stce_9803(); }
};
template <typename stce_9780, typename stce_9969, typename stce_9970, int stce_9971>
struct stce_9784<stce_9780, adjoint_vector<stce_9969, stce_9970, stce_9971>,
                 typename dco::enable_if<(stce_9971 == -1)>::type> {
  typedef adjoint_vector<stce_9969, stce_9970, stce_9971> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef stce_9970& stce_9896;
  static inline stce_9896 value(const type& value, stce_9916* adjoints) { return adjoints->adjoint(value)[0]; }
};
template <typename stce_9780, typename stce_9969, typename stce_9970, int stce_9971>
struct stce_9784<stce_9780, adjoint_vector<stce_9969, stce_9970, stce_9971>,
                 typename dco::enable_if<(stce_9971 > 0)>::type> {
  typedef adjoint_vector<stce_9969, stce_9970, stce_9971> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename stce_9916::value_t& stce_9896;
  static inline stce_9896 value(const type& value, stce_9916* adjoints) { return adjoints->adjoint(value); }
};
template <typename stce_9780, typename DERIVATIVE_T, typename stce_9924>
struct stce_9784<stce_9780, adjoint_vector_lazy<DERIVATIVE_T, stce_9924>> {
  typedef adjoint_vector_lazy<DERIVATIVE_T, stce_9924> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef DERIVATIVE_T& stce_9896;
  static inline stce_9896 value(const type& value, stce_9916* adjoints) {
    return (*adjoints)[value.data()._tape_index()];
  }
};
template <typename stce_9780, typename DERIVATIVE_T>
struct stce_9784<stce_9780, adjoint_vector_abstract<DERIVATIVE_T>> {
  typedef adjoint_vector_abstract<DERIVATIVE_T> stce_9916;
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef DERIVATIVE_T& stce_9896;
  static inline auto value(const type& value, stce_9916* adjoints)
      -> decltype(adjoints->stce_9922(value.data()._tape_index())) {
    return adjoints->stce_9922(value.data()._tape_index());
  }
};
template <typename stce_9780>
struct stce_9784<std::vector<stce_9780>, void, typename dco::enable_if<!dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9899 stce_9803;
  static inline stce_9803 value(const stce_9899& value) { return stce_9803(value.size(), 0.0); }
};
template <typename stce_9780>
struct stce_9784<std::vector<stce_9780>, void, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9799, stce_9780, stce_9899> stce_9803;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
template <typename stce_9780, typename stce_9969, typename stce_9970, int stce_9971>
struct stce_9784<std::vector<stce_9780>, adjoint_vector<stce_9969, stce_9970, stce_9971>,
                 typename dco::enable_if<(stce_9971 == -1)>::type> {
  typedef adjoint_vector<stce_9969, stce_9970, stce_9971> stce_9916;
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9799, stce_9780, stce_9899> stce_9803;
  typedef stce_9898<stce_9800, stce_9780, stce_9899, stce_9916> stce_9896;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
  static inline stce_9896 value(const stce_9899& stce_9855, stce_9916* adjoints) {
    return stce_9896(stce_9855, adjoints);
  }
};
template <typename stce_9780, typename DERIVATIVE_T>
struct stce_9784<std::vector<stce_9780>, adjoint_vector_abstract<DERIVATIVE_T>> {
  typedef adjoint_vector_abstract<DERIVATIVE_T> stce_9916;
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9799, stce_9780, stce_9899> stce_9803;
  typedef stce_9898<stce_9800, stce_9780, stce_9899, stce_9916> stce_9896;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
  static inline stce_9896 value(const stce_9899& stce_9855, stce_9916* adjoints) {
    return stce_9896(stce_9855, adjoints);
  }
};
template <stce_9794 stce_9972, class stce_9780, typename stce_9915, typename stce_9916>
struct stce_9784<stce_9898<stce_9972, stce_9780, stce_9915, stce_9916>, void> {
  typedef stce_9898<stce_9972, stce_9780, stce_9915, stce_9916> stce_9899;
  typedef stce_9898<stce_9799, typename stce_9899::value_t, stce_9899> stce_9803;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780>
inline typename internal::stce_9783<stce_9780>::stce_9803 tangent(const stce_9780& stce_9807) {
  return internal::stce_9783<stce_9780>::value(stce_9807);
}
namespace internal {
template <typename stce_9780, typename stce_9781, typename enable_if> struct stce_9783 {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef type stce_9803;
  static inline stce_9803 value(const type&) { return type(); }
  static inline stce_9803 value(const type&, stce_9781*) { return type(); }
};
template <typename stce_9780>
struct stce_9783<
    stce_9780, void,
    typename dco::enable_if<dco::mode<stce_9780>::is_tangent_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t& stce_9803;
  static inline stce_9803 value(type const& value) { return value.stce_9973(); }
};
template <typename stce_9780>
struct stce_9783<
    stce_9780, void,
    typename dco::enable_if<!dco::mode<stce_9780>::is_tangent_type && !is_gbcp_type<stce_9780>::value>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::derivative_t stce_9803;
  template <typename stce_9877 = stce_9780> static inline stce_9803 value(type const&) {
    stce_9834(!helper::stce_9838<stce_9877>::stce_9753, "dco::tangent called on a non-tangent data type.");
    static stce_9803 stce_9968;
    return stce_9968;
  }
};
template <typename stce_9780>
struct stce_9783<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order > 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t& stce_9803;
  static inline stce_9803 value(const type& value) { return dco::tangent(value._value()); }
};
template <typename stce_9780>
struct stce_9783<stce_9780, void,
                 typename dco::enable_if<(is_gbcp_type<stce_9780>::value && dco::mode<stce_9780>::order == 0)>::type> {
  typedef typename dco::remove_const<stce_9780>::type type;
  typedef typename dco::mode<type>::value_t stce_9803;
  static inline stce_9803 value(const type&) { return stce_9803(); }
};
template <typename stce_9780>
struct stce_9783<std::vector<stce_9780>, void, typename dco::enable_if<!dco::mode<stce_9780>::is_tangent_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9899 stce_9803;
  static inline stce_9803 value(const stce_9899& value) { return stce_9803(value.size(), 0.0); }
};
template <typename stce_9780>
struct stce_9783<std::vector<stce_9780>, void, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9798, stce_9780, stce_9899> stce_9803;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
template <stce_9794 stce_9974, class stce_9780, typename stce_9915, typename stce_9916>
struct stce_9783<stce_9898<stce_9974, stce_9780, stce_9915, stce_9916>, void> {
  typedef stce_9898<stce_9974, stce_9780, stce_9915, stce_9916> stce_9899;
  typedef stce_9898<stce_9798, typename stce_9899::value_t, stce_9899> stce_9803;
  static inline stce_9803 value(const stce_9899& stce_9855) { return stce_9803(stce_9855); }
};
} // namespace internal
} // namespace dco

namespace dco {
template <typename stce_9780> typename internal::stce_9786<stce_9780>::stce_9803 tape(const stce_9780& stce_9807) {
  return internal::stce_9786<stce_9780>::value(stce_9807);
}
template <typename stce_9780>
typename internal::stce_9787<stce_9780>::stce_9803 tape_index(const stce_9780& stce_9807) {
  return internal::stce_9787<stce_9780>::value(stce_9807);
}
namespace internal {
template <typename stce_9780, typename enable_if> struct stce_9786 {
  typedef void* stce_9803;
  static stce_9803 value(const stce_9780&) { return static_cast<void*>(0); }
};
template <typename stce_9780>
struct stce_9786<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef typename dco::mode<stce_9780>::tape_t* stce_9803;
  static stce_9803 value(const stce_9780& value) { return value.tape(); }
};
template <typename stce_9780>
struct stce_9786<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef typename dco::mode<stce_9780>::tape_t* stce_9803;
  static stce_9803 value(const std::vector<stce_9780>& value) {
    stce_9803 tape = 0;
    for (size_t stce_9845 = 0; stce_9845 < value.size(); stce_9845++) {
      if (stce_9786<stce_9780>::value(value[stce_9845]) != 0) {
        tape = stce_9786<stce_9780>::value(value[stce_9845]);
        break;
      }
    }
    return tape;
  }
};
template <typename stce_9780, typename enable_if> struct stce_9787 {
  typedef index_t stce_9803;
  static index_t value(const stce_9780&) { return 0; }
};
template <typename stce_9780>
struct stce_9787<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  typedef index_t& stce_9803;
  static stce_9803 value(const stce_9780& value) { return value._tape_index(); }
};
template <typename stce_9780>
struct stce_9787<std::vector<stce_9780>, typename dco::enable_if<dco::mode<stce_9780>::is_dco_type>::type> {
  typedef std::vector<stce_9780> stce_9899;
  typedef stce_9898<stce_9802, stce_9780, stce_9899> stce_9803;
  typedef const stce_9898<stce_9802, stce_9780, stce_9899> stce_9895;
  static inline stce_9803 value(stce_9899& stce_9855) { return stce_9803(stce_9855); }
  static inline stce_9895 value(const stce_9899& stce_9855) { return stce_9895(stce_9855); }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace folding {
template <typename stce_9780, typename enable_if> struct is_zero_trait {
  static bool get(const stce_9780& stce_9807) { return stce_9807 == 0; }
};
template <typename stce_9780> bool is_zero(const stce_9780& stce_9807) {
  return is_zero_trait<stce_9780>::get(stce_9807);
}
template <typename stce_9780>
struct is_zero_trait<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_tangent_type>::type> {
  static bool get(const stce_9780& stce_9807) { return is_zero(value(stce_9807)) && is_zero(derivative(stce_9807)); }
};
template <typename stce_9780>
struct is_zero_trait<stce_9780, typename dco::enable_if<dco::mode<stce_9780>::is_adjoint_type>::type> {
  static bool get(const stce_9780& stce_9807) { return is_zero(value(stce_9807)) && !tape_index(stce_9807); }
};
} // namespace folding
} // namespace dco

namespace dco {
template <typename stce_9817, typename... stce_9975>
int fprintf(stce_9817& stream, char const* stce_9976, stce_9975&&... stce_9977) {
  return ::fprintf(stream, stce_9976, dco::passive_value(stce_9977)...);
}
template <typename... stce_9975> int printf(char const* const stce_9976, stce_9975&&... stce_9977) {
  return ::printf(stce_9976, dco::passive_value(stce_9977)...);
}
template <typename... stce_9975> int sprintf(char* stream, char const* stce_9976, stce_9975&&... stce_9977) {
  return ::sprintf(stream, stce_9976, dco::passive_value(stce_9977)...);
}
namespace stce_9978 {
inline void init() {}
template <typename stce_9780, typename... stce_9975>
typename dco::enable_if<!dco::mode<typename std::remove_pointer<stce_9780>::type>::is_dco_type>::type
init(stce_9780&, stce_9975&... stce_9977);
template <typename stce_9780, typename... stce_9975>
typename dco::enable_if<dco::mode<typename std::remove_pointer<stce_9780>::type>::is_dco_type>::type
init(stce_9780& stce_9807, stce_9975&... stce_9977) {
  *stce_9807 = 0;
  init(stce_9977...);
}
template <typename stce_9780, typename... stce_9975>
typename dco::enable_if<!dco::mode<typename std::remove_pointer<stce_9780>::type>::is_dco_type>::type
init(stce_9780&, stce_9975&... stce_9977) {
  init(stce_9977...);
}
} // namespace stce_9978
template <typename stce_9817, typename... stce_9975>
int sscanf(stce_9817& stream, char const* stce_9976, stce_9975&&... stce_9977) {
  stce_9978::init(stce_9977...);
  return ::sscanf(stream, stce_9976, &dco::passive_value(*stce_9977)...);
}
template <typename stce_9817, typename... stce_9975>
int fscanf(stce_9817& stream, char const* stce_9976, stce_9975&&... stce_9977) {
  stce_9978::init(stce_9977...);
  return ::fscanf(stream, stce_9976, &dco::passive_value(*stce_9977)...);
}
} // namespace dco

namespace dco {
namespace internal {
template <memory_model::TYPE memory_model, typename stce_9979, memory_model::TYPE stce_9980 = memory_model::stce_9764>
class stce_9981 {};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9982>
struct jacobian_preaccumulator_t : adjoint_vector_abstract<typename dco::mode<stce_9982>::stce_9983> {
  typedef typename dco::mode<stce_9982>::stce_9983 stce_9762;
  typedef stce_9762 stce_9936;
  typedef typename dco::mode<stce_9982>::tape_t tape_t;
  typedef typename tape_t::iterator_t stce_9984;
  typedef typename tape_t::edge_inserter stce_9985;
  tape_t* const stce_9986;
  stce_9984 stce_9987;
  index_t stce_9988;
  typedef adjoint_vector_lazy<stce_9762, tape_t> vector_t;
  vector_t stce_9897;
  bool stce_9989;
  bool stce_9990;
  std::map<index_t, stce_9762> stce_9991;
  void init() {}
  typedef stce_9981<memory_model::BLOB_TAPE, tape_t> stce_9899;
  typedef typename stce_9899::edge_inserter stce_9992;
  typedef typename stce_9899::iterator stce_9993;
  stce_9899* stce_9926;
  stce_9992* stce_9994;
  typedef typename stce_9982::data_t stce_9995;
  std::vector<stce_9995*> stce_9996;
  index_t stce_9954;
  bool& merge_edges() { return stce_9990; }
  jacobian_preaccumulator_t(tape_t* const tape)
      : stce_9986(tape), stce_9897(0, *tape, tape->stce_9942()), stce_9990(false), stce_9926(0), stce_9994(0),
        stce_9954(0) {
    if (stce_9986) {
      stce_9987 = stce_9986->get_position();
      stce_9988 = stce_9987.index();
      stce_9989 = true;
    } else {
      stce_9989 = false;
    }
  }
  ~jacobian_preaccumulator_t() {
    if (stce_9989)
      this->finish();
    if (stce_9926)
      delete stce_9926;
  }
  void start() {
    if (stce_9986) {
      stce_9987 = stce_9986->get_position();
      stce_9988 = stce_9987.index();
      stce_9989 = true;
    } else {
      stce_9989 = false;
    }
  }
  void stce_9997(stce_9982& stce_9807) {
    if (!dco::tape_index(stce_9807))
      return;
    if (dco::tape_index(stce_9807) && dco::tape_index(stce_9807) <= stce_9988) {
      throw dco::exception::create<std::runtime_error>("jacobian_preaccumulator_t: registering output, which is indeed "
                                                       "an input (was alive already before starting point).");
    }
    stce_9996.push_back(&static_cast<stce_9995&>(stce_9807));
  }
  void register_output(stce_9982& stce_9807) {
    if (stce_9986) {
      stce_9997(stce_9807);
    }
  }
  void register_output(std::vector<stce_9982>& stce_9807) {
    if (stce_9986) {
      stce_9996.reserve(stce_9996.size() + stce_9807.size());
      for (size_t stce_9845 = 0; stce_9845 < stce_9807.size(); ++stce_9845) {
        stce_9997(stce_9807[stce_9845]);
      }
    }
  }
  void finish() {
    if (!stce_9989)
      return;
    stce_9989 = false;
    if (!stce_9986)
      return;
    if (!stce_9996.size()) {
      stce_9986->reset_to(stce_9987);
      return;
    }
    const stce_9984 stce_9998 = stce_9986->get_position();
    const index_t stce_9999 = stce_9998.index() - stce_9987.index();
    stce_9897.resize(stce_9999 + 1);
    const index_t stce_10000 = stce_9986->size(stce_9998, stce_9987);
    const index_t stce_10001 = stce_10000 * (1 + static_cast<index_t>(stce_9996.size()));
    if (stce_9926)
      delete stce_9926;
    tape_options stce_10002;
    stce_10002.blob_size_in_byte() = stce_10001 * stce_9899::entry::size_of();
    stce_9926 = new stce_9899(stce_10002, *stce_9986);
    stce_9926->stce_10003().index() = stce_9998.index();
    stce_9897.stce_9951();
    for (typename std::vector<stce_9995*>::iterator stce_10004 = stce_9996.begin(); stce_10004 != stce_9996.end();
         ++stce_10004) {
      stce_9995& stce_9825 = **stce_10004;
      if (stce_9825._tape_index() == 0)
        continue;
      stce_9897.stce_9948(stce_9999 - 1, 0);
      stce_9960(stce_9825._tape_index()) = 1.0;
      stce_9994 = new stce_9992(stce_9926->insert_ref());
      if (stce_9990) {
        stce_9991.clear();
      }
      stce_9986->stce_9964(*this, *this, stce_9998, stce_9987, interpretation_settings(false, true),
                           [](index_t, typename tape_t::stce_9762) {});
      if (stce_9990) {
        for (typename std::map<index_t, stce_9762>::const_iterator stce_10005 = stce_9991.cbegin();
             stce_10005 != stce_9991.cend(); ++stce_10005) {
          stce_9994->insert(stce_10005->first, stce_10005->second);
        }
      }
      delete stce_9994;
    }
    stce_9986->reset_to(stce_9987);
    stce_9993 stce_10006 = stce_9926->current();
    for (typename std::vector<stce_9995*>::reverse_iterator stce_10004 = stce_9996.rbegin();
         stce_10004 != stce_9996.rend(); ++stce_10004) {
      stce_9985 stce_10007(stce_9986->insert_ref());
      for (;; --stce_10006) {
        stce_10007.insert(stce_10006->arg(), stce_10006->pval());
        if (stce_10006->stce_10008())
          break;
      }
      --stce_10006;
      (*stce_10004)->_tape_index() = stce_10007.index();
    }
    stce_9996.clear();
  }
  stce_9762& stce_9960(const index_t stce_9810) { return stce_9897[stce_9810 - stce_9988]; }
  template <class stce_9962>
  void _increment_adjoint(const index_t& stce_9810, const stce_9962& stce_9963, const stce_9762& stce_9923) {
    _increment_adjoint(stce_9810, stce_9963 * stce_9923);
  }
  void stce_9948(index_t stce_9872, index_t stce_9873) { stce_9897.stce_9948(stce_9872, stce_9873); }
  void stce_9950(index_t stce_9810) { stce_9897.stce_9950(stce_9810 - stce_9988); }
  stce_9762& operator[](const index_t stce_9810) { return stce_9897[stce_9810 - stce_9988]; }
  template <typename iterator_t> void stce_9946(iterator_t& stce_9825) {
    _increment_adjoint(stce_9825->arg(), stce_9825->pval() * (*this)[stce_9825.index()]);
  }
  virtual stce_9762 _read_adjoint(const index_t stce_9810) { return stce_9897[stce_9810 - stce_9988]; }
  virtual void _increment_adjoint(const index_t stce_9810, const stce_9762& stce_9923) {
    if (stce_9923 == 0)
      return;
    if (stce_9810 <= stce_9988) {
      if (stce_9990 == false) {
        stce_9994->insert(stce_9810, stce_9923);
      } else {
        stce_9991[stce_9810] += stce_9923;
      }
    } else {
      stce_9960(stce_9810) += stce_9923;
    }
  }
};
template <> struct jacobian_preaccumulator_t<void> {
  jacobian_preaccumulator_t(void*) {}
  void start() {}
  template <typename stce_9780> void register_output(const stce_9780&) {}
  void finish() {}
};
} // namespace internal
} // namespace dco

namespace dco {
namespace helper {
template <typename, typename stce_10009> struct stce_10010 {
  stce_10010(stce_10009*) {}
  template <typename stce_9780> void register_input(const stce_9780&) {}
  template <typename stce_9780> void register_output(const stce_9780&) {}
};
} // namespace helper
} // namespace dco

namespace dco {
namespace helper {
template <typename stce_10011> class stce_10012 {
  template <memory_model::TYPE, typename, memory_model::TYPE> friend class internal::tape;
  typedef typename stce_10011::stce_9936 stce_9762;

protected:
  stce_10011* stce_10013;

public:
  virtual ~stce_10012() {}
  dco::adjoint_vector_abstract<stce_9762>* _adjoint_vector;

public:
  void set_tape(stce_10011* stce_10014) {
    if (stce_10013 != 0) {
      return;
    } else {
      stce_10013 = stce_10014;
    }
  }
  void stce_10015() {}
  inline stce_10011* get_tape() { return stce_10013; }
  stce_10012() : stce_10013(0) {}
  virtual void stce_10016(stce_9859& stce_9860, index_t stce_9868) {
    (void)stce_9860;
    (void)stce_9868;
  }
  virtual mem_long_t size_in_byte() { return sizeof(stce_10011); }
};
} // namespace helper
} // namespace dco

namespace dco {
namespace helper {
template <class stce_10017, class stce_10011> class stce_10018 : public stce_10012<stce_10011> {
private:
  class stce_10019 {
  public:
    virtual ~stce_10019(){};
    virtual mem_long_t size_in_byte() = 0;
    virtual void stce_10020(const std::string&, const std::string&){};
  };
  template <typename stce_10021> class stce_10022 : public stce_10019 {
  public:
    const stce_10021 _data;
    stce_10022(const stce_10021& stce_10023) : _data(stce_10023) {}
    const stce_10021& stce_10024() const { return _data; }
  };
  template <typename stce_10021> class stce_10025 : public stce_10022<stce_10021> {
  public:
    stce_10025(stce_10021 data) : stce_10022<stce_10021>(data) {}
    virtual ~stce_10025() {}
    virtual mem_long_t size_in_byte() { return size_of(stce_10022<stce_10021>::_data); }
    virtual void stce_10020(const std::string& stce_10026, const std::string& stce_10027) {
      if (false && IS_DEBUG && stce_10027 != stce_10026) {
        std::stringstream stce_10028;
        stce_10028 << "read_data error: tried to read " << stce_10026 << " instead of " << stce_10027 << "!";
        throw dco::exception::create<std::runtime_error>(stce_10028.str());
      }
    }
  };
  template <typename stce_10021> class stce_10029 : public stce_10022<stce_10021*> {
  public:
    const index_t stce_10030;
    stce_10029(const stce_10021* data, index_t stce_10031)
        : stce_10022<stce_10021*>(new stce_10021[size_t(stce_10031)]), stce_10030(stce_10031) {
      for (index_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845)
        this->_data[stce_9845] = data[stce_9845];
    }
    stce_10029(const stce_10021* data, const index_t stce_9921, const index_t stce_10031)
        : stce_10022<stce_10021*>(new stce_10021[stce_9752(stce_10031)]), stce_10030(stce_10031) {
      for (index_t stce_9845 = 0, stce_9810 = 0; stce_9845 < stce_10031; ++stce_9845, stce_9810 += stce_9921)
        this->_data[stce_9845] = data[stce_9810];
    }
    virtual ~stce_10029() { delete[] this->_data; }
    virtual mem_long_t size_in_byte() { return stce_10030 * static_cast<index_t>(sizeof(stce_10021)); }
    virtual void stce_10020(const std::string& stce_10026, const std::string& stce_10027) {
      (void)stce_10026;
      (void)stce_10027;
      if (false && IS_DEBUG && stce_10027 + "*" != stce_10026) {
        std::stringstream stce_10028;
        stce_10028 << "read_data error: tried to read " << stce_10026 << " instead of " << stce_10027 << "!";
        throw dco::exception::create<std::runtime_error>(stce_10028.str());
      }
    }
  };
  index_t stce_10032;
  std::vector<stce_10019*> stce_10033;
  std::vector<std::string> stce_10034;

protected:
  virtual ~stce_10018() {
    for (size_t stce_9845 = 0; stce_9845 < stce_10033.size(); stce_9845++)
      delete stce_10033[stce_9845];
    stce_10033.clear();
  }

public:
  stce_10018() : stce_10012<stce_10011>(), stce_10032(0) {}
  virtual mem_long_t size_in_byte() {
    mem_long_t stce_9817 = stce_10012<stce_10011>::size_in_byte();
    for (size_t stce_9845 = 0; stce_9845 < stce_10033.size(); stce_9845++) {
      stce_9817 += stce_10033[stce_9845]->size_in_byte();
    }
    stce_9817 += stce_10033.size() * sizeof(stce_10019*);
    stce_9817 += stce_10034.size() * sizeof(std::string);
    return stce_9817;
  }
  template <typename stce_10021> void write_data(const stce_10021& stce_10035) {
    stce_10033.push_back(new stce_10025<stce_10021>(stce_10035));
    if (IS_DEBUG)
      stce_10034.push_back(type_name<stce_10021>());
  }
  template <typename stce_10021> void write_data(const stce_10021* const stce_10035, const index_t stce_10031) {
    stce_10033.push_back(new stce_10029<stce_10021>(stce_10035, stce_10031));
    if (IS_DEBUG)
      stce_10034.push_back(type_name<stce_10021>());
  }
  template <typename stce_10021>
  void write_data(const stce_10021* const& stce_10035, const index_t stce_9921, const index_t stce_10031) {
    stce_10033.push_back(new stce_10029<stce_10021>(stce_10035, stce_9921, stce_10031));
    if (IS_DEBUG) {
      stce_10034.push_back(type_name<stce_10021>());
    }
  }
  template <typename stce_10021> const stce_10021& read_data() {
    const stce_10021& stce_10035 = static_cast<stce_10022<stce_10021>*>(stce_10033[stce_10032])->stce_10024();
    if (IS_DEBUG)
      stce_10033[stce_10032]->stce_10020(type_name<stce_10021>(), stce_10034.at(stce_10032));
    ++stce_10032;
    if (stce_10032 == static_cast<index_t>(stce_10033.size()))
      stce_10032 = 0;
    return stce_10035;
  }
};
} // namespace helper
} // namespace dco

namespace dco {
namespace helper {
template <class stce_10017, class stce_10011>
class stce_10036 : public stce_10018<stce_10017, stce_10011>,
                   public stce_10010<stce_10011, stce_10036<stce_10017, stce_10011>> {
  typedef stce_10010<stce_10011, stce_10036> stce_10037;
  bool stce_10038;

protected:
  std::vector<index_t> stce_9866;
  std::vector<index_t> stce_9867;
  size_t stce_10039;
  size_t stce_10040;

public:
  stce_10011*& tape() { return this->stce_10013; }
  virtual mem_long_t size_in_byte() {
    mem_long_t stce_9817 = stce_10018<stce_10017, stce_10011>::size_in_byte();
    stce_9817 += stce_9866.size() * sizeof(index_t);
    stce_9817 += stce_9867.size() * sizeof(index_t);
    stce_9817 += 2 * sizeof(index_t);
    return stce_9817;
  }
  size_t stce_10041() { return stce_9866.size(); }
  size_t stce_10042() { return stce_9867.size(); }
  void stce_10015() { stce_10038 = true; }
  void stce_10016(stce_9859& stce_9860, index_t stce_9868) {
    stce_9860.stce_9865(stce_9866, stce_9867, stce_9868 - static_cast<index_t>(stce_9867.size()) - 1);
  }

public:
  void stce_10043(const stce_10017& stce_9807) {
    if ((stce_9807.tape() != 0) && (this->stce_10013 != stce_9807.tape()))
      throw dco::exception::create<std::runtime_error>("impossible binding tape - wrong tape in variable!");
    if (this->stce_10038 == true) {
      throw dco::exception::create<std::runtime_error>(
          "Input registration required, but callback already inserted; please check ordering.");
    }
  }
  void stce_10044() {
    if (this->stce_10013 == NULL) {
      throw dco::exception::create<std::runtime_error>("Output registration required, but no tape available.");
    }
    if (this->stce_10038 == true) {
      throw dco::exception::create<std::runtime_error>(
          "Output registration required, but callback already inserted; please check ordering.");
    }
  }

protected:
  ~stce_10036() {
    if (IS_DEBUG && stce_10039 != 0) {
      DCO_LOG(dco::logERROR) << "not all input adjoints incremented in external adjoint object.";
    }
    if (IS_DEBUG && stce_10040 != 0) {
      DCO_LOG(dco::logERROR) << "not all output adjoints read in external adjoint object.";
    }
  }

public:
  stce_10036(const std::pair<size_t, size_t>& stce_10045)
      : stce_10018<stce_10017, stce_10011>(), stce_10037(this), stce_10038(false), stce_10039(0), stce_10040(0) {
    stce_9866.reserve(stce_10045.first);
    stce_9867.reserve(stce_10045.second);
  }
  stce_10036()
      : stce_10018<stce_10017, stce_10011>(), stce_10037(this), stce_10038(false), stce_10039(0), stce_10040(0) {}
  typename stce_10017::VALUE_TYPE register_input(const stce_10017& stce_9807) {
    stce_10043(stce_9807);
    const index_t stce_9810 = stce_9807._tape_index();
    stce_9866.push_back(stce_9810);
    stce_10037::register_input(stce_9807);
    return stce_9807._value();
  }
  void register_input(const stce_10017* const stce_9807, typename stce_10017::VALUE_TYPE* stce_10046,
                      const size_t stce_10031) {
    stce_9866.reserve(stce_9866.size() + stce_10031);
    for (size_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845) {
      stce_10043(stce_9807[stce_9845]);
      const index_t stce_9810 = stce_9807[stce_9845]._tape_index();
      stce_9866.push_back(stce_9810);
      stce_10046[stce_9845] = stce_9807[stce_9845]._value();
      stce_10037::register_input(stce_9807[stce_9845]);
    }
  }
  void register_input(const std::vector<stce_10017>& stce_9807,
                      std::vector<typename stce_10017::VALUE_TYPE>& stce_10046) {
    assert(stce_9807.size() == stce_10046.size());
    register_input(&(stce_9807[0]), &(stce_10046[0]), stce_9807.size());
  }
  std::vector<typename stce_10017::VALUE_TYPE> register_input(const std::vector<stce_10017>& stce_9807) {
    std::vector<typename stce_10017::VALUE_TYPE> stce_10046(stce_9807.size());
    register_input(stce_9807, stce_10046);
    return stce_10046;
  }
  void register_output(stce_10017* stce_10047, const size_t stce_10031) {
    register_output(NULL, stce_10047, stce_10031);
  }
  void register_output(const typename stce_10017::VALUE_TYPE* const stce_10048, stce_10017* stce_10047,
                       const size_t stce_10031) {
    stce_10044();
    stce_9867.reserve(stce_9867.size() + stce_10031);
    for (size_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845) {
      if (stce_10048) {
        stce_10047[stce_9845] = stce_10048[stce_9845];
      }
      this->stce_10013->register_variable(stce_10047[stce_9845]);
      stce_9867.push_back(stce_10047[stce_9845]._tape_index());
      stce_10037::register_output(stce_10047[stce_9845]);
    }
  }
  void register_output(const std::vector<typename stce_10017::VALUE_TYPE>& stce_10048,
                       std::vector<stce_10017>& stce_10047) {
    assert(stce_10048.size() == stce_10047.size());
    register_output(&(stce_10048[0]), &(stce_10047[0]), stce_10048.size());
  }
  std::vector<stce_10017> register_output(const std::vector<typename stce_10017::VALUE_TYPE>& stce_10048) {
    std::vector<stce_10017> stce_10047(stce_10048.size());
    register_output(stce_10048, stce_10047);
    return stce_10047;
  }
  void register_output(std::vector<stce_10017>& stce_10047) { register_output(&(stce_10047[0]), stce_10047.size()); }
  stce_10017 register_output(const typename stce_10017::VALUE_TYPE& stce_10049, stce_10011* tape = NULL) {
    stce_10017 stce_10050;
    if (tape != NULL) {
      if (this->stce_10013 != NULL && this->stce_10013 != tape) {
        throw dco::exception::create<std::runtime_error>(
            "impossible binding output in external function (register_output) - tape of inputs and outputs differ!");
      }
      this->stce_10013 = tape;
    }
    stce_10044();
    stce_10050 = stce_10049;
    this->stce_10013->register_variable(stce_10050);
    stce_9867.push_back(stce_10050._tape_index());
    stce_10037::register_output(stce_10050);
    return stce_10050;
  }
  inline typename dco::mode<stce_10017>::stce_9983 get_output_adjoint() {
    size_t stce_9810 = stce_10040;
    stce_10040++;
    if (stce_10040 == stce_9867.size())
      stce_10040 = 0;
    typename dco::mode<stce_10017>::stce_9983 back = this->_adjoint_vector->_read_adjoint(stce_9867[stce_9810]);
    return back;
  }
  void get_output_adjoint(typename stce_10017::VALUE_TYPE* stce_9811, const size_t stce_10031) {
    size_t stce_9810 = stce_10040;
    for (size_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845) {
      stce_9811[stce_9845] = get_output_adjoint();
      stce_9810++;
    }
    if (stce_10040 == stce_9867.size()) {
      stce_10040 = 0;
    }
  }
  void get_output_adjoint(std::vector<typename stce_10017::VALUE_TYPE>& stce_9811) {
    assert(stce_9811.size());
    get_output_adjoint(&(stce_9811[0]), stce_9811.size());
  }
  void increment_input_adjoint(const typename stce_10017::VALUE_TYPE* const stce_9923, const size_t stce_10031) {
    for (size_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845) {
      this->_adjoint_vector->_increment_adjoint(stce_9866[stce_10039 + stce_9845], stce_9923[stce_9845]);
    }
    stce_10039 += stce_10031;
    if (stce_10039 == stce_9866.size())
      stce_10039 = 0;
  }
  void increment_input_adjoint(const std::vector<typename stce_10017::VALUE_TYPE>& stce_9923) {
    assert(stce_9923.size() != 0);
    increment_input_adjoint(&(stce_9923[0]), stce_9923.size());
  }
  bool stce_10051() {
    if (stce_10039 == 0)
      return true;
    else
      return false;
  }
  bool stce_10052() {
    if (stce_10040 == 0)
      return true;
    else
      return false;
  }
  void increment_input_adjoint(const typename dco::mode<stce_10017>::stce_9983& stce_9923) {
    size_t stce_9810 = stce_10039;
    stce_10039++;
    if (stce_10039 == stce_9866.size())
      stce_10039 = 0;
    this->_adjoint_vector->_increment_adjoint(stce_9866[stce_9810], stce_9923);
  }
};
} // namespace helper
} // namespace dco

namespace dco {
namespace ACM {
template <class stce_10011, class stce_10053> struct baseclass : dco::helper::stce_10012<stce_10011> {
private:
  std::vector<stce_10053*> stce_10054;
  std::vector<stce_10053*> stce_10055;
  std::vector<index_t> stce_10056;
  std::vector<index_t> stce_10057;
  std::vector<void*> _data;
  int stce_10058;

public:
  typedef stce_10053 active_t;
  typedef stce_10011 tape_t;
  baseclass(tape_t* tape) : stce_10058(0) { this->set_tape(tape); }
  size_t register_input(stce_10053& stce_9807) {
    size_t stce_9847 = stce_10054.size();
    stce_10054.push_back(&stce_9807);
    stce_10057.push_back(stce_9807._tape_index());
    return stce_9847;
  }
  size_t register_input(std::vector<stce_10053>& stce_10059) {
    size_t stce_9847 = stce_10054.size();
    for (int stce_9845 = 0; stce_9845 < stce_10059.size(); ++stce_9845) {
      const stce_10053& stce_10060 = stce_10059[stce_9845];
      this->register_input(stce_10060);
    }
    return stce_9847;
  }
  size_t register_output(stce_10053& stce_9807) {
    if (stce_9807._tape_index() == 0) {
      this->get_tape()->register_variable(stce_9807);
    }
    size_t stce_9847 = stce_10055.size();
    stce_10055.push_back(&stce_9807);
    stce_10056.push_back(stce_9807._tape_index());
    return stce_9847;
  }
  int register_output(std::vector<stce_10053>& stce_10059) {
    int stce_9847 = stce_10055.size();
    for (int stce_9845 = 0; stce_9845 < stce_10059.size(); ++stce_9845) {
      if (stce_10059[stce_9845]._tape_index() == 0) {
        this->get_tape()->register_variable(stce_10059[stce_9845]);
      }
      stce_10056.push_back(stce_10059[stce_9845]._tape_index());
      stce_10055.push_back(&stce_10059[stce_9845]);
    }
    return stce_9847;
  }
  template <typename stce_9780> int write_data(const stce_9780& data) {
    stce_9780* stce_10061 = new stce_9780(data);
    int stce_9847 = _data.size();
    _data.push_back(stce_10061);
    return stce_9847;
  }
  template <typename stce_9780> const stce_9780& read_data(const int stce_10062 = -1) {
    int stce_9810 = 0;
    if (stce_10062 == -1) {
      stce_9810 = stce_10058 % _data.size();
      stce_10058++;
    }
    void* stce_10063 = _data[stce_9810];
    return *static_cast<stce_9780*>(stce_10063);
  }
  size_t stce_10064() { return stce_10054.size(); }
  size_t stce_10065() { return stce_10054.size(); }
  typename stce_10053::VALUE_TYPE& input_value(const int stce_9810) { return stce_10054[stce_9810]->_value(); }
  typename stce_10053::VALUE_TYPE& output_value(const int stce_9810) { return stce_10055[stce_9810]->_value(); }
  typename dco::mode<stce_10053>::stce_9983& input_adjoint(const int stce_9810) {
    return this->get_tape()->_adjoint(stce_10057[stce_9810]);
  }
  typename dco::mode<stce_10053>::stce_9983& output_adjoint(const int stce_9810) {
    return this->get_tape()->_adjoint(stce_10056[stce_9810]);
  }
  virtual void evaluate_primal() { std::cout << "WARNING: you need to implement evaluate_primal!!!!\n"; }
  virtual void evaluate_augmented_primal() {
    std::cout << "WARNING: you need to implement evaluate_augmented_primal!!!!\n";
  }
  virtual void evaluate_adjoint() { std::cout << "WARNING: you need to implement evaluate_adjoint!!!!\n"; }
};
template <class stce_10011, class stce_10053> static void stce_10066(baseclass<stce_10011, stce_10053>* stce_10067) {
  stce_10067->evaluate_adjoint();
}
} // namespace ACM
} // namespace dco
namespace dco {
namespace stce_10068 {
template <class stce_10069> struct stce_10070 {
  std::vector<stce_10069*> stce_10054;
  std::vector<stce_10069*> stce_10055;
  std::vector<void*> _data;
  int stce_10058;
  stce_10070() : stce_10058(0) {}
  virtual ~stce_10070() {}
  template <typename stce_9780> int write_data(const stce_9780& data) {
    stce_9780* stce_10061 = new stce_9780(data);
    int stce_9847 = _data.size();
    _data.push_back(stce_10061);
    return stce_9847;
  }
  template <typename stce_9780> const stce_9780& read_data(const int stce_10062 = -1) {
    int stce_9810 = 0;
    if (stce_10062 == -1) {
      stce_9810 = stce_10058 % _data.size();
      stce_10058++;
    }
    void* stce_10063 = _data[stce_9810];
    return *static_cast<stce_9780*>(stce_10063);
  }
  size_t stce_10064() { return stce_10054.size(); }
  size_t stce_10065() { return stce_10055.size(); }
  stce_10069& input_value(const int stce_9810) { return *stce_10054[stce_9810]; }
  stce_10069& output_value(const int stce_9810) { return *stce_10055[stce_9810]; }
  virtual void evaluate_primal() { std::cout << "WARNING: you need to implement evaluate_primal!!!!\n"; }
};
template <class stce_10069> struct stce_10071 : stce_10070<stce_10069> {
  int register_input(stce_10069& stce_9807) {
    int stce_9847 = this->stce_10054.size();
    this->stce_10054.push_back(&stce_9807);
    return stce_9847;
  }
  int register_input(std::vector<stce_10069>& stce_10059) {
    int stce_9847 = this->stce_10054.size();
    for (int stce_9845 = 0; stce_9845 < stce_10059.size(); ++stce_9845) {
      const stce_10069& stce_10060 = stce_10059[stce_9845];
      this->register_input(stce_10060);
    }
    return stce_9847;
  }
  int register_output(stce_10069& stce_9807) {
    int stce_9847 = this->stce_10055.size();
    this->stce_10055.push_back(&stce_9807);
    return stce_9847;
  }
  int register_output(std::vector<stce_10069>& stce_10059) {
    int stce_9847 = this->stce_10055.size();
    for (int stce_9845 = 0; stce_9845 < stce_10059.size(); ++stce_9845) {
      register_output(stce_10059[stce_9845]);
    }
    return stce_9847;
  }
};
template <class stce_10011, class stce_10053>
struct stce_10072 : public dco::helper::stce_10012<stce_10011>, public stce_10070<stce_10053> {
private:
  std::vector<index_t> stce_10056;
  std::vector<index_t> stce_10057;

public:
  typedef stce_10053 active_t;
  typedef stce_10011 tape_t;
  stce_10072(tape_t* tape) { this->set_tape(tape); }
  stce_10053& stce_10073(const int stce_9810) { return *(this->stce_10054[stce_9810]); }
  stce_10053& stce_10074(const int stce_9810) { return *(this->stce_10055[stce_9810]); }
  typename stce_10053::VALUE_TYPE& input_value(const int stce_9810) { return this->stce_10054[stce_9810]->_value(); }
  typename stce_10053::VALUE_TYPE& output_value(const int stce_9810) { return this->stce_10055[stce_9810]->_value(); }
  typename dco::mode<stce_10053>::stce_9983& input_adjoint(const int stce_9810) {
    return this->get_tape()->_adjoint(stce_10057[stce_9810]);
  }
  typename dco::mode<stce_10053>::stce_9983& output_adjoint(const int stce_9810) {
    return this->get_tape()->_adjoint(stce_10056[stce_9810]);
  }
  int register_input(stce_10053& stce_9807) {
    int stce_9847 = this->stce_10054.size();
    this->stce_10054.push_back(&stce_9807);
    this->stce_10057.push_back(stce_9807._tape_index());
    return stce_9847;
  }
  int register_input(std::vector<stce_10053>& stce_10059) {
    int stce_9847 = this->stce_10054.size();
    for (int stce_9845 = 0; stce_9845 < stce_10059.size(); ++stce_9845) {
      const stce_10053& stce_10060 = stce_10059[stce_9845];
      this->register_input(stce_10060);
    }
    return stce_9847;
  }
  int register_output(stce_10053& stce_9807) {
    if (stce_9807._tape_index() == 0) {
      this->get_tape()->register_variable(stce_9807);
    }
    int stce_9847 = this->stce_10055.size();
    this->stce_10055.push_back(&stce_9807);
    this->stce_10056.push_back(stce_9807._tape_index());
    return stce_9847;
  }
  int register_output(std::vector<stce_10053>& stce_10059) {
    int stce_9847 = this->stce_10055.size();
    for (int stce_9845 = 0; stce_9845 < stce_10059.size(); ++stce_9845) {
      if (stce_10059[stce_9845]._tape_index() == 0) {
        this->get_tape()->register_variable(stce_10059[stce_9845]);
      }
      this->stce_10056.push_back(stce_10059[stce_9845]._tape_index());
      this->stce_10055.push_back(&stce_10059[stce_9845]);
    }
    return stce_9847;
  }
  virtual void evaluate_augmented_primal() {
    std::cout << "WARNING: you need to implement evaluate_augmented_primal!!!!\n";
  }
  virtual void evaluate_adjoint() { std::cout << "WARNING: you need to implement evaluate_adjoint!!!!\n"; }
};
template <class stce_10011, class stce_10053> static void stce_10066(stce_10072<stce_10011, stce_10053>* stce_10067) {
  stce_10067->evaluate_adjoint();
}
} // namespace stce_10068
} // namespace dco

namespace dco {
namespace internal {
template <class stce_10053> class stce_10075 {
private:
  typedef typename dco::mode<stce_10053>::tape_t tape_t;
  typedef typename tape_t::stce_9761 stce_9761;
  typedef typename tape_t::edge_inserter edge_inserter;
  stce_10053& stce_10076;
  edge_inserter stce_9994;
  stce_10075(const stce_10075&);

public:
  stce_10075(stce_10053& stce_10077) : stce_10076(stce_10077), stce_9994(stce_10077.tape()->insert_ref()) {}
  template <typename stce_9793> void put(const stce_9793& stce_9807, const stce_9761& stce_9963) {
    index_t stce_10078 = stce_9807._tape_index();
    if (!HAS_TAPE_ACTIVITY_CHECK || stce_10078 != 0) {
      bool stce_10079 = (stce_9994.index() == 0);
      stce_9994.insert(stce_10078, stce_9963);
      stce_10076._tape_index() = stce_9994.index();
      if (stce_10079)
        stce_10076.stce_10080(stce_10076._value(), stce_9824());
    }
  }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <class stce_10081> struct stce_10082 {
  typedef typename stce_10081::tape_t::stce_9762 derivative_t;

protected:
  mutable index_t stce_10083;

public:
  stce_10082() : stce_10083(0) {}
  DCO_STRONG_INLINE stce_10082(const stce_10082& stce_10084) : stce_10083(stce_10084.stce_10083) {}
  DCO_STRONG_INLINE stce_10082& operator=(const stce_10082& stce_9807) {
    stce_10083 = stce_9807.stce_10083;
    return *this;
  }
  void clear() { stce_10083 = 0; }
  derivative_t& stce_9967() const { return _adjoint(); }
  derivative_t& _adjoint() const {
    if (IS_DEBUG && !stce_10081::global_tape)
      throw dco::exception::create<std::runtime_error>(
          "Tape not created yet. Please use tape_t::create() before accessing derivative components of adjoint types.");
    return stce_10081::global_tape->_adjoint(stce_10083);
  }
  void stce_10085(const derivative_t& stce_9846) const {
    if (IS_DEBUG && !stce_10081::global_tape)
      throw dco::exception::create<std::runtime_error>(
          "Tape not created yet. Please use tape_t::create() before accessing derivative components of adjoint types.");
    stce_10081::global_tape->_adjoint(stce_10083) = stce_9846;
  }
  bool _is_registered() const { return stce_10083 == 0 ? false : true; }
  index_t& _tape_index() const { return stce_10083; }
  template <class stce_10069> DCO_STRONG_INLINE void stce_10080(const stce_10069&, const double&) {}
  template <typename stce_10086>
  static DCO_STRONG_INLINE void register_variable(stce_10086& stce_9807, index_t index, typename stce_10081::tape_t*) {
    if (IS_DEBUG && !stce_10081::global_tape) {
      throw dco::exception::create<std::runtime_error>("Global tape not yet created (is NULL).");
    }
    stce_9807.stce_10083 = index;
  }
  static typename stce_10081::tape_t* tape() { return stce_10081::global_tape; }
  void set_tape(typename stce_10081::tape_t*) {}
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
struct stce_10087 {
  template <class stce_10088, class stce_10089>
  static auto stce_10090(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() == stce_10092._value()) {
    return stce_10091._value() == stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10093(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() == stce_10092) {
    return stce_10091._value() == stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10094(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 == stce_10092._value()) {
    return stce_10091 == stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10095(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() != stce_10092._value()) {
    return stce_10091._value() != stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10096(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() != stce_10092) {
    return stce_10091._value() != stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10097(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 != stce_10092._value()) {
    return stce_10091 != stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10098(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() < stce_10092._value()) {
    return stce_10091._value() < stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10099(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() < stce_10092) {
    return stce_10091._value() < stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10100(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 < stce_10092._value()) {
    return stce_10091 < stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10101(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() <= stce_10092._value()) {
    return stce_10091._value() <= stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10102(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() <= stce_10092) {
    return stce_10091._value() <= stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10103(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 <= stce_10092._value()) {
    return stce_10091 <= stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10104(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() > stce_10092._value()) {
    return stce_10091._value() > stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10105(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() > stce_10092) {
    return stce_10091._value() > stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10106(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 > stce_10092._value()) {
    return stce_10091 > stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10107(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() >= stce_10092._value()) {
    return stce_10091._value() >= stce_10092._value();
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10108(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091._value() >= stce_10092) {
    return stce_10091._value() >= stce_10092;
  }
  template <class stce_10088, class stce_10089>
  static auto stce_10109(const stce_10088& stce_10091, const stce_10089& stce_10092)
      -> decltype(stce_10091 >= stce_10092._value()) {
    return stce_10091 >= stce_10092._value();
  }
};
template <class stce_10110, stce_10110*& stce_9986> struct stce_10111 {
  template <class stce_10088, class stce_10089>
  static bool stce_10090(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() == stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) == stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) == stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_AA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10093(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() == stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) == stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) == stce_10092;
    stce_9986->stce_10115("compare_AP", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10094(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091 == stce_10092._value();
    const bool stce_10112 = stce_10091 == stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 == stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_PA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10095(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() != stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) != stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) != stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_AA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10096(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() != stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) != stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) != stce_10092;
    stce_9986->stce_10115("compare_AP", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10097(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091 != stce_10092._value();
    const bool stce_10112 = stce_10091 != stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 != stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_PA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10098(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() < stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) < stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) < stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_AA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10099(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() < stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) < stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) < stce_10092;
    stce_9986->stce_10115("compare_AP", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10100(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091 < stce_10092._value();
    const bool stce_10112 = stce_10091 < stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 < stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_PA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10101(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() <= stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) <= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) <= stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_AA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10102(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() <= stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) <= stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) <= stce_10092;
    stce_9986->stce_10115("compare_AP", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10103(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091 <= stce_10092._value();
    const bool stce_10112 = stce_10091 <= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 <= stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_PA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10104(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() > stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) > stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) > stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_AA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10105(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() > stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) > stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) > stce_10092;
    stce_9986->stce_10115("compare_AP", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10106(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091 > stce_10092._value();
    const bool stce_10112 = stce_10091 > stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 > stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_PA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10107(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() >= stce_10092._value();
    const bool stce_10112 = stce_10091.stce_10113(0) >= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091.stce_10113(1) >= stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_AA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10108(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091._value() >= stce_10092;
    const bool stce_10112 = stce_10091.stce_10113(0) >= stce_10092;
    const bool stce_10114 = stce_10091.stce_10113(1) >= stce_10092;
    stce_9986->stce_10115("compare_AP", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
  template <class stce_10088, class stce_10089>
  static bool stce_10109(const stce_10088& stce_10091, const stce_10089& stce_10092) {
    const bool stce_9847 = stce_10091 >= stce_10092._value();
    const bool stce_10112 = stce_10091 >= stce_10092.stce_10113(0);
    const bool stce_10114 = stce_10091 >= stce_10092.stce_10113(1);
    stce_9986->stce_10115("compare_PA", stce_9847, stce_10112, stce_10114);
    return stce_9847;
  }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace folding {
template <class stce_10116> class stce_10117 {
public:
  typedef typename stce_10116::stce_9762 stce_9762;
  typedef typename stce_10116::stce_9761 stce_9761;
  typedef typename stce_10116::edge_inserter stce_10118;
  stce_10117(stce_10116* tape) : stce_10119(1), stce_9994(tape->insert_ref()) {}
  template <class stce_10120, typename stce_9759> DCO_ALWAYS_INLINE stce_10120& stce_10121(stce_9759 const& pval) {
    stce_10119 *= static_cast<stce_9761>(pval);
    return static_cast<stce_10120&>(*this);
  }
  DCO_ALWAYS_INLINE stce_9761& pval() { return stce_10119; }
  DCO_ALWAYS_INLINE index_t index() const { return stce_9994.index(); }
  template <class stce_10086> DCO_ALWAYS_INLINE void insert(stce_10086 const& stce_9807) {
    const index_t stce_10122 = stce_9807._tape_index();
    if (!HAS_TAPE_ACTIVITY_CHECK || stce_10122 != 0) {
      if (!stce_9755 || !is_zero(stce_10119)) {
        stce_9994.insert(stce_10122, stce_10119);
      }
    }
  }

protected:
  stce_9761 stce_10119;

private:
  stce_10117();
  stce_10117(stce_10117& stce_9934);
  stce_10118 stce_9994;
};
template <class stce_10116> class stce_10123 : public stce_10117<stce_10116> {
  typedef typename stce_10116::stce_9762 stce_9762;
  typedef typename stce_10116::edge_inserter stce_10118;

public:
  stce_10123(stce_10116* tape) : stce_10117<stce_10116>(tape), stce_10124(0) {}
  template <class stce_10086> DCO_ALWAYS_INLINE void insert(stce_10086 stce_9807) {
    stce_10117<stce_10116>::insert(stce_9807);
    stce_10124 += this->stce_10119 * stce_9807.stce_9973;
  }
  stce_9762 tangent() const { return stce_10124; }

private:
  stce_10123();
  stce_10123(stce_10123& stce_9934);
  stce_9762 stce_10124;
};
template <class stce_10125, class stce_9758, class stce_10126>
DCO_ALWAYS_INLINE void interpret(const dco::internal::active_type<stce_9758, stce_10126>& stce_9807,
                                 stce_10125& stce_10127) {
  stce_10127.insert(stce_9807);
}
template <class stce_10125, class stce_9758, class stce_10128, class stce_10129, class stce_10130>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9777<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9807,
          stce_10125& stce_10127) {
  typename stce_10125::stce_9761 stce_10131 = stce_10127.pval();
  interpret<stce_10125>(stce_9807.stce_10132, stce_10127.template stce_10121<stce_10125>(stce_9807.stce_10133()));
  stce_10127.pval() = stce_10131;
  interpret<stce_10125>(stce_9807.stce_10134, stce_10127.template stce_10121<stce_10125>(stce_9807.stce_10135()));
}
template <class stce_10125, class stce_9758, class stce_10136, class stce_10130>
DCO_ALWAYS_INLINE void interpret(const dco::internal::stce_9774<stce_9758, stce_10136, stce_10130>& stce_9807,
                                 stce_10125& stce_10127) {
  interpret<stce_10125>(stce_9807.stce_10137, stce_10127.template stce_10121<stce_10125>(stce_9807.pval()));
}
template <class stce_10125, class stce_9758, class stce_10128, class stce_10129, class stce_10130>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9778<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9807,
          stce_10125& stce_10127) {
  interpret<stce_10125>(stce_9807.stce_10132, stce_10127.template stce_10121<stce_10125>(stce_9807.stce_10133()));
}
template <class stce_10125, class stce_9758, class stce_10128, class stce_10129, class stce_10130>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9779<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9807,
          stce_10125& stce_10127) {
  interpret<stce_10125>(stce_9807.stce_10134, stce_10127.template stce_10121<stce_10125>(stce_9807.stce_10135()));
}
template <class stce_10116> class stce_10138 {
public:
  stce_10138() : stce_9986(0) {}
  template <class stce_10086> DCO_ALWAYS_INLINE void insert(stce_10086 stce_9807) {
    if (stce_9807.tape())
      stce_9986 = stce_9807.tape();
  }
  stce_10116* tape() const { return stce_9986; }

private:
  stce_10138(stce_10138& stce_9934);
  stce_10116* stce_9986;
};
template <class stce_9758, class stce_10128, class stce_10129, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9777<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9807,
          stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9807.stce_10132, stce_10127);
  if (stce_10127.tape()) {
    if (IS_DEBUG) {
      stce_10116* tape = stce_10127.tape();
      interpret(stce_9807.stce_10134, stce_10127);
      if (tape != stce_10127.tape()) {
        throw dco::exception::create<std::runtime_error>(
            "multiple tape error: different tapes on right-hand side of statement",
            "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/dco_cpp_make_release/dco_cpp_dev/src/"
            "dco_folding.hpp",
            143);
      }
    }
    return;
  }
  interpret(stce_9807.stce_10134, stce_10127);
}
template <class stce_9758, class stce_10136, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void interpret(const dco::internal::stce_9774<stce_9758, stce_10136, stce_10130>& stce_9807,
                                 stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9807.stce_10137, stce_10127);
}
template <class stce_9758, class stce_10128, class stce_10129, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9778<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9807,
          stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9807.stce_10132, stce_10127);
}
template <class stce_9758, class stce_10128, class stce_10129, class stce_10130, class stce_10116>
DCO_ALWAYS_INLINE void
interpret(const dco::internal::stce_9779<stce_9758, stce_10128, stce_10129, stce_10130>& stce_9807,
          stce_10138<stce_10116>& stce_10127) {
  interpret(stce_9807.stce_10134, stce_10127);
}
} // namespace folding
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_10081> class stce_10139 : public stce_10082<stce_10081> {
  typedef stce_10082<stce_10081> stce_10140;

public:
  typedef stce_10081 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename stce_10081::tape_t tape_t;
  typedef typename tape_t::stce_9762 derivative_t;
  stce_10139() {}
  DCO_STRONG_INLINE stce_10139(const stce_10139& stce_10084) : stce_10140(stce_10084) {}
  DCO_STRONG_INLINE stce_10139& operator=(const stce_10139& stce_9807) {
    stce_10140::operator=(static_cast<const stce_10140&>(stce_9807));
    return *this;
  }
  template <class stce_9908> DCO_ALWAYS_INLINE void stce_9909(const stce_9908& stce_10142) {
    if (!stce_10081::global_tape || !stce_10081::global_tape->is_active()) {
      this->clear();
      return;
    }
    using namespace folding;
    stce_10117<tape_t> stce_10143(stce_10081::global_tape);
    interpret(stce_10142, stce_10143);
    this->stce_10083 = stce_10143.index();
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9759 = stce_9780, typename stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1s {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef ga1s mode_t;
  typedef dco::internal::stce_10139<ga1s> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <class stce_9780, class stce_9759, class stce_9760, memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1s<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1s<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::global_tape = 0;
} // namespace dco
namespace dco {
typedef ga1s<double> a1w;
typedef double w_rtype;
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_10081> class stce_10146 {
  typedef typename stce_10081::tape_t tape_t;
  mutable index_t stce_10083;
  mutable tape_t* stce_10147;

public:
  typedef stce_10081 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename tape_t::stce_9762 derivative_t;
  stce_10146() : stce_10083(0), stce_10147(0) {}
  DCO_STRONG_INLINE stce_10146& operator=(const stce_10146& stce_9807) {
    stce_10083 = stce_9807.stce_10083;
    stce_10147 = stce_9807.stce_10147;
    return *this;
  }
  DCO_STRONG_INLINE stce_10146(const stce_10146& stce_10084)
      : stce_10083(stce_10084.stce_10083), stce_10147(stce_10084.stce_10147) {}
  void clear() {
    stce_10083 = 0;
    stce_10147 = 0;
  }
  derivative_t& stce_9967() const { return _adjoint(); }
  derivative_t& _adjoint() const {
    static derivative_t stce_9968 = static_cast<derivative_t>(0);
    if (stce_10147 == 0) {
      stce_9968 = 0;
      return stce_9968;
    } else {
      return stce_10147->_adjoint(stce_10083);
    }
  }
  void stce_10085(const derivative_t& stce_9846) const {
    if (stce_10147 != 0)
      stce_10147->_adjoint(stce_10083) = stce_9846;
  }
  bool _is_registered() const { return stce_10083 == 0 ? false : true; }
  index_t& _tape_index() const { return stce_10083; }
  template <typename stce_10069> DCO_STRONG_INLINE void stce_10080(const stce_10069&, const double&) {}
  template <typename stce_10086>
  static DCO_STRONG_INLINE void register_variable(stce_10086& stce_9807, index_t index, tape_t* tape) {
    stce_9807.stce_10147 = tape;
    stce_9807.stce_10083 = index;
  }
  tape_t* tape() const { return stce_10147; }
  void set_tape(tape_t* stce_9780) { stce_10147 = stce_9780; }
  template <class stce_9908> DCO_ALWAYS_INLINE void stce_9909(const stce_9908& stce_10142) {
    using namespace folding;
    stce_10138<tape_t> stce_10138;
    interpret(stce_10142, stce_10138);
    tape_t* stce_10148 = stce_10138.tape();
    if (!stce_10148 || !stce_10148->is_active()) {
      clear();
      return;
    }
    stce_10117<tape_t> stce_10143(stce_10148);
    interpret(stce_10142, stce_10143);
    stce_10083 = stce_10143.index();
    stce_10147 = stce_10148;
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, class stce_9759 = stce_9780, class stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1sm {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef ga1sm mode_t;
  typedef dco::internal::stce_10146<ga1sm> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_10081> struct data_g {
  typedef stce_10081 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename mode_t::derivative_t derivative_t;
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780> class gvalue {
public:
  typedef internal::data_g<gvalue> data_t;
  typedef stce_9780 active_value_t;
  typedef stce_9780 type;
  typedef type active_t;
  typedef stce_9780 value_t;
  typedef value_t scalar_value_t;
  typedef stce_9780 passive_t;
  typedef stce_9780 scalar_passive_t;
  typedef void derivative_t;
  typedef void stce_9983;
  typedef void tape_t;
  typedef void local_gradient_t;
  typedef void local_gradient_with_activity_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  static const bool is_dco_type = false;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = 0;
  static const size_t p1f_size = 0;
  static tape_t* global_tape;
};
template <typename stce_9780> typename gvalue<stce_9780>::tape_t* gvalue<stce_9780>::global_tape = 0;
} // namespace dco
namespace dco {
template <typename stce_9780> struct mode : public dco::gvalue<stce_9780> {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770>> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770> const> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770>&> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770> const&> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9769, typename stce_9770>
struct mode<internal::active_type<stce_9769, stce_9770>&&> : public stce_9770::mode_t {
  static const bool is_intermediate_type = false;
};
template <typename stce_9780, typename stce_10009, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10009, stce_10149>>
    : public internal::stce_9774<stce_9780, stce_10009, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10009, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10009, stce_10149> const>
    : public internal::stce_9774<stce_9780, stce_10009, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10009, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10009, stce_10149>&>
    : public internal::stce_9774<stce_9780, stce_10009, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10009, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10009, stce_10149> const&>
    : public internal::stce_9774<stce_9780, stce_10009, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <typename stce_9780, typename stce_10009, typename stce_10149>
struct mode<internal::stce_9774<stce_9780, stce_10009, stce_10149>&&>
    : public internal::stce_9774<stce_9780, stce_10009, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149> const>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>&>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149> const&>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10150, class stce_10151, class stce_10149>
struct mode<internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>&&>
    : public internal::stce_9777<stce_9780, stce_10150, stce_10151, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>>
    : public internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149> const>
    : public internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>&>
    : public internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149> const&>
    : public internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>&&>
    : public internal::stce_9778<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>>
    : public internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149> const>
    : public internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>&>
    : public internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149> const&>
    : public internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9780, class stce_10009, class stce_9875, class stce_10149>
struct mode<internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>&&>
    : public internal::stce_9779<stce_9780, stce_10009, stce_9875, stce_10149>::data_t::mode_t {
  static const bool is_intermediate_type = true;
};
template <class stce_9769, class DATA_TYPE>
struct mode<internal::stce_9771<stce_9769, DATA_TYPE>> : public DATA_TYPE::mode_t {
  static const bool is_intermediate_type = true;
};
} // namespace dco

namespace std {
template <typename stce_9780, typename stce_10152, typename stce_10153, typename stce_10154, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9777<stce_10152, stce_10153, stce_10154, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10153>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9774<stce_10152, stce_10150, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9778<stce_10152, stce_10150, stce_10151, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<stce_9780, dco::internal::stce_9779<stce_10152, stce_10150, stce_10151, stce_10155>> {
  using type =
      typename std::common_type<typename dco::mode<stce_9780>::type, typename dco::mode<stce_10151>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10153, typename stce_10154, typename stce_10155>
struct common_type<dco::internal::stce_9777<stce_10152, stce_10153, stce_10154, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10153>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10155>
struct common_type<dco::internal::stce_9774<stce_10152, stce_10150, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<dco::internal::stce_9778<stce_10152, stce_10150, stce_10151, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10150>::type>::type;
};
template <typename stce_9780, typename stce_10152, typename stce_10150, typename stce_10151, typename stce_10155>
struct common_type<dco::internal::stce_9779<stce_10152, stce_10150, stce_10151, stce_10155,
                                            typename enable_if<!dco::mode<stce_9780>::is_dco_type>::type>,
                   stce_9780> {
  using type = typename std::common_type<stce_9780, typename dco::mode<stce_10151>::type>::type;
};
} // namespace std
namespace dco {
template <typename stce_9780, typename stce_10156 = stce_9780> struct dco_type_constructable_from {
  const static bool value = false;
};
template <typename stce_9780> struct dco_explicit_type_cast_to { const static bool value = false; };
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9769> struct stce_10157 {
  const stce_9769 stce_9910;
  stce_10157(stce_9769 const& value) : stce_9910(value) {}
  inline const stce_9769& _value() const { return stce_9910; }
  template <typename TYPE, typename stce_10158 = typename enable_if<dco_explicit_type_cast_to<TYPE>::value>::type>
  explicit operator TYPE() {
    return static_cast<TYPE>(_value());
  }
};
template <class stce_9769, class DATA_TYPE> struct stce_9771 : public stce_10157<stce_9769> {
  stce_9771(const stce_9769& value) : stce_10157<stce_9769>(value) {}
  template <typename stce_9780 = DATA_TYPE>
  DCO_STRONG_INLINE
  operator typename dco::enable_if<is_gbcp_type<stce_9780>::value,
                                   typename stce_9913<stce_9771, stce_9780::gbcp_order>::stce_9895>::type() const {
    return stce_9913<stce_9771, stce_9780::gbcp_order>::value(*this);
  }
};
template <class stce_9769, class stce_9772, class stce_9773, typename>
struct stce_9774 : public stce_9771<stce_9769, typename stce_9772::data_t> {
  const stce_9772 DCO_TEMPORARY_REFORCOPY stce_10137;
  typedef typename stce_9772::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9774(const stce_9772& arg)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(arg._value())), stce_10137(arg) {}
  inline const stce_9769 stce_10113(const int stce_9810) const {
    return stce_9773::stce_10160(stce_10137.stce_10113(stce_9810));
  }
  inline const stce_9769 pval() const { return stce_9773::stce_10161(this->_value(), stce_10137._value()); }
};
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename>
struct stce_9777 : public stce_9771<stce_9769, typename stce_9775::data_t> {
  const stce_9775 DCO_TEMPORARY_REFORCOPY stce_10132;
  const stce_9776 DCO_TEMPORARY_REFORCOPY stce_10134;
  typedef typename stce_9775::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9777(const stce_9775& stce_10162, const stce_9776& stce_10163)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(stce_10162._value(), stce_10163._value())),
        stce_10132(stce_10162), stce_10134(stce_10163) {}
  inline const stce_9769 stce_10133() const {
    return stce_9773::stce_10164(this->_value(), stce_10132._value(), stce_10134._value());
  }
  inline const stce_9769 stce_10135() const {
    return stce_9773::stce_10165(this->_value(), stce_10132._value(), stce_10134._value());
  }
  inline const stce_9769 stce_10113(const int stce_9810) const {
    return stce_9773::stce_10160(stce_10132.stce_10113(stce_9810), stce_10134.stce_10113(stce_9810));
  }
};
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename>
struct stce_9778 : public stce_9771<stce_9769, typename stce_9775::data_t> {
  const stce_9775 DCO_TEMPORARY_REFORCOPY stce_10132;
  const stce_9776 stce_10134;
  typedef typename stce_9775::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9778(const stce_9775& stce_10162, const stce_9776& stce_10163)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(stce_10162._value(), stce_10163)), stce_10132(stce_10162),
        stce_10134(stce_10163) {}
  inline const stce_9769 stce_10113(const int stce_9810) const {
    return stce_9773::stce_10160(stce_10132.stce_10113(stce_9810), stce_10134);
  }
  inline const stce_9769 stce_10133() const {
    return stce_9773::stce_10164(this->stce_9910, stce_10132._value(), stce_10134);
  }
};
template <class stce_9769, class stce_9775, class stce_9776, class stce_9773, typename>
struct stce_9779 : public stce_9771<stce_9769, typename stce_9776::data_t> {
  const stce_9775 stce_10132;
  const stce_9776 DCO_TEMPORARY_REFORCOPY stce_10134;
  typedef typename stce_9776::data_t data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  explicit stce_9779(const stce_9775& stce_10162, const stce_9776& stce_10163)
      : stce_9771<stce_9769, data_t>(stce_9773::stce_10160(stce_10162, stce_10163._value())), stce_10132(stce_10162),
        stce_10134(stce_10163) {}
  inline const stce_9769 stce_10113(const int stce_9810) const {
    return stce_9773::stce_10160(stce_10132, stce_10134.stce_10113(stce_9810));
  }
  inline const stce_9769 stce_10135() const {
    return stce_9773::stce_10165(this->stce_9910, stce_10132, stce_10134._value());
  }
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_9780> struct passive_value_type_of { typedef stce_9780 TYPE; };
template <typename stce_9780> class stce_10166 {
protected:
  stce_9780 stce_9910;

public:
  stce_10166() : stce_9910(0.0) {}
  template <typename stce_9877> stce_10166(const stce_9877& stce_9807) : stce_9910(stce_9807) {}
};
template <class stce_9769, class stce_9770> struct active_type : private stce_10166<stce_9769>, public stce_9770 {
  typedef stce_10166<stce_9769> stce_10167;
  using stce_10167::stce_9910;

public:
  typedef stce_9770 data_t;
  typedef typename data_t::mode_t::value_t VALUE_TYPE;
  typedef typename data_t::mode_t::passive_t stce_10159;
  typedef typename data_t::mode_t::scalar_passive_t stce_10168;

private:
  typedef typename data_t::mode_t::scalar_value_t stce_10169;

public:
  DCO_STRONG_INLINE const stce_9769& _value() const { return stce_9910; }
  stce_9770 const& data() const { return *static_cast<stce_9770 const*>(this); }
  stce_9770& data() { return *static_cast<stce_9770*>(this); }
  DCO_STRONG_INLINE stce_9769& _value() { return stce_9910; }
  DCO_STRONG_INLINE const stce_9769 stce_10113(const int stce_9810) const {
    return stce_9770::stce_10113(stce_9910, stce_9810);
  }
  DCO_STRONG_INLINE active_type() : stce_10167(static_cast<stce_9769>(0.0)) {}
  DCO_STRONG_INLINE active_type(const active_type& stce_10084)
      : stce_10167(stce_10084.stce_9910), stce_9770(stce_10084) {}
  template <typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE
  operator typename dco::enable_if<is_gbcp_type<stce_9780>::value,
                                   typename stce_9913<active_type, stce_9780::gbcp_order>::stce_9895>::type() const {
    return stce_9913<active_type, stce_9780::gbcp_order>::value(*this);
  }
  template <typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE
  operator typename dco::enable_if<is_gbcp_type<stce_9780>::value,
                                   typename stce_9913<active_type, stce_9780::gbcp_order>::stce_9803>::type() {
    return stce_9913<active_type, stce_9780::gbcp_order>::value(*this);
  }
  template <typename stce_9877, typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE typename dco::enable_if<
      (dco::mode<stce_9877>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9877>::active_t>::value),
      active_type>::type&
  operator=(const stce_9877& stce_10142) {
    stce_9910 = stce_10142;
    return *this;
  }
  template <typename stce_9877, typename stce_9780 = stce_9770>
  DCO_STRONG_INLINE
  active_type(const stce_9877& stce_9753,
              typename dco::enable_if<
                  (dco::mode<stce_9877>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
                   dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9877>::active_t>::value),
                  void*>::type = NULL)
      : stce_10167(stce_9753) {}
  template <typename TYPE>
  DCO_STRONG_INLINE active_type(const TYPE& stce_9753, typename dco_type_constructable_from<TYPE>::type* = 0)
      : stce_10167(stce_9753) {}
  template <typename TYPE, typename stce_9780 = stce_9770,
            typename stce_10170 = typename enable_if<!is_gbcp_type<stce_9780>::value>::type,
            typename stce_10158 = typename enable_if<dco_explicit_type_cast_to<TYPE>::value>::type>
  explicit operator TYPE() const {
    return static_cast<TYPE>(_value());
  }
  template <typename TYPE>
  DCO_STRONG_INLINE active_type(
      const TYPE& stce_9753,
      typename dco::enable_if<stce_9882<typename TYPE::data_t::mode_t, typename data_t::mode_t>::value, void*>::type =
          NULL)
      : stce_10167(stce_9753) {}
  DCO_STRONG_INLINE active_type(const stce_10159& stce_9753) : stce_10167(stce_9753) {}
  template <typename scalar_passive_t>
  DCO_STRONG_INLINE active_type(const scalar_passive_t& stce_9753,
                                typename dco::enable_if<!dco::is_same<stce_10159, scalar_passive_t>::value &&
                                                            dco::is_same<stce_10168, scalar_passive_t>::value,
                                                        void*>::type = NULL)
      : stce_10167(stce_9753) {}
  DCO_STRONG_INLINE active_type& operator=(const active_type& stce_9807) {
    stce_9770::operator=(static_cast<const stce_9770&>(stce_9807));
    stce_9910 = stce_9807.stce_9910;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator=(const stce_10159& stce_10142) {
    this->stce_9910 = stce_10142;
    this->clear();
    return *this;
  }
  template <typename scalar_passive_t>
  DCO_STRONG_INLINE typename dco::enable_if<!dco::is_same<stce_10159, scalar_passive_t>::value &&
                                                dco::is_same<stce_10168, scalar_passive_t>::value,
                                            active_type>::type&
  operator=(const scalar_passive_t& stce_10142) {
    this->stce_9910 = stce_10142;
    this->clear();
    return *this;
  }
  template <class stce_10171, class stce_10172>
  DCO_STRONG_INLINE typename dco::enable_if<stce_9882<typename stce_10172::mode_t, typename data_t::mode_t>::value,
                                            active_type>::type&
  operator=(const active_type<stce_10171, stce_10172>& stce_10142) {
    stce_9910 = stce_10142;
    this->clear();
    return *this;
  }
  template <typename TYPE>
  DCO_STRONG_INLINE typename dco_type_constructable_from<TYPE, active_type>::type& operator=(const TYPE& stce_9753) {
    stce_9910 = stce_9753;
    this->clear();
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE
  active_type(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE
  active_type(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE
  active_type(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    this->stce_9909(stce_9807);
    this->stce_9910 = stce_9807.stce_9910;
    return *this;
  }
  template <typename stce_9877, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9877>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9877>::active_t>::value),
      active_type>::type&
  operator+=(const stce_9877& stce_9807) {
    *this = *this + stce_9807;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator+=(const active_type<stce_9769, stce_10172>& stce_9807) {
    *this = *this + stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this + stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this + stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this + stce_9807;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator+=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    *this = *this + stce_9807;
    return *this;
  }
  DCO_ALWAYS_INLINE active_type& operator+=(const VALUE_TYPE& stce_9807) {
    this->_value() += stce_9807;
    return *this;
  }
  template <typename stce_9877, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9877>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9877>::active_t>::value),
      active_type>::type&
  operator-=(const stce_9877& stce_9807) {
    *this = *this - stce_9807;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator-=(const active_type<stce_9769, stce_10172>& stce_9807) {
    *this = *this - stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this - stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this - stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this - stce_9807;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator-=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    *this = *this - stce_9807;
    return *this;
  }
  DCO_ALWAYS_INLINE active_type& operator-=(const VALUE_TYPE& stce_9807) {
    this->_value() -= stce_9807;
    return *this;
  }
  template <typename stce_9877, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9877>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9877>::active_t>::value),
      active_type>::type&
  operator*=(const stce_9877& stce_9807) {
    *this = *this * stce_9807;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator*=(const active_type<stce_9769, stce_10172>& stce_9807) {
    *this = *this * stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this * stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this * stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this * stce_9807;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator*=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    *this = *this * stce_9807;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator*=(const VALUE_TYPE& stce_9807) {
    *this = *this * stce_9807;
    return *this;
  }
  template <typename stce_9877, typename stce_9780 = stce_9770>
  DCO_ALWAYS_INLINE typename enable_if<
      (dco::mode<stce_9877>::order > 0 && dco::internal::is_gbcp_type<stce_9780>::value &&
       dco::is_same<typename stce_9780::mode_t::active_t, typename dco::mode<stce_9877>::active_t>::value),
      active_type>::type&
  operator/=(const stce_9877& stce_9807) {
    *this = *this / stce_9807;
    return *this;
  }
  template <class stce_10172>
  DCO_ALWAYS_INLINE active_type& operator/=(const active_type<stce_9769, stce_10172>& stce_9807) {
    *this = *this / stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this / stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this / stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    *this = *this / stce_9807;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE active_type&
  operator/=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    *this = *this / stce_9807;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator/=(const VALUE_TYPE& stce_9807) {
    *this = *this / stce_9807;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator++() {
    ++this->stce_9910;
    return *this;
  }
  DCO_STRONG_INLINE active_type& operator--() {
    --this->stce_9910;
    return *this;
  }
  DCO_STRONG_INLINE active_type operator++(int) {
    active_type stce_9847(*this);
    ++this->stce_9910;
    return stce_9847;
  }
  DCO_STRONG_INLINE active_type operator--(int) {
    active_type stce_9847(*this);
    --this->stce_9910;
    return stce_9847;
  }
};
template <class stce_9769, class stce_9770> struct passive_value_type_of<active_type<stce_9769, stce_9770>> {
  typedef typename passive_value_type_of<stce_9769>::TYPE TYPE;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <class stce_9979, memory_model::TYPE stce_10173>
class stce_9981<memory_model::BLOB_TAPE_SPLINT, stce_9979, stce_10173> : public stce_9925<stce_9979>, object_logger {
  typedef stce_9925<stce_9979> stce_9935;

public:
  typedef typename stce_9790<stce_9979>::type stce_10174;
  struct entry {
    stce_10174* stce_10175;
    index_t* stce_10176;
    DCO_ALWAYS_INLINE entry(stce_10174* stce_10177, index_t* stce_10178)
        : stce_10175(stce_10177), stce_10176(stce_10178){};
    DCO_ALWAYS_INLINE index_t arg() {
      return (*stce_10176 < 0) ? std::abs(stce_9752(*stce_10176)) - 1 : stce_9752(*stce_10176);
    }
    DCO_ALWAYS_INLINE stce_10174& pval() { return *stce_10175; }
    DCO_ALWAYS_INLINE stce_10174 pval() const { return *stce_10175; }
    DCO_ALWAYS_INLINE bool stce_10008() { return *stce_10176 < 0; }
    DCO_ALWAYS_INLINE static bool stce_10008(index_t* stce_10179) { return *stce_10179 < 0; }
    DCO_ALWAYS_INLINE static index_t stce_10180(index_t stce_10078) { return -stce_10078 - 1; }
    static size_t size_of() { return sizeof(stce_10174) + sizeof(index_t); }
  };
  class iterator {
  public:
    index_t stce_10181;
    entry stce_10182;
    template <class stce_10183> void assign_to_interop(stce_10183& stce_10004) const {
      assert(sizeof(iterator) <= sizeof(stce_10183));
      std::memcpy(&stce_10004, this, sizeof(iterator));
    }
    template <class stce_10183> void assign_from_interop(const stce_10183& stce_10004) {
      assert(sizeof(iterator) <= sizeof(stce_10183));
      std::memcpy(static_cast<void*>(this), &stce_10004, sizeof(iterator));
    }
    DCO_ALWAYS_INLINE const entry* operator->() const { return &stce_10182; }
    DCO_ALWAYS_INLINE entry* operator->() { return &stce_10182; }
    DCO_ALWAYS_INLINE void stce_10184() {
      stce_10182.stce_10175++;
      stce_10182.stce_10176--;
      if (stce_9754 && static_cast<void*>(stce_10182.stce_10175) >= static_cast<void*>(stce_10182.stce_10176)) {
        throw dco::exception::create<std::runtime_error>(
            "Blob tape (splint) container overflow. Allocate bigger blob or use chunk tape container instead.");
      }
    }
    DCO_ALWAYS_INLINE index_t stce_10185() { return ++stce_10181; }
    DCO_ALWAYS_INLINE explicit iterator() : stce_10181(-1), stce_10182(NULL, NULL) {}
    DCO_ALWAYS_INLINE explicit iterator(stce_10174* stce_10177, index_t* stce_10178, index_t index = index_t(-1))
        : stce_10181(index), stce_10182(stce_10177, stce_10178) {}
    DCO_ALWAYS_INLINE index_t index() const { return stce_10181; }
    DCO_ALWAYS_INLINE index_t& index() { return stce_10181; }
    bool stce_10008() const { return entry::stce_10008(stce_10182.stce_10176); }
    DCO_ALWAYS_INLINE void operator--() {
      if (entry::stce_10008(stce_10182.stce_10176))
        stce_10181--;
      stce_10182.stce_10175--;
      stce_10182.stce_10176++;
    }
    DCO_ALWAYS_INLINE iterator operator--(int) {
      iterator stce_10028(*this);
      operator--();
      return stce_10028;
    }
    DCO_ALWAYS_INLINE bool operator==(const iterator& stce_9934) const {
      return stce_10182.stce_10175 == stce_9934.stce_10182.stce_10175;
    }
    DCO_ALWAYS_INLINE bool operator!=(const iterator& stce_9934) const { return !operator==(stce_9934); }
    DCO_ALWAYS_INLINE bool operator<(const iterator& stce_9934) const {
      return stce_10182.stce_10175 < stce_9934.stce_10182.stce_10175;
    }
    DCO_ALWAYS_INLINE bool operator>=(const iterator& stce_9934) const { return !operator<(stce_9934); }
    DCO_ALWAYS_INLINE bool operator>(const iterator& stce_9934) const {
      return stce_10182.stce_10175 > stce_9934.stce_10182.stce_10175;
    }
    DCO_ALWAYS_INLINE bool operator<=(const iterator& stce_9934) const { return !operator>(stce_9934); }
  };
  class edge_inserter {
    iterator& stce_10186;
    index_t stce_10181;

  public:
    edge_inserter(iterator& current) : stce_10186(current), stce_10181(0) {}
    iterator& current() { return stce_10186; }
    edge_inserter& operator=(edge_inserter stce_9934) {
      swap(stce_9934);
      return *this;
    }
    index_t index() const { return stce_10181; }
    void swap(edge_inserter& stce_9934) {
      std::swap(stce_10186, stce_9934.stce_10186);
      std::swap(stce_10181, stce_9934.stce_10181);
    }
    DCO_ALWAYS_INLINE_IF_AGRESSIVE void insert(const index_t& stce_10078, const stce_10174& pval) {
      if (IS_DEBUG && stce_10186.index() < stce_10078) {
        throw dco::exception::create<std::runtime_error>(
            "DCO_DEBUG: tape index of read variable bigger than current progvarcounter.");
      }
      if (stce_10181 == 0) {
        stce_10186.stce_10184();
        new (stce_10186.stce_10182.stce_10175) stce_10174(pval);
        new (stce_10186.stce_10182.stce_10176) index_t(entry::stce_10180(stce_10078));
        stce_10181 = stce_10186.stce_10185();
        DCO_LOG(logDEBUG2) << "inserting first entry, index now = " << stce_10181 << "; pval = " << pval
                           << ", target = " << stce_10078;
        return;
      }
      if (stce_9756 && stce_10078 == *(stce_10186.stce_10182.stce_10176)) {
        *(stce_10186.stce_10182.stce_10175) += pval;
        return;
      }
      stce_10186.stce_10184();
      new (stce_10186.stce_10182.stce_10175) stce_10174(pval);
      new (stce_10186.stce_10182.stce_10176) index_t(stce_10078);
    }

  private:
    edge_inserter(const edge_inserter& stce_9934);
  };

protected:
  void init(tape_options const& stce_9942, index_t stce_10187 = 0) {
    size_t stce_10188;
    if (stce_9942.write_to_file())
      stce_10188 = stce_9942.blob_size_in_byte();
    else
      stce_10188 = get_allocation_size(stce_9942.blob_size_in_byte());
    size_t stce_10189 = stce_10188 / entry::size_of();
    DCO_LOG(logDEBUG1) << "BLOB SPLINT container: user requested allocation size = " << stce_10188
                       << "; size of element = " << entry::size_of() << "; max elements in memory = " << stce_10189;
    if (static_cast<double>(stce_10189) / static_cast<double>(std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max()) >
        1.0) {
      stce_10189 = std::numeric_limits<index_t>::max();
      DCO_LOG(logDEBUG1)
          << "BLOB SPLINT container: too many elements requested for currently used index_t. Setting to: "
          << stce_10189 * 1.e-6 << "M elements";
    }
    index_t stce_10190 = static_cast<index_t>(stce_10189);
    size_t stce_10191 = stce_10190 * entry::size_of();
    DCO_LOG(logDEBUG) << "BLOB SPLINT container: trying allocation for = " << stce_10191 / 1024 << "K ~=~ "
                      << stce_9752(stce_10190) * 1.e-6 << "M elements";
    stce_9926 = stce_1000001(&stce_10191, stce_9942.alloc_use_huge_pages());
    if (!stce_9926) {
      std::string stce_10192 = "";
      if (stce_9942.alloc_use_huge_pages()) {
        stce_10192 =
            " You are using huge pages; have you prepared your system correspondingly (see documentation as well)?";
      }
      throw dco::exception::create<std::runtime_error>("Could not allocate memory. Use environment variables "
                                                       "(DCO_MEM_RATIO, DCO_MAX_ALLOCATION) and see documentation." +
                                                       stce_10192);
    }
    stce_10190 = static_cast<index_t>(stce_10191 / entry::size_of());
    DCO_LOG(logINFO) << "BLOB SPLINT container: actually allocated size = " << stce_10191 / 1024 << "K ~=~ "
                     << stce_9752(stce_10190) * 1.e-6 << "M elements";
    stce_10193 = static_cast<stce_10174*>(stce_9926);
    stce_10194 = static_cast<index_t*>(stce_9926) + stce_10191 / sizeof(index_t) - 1;
    stce_10186 = iterator(stce_10193, stce_10194, stce_10187);
    stce_10195 = iterator(stce_10193, stce_10194, stce_10187);
    stce_10196 = iterator(stce_10193 + stce_9752(stce_10190) - 1, stce_10194 - stce_9752(stce_10190) + 1,
                          std::numeric_limits<index_t>::max());
    new (stce_10186.stce_10182.stce_10175) stce_10174(static_cast<stce_10174>(0.0));
    new (stce_10186.stce_10182.stce_10176) index_t(entry::stce_10180(0));
  }

public:
  DCO_ALWAYS_INLINE explicit stce_9981(tape_options const& stce_9942, stce_9979& tape)
      : stce_9935(tape), object_logger("BLOB SPLINT container"), stce_9926(0), stce_10193(0), stce_10194(0),
        stce_10186(), stce_10195(), stce_10196() {
    assert(stce_10173 != memory_model::stce_9768);
    init(stce_9942);
  }
  DCO_ALWAYS_INLINE explicit stce_9981(iterator& stce_9825, stce_9979& tape)
      : stce_9935(tape), object_logger("BLOB SPLINT container"), stce_9926(0), stce_10193(0), stce_10194(0),
        stce_10186(stce_9825), stce_10195(), stce_10196() {
    assert(stce_10173 == memory_model::stce_9768);
  }
  DCO_ALWAYS_INLINE ~stce_9981() { dco::dealloc(stce_9926); }
  DCO_ALWAYS_INLINE iterator& insert_ref() { return stce_10186; }
  iterator start() { return stce_10195; }
  iterator start() const { return stce_10195; }
  iterator rend() { return start(); }
  iterator current() const { return stce_10186; }
  iterator current() { return stce_10186; }
  iterator& stce_10003() { return stce_10186; }
  iterator rbegin() const { return current(); }
  iterator capacity() const { return stce_10196; }
  bool empty() const { return stce_10186 == start(); }
  index_t size(const iterator& stce_9872, const iterator& stce_9873) const {
    if (stce_9872 < stce_9873)
      throw dco::exception::create<std::runtime_error>("size from < to");
    return static_cast<index_t>(stce_9872->stce_10175 - stce_9873->stce_10175);
  }
  index_t size(iterator stce_9872) const { return size(stce_9872, start()); }
  index_t size() const { return size(current(), start()); }
  index_t stce_10197() const { return size(stce_10196, start()); }
  size_t size_in_byte() const { return size(current(), start()) * entry::size_of(); }
  size_t stce_10198() const { return size(stce_10196, start()) * entry::size_of(); }
  void erase(const iterator& stce_10179) {
    if (!stce_10193)
      return;
    if (stce_10179 > stce_10196)
      throw dco::exception::create<std::runtime_error>("pos behind stack!");
    if (stce_10179 > stce_10186)
      throw dco::exception::create<std::runtime_error>("reset to position out of tape!");
    stce_10186 = stce_10179;
  }
  void stce_10199(const iterator&) {}
  void stce_10200() {}
  index_t stce_10201() const { return stce_10186.index() + 1; }
  void stce_10202(stce_9981 const* const stce_9934) { stce_10003().index() = stce_9934->current().index(); }

private:
  stce_9981(const stce_9981& stce_9934);
  void* stce_9926;
  stce_10174* stce_10193;
  index_t* stce_10194;

protected:
  typename stce_9829<iterator, stce_10173 == memory_model::stce_9768>::type stce_10186;
  iterator stce_10195;
  iterator stce_10196;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_9979, memory_model::TYPE stce_10173>
class stce_9981<memory_model::BLOB_TAPE, stce_9979, stce_10173> : public stce_9925<stce_9979>, public object_logger {
  typedef stce_9925<stce_9979> stce_9935;
  typedef stce_9979 tape_t;

public:
  typedef typename stce_9790<stce_9979>::type stce_10174;
  enum stce_10203 { stce_10204, stce_10205 };
  struct entry {
    index_t stce_10137;
    stce_10174 stce_10119;

  public:
    static size_t size_of() { return sizeof(entry); }
    entry(index_t arg = 0, stce_10174 const& pval = stce_10174(0.)) : stce_10137(arg), stce_10119(pval) {}
    DCO_STRONG_INLINE index_t arg() const {
      return (stce_10137 < 0) ? std::abs(stce_9752(stce_10137)) - 1 : stce_9752(stce_10137);
    }
    DCO_STRONG_INLINE static index_t stce_10180(const index_t& arg) { return -arg - 1; }
    DCO_STRONG_INLINE bool stce_10008() const { return stce_10137 < 0; }
    DCO_STRONG_INLINE void stce_10206(const stce_10174& stce_9921) { stce_10119 += stce_9921; }
    DCO_STRONG_INLINE stce_10174 pval() const { return stce_10119; }
  };
  class iterator {
    entry* stce_10207;
    index_t stce_10181;
    entry const* stce_10208;

  public:
    template <class stce_10183> void assign_to_interop(stce_10183& stce_10004) const {
      assert(sizeof(iterator) <= sizeof(stce_10183));
      std::memcpy(&stce_10004, this, sizeof(iterator));
    }
    template <class stce_10183> void assign_from_interop(const stce_10183& stce_10004) {
      assert(sizeof(iterator) <= sizeof(stce_10183));
      std::memcpy(static_cast<void*>(this), &stce_10004, sizeof(iterator));
    }
    void stce_10209(index_t stce_9810) { stce_10181 = stce_9810; }
    void stce_10184() {
      stce_10207++;
      if (stce_10207 > stce_10208) {
        throw dco::exception::create<std::runtime_error>(
            "Blob tape container overflow. Allocate bigger blob or use chunk tape container instead.");
      }
    }
    index_t index() const { return stce_10181; }
    index_t& index() { return stce_10181; }
    index_t stce_10185() { return ++stce_10181; }
    void stce_10210(entry const* end) { stce_10208 = end; }
    explicit iterator(entry* stce_10179 = 0, index_t index = index_t(-1)) : stce_10207(stce_10179), stce_10181(index) {}
    void operator--() {
      if (stce_10207->stce_10008())
        stce_10181--;
      stce_10207--;
    }
    bool stce_10008() const { return stce_10207->stce_10008(); }
    iterator operator--(int) {
      iterator stce_10028(*this);
      operator--();
      return stce_10028;
    }
    entry* operator*() { return stce_10207; }
    entry* operator->() { return stce_10207; }
    entry* operator*() const { return stce_10207; }
    entry* operator->() const { return stce_10207; }
    bool operator==(const iterator& stce_9934) const { return stce_10207 == stce_9934.stce_10207; }
    bool operator!=(const iterator& stce_9934) const { return !operator==(stce_9934); }
    bool operator<(const iterator& stce_9934) const { return stce_10207 < stce_9934.stce_10207; }
    bool operator>=(const iterator& stce_9934) const { return !operator<(stce_9934); }
    bool operator>(const iterator& stce_9934) const { return stce_10207 > stce_9934.stce_10207; }
    bool operator<=(const iterator& stce_9934) const { return !operator>(stce_9934); }
    friend std::ostream& operator<<(std::ostream& stce_10211, const iterator& stce_10004) {
      stce_10211 << "(" << stce_10004.stce_10207 << ":" << stce_10004.stce_10181 << ")";
      return stce_10211;
    }
  };
  class edge_inserter {
    iterator& stce_10186;
    index_t stce_10181;

  public:
    edge_inserter(iterator& current) : stce_10186(current), stce_10181(0) {}
    iterator& current() { return stce_10186; }
    edge_inserter& operator=(edge_inserter stce_9934) {
      swap(stce_9934);
      return *this;
    }
    index_t index() const { return stce_10181; }
    void swap(edge_inserter& stce_9934) {
      std::swap(stce_10186, stce_9934.stce_10186);
      std::swap(stce_10181, stce_9934.stce_10181);
    }
    DCO_ALWAYS_INLINE_IF_AGRESSIVE void insert(const index_t& stce_10078, const stce_10174& pval) {
      if (IS_DEBUG && stce_10186.index() < stce_10078) {
        throw dco::exception::create<std::runtime_error>(
            "DCO_DEBUG: tape index of read variable bigger than current progvarcounter.");
      }
      if (stce_10181 == 0) {
        stce_10186.stce_10184();
        new (*stce_10186) entry(entry::stce_10180(stce_10078), pval);
        stce_10181 = stce_10186.stce_10185();
        return;
      }
      if (stce_9756 && stce_10078 == stce_10186->arg()) {
        stce_10186->stce_10206(pval);
        return;
      }
      stce_10186.stce_10184();
      new (*stce_10186) entry(stce_10078, pval);
    }

  private:
    edge_inserter(const edge_inserter& stce_9934);
  };
  explicit stce_9981(stce_9981& stce_9872, stce_10203 stce_10212)
      : stce_9935(stce_9872), object_logger("BLOB container"), stce_9926(0), stce_10186(), stce_10195(), stce_10196(),
        stce_10213(stce_10212), stce_9941(stce_9872.stce_9941) {
    if (stce_10212 == stce_10204) {
      stce_9926 = stce_9872.stce_9926;
      stce_10186 = iterator(stce_9926, stce_9872.current().index());
      stce_10195 = stce_10186;
      stce_10196 = stce_9872.stce_10196;
      stce_10186.stce_10210(*stce_10196);
    } else if (stce_10212 == stce_10205) {
      index_t stce_10189 = allocate(stce_9941);
      stce_10186 = iterator(stce_9926, (stce_9872.current().index()));
      stce_10195 = iterator(stce_9926, (stce_9872.current().index()));
      stce_10196 = iterator(stce_9926 + static_cast<DCO_INTEGRAL_TAPE_INT>(stce_10189) - 1,
                            std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max());
      stce_10186.stce_10210(*stce_10196);
      if (*stce_10196 - *stce_10195 < 1) {
        std::stringstream stce_10214;
        stce_10214 << 2 * sizeof(entry);
        dco::dealloc(stce_9926);
        throw dco::exception::create<std::runtime_error>(
            "Blob/chunk size too small. Use bigger blob/chunk size [at least " + stce_10214.str() + " bytes].");
      }
      new (*stce_10186) entry(entry::stce_10180(0));
    }
  }
  index_t allocate(const tape_options& stce_9942) {
    size_t stce_10191 = get_allocation_size(stce_9942.blob_size_in_byte());
    stce_9926 = static_cast<entry*>(stce_1000001(&stce_10191, stce_9942.alloc_use_huge_pages()));
    if (!stce_9926) {
      throw dco::exception::stce_9818<std::bad_alloc>("Could not allocate memory. Use environment variables "
                                                      "(DCO_MEM_RATIO, DCO_MAX_ALLOCATION) and see documentation.");
    }
    size_t stce_10215 = stce_10191 / entry::size_of();
    if (static_cast<double>(stce_10215) / static_cast<double>(std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max()) >
        1.0) {
      stce_10215 = std::numeric_limits<index_t>::max();
    }
    index_t stce_10189 = static_cast<index_t>(stce_10215);
    DCO_LOG(logINFO) << "BLOB container; size = " << stce_9942.blob_size_in_byte() << "b ~=~ "
                     << stce_9942.blob_size_in_byte() / entry::size_of() << "elements";
    DCO_LOG(logINFO) << "BLOB container; tried allocation size = " << stce_10191 << "b ~=~ "
                     << stce_10191 / entry::size_of() << "elements";
    DCO_LOG(logDEBUG) << "sizeof(entry) = " << sizeof(entry) << " == " << entry::size_of();
    return stce_10189;
  }
  void init(tape_options const& stce_9942) {
    index_t stce_10189 = allocate(stce_9942);
    stce_10186 = iterator(stce_9926, 0);
    stce_10195 = iterator(stce_9926, 0);
    stce_10196 = iterator(stce_9926 + static_cast<DCO_INTEGRAL_TAPE_INT>(stce_10189) - 1,
                          std::numeric_limits<DCO_INTEGRAL_TAPE_INT>::max());
    stce_10186.stce_10210(*stce_10196);
    if (*stce_10196 - *stce_10195 < 1) {
      std::stringstream stce_10214;
      stce_10214 << 2 * sizeof(entry);
      dco::dealloc(stce_9926);
      throw dco::exception::create<std::runtime_error>(
          "Blob/chunk size too small. Use bigger blob/chunk size [at least " + stce_10214.str() + " bytes].");
    }
    new (*stce_10186) entry(entry::stce_10180(0));
  }
  DCO_ALWAYS_INLINE explicit stce_9981(tape_options const& stce_9942, tape_t& tape)
      : stce_9935(tape), object_logger("BLOB container"), stce_9926(0), stce_10186(), stce_10195(), stce_10196(),
        stce_10213(stce_10205), stce_9941(stce_9942) {
    assert(stce_10173 != memory_model::stce_9768);
    init(stce_9942);
  }
  DCO_ALWAYS_INLINE explicit stce_9981(iterator& stce_9825, tape_t& tape)
      : stce_9935(tape), object_logger("BLOB container"), stce_9926(0), stce_10186(stce_9825), stce_10195(),
        stce_10196(), stce_10213(stce_10205), stce_9941(tape.stce_9942()) {
    assert(stce_10173 == memory_model::stce_9768);
  }
  DCO_ALWAYS_INLINE ~stce_9981() {
    if (stce_10213 == stce_10205)
      dco::dealloc(stce_9926);
  }
  DCO_ALWAYS_INLINE iterator& insert_ref() { return stce_10186; }
  entry*& stce_10216() { return stce_9926; }
  iterator current() const { return stce_10186; }
  iterator current() { return stce_10186; }
  iterator& stce_10003() { return stce_10186; }
  iterator start() { return stce_10195; }
  iterator start() const { return stce_10195; }
  iterator rend() { return start(); }
  iterator rbegin() const { return current(); }
  iterator capacity() const { return stce_10196; }
  bool empty() const { return stce_10186 == start(); }
  index_t size(const iterator& stce_9872, const iterator& stce_9873) const {
    if (stce_9872 < stce_9873)
      throw dco::exception::create<std::runtime_error>("size from < to");
    return static_cast<index_t>(*stce_9872 - *stce_9873);
  }
  tape_options stce_9942() const { return stce_9941; }
  index_t size(iterator stce_9872) const { return size(stce_9872, start()); }
  index_t size() const { return size(current(), start()); }
  index_t stce_10197() const { return size(stce_10196, start()); }
  size_t size_in_byte() const { return size(current(), start()) * sizeof(entry); }
  size_t stce_10198() const { return size(stce_10196, start()) * sizeof(entry); }
  void erase(const iterator& stce_10179) {
    if (!stce_9926)
      return;
    if (IS_DEBUG && stce_10179 > stce_10196)
      throw dco::exception::create<std::runtime_error>("pos behind stack!");
    if (stce_10179 > stce_10186)
      throw dco::exception::create<std::runtime_error>("reset to position out of tape!");
    stce_10186 = stce_10179;
    stce_10186.stce_10210(*stce_10196);
  }
  void erase() {
    if (!stce_9926)
      return;
    stce_10186 = stce_10195;
    stce_10186.stce_10210(*stce_10196);
  }
  void stce_10199(const iterator&) {}
  void stce_10200() {}
  index_t stce_10201() { return stce_10186.index() + 1; }

private:
  stce_9981(const stce_9981& stce_9934);
  entry* stce_9926;
  typename stce_9829<iterator, stce_10173 == memory_model::stce_9768>::type stce_10186;
  iterator stce_10195;
  iterator stce_10196;
  stce_10203 stce_10213;
  tape_options stce_9941;
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_9979, memory_model::TYPE stce_10173>
class stce_9981<memory_model::CHUNK_TAPE, stce_9979, stce_10173> : public stce_9925<stce_9979>, object_logger {
  typedef stce_9925<stce_9979> stce_9935;

public:
  typedef typename stce_9790<stce_9979>::type stce_10174;

protected:
  typedef stce_9981<memory_model::BLOB_TAPE, stce_9979> stce_10217;
  static void stce_10218(const std::string& stce_10219, char* data, long size) {
    DCO_LOG(logDEBUG1) << "save_data_to_file: bytes to write = " << size << ", fname = " << stce_10219;
    std::ofstream out(stce_10219.c_str(), std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
    if (!out.is_open())
      throw dco::exception::create<std::runtime_error>("could not open file, perhaps index corruption?");
    if (!out.good())
      throw dco::exception::create<std::runtime_error>("file could be opened, but got corrupted afterwards.");
    out.write(data, size);
    if (!out.good())
      throw dco::exception::create<std::runtime_error>("reading the chunk failed, container corrupted.");
    out.close();
  }
  static DCO_INTEGRAL_TAPE_INT stce_10220(const std::string& stce_10219, char* data) {
    struct stat stce_10221;
    if (stat(stce_10219.c_str(), &stce_10221) == -1)
      throw dco::exception::create<std::runtime_error>("could not check file size, perhaps index corruption?");
    DCO_INTEGRAL_TAPE_INT size = static_cast<DCO_INTEGRAL_TAPE_INT>(stce_10221.st_size);
    std::ifstream in(stce_10219.c_str(), std::ios_base::in | std::ios_base::binary);
    if (!in.is_open())
      throw dco::exception::create<std::runtime_error>("could not open file, perhaps index corruption?");
    if (!in.good())
      throw dco::exception::create<std::runtime_error>("file could be opened, but got corrupted afterwards.");
    in.read(data, size);
    if (!in.good())
      throw dco::exception::create<std::runtime_error>("reading the chunk failed, container corrupted.");
    return size;
  }

public:
  class stce_10222 : public stce_10217 {
    index_t stce_10223;
    tape_options stce_9941;
    bool stce_10224;
    stce_10222 *stce_10225, *stce_10226;
    index_t stce_10227;

  public:
    typedef typename stce_10217::entry entry;
    typedef typename stce_10217::iterator iterator;
    index_t stce_10228() const { return stce_10223; }
    static std::string stce_10229(const stce_10222& stce_10230) {
      std::stringstream stce_10219;
      stce_10219 << stce_10230.stce_10231().filename() << '.' << stce_10230.stce_10228();
      return stce_10219.str();
    }
    DCO_ALWAYS_INLINE stce_10222(stce_10222& stce_9872, typename stce_10217::stce_10203 stce_10232)
        : stce_10217(stce_9872, stce_10232), stce_10223(stce_9872.stce_10228() + 1), stce_9941(stce_9872.stce_10231()),
          stce_10224(true), stce_10225(0), stce_10226(0), stce_10227(-1) {}
    DCO_ALWAYS_INLINE stce_10222(tape_options stce_9942, stce_9979& tape)
        : stce_10217(stce_9942, tape), stce_10223(0), stce_9941(stce_9942), stce_10224(true), stce_10225(0),
          stce_10226(0), stce_10227(-1) {}
    DCO_ALWAYS_INLINE ~stce_10222() {
      if (stce_10231().write_to_file())
        std::remove(stce_10229(*this).c_str());
    }
    index_t size(const iterator& stce_9872, const iterator& stce_9873) const {
      return stce_10217::size(stce_9872, stce_9873);
    }
    index_t size(iterator stce_9872) const {
      if (!*this->start())
        throw dco::exception::create<std::runtime_error>("given iterator does not point "
                                                         "into given tape!");
      return stce_10217::size(stce_9872, this->start());
    }
    index_t size() const { return stce_10217::size(this->current(), this->start()); }
    index_t stce_10197() const {
      if (!stce_10233())
        return 0;
      return stce_10217::stce_10197();
    }
    size_t size_in_byte() const {
      return stce_10217::size(this->current(), this->start()) * stce_10217::entry::size_of();
    }
    size_t stce_10198() const {
      if (!stce_10233()) {
        return 0;
      }
      return stce_10217::stce_10197() * stce_10217::entry::size_of();
    }
    tape_options stce_10231() const { return stce_9941; }
    bool stce_10233() const { return stce_10224; }
    void stce_10234(bool stce_10235) { stce_10224 = stce_10235; }
    void stce_10236() { stce_10227 = size(); }
    void stce_10237() { stce_10227 = -1; }
    bool stce_10238() { return stce_10227 != size(); }
    stce_10222*& stce_10239() { return stce_10225; }
    stce_10222*& stce_10240() { return stce_10226; }
  };
  typedef typename stce_10217::entry entry;
  typedef stce_10222* stce_10241;
  typedef typename stce_10217::iterator stce_10242;
  static void stce_10243(stce_10222& stce_10230) {
    if (stce_10230.stce_10231().write_to_file()) {
      assert(!stce_10230.stce_10233());
      DCO_LOG(logDEBUG1) << "wake_up: waking up chunk " << stce_10230.stce_10228() << " | " << stce_10230.stce_10216()
                         << " from sleep.";
      DCO_INTEGRAL_TAPE_INT size =
          stce_10220(stce_10222::stce_10229(stce_10230), reinterpret_cast<char*>(stce_10230.stce_10216()));
      (void)size;
      stce_10230.stce_10234(true);
    } else {
      DCO_LOG(logDEBUG1) << "wake_up: waking already awake chunk " << stce_10230.stce_10228() << " | "
                         << stce_10230.stce_10216();
    }
  }
  static void sleep(stce_10222& stce_10230) {
    DCO_LOG(logDEBUG1) << "sleep: chunk " << stce_10230.stce_10228() << " | " << stce_10230.stce_10216()
                       << " dirty = " << stce_10230.stce_10238();
    if (stce_10230.stce_10231().write_to_file() && stce_10230.stce_10238()) {
      assert(stce_10230.stce_10233());
      DCO_LOG(logDEBUG1) << "sleep: writing chunk " << stce_10230.stce_10228() << " | " << stce_10230.stce_10216();
      const long stce_10244 = stce_9752(stce_10230.size() + 1) * sizeof(entry);
      DCO_LOG(logDEBUG1) << "sleep: chunk.size() = " << stce_10230.size() << ", bytes to write = " << stce_10244
                         << ", ptr diff = " << stce_10230.current() << ", " << stce_10230.start() << " = "
                         << *stce_10230.current() - *stce_10230.start() << " " << sizeof(entry);
      entry* data = stce_10230.stce_10216();
      stce_10218(stce_10222::stce_10229(stce_10230), reinterpret_cast<char*>(data), stce_10244);
      stce_10230.stce_10236();
    } else {
      if (!stce_10230.stce_10238()) {
        DCO_LOG(logDEBUG1) << "sleep: not writing data for chunk: " << stce_10230.stce_10228();
      }
    }
  }
  static void stce_10245(stce_10222& stce_10230, stce_10222& stce_10246) {
    if (!stce_10230.stce_10233()) {
      sleep(stce_10246);
      stce_10246.stce_10234(false);
      stce_10243(stce_10230);
    }
  }
  void stce_10245(stce_10222& stce_10230) {
    if (!stce_10230.stce_10233()) {
      DCO_LOG(logDEBUG1) << "activate: chunk " << stce_10230.stce_10228() << " not awake yet";
      stce_10222* stce_10246 = stce_10186.stce_10247();
      while (stce_10246 && !stce_10246->stce_10233()) {
        stce_10246 = stce_10246->stce_10239();
      }
      if (stce_10246) {
        DCO_LOG(logDEBUG1) << "activate: currently awake " << stce_10246->stce_10228();
        stce_10245(stce_10230, *stce_10246);
      } else {
        stce_10243(stce_10230);
      }
    }
  }
  class iterator {
  private:
    stce_10241 stce_10248;
    stce_10242 stce_10249;

  public:
    template <class stce_10183> void assign_from_interop(const stce_10183& stce_10004) {
      assert(sizeof(iterator) <= sizeof(stce_10183));
      std::memcpy(static_cast<void*>(this), &stce_10004, sizeof(iterator));
    }
    template <class stce_10183> void assign_to_interop(stce_10183& stce_10004) const {
      assert(sizeof(iterator) <= sizeof(stce_10183));
      std::memcpy(&stce_10004, this, sizeof(iterator));
    }
    stce_10241 stce_10247() const { return stce_10248; }
    stce_10242 stce_10250() const { return stce_10249; }
    explicit iterator(const stce_10242& stce_10006, stce_10241 stce_10247)
        : stce_10248(stce_10247), stce_10249(stce_10006) {}
    explicit iterator(stce_10241 stce_10247) : stce_10248(stce_10247), stce_10249(stce_10247->current()) {}
    iterator& operator=(const iterator& stce_10084) {
      this->stce_10248 = stce_10084.stce_10248;
      this->stce_10249 = stce_10084.stce_10249;
      return *this;
    }
    iterator(const iterator& stce_9934) : stce_10248(stce_9934.stce_10248), stce_10249(stce_9934.stce_10249) {}
    iterator() : stce_10248(), stce_10249() {}
    bool stce_10008() const { return stce_10249.stce_10008(); }
    void operator--() {
      DCO_LOG(logDEBUG4) << stce_10249 << " =?= " << stce_10248->start();
      --stce_10249;
      if (stce_10249 == stce_10248->start()) {
        if (stce_10248->stce_10228() == 0)
          return;
        stce_10248 = stce_10248->stce_10239();
        stce_10245(*stce_10248, *(stce_10248->stce_10240()));
        stce_10249 = stce_10248->current();
      }
    }
    index_t index() const { return stce_10249.index(); }
    index_t& index() { return stce_10249.index(); }
    index_t stce_10185() {
      stce_10248->stce_10003().stce_10185();
      return stce_10249.stce_10185();
    }
    stce_10241& stce_10230() { return stce_10248; }
    stce_10242& stce_10251() { return stce_10249; }
    iterator operator--(int) {
      iterator stce_10028(*this);
      operator--();
      return stce_10028;
    }
    entry* operator*() { return *stce_10249; }
    entry* operator*() const { return *stce_10249; }
    entry* operator->() { return *stce_10249; }
    entry* operator->() const { return *stce_10249; }
    bool operator==(const iterator& stce_9934) const {
      return stce_10249 == stce_9934.stce_10249 && stce_10248 == stce_9934.stce_10248;
    }
    bool operator!=(const iterator& stce_9934) const { return !operator==(stce_9934); }
    bool operator<(const iterator& stce_9934) const {
      return (stce_10248 == stce_9934.stce_10248) ? stce_10249 < stce_9934.stce_10249
                                                  : stce_10249.index() < stce_9934.stce_10249.index();
    }
    bool operator>=(const iterator& stce_9934) const { return !operator<(stce_9934); }
    bool operator>(const iterator& stce_9934) const {
      return (stce_10248 == stce_9934.stce_10248) ? stce_10249 > stce_9934.stce_10249
                                                  : stce_10249.index() > stce_9934.stce_10249.index();
    }
    bool operator<=(const iterator& stce_9934) const { return !operator>(stce_9934); }
  };
  class edge_inserter {
    stce_10241& stce_10252;
    stce_10242& stce_10253;
    stce_10242 stce_10249;
    stce_10242 stce_10254;
    index_t stce_10181;

  public:
    DCO_ALWAYS_INLINE edge_inserter(iterator& stce_9825)
        : stce_10252(stce_9825.stce_10230()), stce_10253(stce_9825.stce_10251()), stce_10249(stce_10252->current()),
          stce_10254(stce_10252->capacity()), stce_10181(0) {}
    stce_10242& current() { return stce_10249; }
    DCO_ALWAYS_INLINE ~edge_inserter() {
      if (static_cast<DCO_INTEGRAL_TAPE_INT>(stce_10181)) {
        stce_10253 = stce_10252->stce_10003() = stce_10249;
      }
    }
    index_t index() const { return stce_10181; }
    index_t& index() { return stce_10181; }
    DCO_ALWAYS_INLINE_IF_AGRESSIVE void insert(const index_t& stce_10078, const stce_10174& pval) {
      if (IS_DEBUG && stce_10249.index() < stce_10078) {
        throw dco::exception::create<std::runtime_error>(
            "DCO_DEBUG: tape index of read variable bigger than current progvarcounter.");
      }
      if (*stce_10249 >= *stce_10254) {
        DCO_LOG(logDEBUG1) << "insert: chunk full, updating current and getting next";
        stce_10253 = stce_10252->stce_10003() = stce_10249;
        stce_10255(stce_10252);
        stce_10249 = stce_10252->current();
        stce_10254 = stce_10252->capacity();
      }
      if (stce_10181 == 0) {
        stce_10249.stce_10184();
        new (*stce_10249) entry(entry::stce_10180(stce_10078), pval);
        stce_10181 = stce_10249.stce_10185();
        DCO_LOG(logDEBUG2) << "inserting first entry, index now = " << stce_10181 << "; pval = " << pval
                           << ", target = " << stce_10078 << " in chunk " << stce_10252
                           << " into memory at = " << stce_10249;
        return;
      }
      if (stce_9756 && stce_10249->arg() == stce_10078) {
        DCO_LOG(logDEBUG3) << "merging a parallel edge";
        stce_10249->stce_10206(pval);
        return;
      }
      stce_10249.stce_10184();
      new (*stce_10249) entry(stce_10078, pval);
      DCO_LOG(logDEBUG2) << "inserting next entry, index now = " << stce_10181 << "; pval = " << pval
                         << ", target = " << stce_10078 << " in chunk " << stce_10252
                         << " into memory at = " << stce_10249;
    }

  private:
    edge_inserter(const edge_inserter& stce_9934);
  };

public:
  void init(tape_options const& stce_9942) {
    tape_options stce_10256 = stce_9942;
    stce_10256.blob_size_in_byte() = stce_9942.chunk_size_in_byte();
    stce_10257 = new stce_10222(stce_10256, stce_9935::stce_9927());
    stce_10186 = iterator(stce_10257);
  }
  explicit stce_9981(tape_options const& stce_9942, stce_9979& tape)
      : stce_9935(tape), object_logger("CHUNK container (w/ options)"), stce_10257(0), stce_10186() {
    assert(stce_10173 != memory_model::stce_9768);
    init(stce_9942);
  }
  explicit DCO_ALWAYS_INLINE stce_9981(iterator& stce_9825, stce_9979& tape)
      : stce_9935(tape), object_logger("CHUNK container (w/ options)"), stce_10257(0), stce_10186(stce_9825) {
    assert(stce_10173 == memory_model::stce_9768);
  }
  DCO_ALWAYS_INLINE ~stce_9981() {
    stce_10222* stce_10004 = stce_10257;
    while (stce_10004) {
      stce_10222* stce_10258 = stce_10004;
      stce_10004 = stce_10004->stce_10240();
      delete stce_10258;
    }
  }
  static void stce_10255(stce_10241& stce_9825) {
    DCO_LOG(logDEBUG1) << "current chunk: id = " << stce_9825->stce_10228()
                       << ", index = " << stce_9825->current().index()
                       << ", data pointer = " << stce_9825->stce_10216();
    delete stce_9825->stce_10240();
    if (stce_9825->stce_10231().write_to_file()) {
      sleep(*stce_9825);
      stce_9825->stce_10234(false);
      stce_9825->stce_10240() = new stce_10222(*stce_9825, stce_10222::stce_10204);
    } else {
      stce_9825->stce_10240() = new stce_10222(*stce_9825, stce_10222::stce_10205);
    }
    stce_9825->stce_10240()->stce_10239() = stce_9825;
    stce_9825 = stce_9825->stce_10240();
    DCO_LOG(logDEBUG1) << "next chunk: id = " << stce_9825->stce_10228() << ", index = " << stce_9825->current().index()
                       << ", data pointer = " << stce_9825->stce_10216();
  }
  DCO_ALWAYS_INLINE iterator& insert_ref() { return stce_10186; }
  iterator start() { return iterator(stce_10257->start(), stce_10257); }
  iterator start() const { return iterator(stce_10257->start(), stce_10257); }
  iterator rend() { return start(); }
  iterator& stce_10003() { return stce_10186; }
  iterator current() const { return stce_10186; }
  iterator rbegin() const { return current(); }
  bool empty() const { return current() == start(); }
  index_t size(const iterator& stce_9872, const iterator& stce_9873) const {
    const stce_10222& stce_10259 = *(stce_9872.stce_10247());
    if (stce_9872.stce_10247() == stce_9873.stce_10247())
      return stce_10259.size(stce_9872.stce_10250(), stce_9873.stce_10250());
    index_t size = 0;
    stce_10241 stce_10260 = stce_9872.stce_10247();
    size += stce_10260->size(stce_9872.stce_10250());
    DCO_LOG(logDEBUG2) << "size of last chunk = " << size;
    for (stce_10260 = stce_10260->stce_10239(); stce_10260 != stce_9873.stce_10247();
         stce_10260 = stce_10260->stce_10239()) {
      if (stce_10260) {
        size += stce_10260->size();
        DCO_LOG(logDEBUG2) << "adding " << stce_10260->size() << " => size = " << size;
      }
    }
    const stce_10222& stce_10261 = *(stce_9873.stce_10247());
    size += stce_10261.size(stce_10261.current(), stce_9873.stce_10250());
    DCO_LOG(logDEBUG2) << "very first bit: adding " << stce_10261.size(stce_10261.current(), stce_9873.stce_10250())
                       << " => size = " << size;
    return size;
  }
  index_t size(iterator stce_9872) const { return size(stce_9872, start()); }
  index_t size() const { return size(current(), start()); }
  mem_long_t size_in_byte() const { return size(current(), start()) * entry::size_of(); }
  index_t stce_10197() const {
    index_t size = 0;
    for (stce_10241 stce_10262 = stce_10257; stce_10262 != NULL; stce_10262 = stce_10262->stce_10240())
      if (stce_10262)
        size += stce_10262->stce_10197();
    return size;
  }
  mem_long_t stce_10198() const {
    mem_long_t size = 0;
    for (stce_10241 stce_10262 = stce_10257; stce_10262 != NULL; stce_10262 = stce_10262->stce_10240())
      if (stce_10262)
        size += stce_10262->stce_10198();
    return size;
  }
  void erase(const iterator& stce_10179) {
    if (stce_10179 > current())
      throw dco::exception::create<std::invalid_argument>("erase pos out of tape!");
    stce_10241 stce_10263(stce_10257);
    while (stce_10263 != stce_10179.stce_10247())
      stce_10263 = stce_10263->stce_10240();
    stce_10186.stce_10230() = stce_10263;
    stce_10245(*stce_10186.stce_10230());
    stce_10186.stce_10230()->stce_10237();
    stce_10241 stce_10004 = stce_10263->stce_10240();
    stce_10263->stce_10240() = 0;
    while (stce_10004) {
      stce_10241 stce_10258 = stce_10004;
      stce_10004 = stce_10004->stce_10240();
      delete stce_10258;
    }
    stce_10186.stce_10230()->erase(stce_10179.stce_10250());
    stce_10186.stce_10251() = stce_10186.stce_10230()->current();
  }
  void stce_10199(const iterator& stce_9825) {
    DCO_LOG(logDEBUG1) << "chunk tape: prepare_interpretation; activate: " << stce_9825.stce_10247()->stce_10228()
                       << ", is awake = " << stce_9825.stce_10247()->stce_10233();
    stce_10245(*stce_9825.stce_10247());
  }
  void stce_10200() {
    DCO_LOG(logDEBUG1) << "chunk tape: prepare_recording";
    stce_10245(*stce_10186.stce_10230());
  }
  index_t stce_10201() { return current().index() + 1; }
  void stce_10202(stce_9981 const* const stce_9934) { stce_10003().index() = stce_9934->current().index(); }

private:
  stce_10222* stce_10257;
  typename stce_9829<iterator, stce_10173 == memory_model::stce_9768>::type stce_10186;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <class stce_9979>
class stce_9981<memory_model::stce_9767, stce_9979> : public stce_9981<memory_model::CHUNK_TAPE, stce_9979> {
  typedef stce_9979 tape_t;

public:
  typedef typename stce_9790<stce_9979>::type stce_10174;
  typedef stce_9981<memory_model::CHUNK_TAPE, stce_9979> stce_10264;
  typedef typename stce_10264::entry entry;
  typedef typename stce_10264::edge_inserter edge_inserter;
  typedef typename stce_10264::iterator iterator;
  bool stce_10265, stce_10266, stce_10267, stce_10268;
  double stce_10269, stce_10270, stce_10271;
  std::vector<index_t> stce_10272;
  std::vector<stce_10174> stce_10273;
  std::vector<const void*> stce_10274;
  index_t stce_10275, stce_10276;
  struct stce_10277 {
    static std::string id() { return " gtas "; }
  };
  typedef logging<stce_10277> logger;
  explicit stce_9981(tape_options stce_9942, stce_9979& tape)
      : stce_10264(stce_9942, tape), stce_10265(false), stce_10266(false), stce_10267(false), stce_10268(false),
        stce_10269(1e-6), stce_10270(1e-6), stce_10271(0.0), stce_10275(0), stce_10276(-1) {}
  void stce_10278(log_level_enum level) {
    if (stce_10268 && level <= dco::logWARNING) {
      throw dco::exception::create<std::runtime_error>("Warning occured.");
    }
  }
  void stce_10279() {
    if (stce_10276 == stce_10275) {
      stce_10275++;
      throw dco::exception::create<std::runtime_error>("Event counter reached.");
    }
    stce_10275++;
  };
  void stce_10280(stce_10174 tangent, double stce_10281) {
    if (stce_10267) {
      double stce_10282 = ::fabs(tangent - stce_10281);
      log_level_enum stce_10283 = dco::logWARNING;
      if (stce_10282 < stce_10269) {
        stce_10283 = dco::logINFO;
      }
      logger(stce_10283).get_stream() << stce_10275 << ": fd vs. tangent check";
      logger(stce_10283).get_stream() << " delta = " << stce_10282 << " tangent = " << tangent
                                      << " finite differences = " << stce_10281;
      stce_10278(stce_10283);
    }
  }
  void stce_10284(double stce_10285, double stce_10286, double stce_10287) {
    const double stce_10288 = ::fabs(stce_10285 - stce_10286);
    const double stce_10289 = ::fabs(stce_10285 - stce_10287);
    log_level_enum stce_10283 = dco::logWARNING;
    if (stce_10288 < stce_10270) {
      stce_10283 = dco::logINFO;
    }
    logger(stce_10283).get_stream() << stce_10275 << ": Tangent/adjoint identity check:";
    logger(stce_10283).get_stream() << " tangent vs. adjoint = " << stce_10288;
    logger(stce_10283).get_stream() << "  <x_(1),x^(1)> = " << stce_10285;
    logger(stce_10283).get_stream() << "  <y_(1),y^(1)> = " << stce_10286;
    stce_10278(stce_10283);
    stce_10283 = dco::logWARNING;
    if (stce_10289 < stce_10269) {
      stce_10283 = dco::logINFO;
    }
    logger(stce_10283).get_stream() << " finite differences vs. adjoint = " << stce_10289;
    logger(stce_10283).get_stream() << "  <y_(1),y_{FD}^(1)> = " << stce_10287;
    stce_10278(stce_10283);
  }
  void stce_10290(const iterator& stce_9873) {
    assert(stce_10264::start() == stce_9873);
    stce_10264::stce_10290(stce_9873);
    stce_10272.clear();
    stce_10273.clear();
    stce_10274.clear();
    stce_10271 = 0;
  }
  void stce_10115(std::string stce_10291, const bool stce_9847, const bool stce_10112, const bool stce_10114) {
    if (!stce_10265) {
      stce_10279();
      return;
    }
    log_level_enum stce_10283 = dco::logWARNING;
    if (stce_9847 == stce_10112 && stce_9847 == stce_10114) {
      stce_10283 = dco::logINFO;
    }
    logger(stce_10283).get_stream() << stce_10275 << ": Branch check:" << stce_10291 << std::boolalpha
                                    << " at current value returns " << stce_9847 << ", at minus h " << stce_10112
                                    << ", and at plus h " << stce_10114;
    stce_10278(stce_10283);
    stce_10279();
  }
  template <class data_t> void stce_10292(const data_t* data, const double& tangent) {
    if (stce_10271 == 0) {
      stce_10274.push_back(data);
      stce_10272.push_back(data->_tape_index());
      stce_10273.push_back(tangent);
    }
  }
  template <typename stce_10293> void stce_10294() {
    double stce_10295 = 0;
    for (size_t stce_9845 = 0; stce_9845 < stce_10274.size(); ++stce_9845) {
      const stce_10293& stce_9825 = *static_cast<const stce_10293*>(stce_10274[stce_9845]);
      stce_10295 = std::max(stce_10295, std::fabs(stce_9825.stce_10296[0]));
    }
    const double stce_10297 = 1e-14;
    stce_10271 = std::sqrt(stce_10297) * stce_10295;
    for (size_t stce_9845 = 0; stce_9845 < stce_10274.size(); ++stce_9845) {
      const stce_10293& stce_9825 = *static_cast<const stce_10293*>(stce_10274[stce_9845]);
      stce_9825.stce_10296[0] -= stce_10271 * stce_9825.stce_9973;
      stce_9825.stce_10296[1] += stce_10271 * stce_9825.stce_9973;
    }
  }
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <class stce_9979, memory_model::TYPE stce_9980>
class stce_9981<memory_model::stce_9768, stce_9979, stce_9980>
    : public stce_9981<stce_9980, stce_9979, memory_model::stce_9768> {
public:
  typedef typename stce_9790<stce_9979>::type stce_10174;
  typedef stce_9981<stce_9980, stce_9979, memory_model::stce_9768> stce_10264;
  explicit stce_9981(tape_options stce_9942, stce_9979& tape) : stce_10264(stce_10186, tape), stce_10186() {
    stce_10264::init(stce_9942);
  }
  struct iterator : public stce_10264::iterator {
    iterator() : stce_10298(1), stce_10299(0) {}
    iterator(const typename stce_10264::iterator& stce_10300)
        : stce_10264::iterator(stce_10300), stce_10298(-1), stce_10299(-1) {}
    index_t stce_10298;
    index_t stce_10299;
    const index_t& max_dist() const { return stce_10298; }
    void stce_10301(const index_t& stce_10302) {
      stce_10298 = stce_10302 + 1;
      DCO_LOG(logDEBUG3) << " updating max dist: " << stce_10298;
    }
    const index_t& stce_10303() const { return stce_10299; }
    index_t stce_10185() {
      stce_10299++;
      return stce_10264::iterator::stce_10185();
    }
  };
  class edge_inserter : public stce_10264::edge_inserter {
    iterator& stce_10186;

  public:
    edge_inserter(iterator& current) : stce_10264::edge_inserter(current), stce_10186(current) {}
    iterator& current() { return stce_10186; }
    DCO_ALWAYS_INLINE void insert(const index_t& stce_10078, const stce_10174& pval) {
      DCO_LOG(logDEBUG4) << "target = " << stce_10078 << ", parametercounter = " << current().stce_10303()
                         << ", max dist = " << current().max_dist();
      index_t stce_10304 = current().index();
      stce_10264::edge_inserter::insert(stce_10078, pval);
      if (stce_10078 > current().stce_10303()) {
        index_t stce_10305 = stce_10304 - stce_10078 + 1;
        DCO_LOG(logDEBUG4) << "curdist = " << stce_10305;
        if (stce_10305 - current().max_dist() > 0) {
          current().stce_10301(stce_10305);
        }
      }
    }

  private:
    edge_inserter(const edge_inserter& stce_9934);
  };
  DCO_ALWAYS_INLINE iterator& insert_ref() { return static_cast<iterator&>(stce_10264::insert_ref()); }
  iterator current() const { return stce_10186; }
  iterator current() { return stce_10186; }
  iterator& stce_10003() { return stce_10186; }
  iterator rbegin() const { return stce_10186; }
  index_t stce_10201() {
    using ::log;
    using ::pow;
    index_t max_dist = stce_10186.max_dist();
    bool stce_10306 = (max_dist & (max_dist - 1)) == 0;
    if (HAS_BITWISE_MODULO && !stce_10306) {
      index_t stce_10023 = static_cast<index_t>(floor(log(static_cast<double>(max_dist)) / log(2.0))) + 1;
      stce_10186.stce_10301((1 << stce_9752(stce_10023)) - 1);
      DCO_LOG(logDEBUG2) << "rounding adjoint vector size to " << stce_10186.max_dist();
    }
    return stce_10186.stce_10303() + stce_10186.max_dist() + 1;
  }

private:
  iterator stce_10186;
};
} // namespace internal
namespace helper {
template <typename stce_9788, memory_model::TYPE stce_9789, typename external_adjoint_object_t>
struct stce_10010<internal::tape<memory_model::stce_9768, stce_9788, stce_9789>, external_adjoint_object_t> {
  typedef internal::tape<memory_model::stce_9768, stce_9788, stce_9789> tape_t;
  index_t stce_10307;
  index_t stce_10308;
  external_adjoint_object_t* stce_10309;
  stce_10010(external_adjoint_object_t* stce_10310)
      : stce_10307(std::numeric_limits<index_t>::max()), stce_10308(0), stce_10309(stce_10310) {}
  template <typename stce_9780> void register_input(const stce_9780& stce_9807) {
    index_t stce_9810 = stce_9807._tape_index();
    if (stce_9810 > stce_10309->tape()->current().stce_10303()) {
      stce_10307 = std::min(stce_10307, stce_9810);
    }
  }
  template <typename stce_9780> void register_output(const stce_9780& stce_10050) {
    stce_10308 = std::max(stce_10308, stce_10050._tape_index());
    if (stce_10307 != std::numeric_limits<index_t>::max()) {
      index_t max_dist = stce_10308 - stce_10307;
      if (max_dist > stce_10309->tape()->stce_10003().max_dist()) {
        stce_10309->tape()->stce_10003().stce_10301(max_dist);
      }
    }
  }
};
} // namespace helper
namespace internal {
template <typename stce_9791, typename stce_9979, memory_model::TYPE stce_9980>
class adjoint_vector_lazy<stce_9791, internal::stce_9981<memory_model::stce_9768, stce_9979, stce_9980>>
    : public adjoint_vector_lazy<stce_9791, internal::stce_9981<stce_9980, stce_9979, memory_model::stce_9768>> {
  typedef internal::stce_9981<memory_model::stce_9768, stce_9979, stce_9980> stce_9899;
  typedef typename stce_9899::stce_10264 stce_10264;
  typedef adjoint_vector_lazy<stce_9791, stce_10264> stce_10311;
  typedef typename stce_10311::stce_9762 stce_9762;

public:
  stce_9899& stce_9986;
  adjoint_vector_lazy(index_t size, stce_9899& tape, tape_options stce_9942)
      : stce_10311(size, static_cast<stce_10264&>(tape), stce_9942), stce_9986(tape), stce_10312(true), stce_10313(0) {}
  void init() {
    stce_10314 = stce_9986.current().stce_10303();
    if (HAS_BITWISE_MODULO) {
      stce_10315 = stce_9986.current().max_dist() - 1;
    } else {
      stce_10315 = stce_9986.current().max_dist();
    }
    stce_10316 = this->stce_9897.data() + stce_9752(stce_10314) + 1;
  }
  bool stce_9943(index_t stce_9944) const {
    if (stce_9944 > stce_9986.current().stce_10303()) {
      stce_9944 -= stce_9986.current().stce_10303();
      stce_9944 %= stce_9986.current().max_dist();
      stce_9944 += stce_9986.current().stce_10303() + 1;
    }
    return static_cast<index_t>(this->stce_9937) > stce_9944;
  }
  index_t stce_10317(index_t stce_9810) const {
    if (stce_9810 > stce_9986.current().stce_10303()) {
      stce_9810 -= stce_9986.current().stce_10303();
      stce_9810 %= stce_9986.current().max_dist();
      stce_9810 += stce_9986.current().stce_10303() + 1;
    }
    return stce_9810;
  }
  typename stce_10311::stce_9762& operator[](index_t stce_9810) {
    DCO_LOG(logDEBUG4) << "getting " << stce_9810;
    stce_9810 = stce_10317(stce_9810);
    DCO_LOG(logDEBUG4) << "matched to " << stce_9810;
    return stce_10311::operator[](stce_9810);
  }
  typename stce_10311::stce_9762 operator[](index_t stce_9810) const {
    DCO_LOG(logDEBUG4) << "getting " << stce_9810;
    stce_9810 = stce_10317(stce_9810);
    DCO_LOG(logDEBUG4) << "matched to " << stce_9810;
    return stce_10311::operator[](stce_9810);
  }
  stce_9762 at(index_t stce_9810) const { return stce_9943(stce_9810) ? (*this)[stce_9810] : 0; }
  stce_9762& at(const index_t stce_9810) {
    if (!stce_9943(stce_9810))
      this->resize(stce_9986.stce_10201());
    return (*this)[stce_9810];
  }
  void stce_9950(index_t stce_9810) {
    if (!stce_9943(stce_9810)) {
      DCO_LOG(logDEBUG2) << "Resizing internal adjoint vector to " << stce_9810;
      this->resize(stce_9986.stce_10201());
    }
  }
  template <typename iterator_t> void stce_9946(iterator_t& stce_9825) {
    index_t stce_9873 = stce_9825->arg();
    stce_9762 pval = stce_9825->pval();
    index_t stce_9872 = stce_9825.index();
    if (stce_10312) {
      DCO_LOG(logDEBUG3) << "setting " << stce_9872 << " to 0 ";
      stce_9762& stce_10318 = HAS_BITWISE_MODULO ? stce_10316[(stce_9872 - stce_10314) & stce_10315]
                                                 : stce_10316[(stce_9872 - stce_10314) % stce_10315];
      this->stce_10313 = stce_10318;
      stce_10318 = 0;
    }
    if (stce_9873 > stce_10314) {
      stce_9762& stce_10318 = HAS_BITWISE_MODULO ? stce_10316[(stce_9873 - stce_10314) & stce_10315]
                                                 : stce_10316[(stce_9873 - stce_10314) % stce_10315];
      stce_10318 += pval * this->stce_10313;
    } else {
      (*this)[stce_9873] += pval * this->stce_10313;
    }
    stce_10312 = stce_9825.stce_10008();
  }

private:
  stce_9762* stce_10316;
  index_t stce_10314;
  index_t stce_10315;
  bool stce_10312;
  stce_9762 stce_10313;
};
} // namespace internal
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_10081> struct stce_10319 {
public:
  typedef stce_10081 mode_t;
  typedef stce_10087 stce_10141;

private:
  static const size_t size = mode_t::p1f_size;
  typedef std::bitset<size> stce_10320;

public:
  typedef stce_10320 derivative_t;

private:
  mutable stce_10320 stce_10321;

public:
  stce_10319() {}
  DCO_STRONG_INLINE stce_10319(stce_10319 const& stce_10035) : stce_10321(stce_10035.stce_10321) {}
  DCO_STRONG_INLINE stce_10319& operator=(const stce_10319& stce_10084) {
    stce_10321 = stce_10084.stce_10321;
    return *this;
  }
  stce_10320& stce_9967() const { return stce_10321; }
  void clear() { stce_10321.reset(); }
  template <class stce_9908> DCO_ALWAYS_INLINE void stce_9909(const stce_9908& stce_10142) {
    stce_10319 stce_10028;
    stce_10322(stce_10142, stce_10028.stce_10321);
    stce_10321 = stce_10028.stce_10321;
  }
  typedef typename mode_t::value_t stce_9769;

private:
  template <class stce_10126>
  static void stce_10322(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807, stce_10320& stce_10078) {
    stce_10078 |= stce_9807.stce_10321;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void stce_10322(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
                         stce_10320& stce_10078) {
    stce_10322(stce_9807.stce_10132, stce_10078);
    stce_10322(stce_9807.stce_10134, stce_10078);
  }
  template <class stce_10136, class stce_10130>
  static void stce_10322(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807,
                         stce_10320& stce_10078) {
    stce_10322(stce_9807.stce_10137, stce_10078);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void stce_10322(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
                         stce_10320& stce_10078) {
    stce_10322(stce_9807.stce_10132, stce_10078);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void stce_10322(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
                         stce_10320& stce_10078) {
    stce_10322(stce_9807.stce_10134, stce_10078);
  }
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
namespace stce_10323 {
template <typename stce_10324, typename adjoint_vector>
void stce_10325(stce_10324 stce_9825, stce_10324 stce_9873, const adjoint_vector& stce_10326,
                const std::string& filename = "tape.dot") {
  stce_10325(stce_9825, stce_9873, stce_10326, stce_9859(filename));
}
template <typename stce_10324, typename adjoint_vector>
void stce_10325(stce_10324 stce_9825, stce_10324 stce_9873, const adjoint_vector& stce_10326, stce_9859& stce_9860) {
  if (stce_9825.index() == stce_9873.index()) {
    return;
  } else if (stce_9825.index() < stce_9873.index()) {
    std::swap(stce_9825, stce_9873);
  }
  for (; stce_9825 != stce_9873; stce_9825--) {
    if (stce_9825->stce_10008()) {
      stce_9860.stce_9869(stce_9825.index(), stce_10326.at(stce_9825.index()));
    }
    stce_9860.stce_9871(stce_9825->arg(), stce_9825.index(), stce_9825->pval());
  }
  for (int stce_9845 = 0; stce_9845 <= stce_9825.index(); ++stce_9845) {
    stce_9860.stce_9869(stce_9845, stce_10326.at(stce_9845));
  }
}
template <typename stce_10324, typename adjoint_vector, typename stce_10327>
void stce_10325(stce_10324 stce_9825, stce_10324 stce_9873, const adjoint_vector& stce_10326,
                const stce_10327& stce_10328, stce_9859& stce_9860) {
  if (stce_9825.index() < stce_9873.index()) {
    std::swap(stce_9825, stce_9873);
  }
  stce_10325(stce_9825, stce_9873, stce_10326, stce_9860);
  typedef typename stce_10327::const_reverse_iterator stce_10329;
  for (stce_10329 stce_10004 = stce_10328.rbegin();
       stce_10004 != stce_10328.rend() && stce_9873 <= stce_10004->stce_10330(); ++stce_10004) {
    if (stce_9825 < stce_10004->stce_10330())
      continue;
    stce_10004->stce_10331()->stce_10016(stce_9860, stce_10004->stce_10330().index() + 1);
  }
}
template <typename stce_10324>
void stce_10332(stce_10324 stce_9825, stce_10324 stce_9873, std::string const& filename) {
  if (stce_9825.index() < stce_9873.index()) {
    std::swap(stce_9825, stce_9873);
  }
  std::ofstream stce_9815(filename.c_str());
  stce_9815 << stce_9825.index() << "\n";
  for (; stce_9825 != stce_9873; --stce_9825) {
    stce_9815 << stce_9825->arg() << ", " << stce_9825->pval() << "; ";
    if (stce_9825->stce_10008())
      stce_9815 << "\n";
  }
}
template <bool USE_SPARSE_INTERPRET, typename stce_10324, typename adjoint_vector, typename stce_10333>
DCO_STRONG_INLINE void interpret(stce_10324 stce_9825, const stce_10324& stce_9873, adjoint_vector& stce_10326,
                                 stce_10333 const& stce_10334) {
  using stce_10335 = typename dco::mode<typename adjoint_vector::stce_9936>::data_t;
  using stce_10336 = typename stce_10335::mode_t;
  static constexpr bool sparse_interpret =
      USE_SPARSE_INTERPRET || std::is_base_of<stce_10335, internal::stce_10319<stce_10336>>::value;
  stce_9825.index()--;
  stce_1000002();
  ;
  stce_10326.stce_9950(stce_9812(stce_9752(stce_9825.index())));
  stce_10326.init();
  for (; stce_9825 != stce_9873; --stce_9825) {
    if (sparse_interpret && folding::is_zero(stce_10326[stce_9825.index()])) {
      continue;
    }
    DCO_LOG(logDEBUG3) << stce_10326[stce_9825->arg()] << " <=> adj[" << stce_9825->arg()
                       << "] += " << stce_9825->pval() * stce_10326[stce_9825.index()] << " from idx "
                       << stce_9825.index();
    stce_10326.stce_9946(stce_9825);
    helper::stce_9833(int(), stce_10334, stce_9825->arg(), stce_9825->pval() * stce_10326[stce_9825.index()]);
  }
}
template <bool USE_SPARSE_INTERPRET, typename stce_10324, typename adjoint_vector, typename stce_10333>
DCO_STRONG_INLINE void stce_10337(stce_10324 stce_9825, const stce_10324& stce_9873, adjoint_vector& stce_10326,
                                  stce_10333 const& stce_10334) {
  using stce_10335 = typename dco::mode<typename adjoint_vector::stce_9936>::data_t;
  using stce_10336 = typename stce_10335::mode_t;
  static constexpr bool sparse_interpret =
      USE_SPARSE_INTERPRET || std::is_base_of<stce_10335, internal::stce_10319<stce_10336>>::value;
  stce_9825.index()--;
  stce_1000002();
  ;
  stce_10326.stce_9950(stce_9812(stce_9752(stce_9825.index())));
  stce_10326.init();
  for (; stce_9825 != stce_9873; --stce_9825) {
    if (sparse_interpret && folding::is_zero(stce_10326[stce_9825.index()])) {
      continue;
    }
    DCO_LOG(logDEBUG3) << stce_10326[stce_9825->arg()] << " <=> adj[" << stce_9825->arg()
                       << "] += " << stce_9825->pval() * stce_10326[stce_9825.index()] << " from idx "
                       << stce_9825.index();
    stce_10326.stce_9946(stce_9825);
    helper::stce_9833(int(), stce_10334, stce_9825->arg(), stce_9825->pval() * stce_10326[stce_9825.index()]);
    if (stce_9825->stce_10008()) {
      stce_10326[stce_9825.index()] = 0;
    }
  }
}
template <typename stce_10324, typename adjoint_vector>
DCO_STRONG_INLINE void stce_10338(stce_10324 stce_9825, const stce_10324& stce_9873, adjoint_vector& stce_10326) {
  stce_10326.stce_9950(stce_9825.index());
  for (; stce_9825 != stce_9873; --stce_9825) {
    std::cout << stce_9825.index() << ": " << stce_9825->arg() << ", " << stce_9825->pval() << ", "
              << stce_10326[stce_9825.index()] << std::endl;
  }
}
template <typename tape_t> DCO_STRONG_INLINE void stce_10338(const tape_t* tape) {
  typename tape_t::iterator stce_9825 = tape->get_position();
  for (; stce_9825 != tape->begin(); --stce_9825) {
    std::cout << stce_9825.index() << ": " << stce_9825->arg() << ", " << stce_9825->pval() << std::endl;
  }
}
} // namespace stce_10323
} // namespace internal
} // namespace dco

namespace dco {
template <typename tape_t> struct stce_10339 {
  typedef std::map<std::string, mem_long_t> stce_10340;
  stce_10340 stce_10341;
  tape_t* stce_9986;
  stce_10339(tape_t* tape) : stce_9986(tape) {
    stce_10341["max_tape_memory"] = 0;
    stce_10341["max_adjoint_memory"] = 0;
    stce_10341["max_checkpoint_memory"] = 0;
    stce_10341["max_total_memory"] = 0;
  }
  mem_long_t operator[](std::string stce_10342) { return stce_10341[stce_10342]; }
  void stce_10343() {
    mem_long_t stce_10344 = dco::size_of(stce_9986, tape_t::size_of_stack);
    if (stce_10344 > stce_10341["max_tape_memory"]) {
      stce_10341["max_tape_memory"] = stce_10344;
    }
    stce_10344 = dco::size_of(stce_9986, tape_t::size_of_internal_adjoint_vector);
    if (stce_10344 > stce_10341["max_adjoint_memory"]) {
      stce_10341["max_adjoint_memory"] = stce_10344;
    }
    stce_10344 = dco::size_of(stce_9986, tape_t::size_of_checkpoints);
    if (stce_10344 > stce_10341["max_checkpoint_memory"]) {
      stce_10341["max_checkpoint_memory"] = stce_10344;
    }
    stce_10341["max_total_memory"] = 0;
    for (stce_10340::iterator stce_9845 = stce_10341.begin(); stce_9845 != stce_10341.end(); ++stce_9845) {
      stce_10341["max_total_memory"] += stce_9845->second;
    }
  }
  mem_long_t stce_10345() { return stce_10341["max_tape_memory"]; }
};
} // namespace dco

struct stce_10346 {
  int stce_10347;

public:
  DCO_ALWAYS_INLINE stce_10346() : stce_10347(DCO_COMPATIBILITY_VERSION) {}
  DCO_ALWAYS_INLINE bool is_compatible(int stce_10348, bool stce_10338 = false) {
    if (stce_10338)
      dco::cout_diffs_in_version(stce_10348, stce_10347);
    return stce_10348 == stce_10347;
  }
};
namespace dco {
namespace internal {
template <memory_model::TYPE MEMORY_MODEL, typename stce_10349, memory_model::TYPE stce_9789>
class tape
    : public stce_10346,
      public dco::adjoint_vector_abstract<typename helper::vecsize_info<typename stce_10349::stce_9762>::stce_9851>,
      public stce_9981<MEMORY_MODEL, tape<MEMORY_MODEL, stce_10349, stce_9789>, stce_9789> {
public:
  typedef stce_10349 types_config_t;
  typedef stce_9981<MEMORY_MODEL, tape, stce_9789> stce_9899;
  typedef typename stce_9899::iterator iterator_t;
  typedef iterator_t position_t;
  typedef typename types_config_t::stce_9762 stce_9762;
  typedef typename types_config_t::stce_9761 stce_9761;
  typedef typename helper::vecsize_info<typename stce_10349::stce_9762>::stce_9851 stce_9936;
  typedef tape<MEMORY_MODEL, types_config_t, stce_9789> tape_t;
  typedef adjoint_vector_lazy<typename types_config_t::stce_9762, stce_9899> vector_t;
  vector_t stce_9897;
  stce_10339<tape> stce_10350;
  stce_10339<tape>& stce_10351() { return stce_10350; }
  const stce_10339<tape>& stce_10351() const { return stce_10350; }
  tape& get_tape() { return *this; }

private:
  bool stce_10352;
  bool stce_10353;
  struct stce_10354 {
    stce_10354() {}
    template <typename stce_9760> void operator()(index_t, stce_9760&&) const {}
  };
  static const stce_10354 stce_10355;
  index_t stce_9954;
  tape_options stce_9941;
  bool stce_10356;
  bool stce_10357;
  void stce_9959(const iterator_t& stce_9872, const iterator_t& stce_9873 = stce_9899::start()) {
    stce_9897.stce_9948(stce_9872.index(), stce_9873.index());
  }
  void stce_10358() {
    stce_9897.resize(this->stce_10201());
    stce_9897.stce_9951();
  }
  template <typename stce_10324, typename adjoint_vector, typename stce_10333>
  DCO_STRONG_INLINE void stce_10359(stce_10324 stce_9825, const stce_10324& stce_9873, adjoint_vector& stce_10326,
                                    stce_10333 const& stce_10334) {
    if (stce_10356) {
      dco::internal::stce_10323::interpret<true>(stce_9825, stce_9873, stce_10326, stce_10334);
    } else {
      dco::internal::stce_10323::interpret<false>(stce_9825, stce_9873, stce_10326, stce_10334);
    }
  }
  template <typename stce_10324, typename adjoint_vector, typename stce_10333>
  DCO_STRONG_INLINE void stce_10360(stce_10324 stce_9825, const stce_10324& stce_9873, adjoint_vector& stce_10326,
                                    stce_10333 const& stce_10334) {
    if (stce_10356) {
      dco::internal::stce_10323::stce_10337<true>(stce_9825, stce_9873, stce_10326, stce_10334);
    } else {
      dco::internal::stce_10323::stce_10337<false>(stce_9825, stce_9873, stce_10326, stce_10334);
    }
  }

public:
  const tape_options& stce_9942() const { return stce_9941; }
  bool stce_10361() { return this->start() == this->current(); }
  DCO_ALWAYS_INLINE tape(tape_options stce_9942 = tape_options())
      : stce_10346(), stce_9899(stce_9942, *this), stce_9897(1, *this, stce_9942), stce_10350(this), stce_10352(false),
        stce_10353(true), stce_9954(0), stce_9941(stce_9942), stce_10356(false), stce_10357(true) {}
  DCO_ALWAYS_INLINE ~tape() {
    for (typename std::vector<stce_10362>::iterator stce_10004 = stce_10363.begin(); stce_10004 != stce_10363.end();
         ++stce_10004) {
      stce_10004->stce_10364();
    }
  }
  bool is_active() { return stce_9757 ? stce_10353 : true; }
  bool& sparse_interpret() { return stce_10356; }
  bool& scalar_callback_mode() { return stce_10357; }
  DCO_TAPE_INT current_vector_mode_index() { return stce_9954; }
  iterator_t current() const { return get_position(); }
  iterator_t begin() const { return stce_9899::start(); }
  vector_t& adjoints() { return stce_9897; }
  template <typename stce_9780>
  typename std::enable_if<dco::mode<stce_9780>::is_adjoint_type, stce_9762>::type& adjoint(stce_9780 const& stce_9807) {
    return stce_9897[stce_9807._tape_index()];
  }
  typedef helper::stce_10012<tape> stce_10365;
  static void stce_10366(stce_10365* stce_10367) { stce_10367->get_tape()->stce_10356 = true; }
  static void stce_10368(stce_10365* stce_10367) { stce_10367->get_tape()->stce_10356 = false; }
  void set_sparse_interpret() {
    if (stce_10356 == false) {
      stce_10365* stce_10367 = this->create_callback_object<stce_10365>();
      this->insert_callback(stce_10368, stce_10367);
    }
    stce_10356 = true;
  }
  void unset_sparse_interpret() {
    if (stce_10356 == true) {
      stce_10365* stce_10367 = this->create_callback_object<stce_10365>();
      this->insert_callback(stce_10366, stce_10367);
    }
    stce_10356 = false;
  }
  bool switch_to_active() {
    if (!stce_9757) {
      throw dco::exception::create<std::runtime_error>("activity check disabled but switched",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       188);
    }
    if (!stce_10353) {
      stce_10353 = true;
      return false;
    }
    return true;
  }
  bool switch_to_passive() {
    if (!stce_9757) {
      throw dco::exception::create<std::runtime_error>("activity check disabled but switched",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       199);
    }
    if (stce_10353) {
      stce_10353 = false;
      return true;
    }
    return false;
  }
  bool stce_10369(bool stce_10370) {
    bool stce_10371 = stce_10353;
    stce_10353 = stce_10370;
    return stce_10371;
  }
  template <bool stce_10372> index_t stce_10373() {
    if (!stce_10372 && this->empty()) {
      return stce_9899::insert_ref().stce_10185();
    } else {
      typename stce_9899::edge_inserter stce_10374(stce_9899::insert_ref());
      stce_10374.insert(0, static_cast<typename stce_9899::stce_10174>(0.0));
      return stce_10374.index();
    }
  }
  template <typename stce_10086, typename stce_10367>
  void register_variable(internal::active_type<stce_10086, stce_10367> const& stce_9807) {
    internal::active_type<stce_10086, stce_10367>::register_variable(stce_9807, stce_10373<false>(), this);
  }
  template <typename stce_10086> void register_variable(std::vector<stce_10086> const& stce_9807) {
    this->register_variable(stce_9807.data(), stce_9807.size());
  }
  template <typename stce_10375> void register_variable(stce_10375 first, stce_10375 stce_10376) {
    while (first != stce_10376) {
      this->register_variable(*first++);
    }
  }
  template <typename stce_10375, typename stce_10377>
  void register_variable(stce_10375 stce_10378, stce_10375 stce_10379, stce_10377 stce_10380) {
    while (stce_10378 != stce_10379) {
      *stce_10380 = *stce_10378++;
      this->register_variable(*stce_10380++);
    }
  }
  template <typename stce_10086> void register_variable(stce_10086* stce_9807, size_t stce_10031) {
    for (size_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845) {
      stce_10086::register_variable(stce_9807[stce_9845], stce_10373<false>(), this);
    }
  }
  template <typename stce_10086> void register_output_variable(stce_10086& stce_9807) {
    typename stce_9899::edge_inserter stce_10374(stce_9899::insert_ref());
    stce_10374.insert(dco::tape_index(stce_9807), static_cast<typename stce_9899::stce_10174>(1.0));
    dco::tape_index(stce_9807) = stce_10374.index();
  }
  template <typename stce_10086> void register_output_variable(std::vector<stce_10086>& stce_9807) {
    this->register_output_variable(stce_9807.data(), stce_9807.size());
  }
  template <typename stce_10086> void register_output_variable(stce_10086* stce_9807, size_t stce_10031) {
    for (size_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845) {
      this->register_output_variable(stce_9807[stce_9845]);
    }
  }
  template <typename stce_10375> void register_output_variable(stce_10375 first, stce_10375 stce_10376) {
    while (first != stce_10376) {
      this->register_output_variable(*first++);
    }
  }
  template <stce_9794 stce_10381, typename stce_9780, typename stce_9888>
  void register_output_variable(stce_9898<stce_10381, stce_9780, stce_9888> stce_9807) {
    for (size_t stce_9845 = 0; stce_9845 < stce_9807.size(); ++stce_9845) {
      this->register_output_variable(stce_9807[stce_9845]);
    }
  }
  void reset_to(const iterator_t& stce_9873) {
    stce_10290(stce_9873);
    stce_10382(stce_9873);
  }
  void reset() { reset_to(stce_9899::start()); }
  void interpret_adjoint(interpretation_settings stce_9957 = interpretation_settings()) {
    iterator_t stce_9873 = stce_9899::start();
    stce_9958(get_position(), stce_9873, stce_9957, stce_10355);
  }
  template <typename stce_10333 = decltype(stce_10355)>
  typename std::enable_if<!std::is_same<stce_10333, interpretation_settings>::value>::type
  interpret_adjoint(stce_10333 const& stce_10334 = stce_10355) {
    iterator_t stce_9873 = stce_9899::start();
    interpretation_settings stce_9957;
    stce_9958(get_position(), stce_9873, stce_9957, stce_10334);
  }
  template <typename stce_10333 = decltype(stce_10355)>
  void interpret_adjoint_to(const iterator_t& stce_9873, stce_10333 const& stce_10334 = stce_10355) {
    interpretation_settings stce_9957;
    stce_9958(get_position(), stce_9873, stce_9957, stce_10334);
  }
  template <typename stce_10333 = decltype(stce_10355)>
  void interpret_adjoint_from(const iterator_t& stce_9872, stce_10333 const& stce_10334 = stce_10355) {
    iterator_t stce_9873 = stce_9899::start();
    interpretation_settings stce_9957;
    stce_9958(stce_9872, stce_9873, stce_9957, stce_10334);
  }
  template <typename stce_10333 = decltype(stce_10355)>
  void interpret_adjoint_from_to(const iterator_t& stce_9872, const iterator_t& stce_9873,
                                 stce_10333 const& stce_10334 = stce_10355) {
    interpretation_settings stce_9957;
    stce_9958(stce_9872, stce_9873, stce_9957, stce_10334);
  }
  template <typename stce_10333 = decltype(stce_10355)>
  void interpret_adjoint_and_reset_to(const iterator_t& stce_9873, stce_10333 const& stce_10334 = stce_10355) {
    iterator_t stce_9872(get_position());
    interpretation_settings stce_9957;
    stce_9957.reset = true;
    stce_9957.stce_9917 = true;
    stce_9958(stce_9872, stce_9873, stce_9957, stce_10334);
    stce_10290(stce_9873);
    stce_10382(stce_9873);
  }
  template <typename stce_10333 = decltype(stce_10355)>
  void interpret_adjoint_and_zero_adjoints_to(const iterator_t& stce_9873, stce_10333 const& stce_10334 = stce_10355) {
    iterator_t stce_9872(get_position());
    interpretation_settings stce_9957;
    stce_9957.reset = false;
    stce_9957.stce_9917 = true;
    stce_9958(stce_9872, stce_9873, stce_9957, stce_10334);
  }
  template <typename stce_10333 = decltype(stce_10355)>
  void interpret_adjoint_and_zero_adjoints_from_to(const iterator_t& stce_9872, const iterator_t& stce_9873,
                                                   stce_10333 const& stce_10334 = stce_10355) {
    interpretation_settings stce_9957;
    stce_9957.reset = false;
    stce_9957.stce_9917 = true;
    stce_9958(stce_9872, stce_9873, stce_9957, stce_10334);
  }
  void zero_adjoints() {
    iterator_t stce_9873 = stce_9899::start();
    stce_9959(get_position(), stce_9873);
  }
  void zero_adjoints_to(const iterator_t& stce_9873) { stce_9959(get_position(), stce_9873); }
  void zero_adjoints_from(const iterator_t& stce_9872) {
    iterator_t stce_9873 = stce_9899::start();
    stce_9959(stce_9872, stce_9873);
  }
  void zero_adjoints_from_to(const iterator_t& stce_9872, const iterator_t& stce_9873) {
    stce_9959(stce_9872, stce_9873);
  }
  void stce_10290(const iterator_t& stce_9873) {
    bool alloc = stce_9897.stce_9943(stce_9873.index());
    stce_9897.resize(stce_9873.index() + 1);
    if (alloc) {
      stce_9897.stce_9951();
    }
    stce_9899::erase(stce_9873);
  }

public:
  iterator_t get_position() const { return stce_9899::current(); }
  stce_9936& stce_10383(const index_t tape_index) {
    stce_9762& stce_9923 = _adjoint(tape_index);
    stce_9936* stce_10384 = reinterpret_cast<stce_9936*>(&stce_9923);
    return stce_10384[stce_9954];
  }
  stce_9936 stce_10383(const index_t tape_index) const {
    stce_9762 stce_9923(_adjoint(tape_index));
    stce_9936* stce_10384 = reinterpret_cast<stce_9936*>(&stce_9923);
    return stce_10384[stce_9954];
  }
  stce_9762& _adjoint(index_t tape_index) {
    if (!stce_9897.stce_9943(get_position().index() + 1))
      stce_10358();
    return stce_9897[tape_index];
  }
  stce_9762 _adjoint(const index_t tape_index) const {
    return stce_9897.stce_9943(tape_index) ? stce_9897[tape_index] : 0;
  }
  enum stce_10385 {
    size_of_stack = 1,
    size_of_allocated_stack = 2,
    size_of_internal_adjoint_vector = 4,
    size_of_checkpoints = 8,
    stce_9886 = size_of_stack | size_of_internal_adjoint_vector
  };
  mem_long_t stce_10386() const {
    mem_long_t stce_10387 = 0;
    for (size_t stce_9845 = 0; stce_9845 < stce_10363.size(); stce_9845++) {
      stce_10387 += stce_10363[stce_9845].stce_10331()->size_in_byte();
    }
    return stce_10387;
  }
  mem_long_t stce_9887(const int stce_10388 = stce_9886) const {
    mem_long_t stce_10389 = 0;
    if (stce_10388 & size_of_allocated_stack) {
      stce_10389 += static_cast<size_t>(stce_9899::stce_10198());
    } else if (stce_10388 & size_of_stack) {
      stce_10389 += static_cast<size_t>(stce_9899::size_in_byte());
    }
    if (stce_10388 & size_of_internal_adjoint_vector) {
      stce_10389 += stce_9897.stce_9945();
    }
    if (stce_10388 & size_of_checkpoints) {
      stce_10389 += stce_10386();
    }
    return stce_10389;
  }
  static DCO_ALWAYS_INLINE tape_t* create(tape_options stce_9942 = tape_options()) {
    tape_t* tape = new tape_t(stce_9942);
    return tape;
  }
  static DCO_ALWAYS_INLINE void remove(tape_t*& tape) {
    if (tape == 0)
      return;
    delete tape;
    tape = 0;
  }
  virtual stce_9936 _read_adjoint(const index_t stce_9810) { return stce_10383(stce_9810); }
  virtual void _increment_adjoint(const index_t stce_9810, const stce_9936& stce_9923) {
    stce_10383(stce_9810) += stce_9923;
  }
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  template <typename stce_10390> class stce_10391 {
  public:
    typedef void (*stce_10392)(tape_t& stce_10393, const interpretation_settings& stce_10394, stce_10390* stce_10395);
    typedef void (*stce_10396)(tape_t& stce_10393, stce_10390* stce_10395);
    typedef void (*stce_10397)(stce_10390* stce_10395);
  };
  class stce_10398 {
  public:
    virtual void stce_10399(tape_t& stce_10393, const interpretation_settings& stce_10394,
                            callback_object_t* stce_10395) = 0;
    virtual ~stce_10398(){};
  };
  template <typename stce_10390> class stce_10400 : public stce_10398 {
  private:
    union {
      typename stce_10391<stce_10390>::stce_10397 stce_10401;
      typename stce_10391<stce_10390>::stce_10396 stce_10402;
      typename stce_10391<stce_10390>::stce_10392 stce_10403;
    } stce_10401;
    int stce_10404;

  public:
    stce_10400(typename stce_10391<stce_10390>::stce_10397 stce_10405) : stce_10404(0) {
      stce_10401.stce_10401 = stce_10405;
    }
    stce_10400(typename stce_10391<stce_10390>::stce_10396 stce_10405) : stce_10404(1) {
      stce_10401.stce_10402 = stce_10405;
    }
    stce_10400(typename stce_10391<stce_10390>::stce_10392 stce_10405) : stce_10404(2) {
      stce_10401.stce_10403 = stce_10405;
    }
    void stce_10399(tape_t& stce_10393, const interpretation_settings& stce_10394, callback_object_t* stce_10395) {
      stce_10390* stce_10406 = static_cast<stce_10390*>(stce_10395);
      switch (stce_10404) {
      case 0:
        stce_10401.stce_10401(stce_10406);
        break;
      case 1:
        stce_10401.stce_10402(stce_10393, stce_10406);
        break;
      case 2:
        stce_10401.stce_10403(stce_10393, stce_10394, stce_10406);
        break;
      default:
        if (helper::stce_9837) {
          throw dco::exception::create<std::runtime_error>(
              "Internal error: Unknown callback type. Please contact NAG.");
        }
        break;
      }
    }
    ~stce_10400() {}
  };
  class stce_10362 {
    callback_object_t* stce_10395;
    stce_10398* stce_10407;
    iterator_t stce_10408;

  public:
    stce_10362() = delete;
    stce_10362(const stce_10362& stce_10035) noexcept
        : stce_10395(stce_10035.stce_10395), stce_10407(stce_10035.stce_10407), stce_10408(stce_10035.stce_10408){};
    stce_10362& operator=(const stce_10362& stce_10035) noexcept {
      stce_10395 = stce_10035.stce_10395;
      stce_10407 = stce_10035.stce_10407;
      stce_10408 = stce_10035.stce_10408;
      return *this;
    }
    stce_10362(const iterator_t& stce_10179) : stce_10395(0), stce_10407(0), stce_10408(stce_10179) {}
    bool operator<(const stce_10362& stce_9934) const { return stce_10408 < stce_9934.stce_10408; }
    void stce_10364() {
      delete stce_10395;
      if (stce_10407)
        delete stce_10407;
    }
    template <typename stce_10390, typename stce_10409> void stce_10410(stce_10409 stce_10405) {
      if (stce_10407)
        throw dco::exception::create<std::runtime_error>(
            "Currently not supported to insert external_adjoint_object_bases twice.");
      stce_10407 = new stce_10400<stce_10390>(stce_10405);
    }
    callback_object_t*& stce_10331() { return stce_10395; }
    callback_object_t* stce_10331() const { return stce_10395; }
    iterator_t& stce_10330() { return stce_10408; }
    iterator_t stce_10330() const { return stce_10408; }
    void stce_10399(tape_t& stce_10393, const interpretation_settings& stce_10394) {
      if (stce_10407)
        stce_10407->stce_10399(stce_10393, stce_10394, stce_10395);
    }
  };
  std::vector<stce_10362> stce_10363;
  size_t number_of_callbacks() { return stce_10363.size(); }
  template <class stce_10411> void stce_10412(stce_10411* stce_10395) {
    stce_10363.emplace_back(stce_10362(stce_9899::current()));
    stce_10363.back().stce_10331() = stce_10395;
    stce_10395->set_tape(this);
    typedef typename stce_10411::active_t stce_9982;
    typedef dco::stce_10068::stce_10072<tape_t, stce_9982> stce_10413;
    stce_10413* stce_10067 = stce_10395;
    insert_callback(&dco::stce_10068::stce_10066<tape_t, stce_9982>, stce_10067);
  }
  template <class stce_10411, typename stce_10409> void insert_callback(stce_10409 stce_10407, stce_10411* stce_10367) {
    if (stce_10363.back().stce_10331() == stce_10367) {
      stce_10367->stce_10015();
      stce_10363.back().template stce_10410<stce_10411>(stce_10407);
      stce_10363.back().stce_10330() = stce_9899::current();
      stce_10373<true>();
    } else {
      throw dco::exception::create<std::runtime_error>(
          "please always insert most recently created external function object.");
    }
  }
  template <typename stce_10333> struct stce_10414 : helper::stce_10012<tape> {
    stce_10333 stce_10334;
    template <typename stce_10415>
    stce_10414(stce_10415&& stce_10334) : stce_10334(std::forward<stce_10415>(stce_10334)) {}
  };
  template <typename stce_10416> static auto stce_10417(stce_10416* stce_10367) -> decltype(stce_10367->stce_10334()) {
    stce_10367->stce_10334();
  }
  template <typename stce_10416>
  static auto stce_10417(stce_10416* stce_10367) -> decltype(stce_10367->stce_10334(*stce_10367->_adjoint_vector)) {
    stce_10367->stce_10334(*stce_10367->_adjoint_vector);
  }
  template <typename stce_10333> void insert_callback(stce_10333&& stce_9849) {
    using stce_10418 = stce_10414<typename std::decay<stce_10333>::type>;
    auto* stce_10367 = this->create_callback_object<stce_10418>(std::forward<stce_10333>(stce_9849));
    this->insert_callback(stce_10417<stce_10418>, stce_10367);
  }
  template <class stce_10411, typename... FCN_PARAMETERS>
  stce_10411* create_callback_object(FCN_PARAMETERS&&... parameters) {
    stce_10363.emplace_back(stce_10362(stce_9899::current()));
    stce_10411* stce_10395 = new stce_10411(std::forward<FCN_PARAMETERS>(parameters)...);
    stce_10363.back().stce_10331() = stce_10395;
    stce_10395->set_tape(this);
    return stce_10395;
  }
  template <class stce_10411> inline stce_10411* create_ACM_object() {
    stce_10411* stce_9847 = create_callback_object<stce_10411>();
    typedef typename stce_10411::active_t stce_9982;
    typedef dco::ACM::baseclass<tape_t, stce_9982> stce_10419;
    stce_10419* stce_10067 = stce_9847;
    insert_callback(&dco::ACM::stce_10066<tape_t, stce_9982>, stce_10067);
    return stce_9847;
  }
  template <class stce_10411, typename FCN_PARAMETERS>
  inline stce_10411* create_ACM_object(const FCN_PARAMETERS& parameters) {
    const stce_9856<FCN_PARAMETERS> stce_10420(parameters);
    stce_10362 stce_10421(stce_9899::current());
    stce_10363.push_back(stce_10421);
    stce_10411* stce_10395 = stce_10420.template create<stce_10411>();
    stce_10363.back().stce_10331() = stce_10395;
    stce_10395->set_tape(this);
    typedef typename stce_10411::active_t stce_9982;
    typedef dco::ACM::baseclass<tape_t, stce_9982> stce_10419;
    stce_10419* stce_10067 = stce_10395;
    insert_callback(&dco::ACM::stce_10066<tape_t, stce_9982>, stce_10067);
    return stce_10395;
  }
  template <class stce_10411> void insert_ACM_object(stce_10411* stce_10395) {
    stce_10362 stce_10421(stce_9899::current());
    stce_10363.push_back(stce_10421);
    stce_10363.back().stce_10331() = stce_10395;
    stce_10395->set_tape(this);
    typedef typename stce_10411::active_t stce_9982;
    typedef dco::ACM::baseclass<tape_t, stce_9982> stce_10419;
    stce_10419* stce_10067 = stce_10395;
    insert_callback(&dco::ACM::stce_10066<tape_t, stce_9982>, stce_10067);
  }
  void stce_10382(const iterator_t& stce_9873) {
    typedef typename std::vector<stce_10362>::iterator stce_10329;
    stce_10329 stce_10078 = stce_10363.begin();
    for (; stce_10078 != stce_10363.end() && stce_10078->stce_10330().index() < stce_9873.index(); ++stce_10078) {
    }
    for (stce_10329 stce_10004 = stce_10078; stce_10004 != stce_10363.end(); ++stce_10004)
      stce_10004->stce_10364();
    stce_10363.erase(stce_10078, stce_10363.end());
  }

public:
  void write_to_dot(const std::string& filename = "tape.dot") {
    write_to_dot(stce_9899::current(), stce_9899::start(), filename);
  }
  void write_to_dot(iterator_t stce_9872) { write_to_dot(stce_9872, stce_9899::start()); }
  void write_to_dot(iterator_t stce_9825, iterator_t stce_9873, const std::string& filename = "tape.dot") {
    stce_9859 stce_9860(filename);
    dco::internal::stce_10323::stce_10325(stce_9825, stce_9873, stce_9897, stce_10363, stce_9860);
  }
  void write_to_csv(const std::string& filename = "tape.csv") {
    write_to_csv(stce_9899::current(), stce_9899::start(), filename);
  }
  void write_to_csv(iterator_t stce_9872) { write_to_csv(stce_9872, stce_9899::start()); }
  void write_to_csv(iterator_t stce_9825, iterator_t stce_9873, const std::string& filename = "tape.csv") {
    if (stce_10363.size() != 0)
      throw dco::exception::create<std::runtime_error>("write_to_csv not implemented for callbacks.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       794);
    dco::internal::stce_10323::stce_10332(stce_9825, stce_9873, filename);
  }
  void synchronize_with(tape const* const stce_9934) { this->stce_10202(stce_9934); }
  void stce_10422(iterator_t const& stce_9825, stce_10362& stce_10423, interpretation_settings const& stce_9957) {
    this->stce_10422(*this, stce_9825, stce_10423, stce_9957);
  }
  template <class stce_10424>
  void stce_10422(stce_10424& stce_10384, const iterator_t& stce_9825, stce_10362& stce_10423,
                  const interpretation_settings& stce_9957) {
    if (stce_10423.stce_10330() != stce_9825)
      throw dco::exception::create<std::runtime_error>("invoking callback at wrong position",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       813);
    if (stce_9957.reset) {
      stce_10290(stce_9825);
      stce_10373<true>();
    }
    index_t vecsize = static_cast<index_t>(dco::helper::vecsize_info<typename types_config_t::stce_9762>::vecsize);
    if (stce_10357) {
      for (index_t stce_10425 = 0; stce_10425 < vecsize; stce_10425++) {
        stce_9954 = stce_10425;
        stce_10423.stce_10331()->_adjoint_vector = &stce_10384;
        stce_10423.stce_10399(*this, stce_9957);
      }
    } else {
      stce_10423.stce_10331()->_adjoint_vector = &stce_10384;
      stce_10423.stce_10399(*this, stce_9957);
    }
  }
  struct stce_10426 {
    tape* stce_9986;
    bool stce_10356;
    stce_10426(tape* stce_10014) : stce_9986(stce_10014), stce_10356(stce_10014->sparse_interpret()) {}
    ~stce_10426() { stce_9986->sparse_interpret() = stce_10356; }
  };
  template <typename stce_10333 = decltype(stce_10355)>
  void stce_9958(iterator_t stce_9825, const iterator_t& stce_9873, const interpretation_settings& stce_9957,
                 stce_10333 const& stce_10334) {
    stce_10358();
    stce_9964(stce_9897, *this, stce_9825, stce_9873, stce_9957, stce_10334);
  }
  template <typename stce_10424, typename stce_10427, typename stce_10333>
  void stce_9964(stce_10424& stce_10384, stce_10427& stce_10428, iterator_t stce_9825, const iterator_t& stce_9873,
                 const interpretation_settings& stce_9957, stce_10333 const& stce_10334) {
    stce_10426 stce_10429(this);
    if (stce_9825 > stce_9899::current()) {
      throw dco::exception::create<std::runtime_error>("you try to use a tape position outside of the current tape.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       866);
    }
    if (stce_9873 > stce_9825) {
      throw dco::exception::create<std::runtime_error>("adjoint interpretation: from < to.",
                                                       "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                       "dco_cpp_make_release/dco_cpp_dev/src/dco_tape.hpp",
                                                       871);
    }
    for (int stce_9845 = static_cast<int>(stce_10363.size() - 1);
         stce_9845 >= 0 && stce_9873 <= stce_10363[stce_9845].stce_10330(); --stce_9845) {
      const iterator_t& stce_10430 = stce_10363[stce_9845].stce_10330();
      if (stce_9825 < stce_10430) {
        continue;
      }
      stce_9899::stce_10199(stce_9825);
      if (stce_9957.stce_9917)
        stce_10360(stce_9825, stce_10430, stce_10384, stce_10334);
      else {
        stce_10359(stce_9825, stce_10430, stce_10384, stce_10334);
      }
      stce_9825 = stce_10430;
      stce_9899::stce_10200();
      stce_10422(stce_10428, stce_9825, stce_10363[stce_9845], stce_9957);
      if (stce_9957.reset) {
        stce_10290(stce_9825);
        stce_10363[stce_9845].stce_10364();
        stce_10363.erase(stce_10363.begin() + stce_9845);
      }
    }
    stce_9899::stce_10199(stce_9825);
    if (stce_9957.stce_9917) {
      stce_10360(stce_9825, stce_9873, stce_10384, stce_10334);
    } else {
      stce_10359(stce_9825, stce_9873, stce_10384, stce_10334);
    }
    if (stce_9957.reset) {
      stce_10290(stce_9825);
    }
    stce_9899::stce_10200();
  }
};
template <memory_model::TYPE MEMORY_MODEL, typename stce_10349, memory_model::TYPE stce_9789>
const typename tape<MEMORY_MODEL, stce_10349, stce_9789>::stce_10354
    tape<MEMORY_MODEL, stce_10349, stce_9789>::stce_10355;
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, class stce_9759 = stce_9780, class stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1sm_mod {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  typedef dco::internal::stce_10146<ga1sm_mod> data_t;
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10431 = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10431> tape_t;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
template <class stce_9780, class stce_9759 = stce_9780, class stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1s_mod {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10431 = MEMORY_MODEL;
  typedef dco::internal::stce_10139<ga1s_mod> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10431> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <class stce_9780, class stce_9759, class stce_9760, memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1s_mod<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1s_mod<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::global_tape = 0;
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10432 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1v {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10432>> stce_10144;

public:
  typedef ga1v mode_t;
  typedef dco::internal::stce_10139<ga1v> data_t;
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef stce_9760 stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <typename stce_9780, const size_t stce_10432, typename stce_9759, typename stce_9760,
          memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1v<stce_9780, stce_10432, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1v<stce_9780, stce_10432, stce_9759, stce_9760, MEMORY_MODEL>::global_tape;
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10432 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1vm {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10432>> stce_10144;

public:
  typedef ga1vm mode_t;
  typedef dco::internal::stce_10146<ga1vm> data_t;
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef stce_9760 stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10432 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1vm_mod {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10432>> stce_10144;

public:
  typedef dco::internal::stce_10146<ga1vm_mod> data_t;
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10431 = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef typename derivative_t::value_t stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10431> tape_t;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
template <typename stce_9780, const size_t stce_10432 = 1, typename stce_9759 = stce_9780,
          typename stce_9760 = stce_9759, memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class ga1v_mod {
  typedef types_config_t<stce_9780, stce_9759, dco::helper::valvec<stce_9760, stce_10432>> stce_10144;

public:
  typedef dco::internal::stce_10139<ga1v_mod> data_t;
  static const memory_model::TYPE TAPE_MODEL = memory_model::stce_9768;
  static const memory_model::TYPE stce_10431 = MEMORY_MODEL;
  typedef typename stce_10144::value_t value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef typename derivative_t::value_t stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = false;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef dco::internal::tape<TAPE_MODEL, stce_10144, stce_10431> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <typename stce_9780, const size_t stce_10432, typename stce_9759, typename stce_9760,
          memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename ga1v_mod<stce_9780, stce_10432, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    ga1v_mod<stce_9780, stce_10432, stce_9759, stce_9760, MEMORY_MODEL>::global_tape;
} // namespace dco

namespace dco {
template <typename active_t, typename stce_10433 = void> struct gbcp;
template <typename stce_9982>
struct gbcp<stce_9982, typename dco::enable_if<(dco::mode<stce_9982>::is_dco_type &&
                                                !internal::is_gbcp_type<stce_9982>::value)>::type> {
  typedef stce_9982 binary_t;
  typedef typename dco::mode<binary_t>::value_t active_t;
  typedef active_t active_value_t;
  typedef typename dco::mode<active_value_t>::value_t value_t;
  typedef typename dco::mode<active_value_t>::scalar_value_t scalar_value_t;
  typedef typename mode<active_value_t>::passive_t passive_t;
  typedef typename mode<active_value_t>::scalar_passive_t scalar_passive_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  typedef dco::internal::stce_9907<gbcp> data_t;
  typedef dco::internal::active_type<active_value_t, data_t> type;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = dco::mode<active_value_t>::is_adjoint_type;
  static const bool is_tangent_type = dco::mode<active_value_t>::is_tangent_type;
  static const bool stce_10145 = dco::mode<active_value_t>::stce_10145;
  static const int gbcp_order = 1;
  static const int order = dco::mode<binary_t>::order - 1;
  static const size_t p1f_size = 0;
};
template <typename stce_10434>
struct gbcp<stce_10434, typename dco::enable_if<(dco::mode<stce_10434>::is_dco_type &&
                                                 internal::is_gbcp_type<stce_10434>::value)>::type> {
  typedef stce_10434 binary_t;
  typedef typename dco::mode<binary_t>::active_t active_t;
  typedef typename dco::mode<binary_t>::active_value_t active_value_t;
  typedef typename dco::mode<binary_t>::value_t value_t;
  typedef typename dco::mode<binary_t>::scalar_value_t scalar_value_t;
  typedef typename dco::mode<binary_t>::passive_t passive_t;
  typedef typename dco::mode<binary_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::stce_9907<gbcp> data_t;
  typedef dco::internal::active_type<active_value_t, data_t> type;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = dco::mode<binary_t>::is_adjoint_type;
  static const bool is_tangent_type = dco::mode<binary_t>::is_tangent_type;
  static const int gbcp_order = dco::mode<binary_t>::gbcp_order + 1;
  static const int order = dco::mode<binary_t>::order - 1;
};
template <typename stce_9975>
struct gbcp<stce_9975, typename dco::enable_if<(!dco::mode<stce_9975>::is_dco_type)>::type> {
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
  typedef stce_9975 binary_t;
  typedef binary_t active_t;
  typedef binary_t active_value_t;
  typedef binary_t value_t;
  typedef binary_t scalar_value_t;
  typedef binary_t passive_t;
  typedef typename dco::mode<binary_t>::scalar_passive_t scalar_passive_t;
  typedef binary_t type;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = false;
  static const int gbcp_order = 1;
  static const int order = 0;
};
} // namespace dco

namespace dco {
template <typename stce_9780, size_t stce_10435 = 32> struct gp1f {
  typedef stce_9780 value_t;
  typedef value_t scalar_value_t;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  static const size_t p1f_size = stce_10435;
  typedef internal::stce_10319<gp1f> data_t;
  typedef internal::active_type<double, data_t> type;
  typedef typename data_t::derivative_t derivative_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = false;
  static const bool is_intermediate_type = false;
  static const int order = dco::mode<stce_9780>::order + 1;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_10081> struct stce_10436 {
  typedef stce_10081 mode_t;
  index_t tape_index;
  stce_10436() : tape_index(0) {}
  void clear() { tape_index = 0; }
  typedef typename mode_t::value_t stce_9769;

private:
  template <class stce_10126>
  static void interpret(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807, bool stce_10437) {
    (void)stce_10437;
    stce_10081::global_tape->stce_10438[stce_10081::global_tape->stce_10439] = stce_9807.tape_index;
    stce_10081::global_tape->stce_10439++;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void interpret(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
                        bool stce_10437) {
    interpret(stce_9807.stce_10132, stce_10437);
    interpret(stce_9807.stce_10134, stce_10437);
  }
  template <class stce_10136, class stce_10130>
  static void interpret(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807, bool stce_10437) {
    interpret(stce_9807.stce_10137, stce_10437);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void interpret(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
                        bool stce_10437) {
    interpret(stce_9807.stce_10132, stce_10437);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static void interpret(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
                        bool stce_10437) {
    interpret(stce_9807.stce_10134, stce_10437);
  }

protected:
  template <class stce_9908, class stce_9793> static void stce_9909(const stce_9908& stce_9905, stce_9793& stce_10440) {
    const int stce_10441 = stce_10081::global_tape->stce_10439;
    interpret(stce_9905, false);
    stce_10436& data = const_cast<stce_10436&>(stce_10440);
    if (stce_10441 == stce_10081::global_tape->stce_10439) {
      data.clear();
    } else {
      stce_10081::global_tape->stce_10442++;
      data.tape_index = stce_10081::global_tape->stce_10442;
      stce_10081::global_tape->stce_10443[stce_10081::global_tape->stce_10442].stce_10444 =
          stce_10081::global_tape->stce_10439 - stce_10441;
      stce_10081::global_tape->stce_10443[stce_10081::global_tape->stce_10442].stce_10441 = stce_10441;
    }
  }
  template <class stce_9908> void stce_9909(const stce_9908& stce_9905) { stce_9909(stce_9905, *this); }
};
} // namespace internal
} // namespace dco
namespace dco {
namespace internal {
template <typename stce_9769> struct stce_10445 {
private:
  template <typename stce_10081> friend struct stce_10436;
  struct stce_10446 {
    index_t stce_10444;
    index_t stce_10441;
  };
  stce_10446* stce_10443;
  index_t stce_10442;
  int* stce_10438;
  index_t stce_10439;
  stce_10445(const stce_10445<stce_9769>&) {
    throw dco::exception::create<std::runtime_error>("dco_error: Not implemented yet! Please report, why needed!",
                                                     "/home/nag/amdepyc/gitlab-runner/builds/euytek5L/0/ad-tools/"
                                                     "dco_cpp_make_release/dco_cpp_dev/src/dco_tape_blob_pattern.hpp",
                                                     32);
  }
  stce_10445(index_t stce_10444, index_t stce_10447) {
    stce_10443 = new stce_10446[stce_9752(stce_10447)];
    stce_10442 = 0;
    stce_10438 = new int[size_t(stce_10444)];
    stce_10439 = 0;
  }
  ~stce_10445() {
    if (stce_10443)
      delete[] stce_10443;
    if (stce_10438)
      delete[] stce_10438;
  }

public:
  struct stce_10448 {
    friend struct stce_10445<stce_9769>;

  private:
    index_t stce_10449;
    index_t stce_10450;
    stce_10448(index_t stce_10451, index_t stce_10452) : stce_10449(stce_10451), stce_10450(stce_10452) {}

  public:
    stce_10448() : stce_10449(0), stce_10450(0){};
    index_t stce_10453() { return stce_10449; }
    index_t stce_10454() {
      if (stce_10450 < 0)
        return -stce_10450;
      return stce_10450;
    }
    bool stce_10437() { return stce_10450 < 0; }
  };
  struct iterator_t {
  private:
    index_t _progvarcounter;

  public:
    index_t stce_10447() const { return _progvarcounter; }
    iterator_t(const index_t stce_10455) : _progvarcounter(stce_10455) {}
  };
  iterator_t get_position() { return iterator_t(stce_10442); }
  typedef std::vector<stce_10448> sparse_jacobi;
  template <class stce_9780>
  sparse_jacobi* build_pattern(stce_9780* stce_10453, index_t stce_10031, const iterator_t& stce_10456) {
    sparse_jacobi* stce_9847 = new sparse_jacobi();
    for (index_t stce_9845 = 0; stce_9845 < stce_10031; ++stce_9845) {
      stce_10457(stce_9845 + 1, stce_10453[stce_9845].tape_index, stce_10456, stce_9847);
    }
    return stce_9847;
  }
  void create_pattern_file(sparse_jacobi* stce_10458, std::string filename) {
    std::ofstream out(filename.c_str());
    for (size_t stce_9845 = 0; stce_9845 < stce_10458->size(); ++stce_9845) {
      stce_10448& stce_10459 = (*stce_10458)[stce_9845];
      out << stce_10459.stce_10453() << " " << stce_10459.stce_10454() << " 1" << std::endl;
    }
    out.close();
  }
  void stce_10460(std::string filename) {
    std::ofstream out(filename.c_str());
    out << "digraph {" << std::endl;
    for (index_t stce_9845 = 1; stce_9845 <= stce_10442; ++stce_9845) {
      out << stce_9845 << std::endl;
    }
    for (index_t stce_9845 = 1; stce_9845 <= stce_10442; ++stce_9845) {
      int stce_10444 = stce_10443[stce_9845].stce_10444;
      int stce_10461 = stce_10443[stce_9845].stce_10441;
      for (int stce_10462 = 0; stce_10462 < stce_10444; ++stce_10462) {
        int stce_10078 = stce_10438[stce_10462 + stce_10461];
        out << stce_9845 << " -> " << stce_10078 << std::endl;
      }
    }
    out << "}" << std::endl;
    out.close();
  }
  void stce_10457(index_t stce_10451, index_t stce_9868, const iterator_t& stce_10456, sparse_jacobi* stce_10463) {
    if (stce_9868 == 0)
      return;
    if (stce_9868 <= stce_10456.stce_10447()) {
      stce_10463->push_back(stce_10448(stce_10451, stce_9868));
    } else {
      index_t stce_10444 = stce_10443[stce_9868].stce_10444;
      index_t stce_10461 = stce_10443[stce_9868].stce_10441;
      for (int stce_9845 = 0; stce_9845 < stce_10444; ++stce_9845) {
        stce_10457(stce_10451, stce_10438[stce_9845 + stce_10461], stce_10456, stce_10463);
      }
    }
  }
  static stce_10445* create(index_t size, index_t stce_10464 = 0) {
    if (stce_10464 == 0)
      stce_10464 = size / 2;
    return new stce_10445(size, stce_10464);
  }
  static void remove(stce_10445*& tape) {
    delete tape;
    tape = 0;
  }
  template <class stce_10126> void register_variable(dco::internal::active_type<stce_9769, stce_10126>& stce_10465) {
    stce_10126& data = stce_10465.data();
    stce_10442++;
    data.tape_index = stce_10442;
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780 = double> struct gp1t {
  typedef stce_9780 value_t;
  typedef value_t scalar_value_t;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef typename internal::stce_10445<stce_9780> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef internal::stce_10436<gp1t> data_t;
  typedef internal::active_type<stce_9780, data_t> type;
  static const bool is_dco_type = true;
  static const bool is_intermediate_type = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
};
template <class stce_9780> DCOi_THREAD_LOCAL typename gp1t<stce_9780>::tape_t* gp1t<stce_9780>::global_tape = 0;
} // namespace dco

namespace dco {
namespace internal {
inline bool all(bool stce_10466) { return stce_10466; }
template <std::size_t stce_10031> inline bool all(std::bitset<stce_10031> const& stce_10466) {
  return stce_10466.all();
}
template <typename, typename, typename enable_if = void> struct stce_10467 {
  template <typename stce_9877, typename stce_10381>
  static typename std::common_type<typename dco::mode<stce_9877>::derivative_t, stce_10381>::type
  get(stce_9877&& stce_9807, stce_10381 const& pval) {
    return (HAS_GT1S_ACTIVITY_CHECK && all(stce_9807.stce_10468 == 0.0)) ? stce_9807.stce_10468
                                                                         : stce_9807.stce_10468 * pval;
  }
};
template <typename stce_10469, typename stce_10081>
struct stce_10467<
    stce_10469, stce_10081,
    typename std::enable_if<std::is_base_of<typename stce_10469::data_t,
                                            internal::stce_10319<typename stce_10469::data_t::mode_t>>::value>::type> {
  template <typename stce_9877, typename stce_10381>
  static typename stce_10081::derivative_t get(stce_9877&& stce_9807, stce_10381&& pval) {
    return (stce_9807.stce_10468 == 0) ? static_cast<typename stce_10081::derivative_t>(0.0)
                                       : stce_9807.stce_10468 * (pval == 0 ? pval + 1 : pval);
  }
};
template <typename stce_10081> struct stce_10470 {
  typedef stce_10081 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename mode_t::derivative_t derivative_t;
  mutable derivative_t stce_10468;
  stce_10470() : stce_10468(0.0) {}
  DCO_STRONG_INLINE stce_10470(const stce_10470& stce_10084) : stce_10468(stce_10084.stce_10468) {}
  stce_10470& operator=(const stce_10470& stce_10084) {
    stce_10468 = stce_10084.stce_10468;
    return *this;
  }
  void stce_10085(const derivative_t& stce_9753) { stce_10468 = stce_9753; }
  void stce_9960(derivative_t& stce_9753) const { stce_9753 = stce_10468; }
  void clear() { stce_10468 = 0.0; }
  derivative_t& stce_9967() const {
    stce_1000002();
    ;
    return stce_10468;
  }
  derivative_t& stce_9973() const { return stce_9967(); }
  template <class stce_9908> void stce_9909(const stce_9908& stce_10142) {
    stce_10468 = stce_10471(stce_10142, static_cast<derivative_t>(1.0));
  }
  template <class stce_9769, class stce_10126>
  static derivative_t stce_10471(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807,
                                 const derivative_t& pval) {
    return stce_10467<dco::mode<typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::value_t>,
                      stce_10081>::get(stce_9807, pval);
  }
  template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
  static derivative_t
  stce_10471(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
             const derivative_t& pval) {
    return stce_10471(stce_9807.stce_10132, stce_9807.stce_10133() * pval) +
           stce_10471(stce_9807.stce_10134, stce_9807.stce_10135() * pval);
  }
  template <class stce_9769, class stce_10136, class stce_10130>
  static derivative_t stce_10471(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807,
                                 const derivative_t& pval) {
    return stce_10471(stce_9807.stce_10137, stce_9807.pval() * pval);
  }
  template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
  static derivative_t
  stce_10471(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
             const derivative_t& pval) {
    return stce_10471(stce_9807.stce_10132, stce_9807.stce_10133() * pval);
  }
  template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
  static derivative_t
  stce_10471(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
             const derivative_t& pval) {
    return stce_10471(stce_9807.stce_10134, stce_9807.stce_10135() * pval);
  }
  typedef void tape_t;
  typedef index_t stce_10472;
  void* tape() const { return NULL; }
  index_t _tape_index() const { return 0; }
};
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, typename stce_10473 = stce_9780> class gt1s {
public:
  typedef gt1s mode_t;
  typedef dco::internal::stce_10470<gt1s> data_t;
  typedef stce_9780 value_t;
  typedef stce_9780 active_value_t;
  typedef stce_9780 scalar_value_t;
  typedef stce_10473 derivative_t;
  typedef stce_10473 stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<stce_9780, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = true;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef void tape_t;
  typedef void local_gradient_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_10081> struct stce_10474 {
  typedef stce_10081 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename mode_t::derivative_t derivative_t;
  typedef typename derivative_t::value_t stce_9983;

protected:
  typedef typename mode_t::value_t stce_9769;

public:
  static const int vecsize = derivative_t::stce_9841;
  mutable bool stce_10475;
  mutable derivative_t tlms;
  stce_10474() : stce_10475(false) {
    for (int stce_9845 = 0; stce_9845 < vecsize; ++stce_9845)
      tlms[stce_9845] = 0;
  }
  void stce_10085(const stce_9983& stce_9753, const int stce_10476) {
    if (!stce_10475) {
      stce_10475 = true;
    }
    tlms[stce_10476] = stce_9753;
  }
  derivative_t& stce_9967() const {
    stce_1000002();
    ;
    stce_10475 = true;
    return tlms;
  }
  derivative_t& stce_9973() const { return stce_9967(); }
  void stce_9960(stce_9983& stce_9753, const int stce_10476) const {
    stce_1000002();
    ;
    if (stce_10475) {
      stce_9753 = tlms[stce_10476];
    } else {
      stce_9753 = 0;
    }
  }
  void clear() {
    for (int stce_9845 = 0; stce_9845 < vecsize; ++stce_9845) {
      tlms[stce_9845] = 0.0;
    }
  }
  template <class stce_9908> DCO_ALWAYS_INLINE void stce_9909(const stce_9908& stce_10142) {
    bool stce_10477 = this->stce_10478(stce_10142);
    if (stce_10477) {
      derivative_t stce_10479{};
      stce_10471(stce_10479, stce_10142, 1.0);
      tlms = stce_10479;
      stce_10475 = true;
    } else {
      stce_10475 = false;
    }
  }
  template <class stce_10126>
  static DCO_ALWAYS_INLINE void stce_10471(derivative_t& tlms,
                                           const dco::internal::active_type<stce_9769, stce_10126>& stce_9807,
                                           const stce_9983& pval) {
    if (stce_9807.stce_10475) {
      tlms += stce_9807.tlms * pval;
    }
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static DCO_ALWAYS_INLINE void
  stce_10471(derivative_t& tlms,
             const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
             const stce_9983& pval) {
    stce_10471(tlms, stce_9807.stce_10132, stce_9807.stce_10133() * pval);
    stce_10471(tlms, stce_9807.stce_10134, stce_9807.stce_10135() * pval);
  }
  template <class stce_10136, class stce_10130>
  static DCO_ALWAYS_INLINE void stce_10471(derivative_t& tlms,
                                           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807,
                                           const stce_9983& pval) {
    stce_10471(tlms, stce_9807.stce_10137, stce_9807.pval() * pval);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static DCO_ALWAYS_INLINE void
  stce_10471(derivative_t& tlms,
             const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
             const stce_9983& pval) {
    stce_10471(tlms, stce_9807.stce_10132, stce_9807.stce_10133() * pval);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static DCO_ALWAYS_INLINE void
  stce_10471(derivative_t& tlms,
             const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807,
             const stce_9983& pval) {
    stce_10471(tlms, stce_9807.stce_10134, stce_9807.stce_10135() * pval);
  }
  template <class stce_10126>
  static bool stce_10478(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
    return stce_9807.stce_10475;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static bool stce_10478(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    return stce_10478(stce_9807.stce_10132) || stce_10478(stce_9807.stce_10134);
  }
  template <class stce_10136, class stce_10130>
  static bool stce_10478(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    return stce_10478(stce_9807.stce_10137);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static bool stce_10478(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    return stce_10478(stce_9807.stce_10132);
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  static bool stce_10478(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    return stce_10478(stce_9807.stce_10134);
  }
  typedef void stce_10480;
  typedef void tape_t;
  typedef index_t stce_10472;
  void* tape() const { return NULL; }
  index_t _tape_index() const { return 0; }
};
} // namespace internal
} // namespace dco
namespace dco {
template <class stce_9780, size_t stce_10481 = 1, typename stce_10473 = stce_9780> class gt1v {
public:
  typedef gt1v mode_t;
  typedef dco::internal::stce_10474<gt1v> data_t;
  typedef stce_9780 value_t;
  typedef stce_9780 active_value_t;
  typedef value_t scalar_value_t;
  typedef dco::helper::valvec<stce_10473, stce_10481> derivative_t;
  typedef stce_10473 stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<stce_9780, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = false;
  static const bool is_tangent_type = true;
  static const bool stce_10145 = true;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef void tape_t;
  typedef void local_gradient_t;
  typedef void external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<void> jacobian_preaccumulator_t;
};
} // namespace dco

namespace dco {
namespace internal {
template <typename stce_10081> class stce_10482 : public stce_10470<stce_10081>, public stce_10139<stce_10081> {
  using stce_10483 = stce_10470<stce_10081>;
  using stce_10484 = stce_10139<stce_10081>;

public:
  typedef stce_10081 mode_t;
  typedef stce_10087 stce_10141;
  typedef typename stce_10081::tape_t tape_t;
  typedef typename tape_t::stce_9762 derivative_t;

public:
  stce_10482() : stce_10483(), stce_10484() {}
  DCO_STRONG_INLINE stce_10482(const stce_10482& stce_10084) : stce_10483(stce_10084), stce_10484(stce_10084) {}
  DCO_STRONG_INLINE stce_10482& operator=(const stce_10482& stce_9807) {
    stce_10483::operator=(static_cast<const stce_10483&>(stce_9807));
    stce_10484::operator=(static_cast<const stce_10484&>(stce_9807));
    return *this;
  }
  inline void clear() {
    stce_10483::clear();
    stce_10484::clear();
  }
  inline index_t& _tape_index() const { return stce_10484::_tape_index(); }
  template <typename stce_10086>
  static DCO_STRONG_INLINE void register_variable(stce_10086& stce_9807, index_t index, tape_t* tape) {
    stce_10484::register_variable(stce_9807, index, tape);
  }
  template <class stce_9908> DCO_ALWAYS_INLINE void stce_9909(const stce_9908& stce_10142) {
    stce_10483::stce_9909(stce_10142);
    stce_10484::stce_9909(stce_10142);
  }
};
} // namespace internal
} // namespace dco
namespace dco {
template <typename stce_9780, typename stce_9759 = stce_9780, typename stce_9760 = stce_9759,
          memory_model::TYPE MEMORY_MODEL = DCO_TAPE_MEMORY_MODEL>
class gtas {
  typedef types_config_t<stce_9780, stce_9759, stce_9760> stce_10144;

public:
  static const memory_model::TYPE TAPE_MODEL = MEMORY_MODEL;
  typedef gtas mode_t;
  typedef dco::internal::stce_10482<gtas> data_t;
  typedef typename stce_10144::value_t value_t;
  typedef value_t scalar_value_t;
  typedef typename stce_10144::value_t active_value_t;
  typedef typename stce_10144::stce_9762 derivative_t;
  typedef derivative_t stce_9983;
  typedef typename mode<value_t>::passive_t passive_t;
  typedef typename mode<value_t>::scalar_passive_t scalar_passive_t;
  typedef dco::internal::active_type<value_t, data_t> type;
  typedef type active_t;
  static const bool is_dco_type = true;
  static const bool is_adjoint_type = true;
  static const bool is_tangent_type = true;
  static const bool stce_10145 = false;
  static const int order = dco::mode<stce_9780>::order + 1;
  static const size_t p1f_size = 0;
  typedef internal::tape<TAPE_MODEL, stce_10144> tape_t;
  static DCOi_THREAD_LOCAL tape_t* global_tape;
  typedef typename internal::stce_10075<type> local_gradient_t;
  typedef dco::helper::stce_10012<tape_t> callback_object_t;
  typedef dco::helper::stce_10018<type, tape_t> userdata_object_t;
  typedef dco::helper::stce_10036<type, tape_t> external_adjoint_object_t;
  typedef internal::jacobian_preaccumulator_t<type> jacobian_preaccumulator_t;
};
template <class stce_9780, class stce_9759, class stce_9760, memory_model::TYPE MEMORY_MODEL>
DCOi_THREAD_LOCAL typename gtas<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::tape_t*
    gtas<stce_9780, stce_9759, stce_9760, MEMORY_MODEL>::global_tape = 0;
} // namespace dco

namespace dco {
template <size_t stce_10485> struct subrange_t {
  static const size_t stce_10486 = stce_10485;
  subrange_t(size_t stce_10031) : stce_10030(stce_10031) {}
  size_t stce_10030;
};
template <size_t stce_10485> struct range_t {
  subrange_t<stce_10485> const& stce_10487;
  size_t global_index, stce_10181;
  range_t(subrange_t<stce_10485> const& stce_10394) : stce_10487(stce_10394), global_index(0), stce_10181(0) {}
  range_t& operator++() {
    global_index += stce_10487.stce_10486;
    ++stce_10181;
    return *this;
  }
  bool operator!=(range_t const& stce_10002) const {
    if (stce_10002.stce_10181 != stce_10181)
      return true;
    return false;
  }
  range_t& operator*() { return *this; }
  range_t const& operator*() const { return *this; }
  void stce_10210() {
    global_index = stce_10487.stce_10030;
    stce_10181 = static_cast<size_t>(std::ceil(static_cast<double>(stce_10487.stce_10030) / stce_10485));
  }
  bool is_last() const { return global_index + stce_10485 >= stce_10487.stce_10030; }
};
template <size_t stce_10485> struct inner_range_t {
  range_t<stce_10485> const& stce_10488;
  size_t global_index, sub_index;
  inner_range_t(range_t<stce_10485> const& stce_9850)
      : stce_10488(stce_9850), global_index(stce_9850.global_index), sub_index(0) {}
  inner_range_t& operator++() {
    ++sub_index;
    ++global_index;
    return *this;
  }
  void stce_10210() {
    if ((stce_10488.stce_10181 + 1) * stce_10488.stce_10487.stce_10486 > stce_10488.stce_10487.stce_10030) {
      sub_index = stce_10488.stce_10487.stce_10030 % stce_10488.stce_10487.stce_10486;
    } else {
      sub_index = stce_10488.stce_10487.stce_10486;
    }
  }
  bool operator!=(inner_range_t const& stce_10002) const {
    if (stce_10002.sub_index != sub_index)
      return true;
    return false;
  }
  inner_range_t& operator*() { return *this; }
  inner_range_t const& operator*() const { return *this; }
};
template <size_t stce_10485> static inner_range_t<stce_10485> begin(range_t<stce_10485> const& stce_9850) {
  return inner_range_t<stce_10485>(stce_9850);
}
template <size_t stce_10485> static range_t<stce_10485> begin(subrange_t<stce_10485> const& stce_10394) {
  return range_t<stce_10485>(stce_10394);
}
template <size_t stce_10485> static inner_range_t<stce_10485> end(range_t<stce_10485> const& stce_9850) {
  inner_range_t<stce_10485> stce_10489(stce_9850);
  stce_10489.stce_10210();
  return stce_10489;
}
template <size_t stce_10485> static range_t<stce_10485> end(subrange_t<stce_10485> const& stce_10394) {
  range_t<stce_10485> stce_10489(stce_10394);
  stce_10489.stce_10210();
  return stce_10489;
}
template <size_t stce_10485> static subrange_t<stce_10485> subranges(size_t stce_10031) {
  return subrange_t<stce_10485>(stce_10031);
}
} // namespace dco
namespace dco {
namespace stce_10490 {
template <class stce_9769> struct stce_10491 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 + stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10493 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 - stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(-1.0));
  }
};
template <class stce_9769> struct stce_10494 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 * stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10162);
  }
};
template <class stce_9769> struct stce_10495 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return static_cast<stce_9769>(stce_10162 / stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(-_value / stce_10163);
  }
};
template <class stce_9769> struct stce_10496 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 + stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10497 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 + stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10498 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 - stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0));
  }
};
template <class stce_9769> struct stce_10499 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 - stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(-1.0));
  }
};
template <class stce_9769> struct stce_10500 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 * stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10163);
  }
};
template <class stce_9769> struct stce_10501 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 * stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(stce_10162);
  }
};
template <class stce_9769> struct stce_10502 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 / stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / stce_10163);
  }
};
template <class stce_9769> struct stce_10503 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    return stce_10162 / stce_10163;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(const stce_9769& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return static_cast<stce_9769>(-(stce_10162 / stce_10163) / stce_10163);
  }
};
template <class stce_9769> struct stce_10504 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::sin;
    return sin(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::cos;
    (void)_value;
    return static_cast<stce_9769>(cos(stce_9807));
  }
};
template <class stce_9769> struct stce_10505 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::cos;
    return cos(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::sin;
    (void)_value;
    return static_cast<stce_9769>(-sin(stce_9807));
  }
};
template <class stce_9769> struct stce_10506 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::tan;
    return tan(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::tan;
    (void)_value;
    return static_cast<stce_9769>((static_cast<stce_9769>(1.0) + (tan(stce_9807) * tan(stce_9807))));
  }
};
template <class stce_9769> struct stce_10507 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::cosh;
    return cosh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::sinh;
    (void)_value;
    return static_cast<stce_9769>(sinh(stce_9807));
  }
};
template <class stce_9769> struct stce_10508 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::sinh;
    return sinh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::cosh;
    (void)_value;
    return static_cast<stce_9769>(cosh(stce_9807));
  }
};
template <class stce_9769> struct stce_10509 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::tanh;
    return tanh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::tanh;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) - tanh(stce_9807) * tanh(stce_9807));
  }
};
template <class stce_9769> struct stce_10510 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::asin;
    return asin(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) /
                                  sqrt(static_cast<stce_9769>(1.0) - stce_9807 * stce_9807));
  }
};
template <class stce_9769> struct stce_10511 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::acos;
    return acos(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(-1.0) /
                                  sqrt(static_cast<stce_9769>(1.0) - stce_9807 * stce_9807));
  }
};
template <class stce_9769> struct stce_10512 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::atan;
    return atan(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::atan;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / (static_cast<stce_9769>(1.0) + stce_9807 * stce_9807));
  }
};
template <class stce_9769> struct stce_10513 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::exp;
    return exp(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::exp;
    (void)_value;
    return static_cast<stce_9769>(exp(stce_9807));
  }
};
template <class stce_9769> struct stce_10514 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::sqrt;
    return sqrt(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::sqrt;
    (void)_value;
    return static_cast<stce_9769>(
        static_cast<stce_9769>(1.0) /
        (static_cast<stce_9769>(2.0) *
         sqrt(stce_9807 + ((HAS_SQRT_AVOID_DIVZERO && stce_9807 == static_cast<stce_9769>(0.0))
                               ? static_cast<stce_9769>(DCO_SQRT_EPS)
                               : static_cast<stce_9769>(0.0)))));
  }
};
template <class stce_9769> struct stce_10515 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using std::log;
    return log(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using std::log;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / stce_9807);
  }
};
template <class stce_9769> struct stce_10516 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::erf;
    return erf(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::exp;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(2.0) /
                                  sqrt(static_cast<stce_9769>(3.14159265358979323846264338327950288)) *
                                  exp(-stce_9807 * stce_9807));
  }
};
template <class stce_9769> struct stce_10517 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::erfc;
    return erfc(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::exp;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(-2.0) /
                                  sqrt(static_cast<stce_9769>(3.14159265358979323846264338327950288)) *
                                  exp(-stce_9807 * stce_9807));
  }
};
template <class stce_9769> struct stce_10518 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::asinh;
    return asinh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.) /
                                  sqrt(static_cast<stce_9769>(1.) + (stce_9807 * stce_9807)));
  }
};
template <class stce_9769> struct stce_10519 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::acosh;
    return acosh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::sqrt;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.) /
                                  sqrt((stce_9807 * stce_9807) - static_cast<stce_9769>(1.)));
  }
};
template <class stce_9769> struct stce_10520 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::atanh;
    return atanh(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::atanh;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.) / (static_cast<stce_9769>(1.) - (stce_9807 * stce_9807)));
  }
};
template <class stce_9769> struct stce_10521 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::expm1;
    return expm1(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::exp;
    (void)_value;
    return static_cast<stce_9769>(exp(stce_9807));
  }
};
template <class stce_9769> struct stce_10522 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::log1p;
    return log1p(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::log1p;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / (stce_9807 + static_cast<stce_9769>(1.0)));
  }
};
template <class stce_9769> struct stce_10523 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& arg) {
    using ::log10;
    return log10(arg);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_9807) {
    using ::log10;
    (void)_value;
    return static_cast<stce_9769>(static_cast<stce_9769>(1.0) / (stce_9807 * static_cast<stce_9769>(log(10))));
  }
};
template <class stce_9769> struct stce_10524 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return -stce_10162;
  }
  template <class stce_9780> static inline const stce_9769 stce_10161(const stce_9769&, const stce_9780&) {
    return static_cast<stce_9769>(-1.0);
  }
};
template <class stce_9769> struct stce_10525 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return stce_10162;
  }
  template <class stce_9780> static inline const stce_9769 stce_10161(const stce_9769&, const stce_9780&) {
    return static_cast<stce_9769>(1.0);
  }
};
using ::fabs;
template <class stce_9769> struct stce_10526 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return fabs(stce_10162);
  }
  template <class stce_9780> static inline const stce_9769 stce_10161(const stce_9769&, const stce_9780& stce_10162) {
    if (stce_10162 < 0)
      return static_cast<stce_9769>(-1.0);
    else
      return static_cast<stce_9769>(1.0);
  }
};
using std::abs;
template <class stce_9769> struct stce_10527 {
  template <class stce_9780> static inline const stce_9769 stce_10160(const stce_9780& stce_10162) {
    return abs(stce_10162);
  }
  template <class stce_9780>
  static inline const stce_9769 stce_10161(const stce_9769& _value, const stce_9780& stce_10162) {
    (void)_value;
    if (stce_10162 < 0)
      return static_cast<stce_9769>(-1.0);
    else
      return static_cast<stce_9769>(1.0);
  }
};
using std::atan2;
template <class stce_9769> struct stce_10528 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return atan2(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return -stce_10162 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
};
template <class stce_9769> struct stce_10529 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return atan2(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
};
template <class stce_9769> struct stce_10530 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return atan2(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return -stce_10162 / (stce_10163 * stce_10163 + stce_10162 * stce_10162);
  }
};
template <class stce_9769> struct stce_10531 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    using std::pow;
    return pow(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    using std::pow;
    (void)_value;
    return stce_10163 * pow(stce_10162, stce_10163 - static_cast<stce_9769>(1.0));
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10492& stce_10162, const stce_10156&) {
    using std::log;
    using std::pow;
    return log(stce_10162) * _value;
  }
};
template <class stce_9769> struct stce_10532 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    using std::pow;
    return pow(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    using std::pow;
    (void)_value;
    return stce_10163 * pow(stce_10162, stce_10163 - static_cast<stce_10156>(1.0));
  }
};
template <class stce_9769> struct stce_10533 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    using std::pow;
    return pow(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10492& stce_10162, const stce_10156&) {
    using std::log;
    using std::pow;
    return log(stce_10162) * _value;
  }
};
template <typename stce_9805, size_t stce_9806, typename stce_10534> struct stce_10535 {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9805, stce_9806>
  stce_10161(const vector_ns::vector_t<stce_9805, stce_9806>& _value, const stce_9780& stce_9807) {
    vector_ns::vector_t<stce_9805, stce_9806> stce_9847;
    for (size_t stce_9845 = 0; stce_9845 < stce_9806; ++stce_9845) {
      stce_9847[stce_9845] = stce_10534::stce_10161(_value[stce_9845], stce_9807[stce_9845]);
    }
    return stce_9847;
  }
};
template <typename stce_9805, size_t stce_9806>
struct stce_10527<vector_ns::vector_t<stce_9805, stce_9806>>
    : public stce_10535<stce_9805, stce_9806, stce_10527<stce_9805>> {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9805, stce_9806> stce_10160(const stce_9780& stce_10162) {
    return abs(stce_10162);
  }
};
template <typename stce_9805, size_t stce_9806>
struct stce_10526<vector_ns::vector_t<stce_9805, stce_9806>>
    : public stce_10535<stce_9805, stce_9806, stce_10526<stce_9805>> {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9805, stce_9806> stce_10160(const stce_9780& stce_10162) {
    return fabs(stce_10162);
  }
};
template <typename stce_9805, size_t stce_9806>
struct stce_10514<vector_ns::vector_t<stce_9805, stce_9806>>
    : public stce_10535<stce_9805, stce_9806, stce_10514<stce_9805>> {
  template <class stce_9780>
  static inline const vector_ns::vector_t<stce_9805, stce_9806> stce_10160(const stce_9780& arg) {
    return sqrt(arg);
  }
};
using ::hypot;
template <class stce_9769> struct stce_10536 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return hypot(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10162 / _value;
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / _value;
  }
};
template <class stce_9769> struct stce_10537 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return hypot(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10164(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10162 / _value;
  }
};
template <class stce_9769> struct stce_10538 {
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10160(const stce_10492& stce_10162, const stce_10156& stce_10163) {
    (void)stce_10162;
    (void)stce_10163;
    return hypot(stce_10162, stce_10163);
  }
  template <class stce_10492, class stce_10156>
  static inline const stce_9769 stce_10165(stce_9769 const& _value, const stce_10492& stce_10162,
                                           const stce_10156& stce_10163) {
    (void)_value;
    (void)stce_10162;
    (void)stce_10163;
    return stce_10163 / _value;
  }
};
} // namespace stce_10490
} // namespace dco
namespace dco {
namespace internal {
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10524<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10524<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10524<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10524<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10524<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10525<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10525<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10525<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10525<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10525<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
sin(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sin(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sin(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sin(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
sin(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10504<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
cos(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
cos(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
cos(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
cos(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
cos(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10505<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
tan(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
tan(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
tan(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
tan(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
tan(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10506<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
cosh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
cosh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
cosh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
cosh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
cosh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10507<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
sinh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sinh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sinh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sinh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
sinh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10508<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
asin(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
asin(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
asin(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
asin(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
asin(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10510<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
acos(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
acos(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
acos(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
acos(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
acos(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10511<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
exp(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
exp(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
exp(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
exp(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
exp(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10513<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10512<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
tanh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
tanh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
tanh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
tanh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
tanh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10509<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
sqrt(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sqrt(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sqrt(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
sqrt(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
sqrt(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10514<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
log(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
log(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10515<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
erf(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
erf(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
erf(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
erf(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
erf(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10516<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
erfc(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
erfc(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
erfc(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
erfc(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
erfc(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10517<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
expm1(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10521<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
expm1(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10521<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
expm1(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10521<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
expm1(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10521<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
expm1(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10521<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
asinh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
asinh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
asinh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
asinh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
asinh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10518<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
acosh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
acosh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
acosh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
acosh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
acosh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10519<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atanh(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atanh(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atanh(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atanh(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atanh(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10520<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
log1p(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10522<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log1p(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10522<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log1p(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10522<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log1p(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10522<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
log1p(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10522<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
log10(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10523<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log10(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10523<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log10(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10523<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
log10(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10523<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
log10(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10523<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
fabs(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10526<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
fabs(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10526<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
fabs(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10526<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
fabs(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10526<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
fabs(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10526<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
abs(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10527<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
abs(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10527<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
abs(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10527<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
abs(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::stce_10490::stce_10527<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
abs(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091) {
  return dco::internal::stce_9774<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::stce_10490::stce_10527<stce_9769>>(stce_10091);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10491<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator+(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator+(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10497<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator+(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10490::stce_10497<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator+(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator+(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator+(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator+(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator+(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator+(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator+(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator+(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10496<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator+(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator+(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10497<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t, typename dco::mode<stce_9877>::active_t,
                             stce_9877,
                             dco::stce_10490::stce_10491<typename dco::mode<stce_9877>::active_value_t>>>::type
operator+(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t,
                                  typename dco::mode<stce_9877>::active_t, stce_9877,
                                  dco::stce_10490::stce_10491<typename dco::mode<stce_9877>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10490::stce_10491<typename dco::mode<stce_9780>::active_value_t>>>::type
operator+(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10490::stce_10491<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10493<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator-(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator-(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10499<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator-(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10490::stce_10499<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator-(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator-(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator-(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator-(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator-(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator-(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator-(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator-(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10498<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator-(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator-(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10499<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t, typename dco::mode<stce_9877>::active_t,
                             stce_9877,
                             dco::stce_10490::stce_10493<typename dco::mode<stce_9877>::active_value_t>>>::type
operator-(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t,
                                  typename dco::mode<stce_9877>::active_t, stce_9877,
                                  dco::stce_10490::stce_10493<typename dco::mode<stce_9877>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10490::stce_10493<typename dco::mode<stce_9780>::active_value_t>>>::type
operator-(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10490::stce_10493<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10494<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator*(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator*(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10501<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator*(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10490::stce_10501<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator*(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator*(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator*(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator*(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator*(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator*(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator*(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator*(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator*(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10500<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator*(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator*(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10501<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t, typename dco::mode<stce_9877>::active_t,
                             stce_9877,
                             dco::stce_10490::stce_10494<typename dco::mode<stce_9877>::active_value_t>>>::type
operator*(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t,
                                  typename dco::mode<stce_9877>::active_t, stce_9877,
                                  dco::stce_10490::stce_10494<typename dco::mode<stce_9877>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10490::stce_10494<typename dco::mode<stce_9780>::active_value_t>>>::type
operator*(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10490::stce_10494<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10495<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator/(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
operator/(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10503<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
operator/(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10490::stce_10503<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator/(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator/(
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
operator/(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
operator/(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator/(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator/(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator/(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator/(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator/(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10502<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
operator/(
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
operator/(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10503<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t, typename dco::mode<stce_9877>::active_t,
                             stce_9877,
                             dco::stce_10490::stce_10495<typename dco::mode<stce_9877>::active_value_t>>>::type
operator/(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t,
                                  typename dco::mode<stce_9877>::active_t, stce_9877,
                                  dco::stce_10490::stce_10495<typename dco::mode<stce_9877>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10490::stce_10495<typename dco::mode<stce_9780>::active_value_t>>>::type
operator/(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10490::stce_10495<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10528<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
atan2(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
atan2(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10530<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
atan2(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10490::stce_10530<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
atan2(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
atan2(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
atan2(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
atan2(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
atan2(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
atan2(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
atan2(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
atan2(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10529<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
atan2(const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
atan2(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10530<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t, typename dco::mode<stce_9877>::active_t,
                             stce_9877,
                             dco::stce_10490::stce_10528<typename dco::mode<stce_9877>::active_value_t>>>::type
atan2(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t,
                                  typename dco::mode<stce_9877>::active_t, stce_9877,
                                  dco::stce_10490::stce_10528<typename dco::mode<stce_9877>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10490::stce_10528<typename dco::mode<stce_9780>::active_value_t>>>::type
atan2(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10490::stce_10528<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10531<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
pow(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
    const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
pow(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10533<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
pow(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
    const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10490::stce_10533<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
pow(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
pow(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
pow(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
    const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
pow(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
pow(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10091,
    const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
pow(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
pow(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10091,
    const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
pow(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
    const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10532<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
pow(const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
pow(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
        stce_10091,
    const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10533<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t, typename dco::mode<stce_9877>::active_t,
                             stce_9877,
                             dco::stce_10490::stce_10531<typename dco::mode<stce_9877>::active_value_t>>>::type
pow(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t,
                                  typename dco::mode<stce_9877>::active_t, stce_9877,
                                  dco::stce_10490::stce_10531<typename dco::mode<stce_9877>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10490::stce_10531<typename dco::mode<stce_9780>::active_value_t>>>::type
pow(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10490::stce_10531<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10543>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::active_type<stce_9769, stce_10543>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
                                  dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>,
                                  dco::stce_10490::stce_10536<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
hypot(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
      const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::active_type<stce_9769, stce_10126>,
                                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
                                  dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>
hypot(const typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                                  dco::internal::active_type<stce_9769, stce_10126>,
                                  dco::stce_10490::stce_10538<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::active_type<stce_9769, stce_10126>::VALUE_TYPE,
                  typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t>::value,
    dco::internal::active_type<stce_9769, typename dco::internal::active_type<stce_9769, stce_10126>::data_t>>::type
hypot(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
      const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t,
      dco::internal::active_type<stce_9769, stce_10126>, dco::stce_10490::stce_10538<stce_9769>>(stce_10091,
                                                                                                 stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
                                  typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                                  dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
hypot(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>,
      typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
dco::internal::active_type<stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>
hypot(const typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
typename dco::enable_if<
    !dco::is_same<typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::VALUE_TYPE,
                  typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t>::value,
    dco::internal::active_type<stce_9769,
                               typename dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t>>::type
hypot(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
      const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t,
      dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(stce_10091,
                                                                                                           stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
hypot(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
hypot(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
hypot(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
hypot(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
hypot(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
      const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10092) {
  return dco::internal::stce_9778<
      stce_9769, dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>,
      typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::stce_10490::stce_10537<stce_9769>>(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
dco::internal::active_type<stce_9769,
                           typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>
hypot(const typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE& stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
typename dco::enable_if<
    !dco::is_same<
        typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::VALUE_TYPE,
        typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t>::value,
    dco::internal::active_type<
        stce_9769, typename dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t>>::type
hypot(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
          stce_10091,
      const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<
      stce_9769, typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t,
      dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>, dco::stce_10490::stce_10538<stce_9769>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t, typename dco::mode<stce_9877>::active_t,
                             stce_9877,
                             dco::stce_10490::stce_10536<typename dco::mode<stce_9877>::active_value_t>>>::type
hypot(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9877>::active_value_t,
                                  typename dco::mode<stce_9877>::active_t, stce_9877,
                                  dco::stce_10490::stce_10536<typename dco::mode<stce_9877>::active_value_t>>(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                             typename dco::mode<stce_9780>::active_t,
                             dco::stce_10490::stce_10536<typename dco::mode<stce_9780>::active_value_t>>>::type
hypot(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::internal::stce_9777<typename dco::mode<stce_9780>::active_value_t, stce_9780,
                                  typename dco::mode<stce_9780>::active_t,
                                  dco::stce_10490::stce_10536<typename dco::mode<stce_9780>::active_value_t>>(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10090(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10090(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10093(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10093(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator==(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10094(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10094(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10093(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10094(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator==(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10093(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10094(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10093(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10094(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10093(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator==(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10094(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    bool>::type
operator==(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9877>::active_t::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator==(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10090(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10095(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10095(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10096(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10096(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator!=(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10097(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10097(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10096(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10097(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator!=(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10096(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10097(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10096(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10097(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10096(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator!=(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10097(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    bool>::type
operator!=(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9877>::active_t::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator!=(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10095(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10098(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10098(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10099(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10099(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10100(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10100(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10099(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10100(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10099(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10100(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10099(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10100(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10099(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<(const stce_9780& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10100(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    bool>::type
operator<(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9877>::active_t::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator<(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10098(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10101(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10101(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10102(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10102(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator<=(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10103(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10103(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10102(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10103(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator<=(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10102(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10103(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10102(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10103(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10102(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator<=(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10103(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    bool>::type
operator<=(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9877>::active_t::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator<=(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10101(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10104(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                             const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10104(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
          const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10105(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10105(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
          const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10106(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10106(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10105(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
          const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10106(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
              stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10105(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10106(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10105(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10106(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091,
          const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091,
          const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
          const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10105(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>(const stce_9780& stce_10091,
          const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10106(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    bool>::type
operator>(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9877>::active_t::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator>(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10104(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10539, class stce_10540>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10543>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, class stce_10541, class stce_10542, class stce_10540>
static inline auto operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10107(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10543>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::active_type<stce_9769, stce_10543>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10539, class stce_10540>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9774<stce_9769, stce_10539, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9777<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9778<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, class stce_10541, class stce_10542,
          class stce_10540>
static inline auto operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
                              const dco::internal::stce_9779<stce_9769, stce_10541, stce_10542, stce_10540>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10107(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091,
           const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10108(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10108(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline auto
operator>=(const typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t& stce_10091,
           const dco::internal::active_type<stce_9769, stce_10126>& stce_10092)
    -> decltype(dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10109(stce_10091,
                                                                                                  stce_10092)) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10109(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10108(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t& stce_10091,
           const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10109(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline auto
operator>=(const typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t&
               stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092)
    -> decltype(dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
        stce_10091, stce_10092)) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::active_type<stce_9769, stce_10126>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10108(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091, const dco::internal::active_type<stce_9769, stce_10126>& stce_10092) {
  return dco::internal::active_type<stce_9769, stce_10126>::data_t::stce_10141::stce_10109(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10091, const stce_9780& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10108(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10136, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091, const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_10092) {
  return dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>::data_t::stce_10141::stce_10109(stce_10091,
                                                                                                     stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10091,
           const stce_9780& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10108(
      stce_10091, stce_10092);
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130, typename stce_9780>
static inline typename dco::dco_type_constructable_from<stce_9780, bool>::type
operator>=(const stce_9780& stce_10091,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_10092) {
  return dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>::data_t::stce_10141::stce_10109(
      stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9877>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9780>::value ||
      (dco::mode<stce_9780>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9780::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9780>::active_t, typename dco::mode<stce_9877>::active_t>::value),
    bool>::type
operator>=(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9877>::active_t::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <typename stce_9780, typename stce_9877>
static inline typename enable_if<
    (dco::mode<stce_9780>::order > 0 &&
     (dco::internal::is_gbcp_type<stce_9877>::value ||
      (dco::mode<stce_9877>::is_intermediate_type && dco::internal::is_gbcp_type<typename stce_9877::data_t>::value)) &&
     dco::is_same<typename dco::mode<stce_9877>::active_t, typename dco::mode<stce_9780>::active_t>::value),
    bool>::type
operator>=(const stce_9780& stce_10091, const stce_9877& stce_10092) {
  return dco::mode<stce_9780>::active_t::data_t::stce_10141::stce_10107(stce_10091, stce_10092);
}
template <class stce_9769, class stce_10126>
static inline void stce_10544(dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  double stce_10028 = 0;
  get(stce_9807, stce_10028);
  stce_9807 = stce_10028;
}
template <class stce_9769, class stce_10126>
static inline std::istream& operator>>(std::istream& in, dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  stce_9769& stce_10028 = stce_9807._value();
  in >> stce_10028;
  return in;
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10126>
static inline bool isnan(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return isnan(stce_9807._value());
}
template <class stce_9769, class stce_10126>
static inline bool isnormal(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return isnormal(stce_9807._value());
}
template <class stce_9769, class stce_10126>
static inline bool isinf(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return isinf(stce_9807._value());
}
template <class stce_9769, class stce_10126>
static inline double ceil(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return ceil(stce_9807._value());
}
template <class stce_9769, class stce_10126>
static inline double floor(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return floor(stce_9807._value());
}
template <class stce_9769, class stce_10126>
static inline bool isfinite(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return isfinite(stce_9807._value());
}
template <class stce_9769, class stce_10126>
static inline typename dco::mode<dco::internal::active_type<stce_9769, stce_10126>>::passive_t
round(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return round(dco::passive_value(stce_9807));
}
template <class stce_9769, class stce_10126>
static inline long int lround(const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  return lround(dco::passive_value(stce_9807));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnan(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isnan(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isnormal(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isinf(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isinf(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double ceil(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return ceil(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double floor(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return floor(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isfinite(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t
round(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return round(dco::passive_value(stce_9807));
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline long int
lround(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return lround(dco::passive_value(stce_9807));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnan(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isnan(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isnormal(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isinf(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isinf(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double ceil(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return ceil(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double floor(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return floor(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isfinite(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t
round(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return round(dco::passive_value(stce_9807));
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline long int
lround(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return lround(dco::passive_value(stce_9807));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnan(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isnan(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isnormal(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isinf(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isinf(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double ceil(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return ceil(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline double floor(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return floor(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return isfinite(stce_9807._value());
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::passive_t
round(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return round(dco::passive_value(stce_9807));
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline long int
lround(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  return lround(dco::passive_value(stce_9807));
}
using std::ceil;
using std::floor;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::lround;
using std::round;
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isnan(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return isnan(stce_9807._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isnormal(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return isnormal(stce_9807._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isinf(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return isinf(stce_9807._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline double ceil(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return ceil(stce_9807._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline double floor(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return floor(stce_9807._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline bool isfinite(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return isfinite(stce_9807._value());
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::passive_t
round(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return round(dco::passive_value(stce_9807));
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline long int lround(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  return lround(dco::passive_value(stce_9807));
}
template <class stce_9769, class stce_10126>
static inline std::ostream& operator<<(std::ostream& out,
                                       const dco::internal::active_type<stce_9769, stce_10126>& stce_9807) {
  out << stce_9807._value();
  return out;
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline std::ostream&
operator<<(std::ostream& out,
           const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  out << stce_9807._value();
  return out;
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline std::ostream&
operator<<(std::ostream& out,
           const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  out << stce_9807._value();
  return out;
}
template <class stce_9769, class stce_10128, class stce_10129, class stce_10130>
static inline std::ostream&
operator<<(std::ostream& out,
           const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
  out << stce_9807._value();
  return out;
}
template <class stce_9769, class stce_10136, class stce_10130>
static inline std::ostream& operator<<(std::ostream& out,
                                       const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
  out << stce_9807._value();
  return out;
}
template <typename stce_9780, typename stce_9877,
          typename stce_10545 = decltype(passive_value(std::declval<stce_9780>()) <
                                         passive_value(std::declval<stce_9877>()))>
typename enable_if<mode<stce_9780>::is_dco_type || mode<stce_9877>::is_dco_type,
                   typename stce_9876<(mode<stce_9780>::order > mode<stce_9877>::order), typename mode<stce_9780>::type,
                                      typename mode<stce_9877>::type>::type>::type
min(stce_9780 const& stce_10014, stce_9877 const& stce_10546) {
  if (passive_value(stce_10014) < passive_value(stce_10546))
    return stce_10014;
  else
    return stce_10546;
}
template <typename stce_9780, typename stce_9877,
          typename stce_10545 = decltype(passive_value(std::declval<stce_9780>()) >
                                         passive_value(std::declval<stce_9877>()))>
typename enable_if<mode<stce_9780>::is_dco_type || mode<stce_9877>::is_dco_type,
                   typename stce_9876<(mode<stce_9780>::order > mode<stce_9877>::order), typename mode<stce_9780>::type,
                                      typename mode<stce_9877>::type>::type>::type
max(stce_9780 const& stce_10014, stce_9877 const& stce_10546) {
  if (passive_value(stce_10014) > passive_value(stce_10546))
    return stce_10014;
  else
    return stce_10546;
}
} // namespace internal
} // namespace dco

namespace dco {
namespace helper {
template <typename stce_9780> class complex_t {
private:
  stce_9780 stce_10547;
  stce_9780 stce_10548;

public:
  DCO_STRONG_INLINE complex_t(stce_9780 const& real = 0.0, stce_9780 const& imag = 0.0)
      : stce_10547(real), stce_10548(imag) {}
  template <typename stce_9877> complex_t(std::complex<stce_9877> const& stce_10549) {
    stce_10547 = stce_10549.real();
    stce_10548 = stce_10549.imag();
  }
  template <typename stce_9877> complex_t& operator=(stce_9877 const& stce_9905) {
    stce_10547 = stce_9905;
    stce_10548 = stce_9780();
    return *this;
  }
  template <typename stce_9877> complex_t& operator=(std::complex<stce_9877> const& stce_9905) {
    stce_10547 = stce_9905.real();
    stce_10548 = stce_9905.imag();
    return *this;
  }
  DCO_STRONG_INLINE stce_9780 real() const { return stce_10547; }
  DCO_STRONG_INLINE stce_9780 imag() const { return stce_10548; }
  DCO_STRONG_INLINE stce_9780& real() { return stce_10547; }
  DCO_STRONG_INLINE stce_9780& imag() { return stce_10548; }
  DCO_STRONG_INLINE void real(stce_9780 const& real) { stce_10547 = real; }
  DCO_STRONG_INLINE void imag(stce_9780 const& imag) { stce_10548 = imag; }
};
} // namespace helper
} // namespace dco
namespace std {
template <class stce_9769, typename stce_10550>
class complex<dco::internal::active_type<stce_9769, stce_10550>>
    : public dco::helper::complex_t<dco::internal::active_type<stce_9769, stce_10550>> {
public:
  typedef dco::internal::active_type<stce_9769, stce_10550> active_t;
  typedef dco::helper::complex_t<active_t> stce_10551;
  complex(active_t const& real = active_t(), active_t const& imag = active_t()) : stce_10551(real, imag) {}
  template <typename TYPE>
  complex(TYPE const& real, typename dco::dco_type_constructable_from<TYPE>::type* = 0) : stce_10551(real, TYPE()) {}
  template <typename TYPE>
  complex(TYPE const& real,
          typename dco::enable_if<(dco::mode<TYPE>::is_dco_type &&
                                   dco::stce_9882<dco::mode<TYPE>, dco::mode<active_t>>::value) ||
                                      dco::is_same<TYPE, typename dco::mode<active_t>::passive_t>::value,
                                  void*>::type = NULL)
      : stce_10551(real, TYPE()) {}
  template <typename stce_9877> complex(complex<stce_9877> const& stce_10549) : stce_10551(stce_10549) {}
  complex& operator=(active_t const& stce_9905) {
    static_cast<stce_10551&>(*this) = stce_9905;
    return *this;
  }
  template <typename stce_9877> complex& operator=(complex<stce_9877> const& stce_9905) {
    static_cast<stce_10551&>(*this) = stce_9905;
    return *this;
  }
  template <typename TYPE>
  typename dco::dco_type_constructable_from<TYPE, complex>::type& operator=(const TYPE& stce_9905) {
    static_cast<stce_10551&>(*this) = stce_9905;
    return *this;
  }
  complex& operator=(typename dco::mode<active_t>::passive_t const& stce_9905) {
    static_cast<stce_10551&>(*this) = stce_9905;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807)
      : stce_10551(
            stce_9807,
            typename dco::mode<dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>>::active_t()) {}
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex&
  operator=(const dco::internal::stce_9777<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    static_cast<stce_10551&>(*this) = stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807)
      : stce_10551(
            stce_9807,
            typename dco::mode<dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>>::active_t()) {}
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex&
  operator=(const dco::internal::stce_9778<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    static_cast<stce_10551&>(*this) = stce_9807;
    return *this;
  }
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807)
      : stce_10551(
            stce_9807,
            typename dco::mode<dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>>::active_t()) {}
  template <class stce_10128, class stce_10129, class stce_10130>
  DCO_ALWAYS_INLINE complex&
  operator=(const dco::internal::stce_9779<stce_9769, stce_10128, stce_10129, stce_10130>& stce_9807) {
    static_cast<stce_10551&>(*this) = stce_9807;
    return *this;
  }
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE complex(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807)
      : stce_10551(stce_9807,
                   typename dco::mode<dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>>::active_t()) {}
  template <class stce_10136, class stce_10130>
  DCO_ALWAYS_INLINE complex& operator=(const dco::internal::stce_9774<stce_9769, stce_10136, stce_10130>& stce_9807) {
    static_cast<stce_10551&>(*this) = stce_9807;
    return *this;
  }
  DCO_STRONG_INLINE complex operator-() const { return complex(-this->real(), -this->imag()); }
};
template <typename stce_10492, typename stce_10156, bool stce_10552 = true> struct stce_10553 {
  typedef typename dco::stce_9876<
      dco::mode<stce_10492>::is_dco_type && !dco::mode<stce_10492>::is_intermediate_type, stce_10492,
      typename dco::stce_9876<dco::mode<stce_10156>::is_dco_type && !dco::mode<stce_10156>::is_intermediate_type,
                              stce_10156, void>::type>::type stce_10554;
  typedef typename dco::stce_9876<dco::is_same<stce_10554, stce_10492>::value, stce_10156, stce_10492>::type stce_10555;
  static const bool stce_10556 =
      (stce_10552 || dco::is_same<stce_10554, stce_10492>::value) && !dco::is_same<stce_10554, void>::value &&
      (dco::is_same<stce_10554, typename dco::mode<stce_10555>::active_t>::value ||
       (dco::mode<stce_10555>::is_dco_type && dco::stce_9882<dco::mode<stce_10555>, dco::mode<stce_10554>>::value) ||
       dco::is_same<stce_10555, typename dco::mode<stce_10554>::passive_t>::value);
};
template <typename stce_10492, typename stce_10156, bool stce_10433 = false> struct stce_10557 {};
template <typename stce_10492, typename stce_10156> struct stce_10557<stce_10492, stce_10156, true> {
  typedef typename stce_10553<stce_10492, stce_10156>::stce_10554 type;
  typedef complex<type> stce_10558;
};
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
cos(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
cosh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
exp(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
log(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
log10(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
sin(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
sinh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
sqrt(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
tan(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
tanh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
asin(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
asinh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
acos(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
acosh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
atan(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
atanh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
proj(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10550>
abs(complex<dco::internal::active_type<stce_9769, stce_10550>> const&);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10550>
arg(complex<dco::internal::active_type<stce_9769, stce_10550>> const&);
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
polar(dco::internal::active_type<stce_9769, stce_10550> const&,
      const dco::internal::active_type<stce_9769, stce_10550>& = 0);
template <typename stce_9780>
complex<stce_9780> stce_10559(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 + stce_10563;
    stce_10560.real(stce_10091.real() + stce_10092.real());
    stce_10560.imag(stce_10091.imag() + stce_10092.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091.real() + stce_10092.real());
    stce_10560.imag(stce_10091.imag() + stce_10092.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10559(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10561 = stce_10562 + stce_10563;
    stce_10560.real(stce_10091.real() + stce_10092);
    stce_10560.imag(stce_10091.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091.real() + stce_10092);
    stce_10560.imag(stce_10091.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10559(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    passive_t stce_10562(dco::passive_value(stce_10091));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 + stce_10563;
    stce_10560.real(stce_10091 + stce_10092.real());
    stce_10560.imag(stce_10092.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091 + stce_10092.real());
    stce_10560.imag(stce_10092.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10564(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 - stce_10563;
    stce_10560.real(stce_10091.real() - stce_10092.real());
    stce_10560.imag(stce_10091.imag() - stce_10092.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091.real() - stce_10092.real());
    stce_10560.imag(stce_10091.imag() - stce_10092.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10564(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10561 = stce_10562 - stce_10563;
    stce_10560.real(stce_10091.real() - stce_10092);
    stce_10560.imag(stce_10091.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091.real() - stce_10092);
    stce_10560.imag(stce_10091.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10564(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    passive_t stce_10562(dco::passive_value(stce_10091));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 - stce_10563;
    stce_10560.real(stce_10091 - stce_10092.real());
    stce_10560.imag(-stce_10092.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091 - stce_10092.real());
    stce_10560.imag(-stce_10092.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10565(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 * stce_10563;
    stce_10560.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10560.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10560.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10565(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10561 = stce_10562 * stce_10563;
    stce_10560.real(stce_10091.real() * stce_10092);
    stce_10560.imag(stce_10091.imag() * stce_10092);
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091.real() * stce_10092);
    stce_10560.imag(stce_10091.imag() * stce_10092);
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10565(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    passive_t stce_10562(dco::passive_value(stce_10091));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 * stce_10563;
    stce_10560.real(stce_10091 * stce_10092.real());
    stce_10560.imag(stce_10091 * stce_10092.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10091 * stce_10092.real());
    stce_10560.imag(stce_10091 * stce_10092.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10566(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10045 = stce_10091 * complex<stce_9780>(stce_10092.real(), -stce_10092.imag());
  stce_9780 stce_10084 = stce_10092.real() * stce_10092.real() + stce_10092.imag() * stce_10092.imag();
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 / stce_10563;
    stce_10560.real(stce_10045.real() / stce_10084);
    stce_10560.imag(stce_10045.imag() / stce_10084);
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10045.real() / stce_10084);
    stce_10560.imag(stce_10045.imag() / stce_10084);
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10566(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  complex<stce_9780> stce_10045 = stce_10091 * stce_10092;
  stce_9780 stce_10084 = stce_10092 * stce_10092;
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10561 = stce_10562 / stce_10563;
    stce_10560.real(stce_10045.real() / stce_10084);
    stce_10560.imag(stce_10045.imag() / stce_10084);
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10045.real() / stce_10084);
    stce_10560.imag(stce_10045.imag() / stce_10084);
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10566(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10045 = stce_10091 * complex<stce_9780>(stce_10092.real(), -stce_10092.imag());
  stce_9780 stce_10084 = stce_10092.real() * stce_10092.real() + stce_10092.imag() * stce_10092.imag();
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    passive_t stce_10562(dco::passive_value(stce_10091));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = stce_10562 / stce_10563;
    stce_10560.real(stce_10045.real() / stce_10084);
    stce_10560.imag(stce_10045.imag() / stce_10084);
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10045.real() / stce_10084);
    stce_10560.imag(stce_10045.imag() / stce_10084);
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10567(complex<stce_9780> const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10028;
  if (stce_10091 == stce_9780()) {
    stce_10028 = complex<stce_9780>();
  } else {
    stce_10028 = exp(stce_10092 * log(stce_10091));
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = pow(stce_10562, stce_10563);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10567(complex<stce_9780> const& stce_10091, stce_9780 const& stce_10092) {
  complex<stce_9780> stce_10028;
  if (stce_10091.imag() == typename dco::mode<stce_9780>::active_t() &&
      stce_10091.real() > typename dco::mode<stce_9780>::active_t()) {
    stce_10028 = pow(stce_10091.real(), stce_10092);
  } else {
    complex<stce_9780> stce_10014 = log(stce_10091);
    stce_10028 = polar(static_cast<stce_9780>(exp(stce_10092 * stce_10014.real())),
                       static_cast<stce_9780>(stce_10092 * stce_10014.imag()));
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10561 = pow(stce_10562, stce_10563);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780> stce_10567(stce_9780 const& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10028;
  if (stce_10091 > stce_9780()) {
    stce_10028 = polar(static_cast<stce_9780>(pow(stce_10091, stce_10092.real())),
                       static_cast<stce_9780>(stce_10092.imag() * log(stce_10091)));
  } else {
    stce_10028 = pow(complex<stce_9780>(stce_10091), stce_10092);
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    passive_t stce_10562(dco::passive_value(stce_10091));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10561 = pow(stce_10562, stce_10563);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10568(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10562 += stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() + stce_10092.real());
    stce_10028.imag(stce_10091.imag() + stce_10092.imag());
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() + stce_10092.real());
    stce_10028.imag(stce_10091.imag() + stce_10092.imag());
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10568(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10562 += stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() + stce_10092);
    stce_10028.imag(stce_10091.imag());
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() + stce_10092);
    stce_10028.imag(stce_10091.imag());
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10569(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10562 -= stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() - stce_10092.real());
    stce_10028.imag(stce_10091.imag() - stce_10092.imag());
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() - stce_10092.real());
    stce_10028.imag(stce_10091.imag() - stce_10092.imag());
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10569(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10562 -= stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() - stce_10092);
    stce_10028.imag(stce_10091.imag());
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() - stce_10092);
    stce_10028.imag(stce_10091.imag());
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10570(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10562 *= stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10028.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() * stce_10092.real() - stce_10091.imag() * stce_10092.imag());
    stce_10028.imag(stce_10091.real() * stce_10092.imag() + stce_10091.imag() * stce_10092.real());
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10570(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10562 *= stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() * stce_10092);
    stce_10028.imag(stce_10091.imag() * stce_10092);
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10091.real() * stce_10092);
    stce_10028.imag(stce_10091.imag() * stce_10092);
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10571(complex<stce_9780>& stce_10091, complex<stce_9780> const& stce_10092) {
  complex<stce_9780> stce_10045 = stce_10091 * complex<stce_9780>(stce_10092.real(), -stce_10092.imag());
  stce_9780 stce_10084 = stce_10092.real() * stce_10092.real() + stce_10092.imag() * stce_10092.imag();
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    complex<passive_t> stce_10563(dco::passive_value(stce_10092.real()), dco::passive_value(stce_10092.imag()));
    stce_10562 /= stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10045.real() / stce_10084);
    stce_10028.imag(stce_10045.imag() / stce_10084);
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10045.real() / stce_10084);
    stce_10028.imag(stce_10045.imag() / stce_10084);
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <typename stce_9780>
complex<stce_9780>& stce_10571(complex<stce_9780>& stce_10091, stce_9780 const& stce_10092) {
  complex<stce_9780> stce_10045 = stce_10091 * stce_10092;
  stce_9780 stce_10084 = stce_10092 * stce_10092;
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    passive_t stce_10563(dco::passive_value(stce_10092));
    stce_10562 /= stce_10563;
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10045.real() / stce_10084);
    stce_10028.imag(stce_10045.imag() / stce_10084);
    stce_10091 = stce_10028;
    dco::passive_value(stce_10091.real()) = stce_10562.real();
    dco::passive_value(stce_10091.imag()) = stce_10562.imag();
    return stce_10091;
  } else {
    complex<stce_9780> stce_10028;
    stce_10028.real(stce_10045.real() / stce_10084);
    stce_10028.imag(stce_10045.imag() / stce_10084);
    stce_10091 = stce_10028;
    return stce_10091;
  }
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator+(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10559(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator+(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10559(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator+(dco::internal::active_type<stce_9769, stce_10550> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10559(static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator+(complex<stce_10492> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10559(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator+(complex<stce_10492> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10559(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator+(stce_10492 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10559(
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator-(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10564(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator-(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10564(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator-(dco::internal::active_type<stce_9769, stce_10550> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10564(static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator-(complex<stce_10492> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10564(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator-(complex<stce_10492> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10564(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator-(stce_10492 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10564(
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator*(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10565(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator*(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10565(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator*(dco::internal::active_type<stce_9769, stce_10550> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10565(static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator*(complex<stce_10492> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10565(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator*(complex<stce_10492> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10565(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator*(stce_10492 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10565(
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator/(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10566(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator/(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
          dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10566(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
operator/(dco::internal::active_type<stce_9769, stce_10550> const& stce_10091,
          complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10566(static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator/(complex<stce_10492> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10566(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator/(complex<stce_10492> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10566(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    operator/(stce_10492 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10566(
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
pow(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
    complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10567(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
pow(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10091,
    dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10567(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
pow(dco::internal::active_type<stce_9769, stce_10550> const& stce_10091,
    complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10567(static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10091),
                    static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    pow(complex<stce_10492> const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10567(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    pow(complex<stce_10492> const& stce_10091, stce_10156 const& stce_10092) {
  return stce_10567(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::stce_10558
    pow(stce_10492 const& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10567(
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10091),
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator+=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10568(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator+=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10568(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator+=(complex<stce_10492>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10568(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator+=(complex<stce_10492>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10568(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>&>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator-=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10569(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator-=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10569(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator-=(complex<stce_10492>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10569(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator-=(complex<stce_10492>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10569(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>&>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator*=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10570(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator*=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10570(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator*=(complex<stce_10492>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10570(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator*=(complex<stce_10492>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10570(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>&>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator/=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_10092) {
  return stce_10571(stce_10091, stce_10092);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>&
operator/=(complex<dco::internal::active_type<stce_9769, stce_10550>>& stce_10091,
           dco::internal::active_type<stce_9769, stce_10550> const& stce_10092) {
  return stce_10571(static_cast<complex<dco::internal::active_type<stce_9769, stce_10550>>&>(stce_10091),
                    static_cast<dco::internal::active_type<stce_9769, stce_10550>>(stce_10092));
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator/=(complex<stce_10492>& stce_10091, complex<stce_10156> const& stce_10092) {
  return stce_10571(stce_10091, stce_10092);
}
template <typename stce_10492, typename stce_10156>
DCO_STRONG_INLINE
    typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156, false>::stce_10556>::stce_10558&
    operator/=(complex<stce_10492>& stce_10091, stce_10156 const& stce_10092) {
  return stce_10571(
      static_cast<
          complex<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>&>(
          stce_10091),
      static_cast<typename stce_10557<stce_10492, stce_10156, stce_10553<stce_10492, stce_10156>::stce_10556>::type>(
          stce_10092));
}
template <typename stce_9780> complex<stce_9780> stce_10572(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = sin(stce_10562);
    stce_10560.real(sin(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10560.imag(cos(stce_10091.real()) * sinh(stce_10091.imag()));
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(sin(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10560.imag(cos(stce_10091.real()) * sinh(stce_10091.imag()));
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10573(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = sinh(stce_10562);
    stce_10560.real(sinh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10560.imag(cosh(stce_10091.real()) * sin(stce_10091.imag()));
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(sinh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10560.imag(cosh(stce_10091.real()) * sin(stce_10091.imag()));
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10574(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = cos(stce_10562);
    stce_10560.real(cos(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10560.imag(-sin(stce_10091.real()) * sinh(stce_10091.imag()));
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(cos(stce_10091.real()) * cosh(stce_10091.imag()));
    stce_10560.imag(-sin(stce_10091.real()) * sinh(stce_10091.imag()));
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10575(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = cosh(stce_10562);
    stce_10560.real(cosh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10560.imag(sinh(stce_10091.real()) * sin(stce_10091.imag()));
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(cosh(stce_10091.real()) * cos(stce_10091.imag()));
    stce_10560.imag(sinh(stce_10091.real()) * sin(stce_10091.imag()));
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10576(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028 = sin(stce_10091) / cos(stce_10091);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = tan(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10577(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028 = sinh(stce_10091) / cosh(stce_10091);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = tanh(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10578(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028 = polar(static_cast<stce_9780>(exp(stce_10091.real())), stce_10091.imag());
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = exp(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10579(complex<stce_9780> const& stce_10091) {
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = log(stce_10562);
    stce_10560.real(log(abs(stce_10091)));
    stce_10560.imag(arg(stce_10091));
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(log(abs(stce_10091)));
    stce_10560.imag(arg(stce_10091));
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10580(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028 = log(stce_10091) / log(typename dco::mode<stce_9780>::active_t(10.0));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = log10(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10581(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028;
  if (stce_10091.real() == typename dco::mode<stce_9780>::active_t()) {
    stce_9780 stce_10582 = sqrt(abs(stce_10091.imag()) / 2);
    stce_10028 = complex<stce_9780>(stce_10582, stce_10091.imag() < 0.0 ? stce_9780(-stce_10582) : stce_10582);
  } else {
    stce_9780 stce_10582 = sqrt(2 * (abs(stce_10091) + abs(stce_10091.real())));
    stce_9780 stce_10583 = stce_10582 / 2;
    stce_10028 = stce_10091.real() > typename dco::mode<stce_9780>::active_t()
                     ? complex<stce_9780>(stce_10583, stce_9780(stce_10091.imag() / stce_10582))
                     : complex<stce_9780>(abs(stce_10091.imag()) / stce_10582,
                                          stce_10091.imag() < stce_9780() ? stce_9780(-stce_10583) : stce_10583);
  }
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = sqrt(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10584(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028(-stce_10091.imag(), stce_10091.real());
  stce_10028 = asinh(stce_10028);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = asin(stce_10562);
    stce_10560.real(stce_10028.imag());
    stce_10560.imag(-stce_10028.real());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.imag());
    stce_10560.imag(-stce_10028.real());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10585(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028((stce_10091.real() - stce_10091.imag()) * (stce_10091.real() + stce_10091.imag()) +
                                    stce_9780(1.0),
                                stce_9780(2.0) * stce_10091.real() * stce_10091.imag());
  stce_10028 = sqrt(stce_10028);
  stce_10028 = log(stce_10028 + stce_10091);
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = asinh(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10586(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028 = asin(stce_10091);
  const stce_9780 stce_10587 = 1.5707963267948966192313216916397514L;
  stce_10028 = complex<stce_9780>(stce_10587 - stce_10028.real(), -stce_10028.imag());
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = acos(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10588(complex<stce_9780> const& stce_10091) {
  complex<stce_9780> stce_10028 = stce_9780(2.0) * log(sqrt(stce_9780(0.5) * (stce_10091 + stce_9780(1.0))) +
                                                       sqrt(stce_9780(0.5) * (stce_10091 - stce_9780(1.0))));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = acosh(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10589(complex<stce_9780> const& stce_10091) {
  const stce_9780 stce_10590 = stce_10091.real() * stce_10091.real();
  const stce_9780 stce_10549 = stce_9780(1.0) - stce_10590 - stce_10091.imag() * stce_10091.imag();
  stce_9780 stce_10591 = stce_10091.imag() + stce_9780(1.0);
  stce_9780 stce_10592 = stce_10091.imag() - stce_9780(1.0);
  stce_10591 = stce_10590 + stce_10591 * stce_10591;
  stce_10592 = stce_10590 + stce_10592 * stce_10592;
  complex<stce_9780> stce_10028 =
      complex<stce_9780>(stce_9780(0.5) * atan2(stce_9780(2.0) * stce_10091.real(), stce_10549),
                         stce_9780(0.25) * log(stce_10591 / stce_10592));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = atan(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10593(complex<stce_9780> const& stce_10091) {
  const stce_9780 stce_10594 = stce_10091.imag() * stce_10091.imag();
  const stce_9780 stce_10549 = stce_9780(1.0) - stce_10594 - stce_10091.real() * stce_10091.real();
  stce_9780 stce_10591 = stce_9780(1.0) + stce_10091.real();
  stce_9780 stce_10592 = stce_9780(1.0) - stce_10091.real();
  stce_10591 = stce_10594 + stce_10591 * stce_10591;
  stce_10592 = stce_10594 + stce_10592 * stce_10592;
  complex<stce_9780> stce_10028 =
      complex<stce_9780>(stce_9780(0.25) * (log(stce_10591) - log(stce_10592)),
                         stce_9780(0.5) * atan2(stce_9780(2.0) * stce_10091.imag(), stce_10549));
  if (dco::HAS_INTRINSIC_COMPLEX_PRIMALS) {
    complex<stce_9780> stce_10560;
    typedef typename dco::mode<stce_9780>::passive_t passive_t;
    complex<passive_t> stce_10561;
    complex<passive_t> stce_10562(dco::passive_value(stce_10091.real()), dco::passive_value(stce_10091.imag()));
    stce_10561 = atanh(stce_10562);
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    dco::passive_value(stce_10560.real()) = stce_10561.real();
    dco::passive_value(stce_10560.imag()) = stce_10561.imag();
    return stce_10560;
  } else {
    complex<stce_9780> stce_10560;
    stce_10560.real(stce_10028.real());
    stce_10560.imag(stce_10028.imag());
    return stce_10560;
  }
}
template <typename stce_9780> complex<stce_9780> stce_10595(complex<stce_9780> const& stce_10091) {
  if (dco::IS_DEBUG && (isinf(stce_10091.real()) || isinf(stce_10091.imag()))) {
    throw dco::exception::create<std::runtime_error>(
        "std::proj(std::complex<T>): One value is inf; derivatives undefined. Please contact NAG (support@nag.co.uk).");
  }
  return stce_10091;
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
cos(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10574(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
cosh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10575(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
exp(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10578(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
log(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10579(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
log10(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10580(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
sin(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10572(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
sinh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10573(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
sqrt(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10581(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
tan(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10576(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
tanh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10577(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
asin(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10584(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
asinh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10585(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
acos(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10586(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
acosh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10588(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
atan(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10589(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
atanh(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10593(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE std::complex<dco::internal::active_type<stce_9769, stce_10550>>
proj(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return stce_10595(stce_9807);
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10550>
abs(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return sqrt(pow(stce_9807.real(), 2) + pow(stce_9807.imag(), 2));
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE dco::internal::active_type<stce_9769, stce_10550>
arg(complex<dco::internal::active_type<stce_9769, stce_10550>> const& stce_9807) {
  return atan2(stce_9807.imag(), stce_9807.real());
}
template <class stce_9769, typename stce_10550>
DCO_STRONG_INLINE complex<dco::internal::active_type<stce_9769, stce_10550>>
polar(dco::internal::active_type<stce_9769, stce_10550> const& stce_10596,
      dco::internal::active_type<stce_9769, stce_10550> const& stce_10597) {
  return complex<dco::internal::active_type<stce_9769, stce_10550>>(stce_10596 * cos(stce_10597),
                                                                    stce_10596 * sin(stce_10597));
}
} // namespace std
