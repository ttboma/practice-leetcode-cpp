#include "gtest/gtest.h"
#include "solution.hpp"

TEST(maxProfit, example1) {
    Solution solution;
    std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int expected = 6;
    EXPECT_EQ(solution.maxProfit(2, prices), expected);
}

TEST(maxProfit, example2) {
    Solution solution;
    std::vector<int> prices = {1, 2, 3, 4, 5};
    int expected = 4;
    EXPECT_EQ(solution.maxProfit(2, prices), expected);
}

TEST(maxProfit, example3) {
    Solution solution;
    std::vector<int> prices = {7, 6, 4, 3, 1};
    int expected = 0;
    EXPECT_EQ(solution.maxProfit(2, prices), expected);
}
