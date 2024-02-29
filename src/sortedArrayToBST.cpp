#include "solution.h"

TreeNode *Solution::sortedArrayToBST(std::vector<int> &nums) {
  using X = std::tuple<TreeNode *, std::vector<int>::size_type,
                       std::vector<int>::size_type>;

  if (nums.empty())
    return nullptr;

  auto root = new TreeNode(nums[nums.size() / 2]);

  auto stk = std::vector<X>{{root, 0, nums.size()}};

  while (!stk.empty()) {
    auto mom = stk.back();
    stk.pop_back();

    auto i = std::get<1>(mom);
    auto j = std::get<2>(mom);
    auto k = (i + j) / 2;

    if (i != k) {
      auto child = new TreeNode(nums[(i + k) / 2]);
      std::get<0>(mom)->left = child;
      stk.push_back({child, i, k});
    }
    if (++k != j) {
      auto child = new TreeNode(nums[(k + j) / 2]);
      std::get<0>(mom)->right = child;
      stk.push_back({child, k, j});
    }
  }

  return root;
}
