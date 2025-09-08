cmake_minimum_required(
  VERSION 3.25
)

# set the project name and version
project(
  leetcode_cpp
  VERSION     1.0
  DESCRIPTION "practice with leetcode"
  LANGUAGES   CXX
)

# Including custom cmake utilities
list(
  APPEND CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/cmake"
)
include(RequireOutOfSourceBuilds)
include(FindDependency)
include(ClangCxxDevTools)

# Ensures that the project is built outside of the source directory.
require_out_of_source_build()

# Specify the C++ standard
#
# Create an interface library target named "compiler_flags" to hold common
# compiler settings (no actual object code is produced).
add_library(compiler_flags INTERFACE)

# Require C++20 for all targets that link against compiler_flags.
target_compile_features(compiler_flags INTERFACE cxx_std_20)

# Add compiler warning flags
#
# Define generator expressions to detect compiler families.
#   - gcc_like_cxx: Matches ARMClang, AppleClang, Clang, GNU, and LCC.
#   - msvc_cxx:     Matches MSVC.
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx     "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# Apply warning options only when building this project (BUILD_INTERFACE).
#
# For gcc/clang-like compilers: -Wall -Wextra -Wshadow -Wformat=2 -Wunused
# For MSVC: /W3
target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

include(GNUInstallDirs)

# Put libraries in lib, executables in bin, headers in include
set(CMAKE_INSTALL_RPATH "@executable_path/../${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(src)
add_subdirectory(bin)

# Defines a test target
enable_testing()

add_subdirectory(tests)

# add_subdirectory(docs)
