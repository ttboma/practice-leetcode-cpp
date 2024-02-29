#define BOOST_TEST_MODULE test_construct
#include <boost/test/included/unit_test.hpp>

#include "solution.h"
template <typename T> using Vec = std::vector<T>;

BOOST_AUTO_TEST_CASE(example1) {
  auto sol = Solution();
  auto grid = Vec<Vec<int>>{{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                            {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                            {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
  auto output = sol.construct(grid);
  auto ans = new Node(0, 1, new Node(1, 1),
                      new Node(0, 1, new Node(1, 0), new Node(1, 0),
                               new Node(1, 1), new Node(1, 1)),
                      new Node(1, 0), new Node(1, 1));

  BOOST_TEST(Solution::eq(output, ans));
}
