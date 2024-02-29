#include "solution.h"

#define BOOST_TEST_MODULE test_isPalindrome
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  BOOST_TEST(Solution().isPalindrome(121) == true);
}
BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(Solution().isPalindrome(-121) == false);
}
BOOST_AUTO_TEST_CASE(example3) {
  BOOST_TEST(Solution().isPalindrome(10) == false);
}
