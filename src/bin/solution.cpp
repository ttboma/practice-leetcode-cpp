#include <solution.h>

#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

const auto HELP_MSG = "Usage: solution <COMMAND>\n\nCommands:";

int main(int argc, char *argv[]) {
  po::options_description desc(HELP_MSG);
  desc.add_options()(
      "help", "Print this message or the help of the given subcommand(s)")(
      "fib", po::value<int>(),
      "[509. Fibonacci "
      "Number](https://leetcode.com/problems/fibonacci-number/)");

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
  }

  if (vm.count("fib")) {
    auto n = vm["fib"].as<int>();
    std::cout << Solution{}.fib(n) << std::endl;
  }
}
