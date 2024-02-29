#include "solution.h"

int Solution::maxSubarraySumCircular(std::vector<int> &nums) {
  int min = nums[0];
  int max = nums[0];
  int cur_min = 0;
  int cur_max = 0;
  auto sum = std::accumulate(nums.begin(), nums.end(), 0, [&](auto a, auto b) {
    cur_max = std::max(b, cur_max + b);
    cur_min = std::min(b, cur_min + b);
    max = std::max(cur_max, max);
    min = std::min(cur_min, min);
    return a + b;
  });

  if (min == sum) {
    return max;
  } else {
    return std::max(max, sum - min);
  }
}
