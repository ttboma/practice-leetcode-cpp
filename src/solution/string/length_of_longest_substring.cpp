#include "solution.hpp"

int Solution::lengthOfLongestSubstring(std::string s) {
    if (s.size() < 2)
        return static_cast<int>(s.size());

    // The max sliding window [i, i +j)
    auto maxSw = std::pair<std::size_t, std::size_t>{0, 1};

    // The current sliding window [i, j)
    auto curSw = std::pair<std::size_t, std::size_t>{0, 1};

    // The `char` denotes an existing character in the current sliding window.
    // The `std::size_t` denotes the index of the existing character in the string
    // 's'.
    auto dict = std::map<char, std::size_t>{{s[0], 0}};

    for (; curSw.second != s.size(); ++curSw.second) {
        auto iter = dict.find(s[curSw.second]);

        // If the key is found, ...
        if (iter != dict.end()) {
            if (iter->second >= curSw.first) {
                auto m = curSw.second - curSw.first;
                if (m > maxSw.second) {
                    maxSw.first = curSw.first;
                    maxSw.second = m;
                }
                curSw.first = iter->second + 1;
            }
        }

        dict.insert_or_assign(iter, s[curSw.second], curSw.second);
        // dict[ s[curSw.second] ] = curSw.second;
    }

    return static_cast<int>(std::max(maxSw.second, curSw.second - curSw.first));
}
