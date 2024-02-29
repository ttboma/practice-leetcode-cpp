#include "solution.h"

#define BOOST_TEST_MODULE test_fib
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) { BOOST_TEST(Solution().fib(0) == 0); }
BOOST_AUTO_TEST_CASE(example2) { BOOST_TEST(Solution().fib(1) == 1); }
BOOST_AUTO_TEST_CASE(example3) { BOOST_TEST(Solution().fib(2) == 1); }
BOOST_AUTO_TEST_CASE(example4) { BOOST_TEST(Solution().fib(3) == 2); }
