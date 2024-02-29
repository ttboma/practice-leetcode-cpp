#include "solution.h"

bool Solution::isBalanced(TreeNode *root) {
  auto check_depth = [&](TreeNode const *const v,
                         auto &&check_depth) -> std::pair<bool, int> {
    if (v == nullptr)
      return std::pair<bool, int>{true, 0};
    else {
      auto r = check_depth(v->right, check_depth);
      auto l = check_depth(v->left, check_depth);
      int d = r.second - l.second;
      if (!r.first || !l.first || !(-2 < d && d < 2)) {
        return std::pair<bool, int>{false, 0};
      }
      return std::pair<bool, int>{true, (l.second < r.second) ? (r.second + 1)
                                                              : (l.second + 1)};
    }
  };

  return check_depth(root, check_depth).first;
}
