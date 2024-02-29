#include "solution.h"

ListNode *Solution::deleteDuplicates(ListNode *head) {
  if (head == nullptr)
    return head;

  auto it = head;
  int val = it->val;

  while (it->next != nullptr) {
    if (it->next->val == val) {
      auto t = it->next;
      it->next = t->next;
      delete t;
    } else {
      val = it->next->val;
      it = it->next;
    }
  }

  return head;
}
