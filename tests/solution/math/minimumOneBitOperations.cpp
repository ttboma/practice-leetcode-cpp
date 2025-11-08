#include "gtest/gtest.h"
#include "solution.hpp"

TEST(minimumOneBitOperations, example1) {
    Solution solution;
    int n = 0;
    int expected = 0;
    EXPECT_EQ(solution.minimumOneBitOperations(n), expected);
}

TEST(minimumOneBitOperations, example2) {
    Solution solution;
    int n = 3;
    int expected = 2;
    EXPECT_EQ(solution.minimumOneBitOperations(n), expected);
}

TEST(minimumOneBitOperations, example3) {
    Solution solution;
    int n = 6;
    int expected = 4;
    EXPECT_EQ(solution.minimumOneBitOperations(n), expected);
}
