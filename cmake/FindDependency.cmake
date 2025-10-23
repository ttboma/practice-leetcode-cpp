include(FetchContent)

# Find [boost](https://www.boost.org/)
find_package(Boost COMPONENTS program_options REQUIRED)

# Find [googletest](https://google.github.io/googletest/)
find_package(GTest)

if(${GTest_FOUND})
    message(STATUS "googletest found: ${GTest_VERSION}")
else()
    message(STATUS "fetching google-test from https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip ...")

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

# Find [Doxygen](https://www.doxygen.nl/)
find_package(Doxygen)

if(NOT ${DOXYGEN_FOUND})
  message(WARNING "Doxygen need to be installed to generate the doxygen documentation.")
endif()

find_program(PRE_COMMIT_EXECUTABLE pre-commit)

if (PRE_COMMIT_EXECUTABLE)
    execute_process(
        COMMAND pre-commit install --hook-type commit-msg --hook-type pre-commit --hook-type pre-push
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )

    # Run pre-commit on all files
    add_custom_target(pre_commit
        COMMAND ${PRE_COMMIT_EXECUTABLE} run --all-files
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running pre-commit checks"
        VERBATIM
    )
endif()
