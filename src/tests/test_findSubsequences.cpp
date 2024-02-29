#include "solution.h"

#define BOOST_TEST_MODULE test_findSubsequences
#include <boost/test/included/unit_test.hpp>

template <typename T> using Vec = std::vector<T>;
using String = std::string;

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = Vec<int>{4, 6, 7, 7};
  auto output = Vec<Vec<int>>{{4, 6},    {4, 6, 7}, {4, 6, 7, 7}, {4, 7},
                              {4, 7, 7}, {6, 7},    {6, 7, 7},    {7, 7}};
  auto ans = Solution().findSubsequences(nums);
  std::sort(ans.begin(), ans.end());
  std::sort(output.begin(), output.end());
  auto check = ans.size() == output.size() &&
               std::equal(ans.begin(), ans.end(), output.begin(),
                          [](auto const &a, auto const &b) {
                            return (a.size() == b.size()) &&
                                   std::equal(a.begin(), a.end(), b.begin());
                          });
  BOOST_TEST(check);
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = Vec<int>{4, 4, 3, 2, 1};
  auto output = Vec<Vec<int>>{{4, 4}};
  auto ans = Solution().findSubsequences(nums);
  std::sort(ans.begin(), ans.end());
  std::sort(output.begin(), output.end());
  auto check = ans.size() == output.size() &&
               std::equal(ans.begin(), ans.end(), output.begin(),
                          [](auto const &a, auto const &b) {
                            return (a.size() == b.size()) &&
                                   std::equal(a.begin(), a.end(), b.begin());
                          });
  BOOST_TEST(check);
}
