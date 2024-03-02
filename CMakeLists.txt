cmake_minimum_required(VERSION 3.24.2)

project(leetcode_cpp VERSION 1.0
                     DESCRIPTION "practice with leetcode"
                     LANGUAGES CXX)

# Including custom cmake rules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(require-out-of-source-builds)
include(clang-cxx-dev-tools)
include(find-dependency)

# generates a `compile_commands.json` file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# -std=c++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)
