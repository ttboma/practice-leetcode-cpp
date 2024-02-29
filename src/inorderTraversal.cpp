#include "solution.h"

std::vector<int> Solution::inorderTraversal(TreeNode *root) {
  auto ret = std::vector<int>{};
  auto stk = std::vector<TreeNode *>{};

  for (auto it = root; it != nullptr; it = it->left)
    stk.push_back(it);

  while (!stk.empty()) {
    auto in = stk.back();
    ret.push_back(in->val);
    stk.pop_back();
    in = in->right;

    for (auto it = in; it != nullptr; it = it->left)
      stk.push_back(it);
  }

  return ret;
}
