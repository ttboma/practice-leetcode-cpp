#include "solution.h"

#define BOOST_TEST_MODULE test_addTwoNumbers
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example1) {
  auto sol = Solution();
  auto l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  auto l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  auto l3 = new ListNode(7, new ListNode(0, new ListNode(8)));
  auto output = sol.addTwoNumbers(l1, l2);

  BOOST_TEST(Solution::eq(output, l3));
}
BOOST_AUTO_TEST_CASE(example2) {
  auto sol = Solution();
  auto l1 = new ListNode(0);
  auto l2 = new ListNode(0);
  auto l3 = new ListNode(0);
  auto output = sol.addTwoNumbers(l1, l2);

  BOOST_TEST(Solution::eq(output, l3));
}
BOOST_AUTO_TEST_CASE(example3) {
  auto sol = Solution();
  auto l1 = new ListNode(
      9,
      new ListNode(
          9,
          new ListNode(
              9, new ListNode(
                     9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
  auto l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
  auto l3 = new ListNode(
      8,
      new ListNode(
          9, new ListNode(
                 9, new ListNode(
                        9, new ListNode(
                               0, new ListNode(
                                      0, new ListNode(0, new ListNode(1))))))));
  auto output = sol.addTwoNumbers(l1, l2);

  BOOST_TEST(Solution::eq(output, l3));
}
