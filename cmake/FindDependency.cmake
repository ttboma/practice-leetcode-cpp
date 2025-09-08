include(FetchContent)

# Find boost
find_package(Boost COMPONENTS program_options REQUIRED)

# Find googletest
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

# look for Doxygen package
find_package(Doxygen)

if(NOT ${DOXYGEN_FOUND})
  message(WARNING "Doxygen need to be installed to generate the doxygen documentation.")
endif()
