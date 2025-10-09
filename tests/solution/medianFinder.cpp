#include "gtest/gtest.h"
#include "solution/solution.hpp"

TEST(MedianFinderTest, BasicFunctionality) {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    EXPECT_DOUBLE_EQ(mf.findMedian(), 1.5);
    mf.addNum(3);
    EXPECT_DOUBLE_EQ(mf.findMedian(), 2.0);
}
