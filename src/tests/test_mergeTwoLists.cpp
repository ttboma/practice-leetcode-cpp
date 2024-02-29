#include "solution.h"

#define BOOST_TEST_MODULE test_mergeTwoLists
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  ListNode *list1 = new ListNode(1, new ListNode(3, new ListNode(4)));
  ListNode *list2 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode *output = Solution().mergeTwoLists(list1, list2);
  ListNode *ans = new ListNode(
      1, new ListNode(
             1, new ListNode(
                    2, new ListNode(3, new ListNode(4, new ListNode(4))))));
  BOOST_TEST(Solution::eq(output, ans));
}
BOOST_AUTO_TEST_CASE(example2) {
  ListNode *list1 = nullptr;
  ListNode *list2 = nullptr;
  ListNode *output = Solution().mergeTwoLists(list1, list2);
  BOOST_TEST(Solution::eq(output, nullptr));
}
BOOST_AUTO_TEST_CASE(example3) {
  ListNode *list1 = nullptr;
  ListNode *list2 = new ListNode(0);
  ListNode *output = Solution().mergeTwoLists(list1, list2);
  ListNode *ans = new ListNode(0);
  BOOST_TEST(Solution::eq(output, ans));
}
