file(
    GLOB bin_solution_cpps
    *.cpp
)

add_executable(
    bin_solution
    ${bin_solution_cpps}
)

# Strip symbols in Release builds
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(UNIX)
        add_custom_command(TARGET bin_solution POST_BUILD
            COMMAND ${CMAKE_STRIP} $<TARGET_FILE:bin_solution>
            COMMENT "Stripping symbols from bin_solution"
        )
    endif()
endif()

set_target_properties(
    bin_solution
    PROPERTIES
        OUTPUT_NAME "solution"
)

# Link the executable with the compiler_flags "interface library" so that it
# inherits the C++ standard and warning options.
target_link_libraries(
    bin_solution
    PUBLIC
    compiler_flags
)

# Add other required libraries here, similar to passing -l boost_program_options on the command line
target_link_libraries(
    bin_solution
    PUBLIC
    src_solution
    ${Boost_LIBRARIES}
)

# -I/opt/homebrew/Cellar/boost/1.83.0/include
target_include_directories(
    bin_solution
    PUBLIC
    ${Boost_INCLUDE_DIR}
)

install(
    TARGETS bin_solution
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
