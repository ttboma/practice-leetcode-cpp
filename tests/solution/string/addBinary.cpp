#include <gtest/gtest.h>

#include "solution.hpp"

TEST(addBinary, example1) {
    EXPECT_EQ(Solution{}.addBinary("11", "1"), "100");
}

TEST(addBinary, example2) {
    EXPECT_EQ(Solution().addBinary("1010", "1011"), "10101");
}
