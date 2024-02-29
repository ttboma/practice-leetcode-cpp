#include "solution.h"

int Solution::maxSubArray(std::vector<int> &nums) {
  int max = nums[0];
  int pre = nums[0];
  for (std::vector<int>::size_type i = 1, i_end = nums.size(); i != i_end;
       ++i) {
    int s = nums[i] + pre;
    int cur = (nums[i] < s) ? s : nums[i];
    if (max < cur)
      max = cur;
    pre = cur;
  }

  return max;
}
