#include "solution.h"

int Solution::maxDepth(TreeNode *root) {
  using info = std::pair<TreeNode *, int>;

  if (root == nullptr)
    return 0;

  auto Q = std::queue<info>();
  Q.push(info{root, 1});
  int level = 0;

  for (; !Q.empty(); Q.pop()) {
    auto f = Q.front();
    level = std::get<1>(f);
    if (f.first->left != nullptr)
      Q.push(info{std::get<0>(f)->left, level + 1});
    if (f.first->right != nullptr)
      Q.push(info{std::get<0>(f)->right, level + 1});
  }

  return level;
}
