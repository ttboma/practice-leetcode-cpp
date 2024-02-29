#include "solution.h"

#define BOOST_TEST_MODULE test_isSameTree
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  TreeNode *t1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  BOOST_TEST(Solution().isSameTree(t1, t2) == true);
}
BOOST_AUTO_TEST_CASE(example2) {
  TreeNode *t1 = new TreeNode(1, new TreeNode(2), nullptr);
  TreeNode *t2 = new TreeNode(1, nullptr, new TreeNode(3));
  BOOST_TEST(Solution().isSameTree(t1, t2) == false);
}
BOOST_AUTO_TEST_CASE(example3) {
  TreeNode *t1 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
  TreeNode *t2 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
  BOOST_TEST(Solution().isSameTree(t1, t2) == false);
}
