#include "solution.h"

#define BOOST_TEST_MODULE test_deleteDuplicates
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto sol = Solution();
  auto l1 = new ListNode(1, new ListNode(1, new ListNode(2)));
  auto l2 = new ListNode(1, new ListNode(2));
  auto output = sol.deleteDuplicates(l1);

  BOOST_TEST(Solution::eq(output, l2));
}
BOOST_AUTO_TEST_CASE(example2) {
  auto sol = Solution();
  auto l1 = new ListNode(
      1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
  auto l2 = new ListNode(1, new ListNode(2, new ListNode(3)));
  auto output = sol.deleteDuplicates(l1);

  BOOST_TEST(Solution::eq(l1, l2));
}
