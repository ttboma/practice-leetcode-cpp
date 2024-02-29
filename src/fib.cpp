#include "solution.h"

int Solution::fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  int state[2] = {0, 1};
  for (int i = 0; i != n - 2; ++i) {
    int tmp = state[0] + state[1];
    state[0] = state[1];
    state[1] = tmp;
  }
  return state[0] + state[1];
}
