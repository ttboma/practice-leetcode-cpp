#include "solution.hpp"

/// # 1611. Minimum One Bit Operations to Make Integers Zero
///
/// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/?envType=daily-question&envId=2025-11-08
///
/// Given an integer <code>n</code>, you must transform it into <code>0</code> using the following operations any number
/// of times:
///
/// - Change the rightmost (<code>0^th</code>) bit in the binary representation of <code>n</code>.
/// - Change the <code>i^th</code> bit in the binary representation of <code>n</code> if the <code>(i-1)^th</code> bit
/// is set to <code>1</code> and the <code>(i-2)^th</code> through <code>0^th</code> bits are set to <code>0</code>.
///
/// Return the minimum number of operations to transform <code>n</code> into <code>0</code>.
///
/// **Example 1:**
///
/// ```
/// Input: n = 3
/// Output: 2
/// Explanation: The binary representation of 3 is "11".
/// "11" -> "01" with the 2^nd operation since the 0^th bit is 1.
/// "01" -> "00" with the 1^st operation.
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: n = 6
/// Output: 4
/// Explanation: The binary representation of 6 is "110".
/// "110" -> "010" with the 2^nd operation since the 1^st bit is 1 and 0^th through 0^th bits are 0.
/// "010" -> "011" with the 1^st operation.
/// "011" -> "001" with the 2^nd operation since the 0^th bit is 1.
/// "001" -> "000" with the 1^st operation.
/// ```
///
/// **Constraints:**
///
/// - <code>0 <= n <= 10^9</code>
int Solution::minimumOneBitOperations(int n) {
    if (n == 0)
        return 0;
    int msb = 31 - __builtin_clz(n);  // find most significant bit position
    return (1 << (msb + 1)) - 1 - minimumOneBitOperations(n ^ (1 << msb));
}
