#include "solution.h"

#define BOOST_TEST_MODULE test_countSubTrees
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto sol = Solution();
  auto n = 7;
  auto edges = std::vector<std::vector<int>>{
      {0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6},
  };
  auto labels = "abaedcd";
  auto ans = sol.countSubTrees(n, edges, labels);
  auto output = std::vector<int>{2, 1, 1, 1, 1, 1, 1};

  BOOST_TEST(std::equal(output.begin(), output.end(), ans.begin()));
}
BOOST_AUTO_TEST_CASE(example2) {
  auto sol = Solution();
  auto n = 4;
  auto edges = std::vector<std::vector<int>>{{0, 1}, {1, 2}, {0, 3}};
  auto labels = "bbbb";
  auto ans = sol.countSubTrees(n, edges, labels);
  auto output = std::vector<int>{4, 2, 1, 1};

  BOOST_TEST(std::equal(output.begin(), output.end(), ans.begin()));
}
BOOST_AUTO_TEST_CASE(example3) {
  auto sol = Solution();
  auto n = 5;
  auto edges = std::vector<std::vector<int>>{{0, 1}, {0, 2}, {1, 3}, {0, 4}};
  auto labels = "aabab";
  auto ans = sol.countSubTrees(n, edges, labels);
  auto output = std::vector<int>{3, 2, 1, 1, 1};

  BOOST_TEST(std::equal(output.begin(), output.end(), ans.begin()));
}
BOOST_AUTO_TEST_CASE(example4) {
  auto sol = Solution();
  auto n = 4;
  auto edges = std::vector<std::vector<int>>{{0, 2}, {0, 3}, {2, 1}};
  auto labels = "aeed";
  auto ans = sol.countSubTrees(n, edges, labels);
  auto output = std::vector<int>{1, 1, 2, 1};

  BOOST_TEST(std::equal(output.begin(), output.end(), ans.begin()));
}
