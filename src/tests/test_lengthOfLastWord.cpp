#include "solution.h"

#define BOOST_TEST_MODULE test_lengthOfLastWord
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  BOOST_TEST(Solution().lengthOfLastWord("Hello World") == 5);
}
BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(Solution().lengthOfLastWord("   fly me   to   the moon  ") == 4);
}
BOOST_AUTO_TEST_CASE(example3) {
  BOOST_TEST(Solution().lengthOfLastWord("luffy is still joyboy") == 6);
}
