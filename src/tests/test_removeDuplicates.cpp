#include "solution.h"

#define BOOST_TEST_MODULE test_removeDuplicates
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = std::vector<int>{1, 1, 2};
  BOOST_TEST(Solution().removeDuplicates(nums) == 2);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  BOOST_TEST(Solution().removeDuplicates(nums) == 5);
}
