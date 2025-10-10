#include "solution/solution.hpp"

/// # 198. House Robber
///
/// https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
/// stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems
/// connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same
/// night</b>.
///
/// Given an integer array <code>nums</code> representing the amount of money of each house, return the maximum amount
/// of money you can rob tonight <b>without alerting the police</b>.
///
/// **Example 1:**
///
/// ```
/// Input: nums = [1,2,3,1]
/// Output: 4
/// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
/// Total amount you can rob = 1 + 3 = 4.
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: nums = [2,7,9,3,1]
/// Output: 12
/// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
/// Total amount you can rob = 2 + 9 + 1 = 12.
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= nums.length <= 100</code>
/// - <code>0 <= nums[i] <= 400</code>
int Solution::rob(std::vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    } else if (nums.size() == 2) {
        return std::max(nums[0], nums[1]);
    }

    int cache[] = {nums[0], std::max(nums[0], nums[1])};
    int i = 2;

    for (; i != nums.size(); ++i) {
        int a = nums[i] + cache[i % 2];
        int b = cache[(i + 1) % 2];
        cache[i % 2] = std::max(a, b);
    }

    return cache[(i + 1) % 2];
}
