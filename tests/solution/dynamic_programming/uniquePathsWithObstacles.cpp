#include <gtest/gtest.h>

#include "solution.hpp"

TEST(UniquePathsWithObstacles, Example1) {
    auto sol = Solution();
    auto obstacleGrid = std::vector<std::vector<int>>{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    auto const result = sol.uniquePathsWithObstacles(obstacleGrid);
    auto const expected = 2;
    EXPECT_EQ(result, expected);
}

TEST(UniquePathsWithObstacles, Example2) {
    auto sol = Solution();
    auto obstacleGrid = std::vector<std::vector<int>>{{0, 1}, {0, 0}};
    auto const result = sol.uniquePathsWithObstacles(obstacleGrid);
    auto const expected = 1;
    EXPECT_EQ(result, expected);
}
