file(
    GLOB testsDesignPatternCpps
    *.cpp
)

add_executable(tests_design_pattern ${testsDesignPatternCpps})

target_link_libraries(
    tests_design_pattern
    src_design_pattern
    GTest::gtest_main
    compiler_flags
)

set_target_properties(tests_design_pattern PROPERTIES
    BUILD_RPATH "${CMAKE_BINARY_DIR}/src/design_pattern"
)

gtest_discover_tests(tests_design_pattern)
