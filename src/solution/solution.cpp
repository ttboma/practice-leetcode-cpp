#include "solution.hpp"

#include <sstream>

bool Solution::eq(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr && l2 != nullptr) return false;
        if (l1 != nullptr && l2 == nullptr) return false;
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}

bool Solution::eq(TreeNode* t1, TreeNode* t2) {
    auto stack1 = std::vector<TreeNode*>{t1};
    auto stack2 = std::vector<TreeNode*>{t2};
    while (!stack1.empty()) {
        auto t1 = stack1.back();
        stack1.pop_back();
        auto t2 = stack2.back();
        stack2.pop_back();
        if (t1 == nullptr) {
            if (t2 != nullptr) {
                return false;
            }
            continue;
        } else if (t2 == nullptr) {
            return false;
        } else if (t1->val != t2->val) {
            return false;
        } else {
            stack1.push_back(t1->left);
            stack1.push_back(t1->right);
            stack2.push_back(t2->left);
            stack2.push_back(t2->right);
        }
    }
    return true;
}

bool Solution::eq(QuadTree::Node* t1, QuadTree::Node* t2) {
    if ((t1 == nullptr) ^ (t2 == nullptr)) return false;
    if (t1 == nullptr && t2 == nullptr) return true;
    if ((t1->isLeaf == true) ^ (t2->isLeaf == true)) return true;
    if ((t1->isLeaf == true) && (t2->isLeaf == true)) {
        if (t1->val != t2->val) return false;
        return true;
    } else {
        return eq(t1->topLeft, t2->topLeft) && eq(t1->topRight, t2->topRight) && eq(t1->bottomLeft, t2->bottomLeft) &&
               eq(t1->bottomRight, t2->bottomRight);
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const RandomList& list) {
    std::unordered_map<Node*, std::size_t> node_to_index;
    std::size_t index = 0;
    for (auto curr = list.getHead(); curr != nullptr; curr = curr->next) {
        node_to_index[curr] = index++;
    }

    os << "[";
    auto curr = list.getHead();
    while (true) {
        os << "[" << curr->val << ",";
        if (curr->random != nullptr) {
            os << node_to_index[curr->random];
        } else {
            os << "null";
        }
        os << "]";

        curr = curr->next;
        if (curr == nullptr) break;

        os << ",";
    }
    os << "]";

    return os;
}

bool RandomList::operator==(const RandomList& other) const {
    std::ostringstream head_stream1, head_stream2;
    head_stream1 << *this;
    head_stream2 << other;
    return head_stream1.str() == head_stream2.str();
}
