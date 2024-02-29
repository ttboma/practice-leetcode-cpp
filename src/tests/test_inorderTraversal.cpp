#include "solution.h"

#define BOOST_TEST_MODULE test_inorderTraversal
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  TreeNode *root =
      new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
  auto output = Solution().inorderTraversal(root);
  BOOST_TEST(std::equal(output.begin(), output.end(),
                        std::vector<int>{1, 3, 2}.begin()));
}
BOOST_AUTO_TEST_CASE(example2) {
  TreeNode *root = nullptr;
  auto output = Solution().inorderTraversal(root);
  BOOST_TEST(
      std::equal(output.begin(), output.end(), std::vector<int>{}.begin()));
}
BOOST_AUTO_TEST_CASE(example3) {
  TreeNode *root = new TreeNode(1);
  auto output = Solution().inorderTraversal(root);
  BOOST_TEST(
      std::equal(output.begin(), output.end(), std::vector<int>{1}.begin()));
}
