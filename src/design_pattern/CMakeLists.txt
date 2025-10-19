file(
    GLOB src_design_pattern_cpps
    *.cpp
)

add_library(
    src_design_pattern
    ${src_design_pattern_cpps}
)

target_compile_definitions(
    src_design_pattern
    PRIVATE
    FIB_IMPL_DYNAMIC_PROGRAMMING
)

target_include_directories(
    src_design_pattern
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# link src_design_pattern to compiler_flags
target_link_libraries(
    src_design_pattern
    PRIVATE
    compiler_flags
)

# state that src_design_pattern need PIC when the default is shared libraries
set_target_properties(
    src_design_pattern
    PROPERTIES
    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
)

install(
  TARGETS src_design_pattern
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
