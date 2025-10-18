#include "solution.hpp"

/// # 69. Sqrt(x)
///
/// <https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// Given a non-negative integer <code>x</code>, return the square root of <code>x</code> rounded down to the nearest
/// integer. The returned integer should be **non-negative**  as well.
///
/// You **must not use**  any built-in exponent function or operator.
///
/// - For example, do not use <code>pow(x, 0.5)</code> in c++ or <code>x ** 0.5</code> in python.
///
/// **Example 1:**
///
/// ```
/// Input: x = 4
/// Output: 2
/// Explanation: The square root of 4 is 2, so we return 2.
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: x = 8
/// Output: 2
/// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
/// ```
///
/// **Constraints:**
///
/// - <code>0 <= x <= 2^31 - 1</code>
int Solution::mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int first{1}, last{x / 2 + 1};
    int count = last - first;
    int step{}, it{};

    while (count > 0) {
        it = first;
        step = count / 2;
        it += step;

        if (!(x / it < it)) {
            first = ++it;
            count -= 1 + step;
        } else {
            count = step;
        }
    }

    return --it;
}
