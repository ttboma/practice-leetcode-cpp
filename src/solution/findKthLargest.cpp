#include <iostream>

#include "solution.hpp"

/// # 215. Kth Largest Element in an Array
///
/// <https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// Given an integer array <code>nums</code> and an integer <code>k</code>, return the <code>k^th</code> largest element
/// in the array.
///
/// Note that it is the <code>k^th</code> largest element in the sorted order, not the <code>k^th</code> distinct
/// element.
///
/// Can you solve it without sorting?
///
/// **Example 1:**
///
/// ```
/// Input: nums = [3,2,1,5,6,4], k = 2
/// Output: 5
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
/// Output: 4
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= k <= nums.length <= 10^5</code>
/// - <code>-10^4 <= nums[i] <= 10^4</code>
int findKthLargest_helper(std::vector<int>::iterator first, std::vector<int>::iterator last, int i) {
    if (i == 0) {
        return *std::max_element(first, last);
    }

    auto pivot = *std::next(first, std::distance(first, last) / 2);

    auto middle1 = std::partition(first, last, [&](const auto& e) { return e > pivot; });

    if (i < std::distance(first, middle1)) {
        return findKthLargest_helper(first, middle1, i);
    }

    auto middle2 = std::partition(first, last, [&](const auto& e) { return !(e < pivot); });

    if (auto d = std::distance(first, middle2); i < d) {
        return *middle1;
    } else {
        return findKthLargest_helper(middle2, last, i - d);
    }
}

int Solution::findKthLargest(std::vector<int>& nums, int k) {
    return findKthLargest_helper(nums.begin(), nums.end(), k - 1);
}
