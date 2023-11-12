set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/examples/")

find_package(OpenMP REQUIRED)

set(executables
        run_lotka_volterra
        run_adam_lv
        run_optimistic_search_lv
        run_hmc_lv

        run_optimistic_search2
        run_hmc_tf2
        run_hmc_tf2_hc
        run_chen_hmc_convergence

        run_multidim_chen

        run_harth_opt_search
        run_harth_hmc

        run_simpson_opt_search
        run_simpson_contour
        run_simpson_hmc_no_hc
        run_simpson_hmc_with_hc
        run_simpson_hmc_convergence
        run_simpson

        run_model_based_kriging
        bench_model_based_kriging
)

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

    # - Link libraries ----------
    target_link_libraries(${exec} PRIVATE OpenMP::OpenMP_CXX dcoc)
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

endforeach()
