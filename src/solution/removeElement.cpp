#include "solution.h"

int Solution::removeElement(std::vector<int> &nums, int val) {
  auto k = nums.size();

  for (std::vector<int>::size_type i = 0; i < k; ++i) {
    if (nums[i] == val) {
      while (k != i && nums[--k] == val)
        ;
      nums[i] = nums[k];
    }
  }

  return static_cast<int>(k);
}
