# Collect all source files from subdirectories
file(GLOB_RECURSE src_solution_cpps
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/array/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/linked_list/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tree/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dynamic_programming/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/math/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/heap/*.cpp
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
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/nlohmann/json/include
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
