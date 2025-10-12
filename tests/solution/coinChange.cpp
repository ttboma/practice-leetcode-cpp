#include "gtest/gtest.h"
#include "solution/solution.hpp"

TEST(coinChange, example1) {
    Solution sol;
    std::vector<int> coins{1, 2, 5};
    int amount = 11;
    int expected = 3;
    EXPECT_EQ(sol.coinChange(coins, amount), expected);
}

TEST(coinChange, example2) {
    Solution sol;
    std::vector<int> coins{2};
    int amount = 3;
    int expected = -1;
    EXPECT_EQ(sol.coinChange(coins, amount), expected);
}

TEST(coinChange, example3) {
    Solution sol;
    std::vector<int> coins{1};
    int amount = 0;
    int expected = 0;
    EXPECT_EQ(sol.coinChange(coins, amount), expected);
}
