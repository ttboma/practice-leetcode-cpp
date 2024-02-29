file(GLOB SRC_SOLUTION solution/*.cpp)

add_library(leetcode_cpp STATIC ${SRC_SOLUTION})
target_include_directories(leetcode_cpp PUBLIC ${PROJECT_SOURCE_DIR}/include/leetcode_cpp)

add_subdirectory(bin)
