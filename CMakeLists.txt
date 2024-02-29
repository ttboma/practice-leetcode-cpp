# Using the current cmake version as a reqiremnet.
# This version is somewhat arbitrary in this example. 
# But providing a version number allows for future support for your build environment. 
# Therefore, you should use the current version of CMake on your system. 
# You can find out the current verion of CMake by the shell command: `cmake --version`.
cmake_minimum_required( VERSION 3.20.3 )                                    

# Sets the name of the project, and stores it in the variable PROJECT_NAME. 
# When called from the top-level CMakeLists.txt also stores the project name in the variable CMAKE_PROJECT_NAME.
project( solution )													    

# 1. Specify debug flag, it's like -g option to gcc
#    By default, CMake is able to handle the following build types:
#    - Debug: Usually a classic debug build including debugging information, no optimization etc. 
#    - Release: Your typical release build with no debugging information and full optimization. 
#    - RelWithDebInfo: Same as Release, but with debugging information. 
#    - MinSizeRel: A special Release build optimized for size.
# 2. These will add the needed compile options on targets (e.g. -std=c++17 for gcc)
# 3. The version can be made a requirement by setting to ON the variables 
#    CMAKE_C_STANDARD_REQUIRED and CMAKE_CXX_STANDARD_REQUIRED respectively
# 4. Specify some other flags for gcc
# 5. Additional flags under debug mode
# 6. Additional flags under release mode
# 7. For clangd
# 8. To build CMake in a different directory, set default to "build" (NOT WORKING!!)
# ---------------------------------------------------------------------------------- {{{
set( CMAKE_BUILD_TYPE              Debug                          ) # (1)
set( CMAKE_CXX_STANDARD            17                             ) # (2)
set( CMAKE_CXX_STANDARD_REQUIRED   ON                             ) # (3)
set( CMAKE_CXX_COMPILER            "g++"                          ) 
set( CMAKE_CXX_FLAGS                                              ) # (4)	
set( CMAKE_CXX_FLAGS_DEBUG         "-O0 -Werror -pedantic-errors" ) # (5)  
set( CMAKE_CXX_FLAGS_RELEASE       "-O2 -DNDEBUG "                ) # (6) 
set( CMAKE_EXPORT_COMPILE_COMMANDS 1                              ) # (7)
set( CMAKE_BINARY_DIR              build                          ) # (8)
# }}}

# 1. Add the given directories to those the compiler uses to search for include files.
#    Relative paths are interpreted as relative to the current source directory
#    (like -I flag).
# 2. Adds the paths in which the linker should search for libraries. 
#    Relative paths given to this command are interpreted as relative to the current source directory
#    (like -L flag).
# ---------------------------------------------------------------------------------------------------- {{{
include_directories( ${PROJECT_SOURCE_DIR}/inc /opt/homebrew/include/ ) # (1)												
link_directories()                                                      # (2)
# }}}

# build libraries from sources
# 
# 1. Set my library name to be ${PROJECT_NAME} and store in the user-defined variable ${lib_name} 
# 2. The ARCHIVE_OUTPUT_DIRECTORY property specifies the directory into which archive target files should be built.
#    And the property is initialized by the value of the CMAKE_ARCHIVE_OUTPUT_DIRECTORY variable if it is set when a target is created.
# 3. The LIBRARY_OUTPUT_DIRECTORY property specifies the directory into which library target files should be built.
#    And the property is initialized by the value of the CMAKE_LIBRARY_OUTPUT_DIRECTORY variable if it is set when a target is created.
# -------------------------------------------- {{{
set( lib_name                       ${PROJECT_NAME}                  ) # (1)                   
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/target/lib ) # (2)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/target/lib ) # (3)
file( GLOB lib_src ${PROJECT_SOURCE_DIR}/src/*.cpp )
add_library( ${lib_name} STATIC ${lib_src} ) # static library
# }}} 

# Build each test 
#
# 1. The RUNTIME_OUTPUT_DIRECTORY specifies the directory into which runtime target files should be built. 
#    And the property is initialized by the value of the CMAKE_RUNTIME_OUTPUT_DIRECTORY variable if it is set when a target is created.
# ------------------------- {{{ 
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/target/tests ) # (1)	
file( GLOB test_src ${PROJECT_SOURCE_DIR}/src/tests/*.cpp )
foreach( item ${test_src} )
	get_filename_component( test ${item} NAME_WE )
	string( REPLACE test_ "" src ${test} )
	add_executable( ${test} src/tests/${test}.cpp src/${src}.cpp src/solution.cpp )
endforeach()
# }}}

add_custom_target( cleanall 
	COMMAND rm -rf ${PROJECT_SOURCE_DIR}/target/
)
