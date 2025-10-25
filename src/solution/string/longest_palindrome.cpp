#include "solution.hpp"

// This is an implementation of
// [Manacher's
// Algorithm](https://medium.com/hoskiss-stand/manacher-299cf75db97e)
//
// For i = 0..(s.size()*2 + 1),
// s'[i] := '_'   , if i is even
// s'[i] := s[i/2], if is odd
std::string ManachersAlgorithm(std::string s) {
    if (s.size() <= 1)
        return s;
    if (s.size() == 2) {
        if (s[0] == s[1])
            return s;
        else
            return s.substr(0, 1);
    }

    auto LPS = std::vector<std::size_t>(s.size() * 2 + 1, 0);

    for (std::size_t c = 0; c != s.size() * 2;) {
        // compute LPS[c]
        auto i = c + LPS[c];
        auto j = c - LPS[c];
        while (j-- != 0 && ++i != LPS.size() && (!(i % 2) || s[i / 2] == s[j / 2])  // s'[i] == s'[j]
        )
            ++LPS[c];

        // fast forward to the next LPS[c'] that needed to be computed
        if (LPS[c] == 0) {
            ++c;
        } else {
            std::size_t r = 1;
            while (r < LPS[c]) {
                auto cr = c + r;
                auto cl = c - r;
                auto x = LPS[c] - r;
                LPS[cr] = std::min(x, LPS[cl]);

                if (LPS[cl] == x) {  // LPS[cl] might be longer
                    break;
                }
                ++r;
            }
            c += r;
        }
    }
    // Get the index of the greatest value in LPS
    auto it = std::max_element(LPS.begin(), LPS.end());
    int center = std::distance(LPS.begin(), it);

    // s'[(center-LPS[center])..=(center+LPS[center])]
    auto pos = center - LPS[center];
    auto len = (LPS[center] * 2 + 1) / 2 + (pos % 2);
    return s.substr(pos / 2, len);
}

std::string longestPalindromeDp(std::string s) {
    std::size_t start = 0;
    std::size_t maxLen = 1;
    std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

    for (std::size_t i = 0; i < s.size(); ++i) {
        dp[i][i] = true;
    }
    for (std::size_t d = 1; d != s.size(); ++d) {
        for (std::size_t i = 0; i + d < s.size(); ++i) {
            std::size_t j = i + d;
            if (s[i] == s[j] && (d <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxLen);
}

/// # 5. Longest Palindromic Substring
///
/// <https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// Given a string <code>s</code>, return the longest <button type="button" aria-haspopup="dialog" aria-expanded="false"
/// aria-controls="radix-:r1u:" data-state="closed" class="">palindromic</button> <button type="button"
/// aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-:r1v:" data-state="closed"
/// class="">substring</button> in <code>s</code>.
///
/// **Example 1:**
///
/// ```
/// Input: s = "babad"
/// Output: "bab"
/// Explanation: "aba" is also a valid answer.
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: s = "cbbd"
/// Output: "bb"
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= s.length <= 1000</code>
/// - <code>s</code> consist of only digits and English letters.
std::string Solution::longestPalindrome(std::string s) {
    return longestPalindromeDp(s);
}
