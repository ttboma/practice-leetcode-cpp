#include "solution.hpp"

int Solution::minFlipsMonoIncr(std::string s) {
    if (s.size() < 2)
        return 0;

    int minFlip = 0;
    int numOne = (s[0] == '1') ? 1 : 0;
    for (std::string::size_type i = 1, iEnd = s.size(); i != iEnd; ++i) {
        if (s[i] == '1') {
            ++numOne;
        } else {
            minFlip = std::min(numOne, minFlip + 1);
        }
    }

    return minFlip;
}
