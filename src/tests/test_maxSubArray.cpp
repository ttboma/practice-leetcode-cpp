#include "solution.h"

#define BOOST_TEST_MODULE test_maxSubArray
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  BOOST_TEST(Solution().maxSubArray(nums) == 6);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = std::vector<int>{1};
  BOOST_TEST(Solution().maxSubArray(nums) == 1);
}
BOOST_AUTO_TEST_CASE(example3) {
  auto nums = std::vector<int>{5, 4, -1, 7, 8};
  BOOST_TEST(Solution().maxSubArray(nums) == 23);
}
