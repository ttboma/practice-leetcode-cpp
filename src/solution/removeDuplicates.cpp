#include "solution.h"

int Solution::removeDuplicates(std::vector<int> &nums) {
  if (nums.size() == 0) {
    return 0;
  }

  auto k = std::vector<int>::size_type(0);
  for (std::vector<int>::size_type i = 0, i_end = nums.size(); ++i != i_end;) {
    if (nums[k] != nums[i]) {
      nums[++k] = nums[i];
    }
  }
  return static_cast<int>(k + 1);
}
