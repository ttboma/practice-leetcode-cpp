#include <solution.h>

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
  int carry = 0;
  ListNode *head = new ListNode(-1);
  ListNode *it = head;

  while (l1 != nullptr or l2 != nullptr or carry != 0) {
    it->next = new ListNode(carry);
    it = it->next;

    if (l1 != nullptr) {
      it->val += l1->val;
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      it->val += l2->val;
      l2 = l2->next;
    }

    carry = it->val / 10;
    it->val = it->val % 10;
  }

  it = head;
  head = head->next;
  delete it;

  return head;
}
