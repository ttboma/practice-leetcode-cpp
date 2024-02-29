#include "solution.h"

#define BOOST_TEST_MODULE test_removeElement
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = std::vector<int>{3, 2, 2, 3};
  BOOST_TEST(Solution().removeElement(nums, 3) == 2);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = std::vector<int>{0, 1, 2, 2, 3, 0, 4, 2};
  BOOST_TEST(Solution().removeElement(nums, 2) == 5);
}
