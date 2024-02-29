#include "solution.h"

#define BOOST_TEST_MODULE test_subarraysDivByK
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = std::vector<int>{4,5,0,-2,-3,1}; 
  auto k = 5;
  BOOST_TEST(Solution().subarraysDivByK(nums, k) == 7);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = std::vector<int>{5}; 
  auto k = 9;
  BOOST_TEST(Solution().subarraysDivByK(nums, k) == 0);
}
