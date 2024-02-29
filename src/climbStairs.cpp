#include "solution.h"

int Solution::climbStairs(int n) {
  if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else if (n == 3)
    return 3;

  auto r = std::vector<int>{1, 2, 3};
  for (; 3 < n; n -= 3) {
    r[0] = r[1] + r[2];
    r[1] = r[2] + r[0];
    r[2] = r[0] + r[1];
  }

  return r[static_cast<std::vector<int>::size_type>(n) - 1];
}
