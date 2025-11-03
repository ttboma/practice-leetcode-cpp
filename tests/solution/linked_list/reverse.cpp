#include "data_structures/list_node.hpp"
#include "gtest/gtest.h"
#include "solution.hpp"

TEST(reverseKGroup, example1) {
    Solution sol;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;
    ListNode* result = sol.reverseKGroup(head, k);

    std::vector<int> expected_values = {2, 1, 4, 3, 5};
    ListNode* current = result;
    for (int val : expected_values) {
        ASSERT_NE(current, nullptr);
        EXPECT_EQ(current->val, val);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr);
}

TEST(reverseKGroup, example2) {
    Solution sol;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 3;
    ListNode* result = sol.reverseKGroup(head, k);

    std::vector<int> expected_values = {3, 2, 1, 4, 5};
    ListNode* current = result;
    for (int val : expected_values) {
        ASSERT_NE(current, nullptr);
        EXPECT_EQ(current->val, val);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr);
}
