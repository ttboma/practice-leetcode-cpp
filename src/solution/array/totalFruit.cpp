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
    auto max = static_cast<int>(i);
    auto cur_max = static_cast<int>(i);
    auto conseq = 1;
    for (std::size_t idx = i; idx != fruits.size(); ++idx) {
        if (bucket[1] == fruits[idx]) {
            cur_max = cur_max + 1;
            conseq = conseq + 1;
        } else if (bucket[0] == fruits[idx]) {
            cur_max = cur_max + 1;
            conseq = 1;
            bucket[0] = bucket[1];
            bucket[1] = fruits[idx];
        } else {
            max = std::max(max, cur_max);
            bucket[0] = bucket[1];
            bucket[1] = fruits[idx];
            cur_max = conseq + 1;
            conseq = 1;
        }
    }
    return std::max(max, cur_max);
}
