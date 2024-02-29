#include "solution.h"

#define BOOST_TEST_MODULE test_addBinary
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  BOOST_TEST(Solution().addBinary("11", "1") == "100");
}

BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(Solution().addBinary("1010", "1011") == "10101");
}
