#include "solution.h"

#define BOOST_TEST_MODULE test_plusOne
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto digits = std::vector<int>{1, 2, 3};
  auto output = Solution().plusOne(digits);
  BOOST_TEST(std::equal(output.begin(), output.end(),
                        std::vector<int>{1, 2, 4}.begin()));
}
BOOST_AUTO_TEST_CASE(example2) {
  auto digits = std::vector<int>{4, 3, 2, 1};
  auto output = Solution().plusOne(digits);
  BOOST_TEST(std::equal(output.begin(), output.end(),
                        std::vector<int>{4, 3, 2, 2}.begin()));
}
BOOST_AUTO_TEST_CASE(example3) {
  auto digits = std::vector<int>{9};
  auto output = Solution().plusOne(digits);
  BOOST_TEST(
      std::equal(output.begin(), output.end(), std::vector<int>{1, 0}.begin()));
}
