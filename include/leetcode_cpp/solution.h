#pragma once

#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
  // Methods
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);  // #2    Add Two Numbers
  int lengthOfLongestSubstring(
      std::string s);  // #3    Longest Substring Without Repeating Characters
  std::string longestPalindrome(
      std::string s);             // #5    Longest Palindromic Substring
  bool isPalindrome(int x);       // #9    Palindrome Number
  int romanToInt(std::string s);  // #13   Roman to Integer
  std::string longestCommonPrefix(
      std::vector<std::string>& strs);  // #14   Longest Common Prefix
  bool isValid(std::string s);          // #20   Valid Parentheses
  ListNode* mergeTwoLists(ListNode* list1,
                          ListNode* list2);  // #21   Merge Two Sorted Lists
  int removeDuplicates(
      std::vector<int>& nums);  // #26   Remove Duplicates from Sorted Array
  int removeElement(std::vector<int>& nums, int val);  // #27   Remove Element
  int strStr(std::string haystack,
             std::string needle);  // #28   Implement strStr()
  int searchInsert(std::vector<int>& nums,
                   int target);             // #35   Search Insert Position
  int maxSubArray(std::vector<int>& nums);  // #53   Maximum Subarray
  int lengthOfLastWord(std::string s);      // #58   Length of Last Word
  std::vector<int> plusOne(std::vector<int>& digits);   // #66   Plus One
  std::string addBinary(std::string a, std::string b);  // #67   Add Binary
  int mySqrt(int x);                                    // #69   Sqrt(x)
  int climbStairs(int n);                               // #70   Climbing Stairs
  ListNode* deleteDuplicates(
      ListNode* head);  // #83   Remove Duplicates from Sorted List
  std::vector<int> inorderTraversal(
      TreeNode* root);  // #94   Binary Tree Inorder Traversal
  bool isSameTree(TreeNode* p, TreeNode* q);  // #100  Same Tree
  bool isSymmetric(TreeNode* root);           // #101  Symmetric Tree
  int maxDepth(TreeNode* root);  // #104  Maximum Depth of Binary Tree
  TreeNode* sortedArrayToBST(
      std::vector<int>&
          nums);  // #108  Convert Sorted Array to Binary Search Tree
  bool isBalanced(TreeNode* root);  // #110  Balanced Binary Tree
  int minDepth(TreeNode* root);     // #111  Minimum Depth of Binary Tree
  int maxProfit(
      std::vector<int>& prices);  // #122  Best Time to Buy and Sell Stock II
  void reverseString(std::vector<char>& s);  // #344  Reverse std::string
  int fib(int n);                            // #509  Fibonacci Number
  std::vector<int> countSubTrees(
      int n, std::vector<std::vector<int>>& edges,
      std::string
          labels);  // #1519 Number of Nodes in the Sub-Tree With the Same Label
  int longestPath(
      std::vector<int>& parent,
      std::string s);  // #2246 Longest Path With Different Adjacent Characters
  std::vector<std::vector<int>> insert(
      std::vector<std::vector<int>>& intervals,
      std::vector<int>& newInterval);  // #57   Insert Interval
  int minFlipsMonoIncr(
      std::string s);  // #926  Flip std::string to Monotone Increasing
  int maxSubarraySumCircular(
      std::vector<int>& nums);  // #918  Maximum Sum Circular Subarray
  int subarraysDivByK(std::vector<int>& nums,
                      int k);  // #974  Subarray Sums Divisible by K
  std::vector<std::vector<int>> findSubsequences(
      std::vector<int>& nums);  // #491  Non-decreasing Subsequences
  int totalFruit(std::vector<int>& fruits);  // #904  Fruit Into Baskets
  Node* construct(
      std::vector<std::vector<int>>& grid);  // #427  Construct Quad Tree

  // Comparsion utilities
 public:
  static bool eq(ListNode* l1, ListNode* l2);
  static bool eq(TreeNode* t1, TreeNode* t2);
  static bool eq(Node* t1, Node* t2);
};
