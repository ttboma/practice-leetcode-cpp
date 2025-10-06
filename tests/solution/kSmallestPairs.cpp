#include <gtest/gtest.h>

#include "solution.hpp"

TEST(kSmallestPairs, example1) {
    std::vector<int> nums1 = {1, 7, 11};
    std::vector<int> nums2 = {2, 4, 6};
    int k = 3;
    std::vector<std::vector<int>> expected = {{1, 2}, {1, 4}, {1, 6}};
    EXPECT_EQ(Solution{}.kSmallestPairs(nums1, nums2, k), expected);
}

TEST(kSmallestPairs, example2) {
    std::vector<int> nums1 = {1, 1, 2};
    std::vector<int> nums2 = {1, 2, 3};
    int k = 2;
    std::vector<std::vector<int>> expected = {{1, 1}, {1, 1}};
    EXPECT_EQ(Solution{}.kSmallestPairs(nums1, nums2, k), expected);
}
