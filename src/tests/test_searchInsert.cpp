#include "solution.h"

#define BOOST_TEST_MODULE test_searchInsert
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = std::vector<int>{1, 3, 5, 6};
  BOOST_TEST(Solution().searchInsert(nums, 5) == 2);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = std::vector<int>{1, 3, 5, 6};
  BOOST_TEST(Solution().searchInsert(nums, 2) == 1);
}
BOOST_AUTO_TEST_CASE(example3) {
  auto nums = std::vector<int>{1, 3, 5, 6};
  BOOST_TEST(Solution().searchInsert(nums, 7) == 4);
}
