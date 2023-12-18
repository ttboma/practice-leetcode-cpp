set(BOOST_ROOT /opt/homebrew/Cellar/boost/1.83.0)

add_executable(solution solution.cpp)
target_include_directories(solution PUBLIC ${BOOST_ROOT}/include) # -I/opt/homebrew/Cellar/boost/1.83.0/include
target_link_directories(solution PUBLIC ${BOOST_ROOT}/lib) # -L/opt/homebrew/Cellar/boost/1.83.0/lib
target_link_libraries(solution PUBLIC leetcode_cpp boost_program_options) # -lboost_program_options
