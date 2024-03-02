# Find boost
find_package(Boost COMPONENTS program_options REQUIRED)

# Find googletest
find_package(GTest)

# [If googletest is not found, try to fetch it from github](https://google.github.io/googletest/quickstart-cmake.html)
if(NOT ${GTest_FOUND})
    message("fetching google-test from https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip ...")

    include(FetchContent)
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
  message(WARNING "Doxygen need to be installed to generate the doxygen documentation")
endif()
