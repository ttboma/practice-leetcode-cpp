#include "gtest/gtest.h"
#include "solution.hpp"

TEST(LongestPalindrome, example1) {
    Solution solution;
    EXPECT_EQ(solution.longestPalindrome("babad"), "bab");
}

TEST(LongestPalindrome, example2) {
    Solution solution;
    EXPECT_EQ(solution.longestPalindrome("cbbd"), "bb");
}
