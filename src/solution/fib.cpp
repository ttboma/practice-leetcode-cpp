#include "solution.h"

/// # 509. Fibonacci Number
///
/// <https://leetcode.com/problems/fibonacci-number/>
///
/// The <b>Fibonacci numbers</b>, commonly denoted `F(n)` form a sequence, called the <b>Fibonacci sequence</b>, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,
///
/// ```
/// F(0) = 0, F(1) = 1
/// F(n) = F(n - 1) + F(n - 2), for n > 1.
/// ```
///
/// Given `n`, calculate `F(n)`.
///
/// **Example 1:**
///
/// ```txt
/// Input: n = 2
/// Output: 1
/// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
/// ```
///
/// **Example 2:**
///
/// ```txt
/// Input: n = 3
/// Output: 2
/// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
/// ```
///
/// **Example 3:**
///
/// ```txt
/// Input: n = 4
/// Output: 3
/// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
/// ```
///
/// **Constraints:**
///
/// - `0 <= n <= 30`
int Solution::fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  int state[2] = {0, 1};
  for (int i = 0; i != n - 2; ++i) {
    int tmp = state[0] + state[1];
    state[0] = state[1];
    state[1] = tmp;
  }
  return state[0] + state[1];
}
