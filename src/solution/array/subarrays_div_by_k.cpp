#include "solution.hpp"

int Solution::subarraysDivByK(std::vector<int>& nums, int k) {
    auto count = 0;
    auto prevNum = 0;
    auto modGroup = std::vector<int>(k);
    modGroup[0] = 1;

    for (std::vector<int>::size_type i = 0; i != nums.size(); ++i) {
        prevNum = (prevNum + nums[i] % k + k) % k;
        count += modGroup[prevNum]++;
    }

    return count;
}
