#include <algorithm>
#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
#include <nlohmann/json.hpp>
#include <solution.hpp>
#include <sstream>

namespace po = boost::program_options;

// Overload operator<< for std::pair<T,T>
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// Overload operator<< for std::vector<T>
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    if (vec.empty()) {
        return os << "[]";
    }
    os << "[" << vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        os << ", " << vec[i];
    }
    os << "]";
    return os;
}

const auto HELP_MSG = "Usage: solution <COMMAND>\n\nCommands:";

int main(int argc, char* argv[]) {
    po::options_description desc(HELP_MSG);

    // NOTE:
    //  Keep the options aligned for better readability, keep the clang-format off/on tags to avoid reformatting
    //  by clang-format
    // clang-format off
    desc.add_options()
        ("help"                , "Print this message or the help of the given subcommand(s)")
        ("fib"                 , "[509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)")
        ("isSubsequence"       , "[392. Is Subsequence](https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("merge"               , "[88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("findKthLargest"      , "[215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1783751282/?envType=study-plan-v2&envId=top-interview-150)")
        ("kSmallestPairs"      , "[373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("findMaximizedCapital", "[502. IPO](https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("climbStairs"         , "[70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("rob"                 , "[198. House Robber](https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("wordBreak"           , "[139. Word Break](https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("coinChange"          , "[322. Coin Change](https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150)")
    ;
    // clang-format on

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    nlohmann::json j;
    std::cin >> j;  // reads JSON directly from stdin
    if (vm.count("fib")) {
        int n = j["n"];
        std::cout << Solution{}.fib(n) << std::endl;
    } else if (vm.count("isSubsequence")) {
        auto s = j["s"].get<std::string>();
        auto t = j["t"].get<std::string>();
        std::cout << std::boolalpha << Solution{}.isSubsequence(s, t) << std::endl;
    } else if (vm.count("merge")) {
        auto nums1 = j["nums1"].get<std::vector<int>>();
        int m = j["m"];
        auto nums2 = j["nums2"].get<std::vector<int>>();
        int n = j["n"];
        Solution{}.merge(nums1, m, nums2, n);
        std::cout << nums1 << std::endl;
    } else if (vm.count("findKthLargest")) {
        auto nums = j["nums"].get<std::vector<int>>();
        int k = j["k"];
        std::cout << Solution{}.findKthLargest(nums, k) << std::endl;
    } else if (vm.count("kSmallestPairs")) {
        auto nums1 = j["nums1"].get<std::vector<int>>();
        auto nums2 = j["nums2"].get<std::vector<int>>();
        int k = j["k"];
        std::cout << Solution{}.kSmallestPairs(nums1, nums2, k) << std::endl;
    } else if (vm.count("findMaximizedCapital")) {
        int k = j["k"];
        int w = j["w"];
        auto profits = j["profits"].get<std::vector<int>>();
        auto capital = j["capital"].get<std::vector<int>>();
        std::cout << Solution{}.findMaximizedCapital(k, w, profits, capital) << std::endl;
    } else if (vm.count("climbStairs")) {
        int n = j["n"];
        std::cout << Solution{}.climbStairs(n) << std::endl;
    } else if (vm.count("rob")) {
        auto nums = j["nums"].get<std::vector<int>>();
        std::cout << Solution{}.rob(nums) << std::endl;
    } else if (vm.count("wordBreak")) {
        auto s = j["s"].get<std::string>();
        auto wordDict = j["wordDict"].get<std::vector<std::string>>();
        std::cout << std::boolalpha << Solution{}.wordBreak(s, wordDict) << std::endl;
    } else if (vm.count("coinChange")) {
        auto coins = j["coins"].get<std::vector<int>>();
        int amount = j["amount"];
        std::cout << Solution{}.coinChange(coins, amount) << std::endl;
    } else {
        return -1;
    }

    return 0;
}
