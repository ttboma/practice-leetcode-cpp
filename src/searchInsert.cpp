#include "solution.h"

int Solution::searchInsert(std::vector<int> &nums, int target) {
  auto i = std::vector<int>::size_type(0);
  auto j = nums.size();

  for (std::vector<int>::size_type k = (i + j) / 2; i != j; k = (i + j) / 2) {
    if (target == nums[k]) {
      return static_cast<int>(k);
    } else if (target < nums[k]) {
      j = k;
    } else // ( nums[k] < target )
    {
      i = k + 1;
    }
  }

  return static_cast<int>(i);
}
