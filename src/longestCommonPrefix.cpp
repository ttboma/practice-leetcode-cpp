#include "solution.h"

std::string Solution::longestCommonPrefix(std::vector<std::string> &strs) {
  std::string ret;

  if (strs.empty())
    return "";

  for (std::size_t j = 0, j_end = strs[0].size(); j != j_end; ++j) {
    for (std::size_t i = 1, i_end = strs.size(); i != i_end; ++i) {
      if (strs[i][j] != strs[0][j])
        return ret;
    }
    ret += strs[0][j];
  }

  return ret;
}
