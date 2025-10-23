#include "gtest/gtest.h"
#include "solution.hpp"

TEST(climbStairs, example1) {
    int n = 2;
    EXPECT_EQ(Solution{}.climbStairs(n), 2);
}

TEST(climbStairs, example2) {
    int n = 3;
    EXPECT_EQ(Solution{}.climbStairs(n), 3);
}
