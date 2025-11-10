#include "solution.hpp"

/// # 3542. Minimum Operations to Convert All Elements to Zero
///
/// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10
///
/// You are given an array <code>nums</code> of size <code>n</code>, consisting of **non-negative**  integers. Your task
/// is to apply some (possibly zero) operations on the array so that **all**  elements become 0.
///
/// In one operation, you can select a <button type="button" aria-haspopup="dialog" aria-expanded="false"
/// aria-controls="radix-:r1q:" data-state="closed" class="">subarray</button> <code>[i, j]</code> (where <code>0 <= i
/// <= j < n</code>) and set all occurrences of the **minimum**  **non-negative**  integer in that subarray to 0.
///
/// Return the **minimum**  number of operations required to make all elements in the array 0.
///
/// **Example 1:**
///
/// <div class="example-block">
/// Input: nums = [0,2]
///
/// Output: 1
///
/// Explanation:
///
/// - Select the subarray <code>[1,1]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2.
/// Setting all occurrences of 2 to 0 results in <code>[0,0]</code>.
/// - Thus, the minimum number of operations required is 1.
///
/// **Example 2:**
///
/// <div class="example-block">
/// Input: nums = [3,1,2,1]
///
/// Output: 3
///
/// Explanation:
///
/// - Select subarray <code>[1,3]</code> (which is <code>[1,2,1]</code>), where the minimum non-negative integer is 1.
/// Setting all occurrences of 1 to 0 results in <code>[3,0,2,0]</code>.
/// - Select subarray <code>[2,2]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2.
/// Setting all occurrences of 2 to 0 results in <code>[3,0,0,0]</code>.
/// - Select subarray <code>[0,0]</code> (which is <code>[3]</code>), where the minimum non-negative integer is 3.
/// Setting all occurrences of 3 to 0 results in <code>[0,0,0,0]</code>.
/// - Thus, the minimum number of operations required is 3.
///
/// **Example 3:**
///
/// <div class="example-block">
/// Input: nums = [1,2,1,2,1,2]
///
/// Output: 4
///
/// Explanation:
///
/// - Select subarray <code>[0,5]</code> (which is <code>[1,2,1,2,1,2]</code>), where the minimum non-negative integer
/// is 1. Setting all occurrences of 1 to 0 results in <code>[0,2,0,2,0,2]</code>.
/// - Select subarray <code>[1,1]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2.
/// Setting all occurrences of 2 to 0 results in <code>[0,0,0,2,0,2]</code>.
/// - Select subarray <code>[3,3]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2.
/// Setting all occurrences of 2 to 0 results in <code>[0,0,0,0,0,2]</code>.
/// - Select subarray <code>[5,5]</code> (which is <code>[2]</code>), where the minimum non-negative integer is 2.
/// Setting all occurrences of 2 to 0 results in <code>[0,0,0,0,0,0]</code>.
/// - Thus, the minimum number of operations required is 4.
///
/// **Constraints:**
///
/// - <code>1 <= n == nums.length <= 10^5</code>
/// - <code>0 <= nums[i] <= 10^5</code>
int Solution::minOperations(std::vector<int>& nums) {
    std::vector<int> stack;
    int res = 0;
    for (int num : nums) {
        while (!stack.empty() && stack.back() > num)
            stack.pop_back();

        if (num == 0)
            continue;
        if (stack.empty() || stack.back() < num) {
            res++;
            stack.push_back(num);
        }
    }
    return res;
}
