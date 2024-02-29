#include "solution.h"

void Solution::reverseString(std::vector<char> &s) {
  for (std::vector<char>::size_type i = 0, i_end = s.size() / 2,
                                    j = s.size() - 1;
       i != i_end; ++i) {
    std::swap(s[i], s[j - i]);
  }
}
