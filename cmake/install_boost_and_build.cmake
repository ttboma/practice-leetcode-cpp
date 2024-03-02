# This is just an archive method of installing boost, not successfully completed yet
function(install_boost_on_windows)
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        # Add boost lib sources
        set(BOOST_INCLUDE_LIBRARIES program_options)
        set(BOOST_ENABLE_CMAKE ON)

        # Download and extract the boost library from GitHub
        message(STATUS "Downloading and extracting boost library sources. This will take some time...")
        include(FetchContent)
        Set(FETCHCONTENT_QUIET FALSE) # Needed to print downloading progress
        FetchContent_Declare(
            Boost
            URL https://boostorg.jfrog.io/artifactory/main/release/1.84.0/source/boost_1_84_0.tar.gz
            USES_TERMINAL_DOWNLOAD TRUE
            GIT_PROGRESS TRUE
            DOWNLOAD_NO_EXTRACT FALSE
        )
        FetchContent_MakeAvailable(Boost)
        execute_process(
            COMMAND bootstrap.bat
            WORKING_DIRECTORY ${boost_SOURCE_DIR}
            RESULT_VARIABLE BOOST_B2_SUCCESS
        )
        execute_process(
            COMMAND b2 install --prefix="${boost_BINARY_DIR}" --with-program_options
            WORKING_DIRECTORY ${boost_SOURCE_DIR}
            RESULT_VARIABLE BOOST_B2_SUCCESS
        )
        find_package(Boost PATHS ${boost_SOURCE_DIR} COMPONENTS program_options REQUIRED)
    else()
        message(WARNING "Boost need to be built with bootstrap.")
    endif()
endfunction()
