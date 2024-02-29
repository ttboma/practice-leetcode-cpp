#include "solution.h"

#define BOOST_TEST_MODULE test_isSymmetric
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  TreeNode *root =
      new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                   new TreeNode(2, new TreeNode(4), new TreeNode(3)));
  BOOST_TEST(Solution().isSymmetric(root) == true);
}
BOOST_AUTO_TEST_CASE(example2) {
  TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)),
                                new TreeNode(2, nullptr, new TreeNode(3)));
  BOOST_TEST(Solution().isSymmetric(root) == false);
}
