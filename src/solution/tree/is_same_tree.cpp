#include "solution.hpp"

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    auto pStk = std::vector<TreeNode*>{};
    auto qStk = std::vector<TreeNode*>{};

    if (p != nullptr)
        pStk.push_back(p);
    if (q != nullptr)
        qStk.push_back(q);

    while (!pStk.empty()) {
        if (qStk.empty())
            return false;

        auto nodeP = pStk.back();
        pStk.pop_back();
        auto nodeQ = qStk.back();
        qStk.pop_back();

        if (nodeP->val != nodeQ->val)
            return false;

        if (nodeP->right != nullptr) {
            if (nodeQ->right == nullptr)
                return false;
            pStk.push_back(nodeP->right);
            qStk.push_back(nodeQ->right);
        } else if (nodeQ->right != nullptr)
            return false;

        if (nodeP->left != nullptr) {
            if (nodeQ->left == nullptr)
                return false;
            pStk.push_back(nodeP->left);
            qStk.push_back(nodeQ->left);
        } else if (nodeQ->left != nullptr)
            return false;
    }
    if (!qStk.empty())
        return false;

    return true;
}
