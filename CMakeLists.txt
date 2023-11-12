cmake_minimum_required(VERSION 3.16)

project(BayesianLotkaVolterra CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EB_CXX_FLAGS -Wall -Wextra -pedantic -Wconversion -Wshadow -fdiagnostics-color=always)
set(EB_CXX_LINK_FLAGS)

set(EB_DCO_FLAGS -DDCO_AUTO_SUPPORT -DDCO_EXT_EIGEN_IGNORE_VERSION -DDCO_EXT_EIGEN_IGNORE_NO_INTERMEDIATES -DDCO_STD_COMPATIBILITY -DDCO_TAPE_USE_INT64)
set(EB_DCO_BASE_PATH ${CMAKE_SOURCE_DIR}/ThirdParty/DCO/dcl6i40ngl_v402)

# - Build type options -----------------------------------------------------------------------------
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # - Check if interprocedural optimizations are available ---------------------------------------
    include(CheckIPOSupported)
    check_ipo_supported(RESULT ipo_available OUTPUT ipo_available_output)
    if(ipo_available)
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
    else()
        message(WARNING "Could not enable interprocedural optimization")
    endif()
    set(CMAKE_CXX_FLAGS_RELEASE "-O3") # Disable -DNDEBUG flag because I want to keep assertions
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EB_CXX_FLAGS      ${EB_CXX_FLAGS}      -fsanitize=address,undefined,leak -O0)
    set(EB_CXX_LINK_FLAGS ${EB_CXX_LINK_FLAGS} -fsanitize=address,undefined,leak)
else()
    message(FATAL_ERROR "Unknown build type ${CMAKE_BUILD_TYPE}. Available are \"Release\" and \"Debug\".")
endif()

# - Profiling using gprof --------------------------------------------------------------------------
option(EB_USE_GPROF "Enable profiling with gprof" OFF)
if (EB_USE_GPROF)
    set(EB_CXX_FLAGS      ${EB_CXX_FLAGS}      -pg)
    set(EB_CXX_LINK_FLAGS ${EB_CXX_LINK_FLAGS} -pg)
endif()

# - Check if `-march=native` is available ---------------------------------------------------------
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
if(COMPILER_SUPPORTS_MARCH_NATIVE)
    set(EB_CXX_FLAGS ${EB_CXX_FLAGS} -march=native)
endif()

# - Use MKL as backend for matrix operations ------------------------------------------------------
option(EB_USE_MKL "Use Intels MKL as backend for the matrix operations" OFF)
if(EB_USE_MKL)
    message(STATUS "Use Intels MKL as backend for the matrix operations")
    set(MKLROOT "/opt/intel/oneapi/mkl/latest")
    if(NOT EXISTS ${MKLROOT})
        message(FATAL_ERROR "Did not find Intels MLK at '${MKLROOT}'")
    endif()

    set(EB_CXX_FLAGS ${EB_CXX_FLAGS} -DEIGEN_USE_MKL_ALL -DMKL_ILP64 -m64)
endif()

# - Use ccache to cache compiled code -------------------------------------------------------------
option(EB_USE_CCACHE "Use ccache to speed up compilation process" ON)
find_program(CCACHE ccache)
if (CCACHE AND EB_USE_CCACHE)
    message(STATUS "Use ccache")
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
else()
    message(STATUS "Do not use ccache")
endif()

# - Examples; default is ON -----------------------------------------------------------------------
option(EB_BUILD_EXAMPLE "Build examples" ON)
if(EB_BUILD_EXAMPLE)
    message(STATUS "Build examples")
    add_subdirectory(${CMAKE_SOURCE_DIR}/examples/)
endif()

# - Tests; default is OFF -------------------------------------------------------------------------
option(EB_BUILD_TEST "Build tests using the google test library" OFF)
if(EB_BUILD_TEST)
    enable_testing()

    # Disable interprocedural optimizations for google test library
    if (ipo_available)
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)
    endif()

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        main
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Re-enable interprocedural optimizations if available
    if (ipo_available)
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
    endif()

    message(STATUS "Build tests")
    add_subdirectory(${CMAKE_SOURCE_DIR}/test/)
endif()
