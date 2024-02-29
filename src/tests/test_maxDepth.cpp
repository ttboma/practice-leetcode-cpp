#include "solution.h"

#define BOOST_TEST_MODULE test_maxDepth
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  BOOST_TEST(Solution().maxDepth(root) == 3);
}
BOOST_AUTO_TEST_CASE(example2) {
  TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2));
  BOOST_TEST(Solution().maxDepth(root) == 2);
}
