#include "solution.h"

#define BOOST_TEST_MODULE test_minFlipsMonoIncr
#include <boost/test/included/unit_test.hpp>

template <typename T> using Vec = std::vector<T>;
using String = std::string;

BOOST_AUTO_TEST_CASE(example1) {
  BOOST_TEST(1 == Solution().minFlipsMonoIncr("00110"));
}
BOOST_AUTO_TEST_CASE(example2) {
  BOOST_TEST(2 == Solution().minFlipsMonoIncr("010110"));
}
BOOST_AUTO_TEST_CASE(example3) {
  BOOST_TEST(2 == Solution().minFlipsMonoIncr("00011000"));
}
