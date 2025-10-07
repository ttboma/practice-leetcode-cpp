#include <algorithm>
#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
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
        ("help"         , "Print this message or the help of the given subcommand(s)")
        ("fib"          , "[509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)")
        ("isSubsequence", "[392. Is Subsequence](https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("hasCycle"     , "[141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("merge"        , "[88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("findKthLargest", "[215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1783751282/?envType=study-plan-v2&envId=top-interview-150)")
        ("kSmallestPairs", "[373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150)")
        ("findMaximizedCapital", "[502. IPO](https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150)")
    ;
    // clang-format on

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("fib")) {
        int n;
        std::cin >> n;
        std::cout << Solution{}.fib(n) << std::endl;
    } else if (vm.count("isSubsequence")) {
        std::string s, t;
        std::cin >> s >> t;
        std::cout << std::boolalpha << Solution{}.isSubsequence(s, t) << std::endl;
    } else if (vm.count("hasCycle")) {
        std::cout << std::boolalpha << Solution{}.hasCycle(nullptr) << std::endl;
    } else if (vm.count("merge")) {
        std::vector<int> nums1, nums2;
        int m, n;
        std::string buffer;
        std::getline(std::cin, buffer);
        std::istringstream iss1(std::move(buffer));
        std::copy(std::istream_iterator<int>(iss1), std::istream_iterator<int>(), std::back_inserter(nums1));
        std::cin >> m;
        std::cin.ignore();  // Ignore the newline after m
        std::getline(std::cin, buffer);
        std::istringstream iss2(std::move(buffer));
        std::copy(std::istream_iterator<int>(iss2), std::istream_iterator<int>(), std::back_inserter(nums2));
        std::cin >> n;
        Solution{}.merge(nums1, m, nums2, n);
        std::ranges::copy(nums1, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    } else if (vm.count("findKthLargest")) {
        std::vector<int> nums;
        int k;
        std::string buffer;
        std::getline(std::cin, buffer);
        std::istringstream iss(std::move(buffer));
        std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(nums));
        std::cin >> k;
        std::cout << Solution{}.findKthLargest(nums, k) << std::endl;
    } else if (vm.count("kSmallestPairs")) {
        std::vector<int> nums1, nums2;
        int k;
        std::string buffer;
        std::getline(std::cin, buffer);
        std::istringstream iss1(std::move(buffer));
        std::copy(std::istream_iterator<int>(iss1), std::istream_iterator<int>(), std::back_inserter(nums1));
        std::getline(std::cin, buffer);
        std::istringstream iss2(std::move(buffer));
        std::copy(std::istream_iterator<int>(iss2), std::istream_iterator<int>(), std::back_inserter(nums2));
        std::cin >> k;
        auto result = Solution{}.kSmallestPairs(nums1, nums2, k);
        std::cout << result << std::endl;
    } else if (vm.count("findMaximizedCapital")) {
        int k, w;
        std::vector<int> profits, capital;
        std::string buffer;
        std::cin >> k >> w;
        std::cin.ignore();  // Ignore the newline after w
        std::getline(std::cin, buffer);
        std::istringstream iss1(std::move(buffer));
        std::copy(std::istream_iterator<int>(iss1), std::istream_iterator<int>(), std::back_inserter(profits));
        std::getline(std::cin, buffer);
        std::istringstream iss2(std::move(buffer));
        std::copy(std::istream_iterator<int>(iss2), std::istream_iterator<int>(), std::back_inserter(capital));
        std::cout << Solution{}.findMaximizedCapital(k, w, profits, capital) << std::endl;
    } else {
        return -1;
    }

    return 0;
}
