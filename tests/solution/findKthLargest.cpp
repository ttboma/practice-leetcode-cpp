#include <gtest/gtest.h>

#include "solution.hpp"

TEST(findKthLargest, example1) {
    auto nums = std::vector<int>{3, 2, 1, 5, 6, 4};
    EXPECT_EQ(Solution{}.findKthLargest(nums, 2), 5);
}

TEST(findKthLargest, example2) {
    auto nums = std::vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6};
    EXPECT_EQ(Solution{}.findKthLargest(nums, 4), 4);
}
