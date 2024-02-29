#include "solution.h"

#define BOOST_TEST_MODULE test_isValid
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) { BOOST_TEST(Solution().isValid("()") == true); }
BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(Solution().isValid("()[]{}") == true);
}
BOOST_AUTO_TEST_CASE(example3) {
  BOOST_TEST(Solution().isValid("(]") == false);
}
