#include "solution.h"

#define BOOST_TEST_MODULE test_isBalanced
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  TreeNode *root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  BOOST_TEST(Solution().isBalanced(root) == true);
}
BOOST_AUTO_TEST_CASE(example2) {
  TreeNode *root = new TreeNode(
      1,
      new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)),
                   new TreeNode(3)),
      new TreeNode(2));
  BOOST_TEST(Solution().isBalanced(root) == false);
}
BOOST_AUTO_TEST_CASE(example3) {
  TreeNode *root = nullptr;
  BOOST_TEST(Solution().isBalanced(root) == true);
}
