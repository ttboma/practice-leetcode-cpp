# Additional targets to perform clang-format/clang-tidy
# Get all project files
file(GLOB_RECURSE
     ALL_CXX_SOURCE_FILES
     src/*.cpp include/*.h tests/*.cpp
     )

# Adding clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
  add_custom_target(
    clang-format
    COMMAND clang-format
    -i
    -style=Google
    ${ALL_CXX_SOURCE_FILES}
    )
endif()

set(INCLUDE_DIRECTORIES include/leetcode_cpp)

# Adding clang-tidy target if executable is found
find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)
  add_custom_target(
    clang-tidy
    COMMAND clang-tidy
    ${ALL_CXX_SOURCE_FILES}
    -config=''
    --checks=performance-*
    --
    -std=c++20
    ${INCLUDE_DIRECTORIES}
    )
endif()
