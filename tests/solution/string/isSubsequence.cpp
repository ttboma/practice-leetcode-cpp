#include <gtest/gtest.h>

#include "solution.hpp"

TEST(isSubsequence, example1) {
    std::string s = "abc", t = "ahbgdc";
    EXPECT_EQ(Solution{}.isSubsequence(std::move(s), std::move(t)), true);
}

TEST(isSubsequence, example2) {
    std::string s = "axc", t = "ahbgdc";
    EXPECT_EQ(Solution{}.isSubsequence(std::move(s), std::move(t)), false);
}
