# Collect all test files from subdirectories
file(GLOB_RECURSE testsSolutionCpps
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/array/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/linked_list/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tree/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/math/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/heap/*.cpp
)

add_executable(tests_solution ${testsSolutionCpps})

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
