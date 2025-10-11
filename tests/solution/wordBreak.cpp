#include "gtest/gtest.h"
#include "solution/solution.hpp"

using namespace std;

TEST(wordBreak, example1) {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    EXPECT_TRUE(solution.wordBreak(s, wordDict));
}

TEST(wordBreak, example2) {
    Solution solution;
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    EXPECT_TRUE(solution.wordBreak(s, wordDict));
}

TEST(wordBreak, example3) {
    Solution solution;
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    EXPECT_FALSE(solution.wordBreak(s, wordDict));
}

TEST(wordBreak, example4) {
    Solution solution;
    string s =
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                               "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    EXPECT_FALSE(solution.wordBreak(s, wordDict));
}
