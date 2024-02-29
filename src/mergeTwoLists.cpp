#include "solution.h"

ListNode *Solution::mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (list1 == nullptr)
    return list2;

  if (list2 == nullptr)
    return list1;

  ListNode *n = list1;

  if (list2->val < list1->val) {
    n = list2;
    list2 = list1;
    list1 = n;
  }

  // Event: assert that list1->val <= list2->val

  for (ListNode *x = n; list2 != nullptr; x = n) {
    for (; !(x->next == nullptr || x->next->val > list2->val); x = x->next)
      ;

    n = list2;
    list2 = x->next;
    x->next = n;
  }

  return list1;
}
