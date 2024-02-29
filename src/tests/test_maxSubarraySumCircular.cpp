#include "solution.h"

#define BOOST_TEST_MODULE test_maxSubarraySumCircular
#include <boost/test/included/unit_test.hpp>

template <typename T> using Vec = std::vector<T>;

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = Vec<int>{1,-2,3,-2};
  BOOST_TEST(3 == Solution().maxSubarraySumCircular(nums));
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = Vec<int>{5,-3,5};
  BOOST_TEST(10 == Solution().maxSubarraySumCircular(nums));
}
BOOST_AUTO_TEST_CASE(example3) {
  auto nums = Vec<int>{-3,-2,-3};
  BOOST_TEST(-2 == Solution().maxSubarraySumCircular(nums));
}
