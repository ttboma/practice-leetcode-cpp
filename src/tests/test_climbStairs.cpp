#include "solution.h"

#define BOOST_TEST_MODULE test_climbStairs
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) { BOOST_TEST(Solution().climbStairs(2) == 2); }
BOOST_AUTO_TEST_CASE(example2) { BOOST_TEST(Solution().climbStairs(3) == 3); }
