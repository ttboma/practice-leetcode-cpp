file(
    GLOB tests_sort_cpps
    *.cpp
)

add_executable(tests_sort ${tests_sort_cpps})

target_link_libraries(
    tests_sort
    GTest::gtest_main
    compiler_flags
)

target_include_directories(
    tests_sort PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

gtest_discover_tests(tests_sort)
