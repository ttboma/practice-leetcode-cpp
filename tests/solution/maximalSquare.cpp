#include "gtest/gtest.h"
#include "solution.hpp"

TEST(maximalSquare, example1) {
    Solution solution;
    std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    EXPECT_EQ(solution.maximalSquare(matrix), 4);
}

TEST(maximalSquare, example2) {
    Solution solution;
    std::vector<std::vector<char>> matrix = {{'1', '0'}, {'1', '0'}};
    EXPECT_EQ(solution.maximalSquare(matrix), 1);
}

TEST(maximalSquare, example3) {
    Solution solution;
    std::vector<std::vector<char>> matrix = {{'0'}};
    EXPECT_EQ(solution.maximalSquare(matrix), 0);
}
