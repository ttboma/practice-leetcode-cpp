#include "gtest/gtest.h"
#include "solution.hpp"

TEST(mySqrt, example1) {
    Solution solution;
    EXPECT_EQ(solution.mySqrt(4), 2);
}

TEST(mySqrt, example2) {
    Solution solution;
    EXPECT_EQ(solution.mySqrt(8), 2);
}
