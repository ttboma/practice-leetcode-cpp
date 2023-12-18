cmake_minimum_required(VERSION 3.24.2)
project(leetcode_cpp VERSION 1.0
                     DESCRIPTION "practice with leetcode"
                     LANGUAGES CXX)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. For example, run `cmake . -B build`. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -std=c++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS NO)

# -g
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(bin)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)
