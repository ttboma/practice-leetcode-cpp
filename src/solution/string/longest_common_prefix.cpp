#include "solution.hpp"

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs) {
    std::string ret;

    if (strs.empty())
        return "";

    for (std::size_t j = 0, jEnd = strs[0].size(); j != jEnd; ++j) {
        for (std::size_t i = 1, iEnd = strs.size(); i != iEnd; ++i) {
            if (strs[i][j] != strs[0][j])
                return ret;
        }
        ret += strs[0][j];
    }

    return ret;
}
