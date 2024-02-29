#include "solution.h"

#define BOOST_TEST_MODULE test_sortedArrayToBST
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto nums = std::vector<int>{-10, -3, 0, 5, 9};
  auto output = Solution().sortedArrayToBST(nums);
  auto t1 = new TreeNode(0, new TreeNode(-3, new TreeNode(-10), nullptr),
                         new TreeNode(9, new TreeNode(5), nullptr));
  auto t2 = new TreeNode(0, new TreeNode(-10, nullptr, new TreeNode(-3)),
                         new TreeNode(5, nullptr, new TreeNode(9)));
  BOOST_TEST((Solution().eq(output, t1) || Solution().eq(output, t2)));
}
BOOST_AUTO_TEST_CASE(example2) {
  auto nums = std::vector<int>{1, 3};
  auto output = Solution().sortedArrayToBST(nums);
  auto t1 = new TreeNode(3, new TreeNode(1), nullptr);
  auto t2 = new TreeNode(1, nullptr, new TreeNode(3));
  BOOST_TEST((Solution().eq(output, t1) || Solution().eq(output, t2)));
}
