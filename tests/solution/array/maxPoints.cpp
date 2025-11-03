#include "gtest/gtest.h"
#include "solution.hpp"

TEST(maxPoints, example1) {
    Solution sol;
    std::vector<std::vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    EXPECT_EQ(sol.maxPoints(points), 3);
}

TEST(maxPoints, example2) {
    Solution sol;
    std::vector<std::vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    EXPECT_EQ(sol.maxPoints(points), 4);
}
