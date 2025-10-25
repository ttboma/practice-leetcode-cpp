#include "solution.hpp"

int Solution::totalFruit(std::vector<int>& fruits) {
    if (fruits.size() < 3) {
        return static_cast<int>(fruits.size());
    }
    std::size_t i = 1;
    while (i != fruits.size() && fruits[i] == fruits[0]) {
        ++i;
    }
    if (i == fruits.size()) {
        return static_cast<int>(i);
    }
    int bucket[2] = {fruits[0], fruits[i++]};
    auto maxVal = static_cast<int>(i);
    auto curMax = static_cast<int>(i);
    auto conseq = 1;
    for (std::size_t idx = i; idx != fruits.size(); ++idx) {
        if (bucket[1] == fruits[idx]) {
            curMax = curMax + 1;
            conseq = conseq + 1;
        } else if (bucket[0] == fruits[idx]) {
            curMax = curMax + 1;
            conseq = 1;
            bucket[0] = bucket[1];
            bucket[1] = fruits[idx];
        } else {
            maxVal = std::max(maxVal, curMax);
            bucket[0] = bucket[1];
            bucket[1] = fruits[idx];
            curMax = conseq + 1;
            conseq = 1;
        }
    }
    return std::max(maxVal, curMax);
}
