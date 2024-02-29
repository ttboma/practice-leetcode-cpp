cmake_minimum_required(VERSION 3.24.2)
project(leetcode_cpp VERSION 1.0
                     DESCRIPTION "practice with leetcode"
                     LANGUAGES CXX)

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. For example, run `cmake . -B build`. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# generates a `compile_commands.json` file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# -std=c++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)

# Including custom cmake rules
include(cmake/clang-cxx-dev-tools.cmake)
