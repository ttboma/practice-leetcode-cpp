#include "solution.h"

int Solution::minDepth(TreeNode *root) {
  using x = std::pair<TreeNode *, int>;

  if (root == nullptr)
    return 0;

  auto Q = std::queue<x>();

  Q.push({root, 1});

  while (!Q.empty()) {
    auto f = Q.front();
    Q.pop();

    bool isleaf = true;

    if (f.first->left != nullptr) {
      isleaf = false;
      Q.push({f.first->left, f.second + 1});
    }
    if (f.first->right != nullptr) {
      isleaf = false;
      Q.push({f.first->right, f.second + 1});
    }
    if (isleaf)
      return f.second;
  }

  return -1;
}
