file(
    GLOB tests_solution_cpps
    *.cpp
)

add_executable(tests_solution ${tests_solution_cpps})

target_link_libraries(
    tests_solution
    GTest::gtest_main
    src_solution
    compiler_flags
)

set_target_properties(tests_solution PROPERTIES
    BUILD_RPATH "${CMAKE_BINARY_DIR}/src/solution"
)

gtest_discover_tests(tests_solution)
