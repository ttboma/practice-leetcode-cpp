#include "solution.h"

bool Solution::isSymmetric(TreeNode *root) {
  if (root == nullptr)
    return true;

  auto pstk = std::vector<TreeNode *>{};
  auto qstk = std::vector<TreeNode *>{};

  if (root->left != nullptr)
    pstk.push_back(root->left);
  if (root->right != nullptr)
    qstk.push_back(root->right);

  while (!pstk.empty()) {
    if (qstk.empty())
      return false;

    auto p = pstk.back();
    pstk.pop_back();
    auto q = qstk.back();
    qstk.pop_back();

    if (p->val != q->val)
      return false;

    if (p->right != nullptr) {
      if (q->left == nullptr)
        return false;
      pstk.push_back(p->right);
      qstk.push_back(q->left);
    } else if (q->left != nullptr)
      return false;

    if (p->left != nullptr) {
      if (q->right == nullptr)
        return false;
      pstk.push_back(p->left);
      qstk.push_back(q->right);
    } else if (q->right != nullptr)
      return false;
  }
  if (!qstk.empty())
    return false;

  return true;
}
