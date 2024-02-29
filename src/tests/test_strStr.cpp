#include "solution.h"

#define BOOST_TEST_MODULE test_strStr
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  BOOST_TEST(Solution().strStr("sadbutsad", "sad") == 0);
}
BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(Solution().strStr("leetcode", "leeto") == -1);
}
