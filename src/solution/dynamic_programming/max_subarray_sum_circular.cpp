#include "solution.hpp"

int Solution::maxSubarraySumCircular(std::vector<int>& nums) {
    int min = nums[0];
    int max = nums[0];
    int curMin = 0;
    int curMax = 0;
    auto sum = std::accumulate(nums.begin(), nums.end(), 0, [&](auto a, auto b) {
        curMax = std::max(b, curMax + b);
        curMin = std::min(b, curMin + b);
        max = std::max(curMax, max);
        min = std::min(curMin, min);
        return a + b;
    });

    if (min == sum) {
        return max;
    } else {
        return std::max(max, sum - min);
    }
}
