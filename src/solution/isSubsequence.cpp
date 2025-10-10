#include "solution/solution.hpp"

/// # [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/description/)
///
/// Given two strings <code>s</code> and <code>t</code>, return <code>true</code> if <code>s</code> is a **subsequence**
/// of <code>t</code>, or <code>false</code> otherwise.
///
/// A **subsequence**  of a string is a new string that is formed from the original string by deleting some (can be
/// none) of the characters without disturbing the relative positions of the remaining characters. (i.e.,
/// <code>"ace"</code> is a subsequence of <code>"abcde"</code> while <code>"aec"</code> is not).
///
/// **Example 1:**
///
/// ```
/// Input: s = "abc", t = "ahbgdc"
/// Output: true
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: s = "axc", t = "ahbgdc"
/// Output: false
/// ```
///
/// **Constraints:**
///
/// - <code>0 <= s.length <= 100</code>
/// - <code>0 <= t.length <= 10^4</code>
/// - <code>s</code> and <code>t</code> consist only of lowercase English letters.
///
/// **Follow up:**  Suppose there are lots of incoming <code>s</code>, say <code>s<sub>1</sub>, s<sub>2</sub>, ...,
/// s<sub>k</sub></code> where <code>k >= 10^9</code>, and you want to check one by one to see if <code>t</code> has its
/// subsequence. In this scenario, how would you change your code?
bool Solution::isSubsequence(std::string s, std::string t) {
    if (s.empty()) {
        return true;
    }
    auto it = s.begin();
    for (auto m : t) {
        if (m == *it && ++it == s.end()) {
            return true;
        }
    }
    return false;
}
