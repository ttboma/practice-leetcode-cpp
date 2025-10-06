#pragma once

#include <algorithm>
#include <functional>
#include <iterator>
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
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct QuadTree {
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
    std::vector<std::vector<int>>& grid;
    Node* zero = new Node(false, true);
    Node* one = new Node(true, true);

    QuadTree(std::vector<std::vector<int>>& grid) : grid(grid) {}
    Node* construct() { return construct(0, 0, grid.size()); }
    Node* construct(unsigned row, unsigned col, unsigned dim);
};

class Solution {
    // Methods
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    int lengthOfLongestSubstring(std::string s);
    std::string longestPalindrome(std::string s);
    bool isPalindrome(int x);
    int romanToInt(std::string s);
    std::string longestCommonPrefix(std::vector<std::string>& strs);
    bool isValid(std::string s);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    int removeDuplicates(std::vector<int>& nums);
    int removeElement(std::vector<int>& nums, int val);
    int strStr(std::string haystack, std::string needle);
    int searchInsert(std::vector<int>& nums, int target);
    int maxSubArray(std::vector<int>& nums);
    int lengthOfLastWord(std::string s);
    std::vector<int> plusOne(std::vector<int>& digits);
    std::string addBinary(std::string a, std::string b);
    int mySqrt(int x);
    int climbStairs(int n);
    ListNode* deleteDuplicates(ListNode* head);
    std::vector<int> inorderTraversal(TreeNode* root);
    bool isSameTree(TreeNode* p, TreeNode* q);
    bool isSymmetric(TreeNode* root);
    int maxDepth(TreeNode* root);
    TreeNode* sortedArrayToBST(std::vector<int>& nums);
    bool isBalanced(TreeNode* root);
    int minDepth(TreeNode* root);
    int maxProfit(std::vector<int>& prices);
    void reverseString(std::vector<char>& s);
    int fib(int n);
    std::vector<int> countSubTrees(int n, std::vector<std::vector<int>>& edges, std::string labels);
    int longestPath(std::vector<int>& parent, std::string s);
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval);
    int minFlipsMonoIncr(std::string s);
    int maxSubarraySumCircular(std::vector<int>& nums);
    int subarraysDivByK(std::vector<int>& nums, int k);
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums);
    int totalFruit(std::vector<int>& fruits);
    QuadTree::Node* construct(std::vector<std::vector<int>>& grid);
    bool isSubsequence(std::string s, std::string t);
    bool hasCycle(ListNode* head);
    ListNode* reverseBetween(ListNode* head, int left, int right);
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
    int findKthLargest(std::vector<int>& nums, int k);
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k);

    // Comparison utilities
   public:
    static bool eq(ListNode* l1, ListNode* l2);
    static bool eq(TreeNode* t1, TreeNode* t2);
    static bool eq(QuadTree::Node* t1, QuadTree::Node* t2);
};
