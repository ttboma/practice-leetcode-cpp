#include "solution.hpp"

bool Solution::isSymmetric(TreeNode* root) {
    if (root == nullptr)
        return true;

    auto pStk = std::vector<TreeNode*>{};
    auto qStk = std::vector<TreeNode*>{};

    if (root->left != nullptr)
        pStk.push_back(root->left);
    if (root->right != nullptr)
        qStk.push_back(root->right);

    while (!pStk.empty()) {
        if (qStk.empty())
            return false;

        auto p = pStk.back();
        pStk.pop_back();
        auto q = qStk.back();
        qStk.pop_back();

        if (p->val != q->val)
            return false;

        if (p->right != nullptr) {
            if (q->left == nullptr)
                return false;
            pStk.push_back(p->right);
            qStk.push_back(q->left);
        } else if (q->left != nullptr)
            return false;

        if (p->left != nullptr) {
            if (q->right == nullptr)
                return false;
            pStk.push_back(p->left);
            qStk.push_back(q->right);
        } else if (q->right != nullptr)
            return false;
    }
    if (!qStk.empty())
        return false;

    return true;
}
