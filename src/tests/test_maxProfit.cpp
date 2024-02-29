#include "solution.h"

#define BOOST_TEST_MODULE test_maxProfit
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto prices = std::vector<int>{7, 1, 5, 3, 6, 4};
  BOOST_TEST(Solution().maxProfit(prices) == 7);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto prices = std::vector<int>{1, 2, 3, 4, 5};
  BOOST_TEST(Solution().maxProfit(prices) == 4);
}
BOOST_AUTO_TEST_CASE(example3) {
  auto prices = std::vector<int>{7, 6, 4, 3, 1};
  BOOST_TEST(Solution().maxProfit(prices) == 0);
}
