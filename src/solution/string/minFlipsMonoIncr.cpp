#include "solution.hpp"

int Solution::minFlipsMonoIncr(std::string s) {
    if (s.size() < 2)
        return 0;

    int min_flip = 0;
    int num_one = (s[0] == '1') ? 1 : 0;
    for (std::string::size_type i = 1, i_end = s.size(); i != i_end; ++i) {
        if (s[i] == '1') {
            ++num_one;
        } else {
            min_flip = std::min(num_one, min_flip + 1);
        }
    }

    return min_flip;
}
