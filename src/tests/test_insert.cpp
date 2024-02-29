#include "solution.h"

#define BOOST_TEST_MODULE test_insert
#include <boost/test/included/unit_test.hpp>

template <typename T> using Vec = std::vector<T>;
using String = std::string;

BOOST_AUTO_TEST_CASE(example1) {
  auto intervals = Vec<Vec<int>>{{1, 3}, {6, 9}};
  auto newInterval = Vec<int>{2, 5};
  auto ans = Solution().insert(intervals, newInterval);
  auto output = Vec<Vec<int>>{{1, 5}, {6, 9}};
  auto check =
      ans.size() == output.size() &&
      std::equal(ans.begin(), ans.end(), output.begin(), [](auto const& a, auto const& b) {
        return (a.size() == b.size()) &&
               std::equal(a.begin(), a.end(), b.begin());
      });
  BOOST_TEST(check);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto intervals = Vec<Vec<int>>{{1,2},{3,5},{6,7},{8,10},{12,16}};
  auto newInterval = Vec<int>{4,8};
  auto output = Vec<Vec<int>>{{1,2},{3,10},{12,16}};
  auto ans = Solution().insert(intervals, newInterval);
  auto check =
      ans.size() == output.size() &&
      std::equal(ans.begin(), ans.end(), output.begin(), [](auto const& a, auto const& b) {
        return (a.size() == b.size()) &&
               std::equal(a.begin(), a.end(), b.begin());
      });
  BOOST_TEST(check);
}
