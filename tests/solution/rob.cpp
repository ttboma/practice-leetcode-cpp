#include "gtest/gtest.h"
#include "solution.hpp"

TEST(rob, example1) {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3, 1};
    EXPECT_EQ(solution.rob(nums1), 4);
}

TEST(rob, example2) {
    Solution solution;
    std::vector<int> nums2 = {2, 7, 9, 3, 1};
    EXPECT_EQ(solution.rob(nums2), 12);
}

TEST(rob, example3) {
    Solution solution;
    std::vector<int> nums2 = {2, 1, 1, 2};
    EXPECT_EQ(solution.rob(nums2), 4);
}
