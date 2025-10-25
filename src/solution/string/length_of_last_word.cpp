#include "solution.hpp"

int Solution::lengthOfLastWord(std::string s) {
    int gmax = 0;
    int lmax = 0;
    for (std::string::size_type i = 0, iEnd = s.size(); i != iEnd; ++i) {
        if (s[i] != ' ') {
            ++lmax;
        } else {
            if (lmax != 0)
                gmax = lmax;
            lmax = 0;
        }
    }
    return (lmax) ? lmax : gmax;
}
