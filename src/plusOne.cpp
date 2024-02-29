#include "solution.h"

std::vector<int> Solution::plusOne(std::vector<int> &digits) {
  for (auto it = digits.rbegin(), it_end = digits.rend(); it != it_end; ++it) {
    if (*it == 9)
      *it = 0;
    else {
      ++*it;
      break;
    }
  }

  if (digits[0] == 0)
    digits.emplace(digits.begin(), 1);

  return digits;
}
