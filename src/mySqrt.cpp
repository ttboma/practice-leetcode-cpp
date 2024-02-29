#include "solution.h"

int Solution::mySqrt(int x) {
  if (x == 0 || x == 1)
    return x;

  int i = 1, j = x / 2 + 1;
  while (i != j) {
    int k = (i + j) / 2;
    int t = x / k;
    if (k == t)
      return k;
    else if (k < t)
      i = k + 1;
    else
      j = k;
  }
  return (i - 1);
}
