#include "solution.h"

int Solution::lengthOfLastWord(std::string s) {
  int gmax = 0;
  int lmax = 0;
  for (std::string::size_type i = 0, i_end = s.size(); i != i_end; ++i) {
    if (s[i] != ' ') {
      ++lmax;
    } else {
      if (lmax != 0)
        gmax = lmax;
      lmax = 0;
    }
  }
  return (lmax) ? lmax : gmax;
}
