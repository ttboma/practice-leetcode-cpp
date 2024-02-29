#include "solution.h"

#define BOOST_TEST_MODULE test_reverseString
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto s = std::vector<char>{'h', 'e', 'l', 'l', 'o'};
  Solution().reverseString(s);
  BOOST_TEST(std::equal(s.begin(), s.end(),
                        std::vector<char>{'o', 'l', 'l', 'e', 'h'}.begin()));
}
BOOST_AUTO_TEST_CASE(example2) {
  auto s = std::vector<char>{'H', 'a', 'n', 'n', 'a', 'h'};
  Solution().reverseString(s);
  BOOST_TEST(
      std::equal(s.begin(), s.end(),
                 std::vector<char>{'h', 'a', 'n', 'n', 'a', 'H'}.begin()));
}
