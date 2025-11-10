#include "gtest/gtest.h"
#include "solution.hpp"

TEST(minOperations, example1) {
    Solution solution;
    std::vector<int> nums = {0, 2};
    int expected = 1;
    EXPECT_EQ(solution.minOperations(nums), expected);
}

TEST(minOperations, example2) {
    Solution solution;
    std::vector<int> nums = {3, 1, 2, 1};
    int expected = 3;
    EXPECT_EQ(solution.minOperations(nums), expected);
}

TEST(minOperations, example3) {
    Solution solution;
    std::vector<int> nums = {1, 2, 1, 2, 1, 2};
    int expected = 4;
    EXPECT_EQ(solution.minOperations(nums), expected);
}
