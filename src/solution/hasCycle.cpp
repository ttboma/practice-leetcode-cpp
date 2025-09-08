#include "solution.hpp"

bool Solution::hasCycle(ListNode *head) {
    ListNode *slow = head;
    if (slow == nullptr) return false;

    ListNode *fast = slow->next;
    while (fast != slow) {
        if (fast == nullptr) return false;
        fast = fast->next;
        if (fast == nullptr) return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
