# Additional targets to perform clang-format/clang-tidy
# Get all project files
file(GLOB_RECURSE
     ALL_CXX_SOURCE_FILES
     src/*.cpp src/*.h include/*.h include/*.hpp tests/*.cpp
     )

# Adding clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
  add_custom_target(
    clang-format
    COMMAND ${CLANG_FORMAT}
    -i
    -style=file
    ${ALL_CXX_SOURCE_FILES}
    COMMENT "Running clang-format on all source files"
    )
endif()

# Adding clang-tidy target if executable is found
find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)
  add_custom_target(
    clang-tidy
    COMMAND ${CLANG_TIDY}
    ${ALL_CXX_SOURCE_FILES}
    --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy
    --
    -std=c++20
    -I${CMAKE_SOURCE_DIR}/include
    COMMENT "Running clang-tidy on all source files"
    VERBATIM
    )
endif()
