#include "solution.h"

#define BOOST_TEST_MODULE test_totalFruit
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto Input = std::vector<int>{1, 2, 1};
  BOOST_TEST(Solution().totalFruit(Input) == 3);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto Input = std::vector<int>{0, 1, 2, 2};
  BOOST_TEST(Solution().totalFruit(Input) == 3);
}
BOOST_AUTO_TEST_CASE(example3) {
  auto Input = std::vector<int>{1, 2, 3, 2, 2};
  BOOST_TEST(Solution().totalFruit(Input) == 4);
}
