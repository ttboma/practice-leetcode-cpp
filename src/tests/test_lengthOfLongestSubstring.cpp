#include "solution.h"

#define BOOST_TEST_MODULE test_lengthOfLongestSubstring
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  BOOST_TEST(Solution().lengthOfLongestSubstring("abcabcbb") == 3);
}
BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(Solution().lengthOfLongestSubstring("bbbbb") == 1);
}
BOOST_AUTO_TEST_CASE(example3) {
  BOOST_TEST(Solution().lengthOfLongestSubstring("pwwkew") == 3);
}
