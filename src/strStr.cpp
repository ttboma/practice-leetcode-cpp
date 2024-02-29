#include "solution.h"

// KMP (Knuth-Morris-Pratt) algorithm
std::vector<std::string::size_type> kmp(const std::string &p) {
  if (p.size() == 0)
    return std::vector<std::string::size_type>{};

  auto r = std::vector<std::string::size_type>{0};
  for (std::string::size_type i = 1, i_end = p.size(); i != i_end; ++i) {
    for (auto k = r[i - 1]; true; k = r[k - 1]) {
      if (p[k] == p[i]) {
        r.push_back(k + 1);
        break;
      } else if (k == 0) {
        r.push_back(0);
        break;
      }
    }
  }
  return r;
}

int Solution::strStr(std::string haystack, std::string needle) {
  // Longest Proper Prefix Which Is Also Suffix Problem by KMP algorithm
  auto lps = kmp(needle); 

  for (std::string::size_type i = 0, j = 0; i != haystack.size();) {
    if (haystack[i] != needle[j])
      if (j == 0)
        ++i;
      else
        j = lps[j - 1];
    else {
      ++i;
      if (++j == needle.size())
        return static_cast<int>(i - j);
    }
  }
  return -1;
}
