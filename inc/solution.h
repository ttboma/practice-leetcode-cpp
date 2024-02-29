#ifndef _SYCLEETCODESOL_H_
#define _SYCLEETCODESOL_H_

#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
  template <typename T>
  using Vec = std::vector<T>;
  using String = std::string;
  
// Methods
public:
	ListNode*     addTwoNumbers(ListNode* l1, ListNode* l2);                 // #2    Add Two Numbers 
	int           lengthOfLongestSubstring(String s);                        // #3    Longest Substring Without Repeating Characters
	String        longestPalindrome(String s);                               // #5    Longest Palindromic Substring
	bool          isPalindrome(int x);                                       // #9    Palindrome Number
	int           romanToInt(String s);                                      // #13   Roman to Integer 
	String        longestCommonPrefix(Vec<String>& strs);                    // #14   Longest Common Prefix 
	bool          isValid(String s);                                         // #20   Valid Parentheses
	ListNode*     mergeTwoLists(ListNode* list1, ListNode* list2);           // #21   Merge Two Sorted Lists
	int           removeDuplicates(Vec<int>& nums);                          // #26   Remove Duplicates from Sorted Array
	int           removeElement(Vec<int>& nums, int val);                    // #27   Remove Element
	int           strStr(String haystack, String needle);                    // #28   Implement strStr()
	int           searchInsert(Vec<int>& nums, int target);                  // #35   Search Insert Position
	int           maxSubArray(Vec<int>& nums);                               // #53   Maximum Subarray	
	int           lengthOfLastWord(String s);                                // #58   Length of Last Word
	Vec<int>      plusOne(Vec<int>& digits);                                 // #66   Plus One
	String        addBinary(String a, String b);                             // #67   Add Binary
	int           mySqrt(int x);                                             // #69   Sqrt(x)	
	int           climbStairs(int n);                                        // #70   Climbing Stairs
	ListNode*     deleteDuplicates(ListNode* head);                          // #83   Remove Duplicates from Sorted List
	Vec<int>      inorderTraversal(TreeNode* root);                          // #94   Binary Tree Inorder Traversal
	bool          isSameTree(TreeNode* p, TreeNode* q);                      // #100  Same Tree
	bool          isSymmetric(TreeNode* root);                               // #101  Symmetric Tree 
	int           maxDepth(TreeNode* root);                                  // #104  Maximum Depth of Binary Tree 
	TreeNode*     sortedArrayToBST(Vec<int>& nums);                          // #108  Convert Sorted Array to Binary Search Tree
	bool          isBalanced(TreeNode* root);                                // #110  Balanced Binary Tree
	int           minDepth(TreeNode* root);                                  // #111  Minimum Depth of Binary Tree
	int           maxProfit(Vec<int>& prices);                               // #122  Best Time to Buy and Sell Stock II
	void          reverseString(Vec<char>& s);                               // #344  Reverse String
	int           fib(int n);                                                // #509  Fibonacci Number
  Vec<int>      countSubTrees(int n, Vec<Vec<int>>& edges, String labels); // #1519 Number of Nodes in the Sub-Tree With the Same Label
  int           longestPath(Vec<int>& parent, String s);                   // #2246 Longest Path With Different Adjacent Characters 
  Vec<Vec<int>> insert(Vec<Vec<int>>& intervals, Vec<int>& newInterval);   // #57   Insert Interval
  int           minFlipsMonoIncr(String s);                                // #926  Flip String to Monotone Increasing 
  int           maxSubarraySumCircular(Vec<int>& nums);                    // #918  Maximum Sum Circular Subarray 
  int           subarraysDivByK(Vec<int>& nums, int k);                    // #974  Subarray Sums Divisible by K
  Vec<Vec<int>> findSubsequences(Vec<int>& nums);                          // #491  Non-decreasing Subsequences
  int           totalFruit(Vec<int>& fruits);                              // #904  Fruit Into Baskets
  Node*         construct(Vec<Vec<int>>& grid);                            // #427  Construct Quad Tree
  
// Comparsion utilities
public:
	static bool eq(ListNode* l1, ListNode* l2);
	static bool eq(TreeNode* t1, TreeNode* t2);
  static bool eq(Node *t1, Node *t2);
};

#endif // _SYCLEETCODESOL_H_
