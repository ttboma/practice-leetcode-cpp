#include <solution.h>

#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

const auto HELP_MSG = "Usage: solution <COMMAND>\n\nCommands:";

int main(int argc, char *argv[]) {
  po::options_description desc(HELP_MSG);
  desc.add_options()(
      "help", "Print this message or the help of the given subcommand(s)")(
      "fib",
      "[509. Fibonacci "
      "Number](https://leetcode.com/problems/fibonacci-number/)")(
      "isSubsequence",
      "[392. Is "
      "Subsequence](https://leetcode.com/problems/is-subsequence/description/"
      "?envType=study-plan-v2&envId=top-interview-150)");

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
  }

  if (vm.count("isSubsequence")) {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << std::boolalpha << Solution{}.isSubsequence(s, t) << std::endl;
  }
}
