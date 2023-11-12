set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/test/")

find_package(OpenMP REQUIRED)

set(executables
        test_compiletime_distributions
        test_runtime_distributions
        test_prior
        test_hypercube
        test_read_csv
        test_adam
        test_random
        test_hmc_tangent
        test_hmc_adjoint
)

include(GoogleTest)
foreach(exec ${executables})
    # - Define executables ------
    add_executable(${exec} ${exec}.cpp)

    # - Set compile flags -------
    target_compile_options(${exec} PRIVATE ${EB_CXX_FLAGS} ${EB_DCO_FLAGS})

    # - Set link flags ----------
    target_link_options(${exec} PRIVATE ${EB_CXX_LINK_FLAGS})

    # - Define include path -----
    target_include_directories(${exec}        PRIVATE ${CMAKE_SOURCE_DIR}/include/)
    target_include_directories(${exec} SYSTEM PRIVATE ${CMAKE_SOURCE_DIR}/ThirdParty/ ${EB_DCO_BASE_PATH}/include/)
    if(EB_USE_MKL)
        target_include_directories(${exec} SYSTEM PRIVATE ${MKLROOT}/include/)
    endif()

    # - Define link path --------
    target_link_directories(${exec} PRIVATE ${EB_DCO_BASE_PATH}/lib/)
    if(EB_USE_MKL)
        target_link_directories(${exec} PRIVATE ${MKLROOT}/lib/intel64/)
    endif()

    # - Link libraries ---------
    target_link_libraries(${exec} PRIVATE GTest::gtest_main OpenMP::OpenMP_CXX dcoc)
    if(EB_USE_MKL)
        target_link_libraries(${exec} PRIVATE 
                                    -Wl,--start-group
                                        libmkl_intel_ilp64.a
                                        libmkl_gnu_thread.a
                                        libmkl_core.a
                                    -Wl,--end-group
                                    gomp
                                    pthread
                                    m
                                    dl)
    endif()

    gtest_discover_tests(${exec})
endforeach()
