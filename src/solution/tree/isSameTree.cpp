#include "solution.hpp"

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    auto pstk = std::vector<TreeNode*>{};
    auto qstk = std::vector<TreeNode*>{};

    if (p != nullptr)
        pstk.push_back(p);
    if (q != nullptr)
        qstk.push_back(q);

    while (!pstk.empty()) {
        if (qstk.empty())
            return false;

        auto node_p = pstk.back();
        pstk.pop_back();
        auto node_q = qstk.back();
        qstk.pop_back();

        if (node_p->val != node_q->val)
            return false;

        if (node_p->right != nullptr) {
            if (node_q->right == nullptr)
                return false;
            pstk.push_back(node_p->right);
            qstk.push_back(node_q->right);
        } else if (node_q->right != nullptr)
            return false;

        if (node_p->left != nullptr) {
            if (node_q->left == nullptr)
                return false;
            pstk.push_back(node_p->left);
            qstk.push_back(node_q->left);
        } else if (node_q->left != nullptr)
            return false;
    }
    if (!qstk.empty())
        return false;

    return true;
}
