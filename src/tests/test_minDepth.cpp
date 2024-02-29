#include "solution.h"

#define BOOST_TEST_MODULE test_minDepth
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  BOOST_TEST(Solution().minDepth(root) == 2);
}
BOOST_AUTO_TEST_CASE(example2) {
  TreeNode *root = new TreeNode(
      2, nullptr,
      new TreeNode(
          3, nullptr,
          new TreeNode(4, nullptr, new TreeNode(5, nullptr, new TreeNode(6)))));
  BOOST_TEST(Solution().minDepth(root) == 5);
}
