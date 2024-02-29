#include "solution.h"

template <typename T>
using Vec = std::vector<T>;

int Solution::subarraysDivByK(Vec<int>& nums, int k) {
  auto count = 0;
  auto prev_num = 0;
  auto mod_group = Vec<int>(k);
  mod_group[0] = 1;

  for (Vec<int>::size_type i = 0; i != nums.size(); ++i) {
    prev_num = (prev_num + nums[i] % k + k) % k;
    count += mod_group[prev_num]++;
  }

  return count;
}
