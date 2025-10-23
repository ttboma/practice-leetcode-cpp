#include <gtest/gtest.h>

#include "solution.hpp"

TEST(merge, example1) {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(nums1, std::vector<int>({1, 2, 2, 3, 5, 6}));
}

TEST(merge, example2) {
    std::vector<int> nums1 = {1};
    int m = 1;
    std::vector<int> nums2 = {};
    int n = 0;
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(nums1, std::vector<int>({1}));
}

TEST(merge, example3) {
    std::vector<int> nums1 = {0};
    int m = 0;
    std::vector<int> nums2 = {1};
    int n = 1;
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(nums1, std::vector<int>({1}));
}

TEST(merge, example4) {
    std::vector<int> nums1 = {1, 0};
    int m = 1;
    std::vector<int> nums2 = {2};
    int n = 1;
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(nums1, std::vector<int>({1, 2}));
}

TEST(merge, example5) {
    std::vector<int> nums1 = {2, 0};
    int m = 1;
    std::vector<int> nums2 = {1};
    int n = 1;
    Solution{}.merge(nums1, m, nums2, n);
    EXPECT_EQ(nums1, std::vector<int>({1, 2}));
}
