add_executable(solution solution.cpp)
target_include_directories(solution PRIVATE ${Boost_INCLUDE_DIR})       # -I/opt/homebrew/Cellar/boost/1.83.0/include
target_link_libraries(solution PRIVATE leetcode_cpp ${Boost_LIBRARIES}) # -lboost_program_options
