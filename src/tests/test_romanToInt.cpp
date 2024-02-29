#include "solution.h"

#define BOOST_TEST_MODULE test_romanToInt
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  BOOST_TEST(Solution().romanToInt("III") == 3);
}
BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(Solution().romanToInt("LVIII") == 58);
}
BOOST_AUTO_TEST_CASE(example3) {
  BOOST_TEST(Solution().romanToInt("MCMXCIV") == 1994);
}
