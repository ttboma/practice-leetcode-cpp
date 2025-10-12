#include "solution.hpp"

using namespace std;

struct wordBreakHelperRecur {
    const std::vector<std::string>& wordDict;
    std::vector<bool> visited;
    std::vector<bool> ret;

    wordBreakHelperRecur(const std::vector<std::string>& wd)
        : wordDict(wd), visited(wd.size(), false), ret(wd.size(), false) {
        visited[0] = true;
        ret[0] = true;
    }

    bool operator()(std::string::iterator first, std::string::iterator last) {
        if (auto idx = last - first; visited[idx]) {
            return ret[idx];
        }
        for (const auto& w : wordDict) {
            auto p = std::mismatch(first, last, w.begin());
            if (p.second == w.end() && (*this)(p.first, last)) {  // match
                return true;
            }
        }
        return false;
    }
};

bool wordBreakHelperDP(std::string s, const std::vector<std::string>& wordDict) {
    auto n = s.size();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (size_t i = 1; i <= n; ++i) {
        for (const auto& w : wordDict) {
            if (i >= w.size() && dp[i - w.size()] && std::equal(s.begin() + i - w.size(), s.begin() + i, w.begin())) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

/// # 139. Word Break
///
/// <https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, return <code>true</code> if
/// <code>s</code> can be segmented into a space-separated sequence of one or more dictionary words.
///
/// **Note**  that the same word in the dictionary may be reused multiple times in the segmentation.
///
/// **Example 1:**
///
/// ```
/// Input: s = "leetcode", wordDict = ["leet","code"]
/// Output: true
/// Explanation: Return true because "leetcode" can be segmented as "leet code".
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: s = "applepenapple", wordDict = ["apple","pen"]
/// Output: true
/// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
/// Note that you are allowed to reuse a dictionary word.
/// ```
///
/// **Example 3:**
///
/// ```
/// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
/// Output: false
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= s.length <= 300</code>
/// - <code>1 <= wordDict.length <= 1000</code>
/// - <code>1 <= wordDict[i].length <= 20</code>
/// - <code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.
/// - All the strings of <code>wordDict</code> are **unique** .
bool Solution::wordBreak(std::string s, std::vector<std::string>& wordDict) {
    return wordBreakHelperDP(std::move(s), wordDict);
}
