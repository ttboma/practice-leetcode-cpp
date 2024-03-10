#include "solution.h"

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
