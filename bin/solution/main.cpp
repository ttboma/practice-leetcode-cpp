#include <boost/program_options.hpp>
#include <iostream>
#include <solution.hpp>

namespace po = boost::program_options;

const auto HELP_MSG = "Usage: solution <COMMAND>\n\nCommands:";

int main(int argc, char *argv[]) {
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
    } else {
        return -1;
    }

    return 0;
}
