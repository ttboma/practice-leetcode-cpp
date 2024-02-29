#include "solution.h"

int Solution::lengthOfLongestSubstring(std::string s) {
  if (s.size() < 2)
    return static_cast<int>(s.size());

  // The max sliding window [i, i +j)
  auto max_sw = std::pair<std::size_t, std::size_t>{0, 1};

  // The current sliding window [i, j)
  auto cur_sw = std::pair<std::size_t, std::size_t>{0, 1};

  // The `char` denotes an existing character in the current sliding window.
  // The `std::size_t` denotes the index of the existing character in the string
  // 's'.
  auto dict = std::map<char, std::size_t>{{s[0], 0}};

  for (; cur_sw.second != s.size(); ++cur_sw.second) {
    auto iter = dict.find(s[cur_sw.second]);

    // If the key is found, ...
    if (iter != dict.end()) {
      if (iter->second >= cur_sw.first) {
        auto m = cur_sw.second - cur_sw.first;
        if (m > max_sw.second) {
          max_sw.first = cur_sw.first;
          max_sw.second = m;
        }
        cur_sw.first = iter->second + 1;
      }
    }

    dict.insert_or_assign(iter, s[cur_sw.second], cur_sw.second);
    // dict[ s[cur_sw.second] ] = cur_sw.second;
  }

  return static_cast<int>(
      std::max(max_sw.second, cur_sw.second - cur_sw.first));
}
