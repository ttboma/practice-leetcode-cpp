#include "solution.h"

#define BOOST_TEST_MODULE test_longestCommonPrefix
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto str = std::vector<std::string>{"flower", "flow", "flight"};
  BOOST_TEST(Solution().longestCommonPrefix(str) == "fl");
}
BOOST_AUTO_TEST_CASE(example2) {
  auto str = std::vector<std::string>{"dog", "racecar", "car"};
  BOOST_TEST(Solution().longestCommonPrefix(str) == "");
}
