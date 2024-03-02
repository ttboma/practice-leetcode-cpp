enable_testing()

file(GLOB TEST_SOLUTION solution/*.cpp)
add_executable(test_solution ${TEST_SOLUTION})
target_link_libraries(test_solution GTest::gtest_main leetcode_cpp)

include(GoogleTest)
gtest_discover_tests(test_solution)
