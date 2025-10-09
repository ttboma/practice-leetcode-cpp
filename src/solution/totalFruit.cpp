#include "solution/solution.hpp"

int Solution::totalFruit(std::vector<int> &fruits) {
    if (fruits.size() < 3) {
        return fruits.size();
    }
    auto i = 1;
    while (i != fruits.size() && fruits[i] == fruits[0]) {
        ++i;
    }
    if (i == fruits.size()) {
        return i;
    }
    int bucket[2] = {fruits[0], fruits[i++]};
    auto max = i;
    auto cur_max = i;
    auto conseq = 1;
    for (auto idx = i; idx != fruits.size(); ++idx) {
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
