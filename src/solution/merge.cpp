#include "solution/solution.hpp"

/// # 88. Merge Sorted Array
///
/// <https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// You are given two integer arrays <code>nums1</code> and <code>nums2</code>, sorted in **non-decreasing order** , and
/// two integers <code>m</code> and <code>n</code>, representing the number of elements in <code>nums1</code> and
/// <code>nums2</code> respectively.
///
/// **Merge**  <code>nums1</code> and <code>nums2</code> into a single array sorted in **non-decreasing order** .
///
/// The final sorted array should not be returned by the function, but instead be stored inside the array
/// <code>nums1</code>. To accommodate this, <code>nums1</code> has a length of <code>m + n</code>, where the first
/// <code>m</code> elements denote the elements that should be merged, and the last <code>n</code> elements are set to
/// <code>0</code> and should be ignored. <code>nums2</code> has a length of <code>n</code>.
///
/// **Example 1:**
///
/// ```
/// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
/// Output: [1,2,2,3,5,6]
/// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
/// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: nums1 = [1], m = 1, nums2 = [], n = 0
/// Output: [1]
/// Explanation: The arrays we are merging are [1] and [].
/// The result of the merge is [1].
/// ```
///
/// **Example 3:**
///
/// ```
/// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
/// Output: [1]
/// Explanation: The arrays we are merging are [] and [1].
/// The result of the merge is [1].
/// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in
/// nums1.
/// ```
///
/// **Constraints:**
///
/// - <code>nums1.length == m + n</code>
/// - <code>nums2.length == n</code>
/// - <code>0 <= m, n <= 200</code>
/// - <code>1 <= m + n <= 200</code>
/// - <code>-10^9 <= nums1[i], nums2[j] <= 10^9</code>
///
/// **Follow up: ** Can you come up with an algorithm that runs in <code>O(m + n)</code> time?
void Solution::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::vector<int>::size_type i = m + n;
    while (m != 0 || n != 0) {
        if (m == 0) {
            nums1[--i] = nums2[--n];
        } else if (n == 0) {
            nums1[--i] = nums1[--m];
        } else if (nums1[m - 1] < nums2[n - 1]) {
            nums1[--i] = nums2[--n];
        } else {
            nums1[--i] = nums1[--m];
        }
    }
}
