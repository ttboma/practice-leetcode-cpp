file(
    GLOB src_solution_cpps
    *.cpp
)

add_library(
    src_solution
    ${src_solution_cpps}
)

target_compile_definitions(
    src_solution
    PRIVATE
    FIB_IMPL_DYNAMIC_PROGRAMMING
)

target_include_directories(
    src_solution
    PUBLIC
    ${CMAKE_SOURCE_DIR}/src
)

# link src_solution to compiler_flags
target_link_libraries(
    src_solution
    PRIVATE
    compiler_flags
)

# state that src_solution need PIC when the default is shared libraries
set_target_properties(
    src_solution
    PROPERTIES
    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
)

install(
  TARGETS src_solution
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
