/**
dco/c++/base v4.0.2
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2023
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#include <sstream>
#include <cmath>
#include <vector>
#include <array>
#include <iostream>
#include <map>
#include <fstream>
#include <complex>
#include <string>
#include <exception>

#include <stdexcept>
#include <bitset>
#include <set>
#include <sys/stat.h>
#include <cassert>
#include <cstring>
#include <limits>
#include <iomanip>
#include <algorithm>

#include <functional>
#include <type_traits>
#include <memory>

#if !defined(_WIN32)
#include <cxxabi.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <stdlib.h>
#endif

#ifdef _WIN32
#include <time.h>
#ifndef DCO_SKIP_WINDOWS_H_INCLUDE
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif
#endif

#include "dco_version.hpp"
