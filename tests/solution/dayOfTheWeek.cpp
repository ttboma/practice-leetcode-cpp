#include "gtest/gtest.h"
#include "solution.hpp"

TEST(dayOfTheWeek, example1) {
    Solution sol;
    EXPECT_EQ(sol.dayOfTheWeek(31, 8, 2019), "Saturday");
}

TEST(dayOfTheWeek, example2) {
    Solution sol;
    EXPECT_EQ(sol.dayOfTheWeek(18, 7, 1999), "Sunday");
}

TEST(dayOfTheWeek, example3) {
    Solution sol;
    EXPECT_EQ(sol.dayOfTheWeek(15, 8, 1993), "Sunday");
}
