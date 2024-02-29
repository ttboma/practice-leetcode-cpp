#include "solution.h"

bool Solution::isPalindrome(int x) {
  if (x == 0)
    return true;
  if (x < 0 || x % 10 == 0)
    return false;

  int reverse_x = 0;

  while (x > reverse_x) {
    reverse_x = reverse_x * 10 + x % 10;
    x /= 10;
  }

  return x == reverse_x or x == reverse_x / 10;
}
