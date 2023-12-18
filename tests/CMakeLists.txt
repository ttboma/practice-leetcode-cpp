# [Declare a dependency on GoogleTest](https://google.github.io/googletest/quickstart-cmake.html)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# set GTEST_ROOT variable to where you install gtest
set(GTEST_ROOT /opt/homebrew/Cellar/googletest/1.14.0)

file(GLOB TEST_SOLUTION solution/*.cpp)

enable_testing()
add_executable(test_solution ${TEST_SOLUTION})
target_include_directories(test_solution PUBLIC ${GTEST_ROOT}/include)
target_link_libraries(test_solution GTest::gtest_main leetcode_cpp)
include(GoogleTest)
gtest_discover_tests(test_solution)
