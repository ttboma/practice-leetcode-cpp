#include "solution.hpp"

/// # 70. Climbing Stairs
///
/// <https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// You are climbing a staircase. It takes <code>n</code> steps to reach the top.
///
/// Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to
/// the top?
///
/// **Example 1:**
///
/// ```
/// Input: n = 2
/// Output: 2
/// Explanation: There are two ways to climb to the top.
/// 1. 1 step + 1 step
/// 2. 2 steps
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: n = 3
/// Output: 3
/// Explanation: There are three ways to climb to the top.
/// 1. 1 step + 1 step + 1 step
/// 2. 1 step + 2 steps
/// 3. 2 steps + 1 step
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= n <= 45</code>
int Solution::climbStairs(int n) {
    int cache[] = {1, 1};
    for (std::size_t i = 2; i <= static_cast<std::size_t>(n); ++i) {
        cache[i % 2] = cache[0] + cache[1];
    }
    return cache[n % 2];
}
