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
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Include data structures
#include "data_structures/graph_nodes.hpp"
#include "data_structures/list_node.hpp"
#include "data_structures/median_finder.hpp"
#include "data_structures/quad_tree.hpp"
#include "data_structures/random_list.hpp"
#include "data_structures/tree_node.hpp"

class Solution {
    // Methods
public:
    // Linked List
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    ListNode* deleteDuplicates(ListNode* head);
    bool hasCycle(ListNode* head);
    ListNode* reverseBetween(ListNode* head, int left, int right);
    Node* copyRandomList(Node* head);

    // String
    int lengthOfLongestSubstring(std::string s);
    std::string longestPalindrome(std::string s);
    std::string longestCommonPrefix(std::vector<std::string>& strs);
    bool isValid(std::string s);
    int strStr(std::string haystack, std::string needle);
    int lengthOfLastWord(std::string s);
    std::string addBinary(std::string a, std::string b);
    void reverseString(std::vector<char>& s);
    bool isSubsequence(std::string s, std::string t);
    int minFlipsMonoIncr(std::string s);
    std::string dayOfTheWeek(int day, int month, int year);

    // Array
    int removeDuplicates(std::vector<int>& nums);
    int removeElement(std::vector<int>& nums, int val);
    int searchInsert(std::vector<int>& nums, int target);
    int maxSubArray(std::vector<int>& nums);
    std::vector<int> plusOne(std::vector<int>& digits);
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval);
    int maxSubarraySumCircular(std::vector<int>& nums);
    int subarraysDivByK(std::vector<int>& nums, int k);
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums);
    int totalFruit(std::vector<int>& fruits);
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

    // Tree
    std::vector<int> inorderTraversal(TreeNode* root);
    bool isSameTree(TreeNode* p, TreeNode* q);
    bool isSymmetric(TreeNode* root);
    int maxDepth(TreeNode* root);
    TreeNode* sortedArrayToBST(std::vector<int>& nums);
    bool isBalanced(TreeNode* root);
    int minDepth(TreeNode* root);
    std::vector<int> countSubTrees(int n, std::vector<std::vector<int>>& edges, std::string labels);
    int longestPath(std::vector<int>& parent, std::string s);
    QuadTree::Node* construct(std::vector<std::vector<int>>& grid);

    // Dynamic Programming
    int fib(int n);
    int climbStairs(int n);
    int maxProfit(int k, std::vector<int>& prices);
    int rob(std::vector<int>& nums);
    bool wordBreak(std::string s, std::vector<std::string>& wordDict);
    int coinChange(std::vector<int>& coins, int amount);
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
    int maximalSquare(std::vector<std::vector<char>>& matrix);

    // Math
    bool isPalindrome(int x);
    int romanToInt(std::string s);
    int mySqrt(int x);

    // Heap / Priority Queue
    int findKthLargest(std::vector<int>& nums, int k);
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k);
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital);
    GraphNode* cloneGraph(GraphNode* node);
    ListNode* reverseKGroup(ListNode* head, int k);
    int maxPoints(std::vector<std::vector<int>>& points);

    // Comparison utilities
public:
    static bool eq(ListNode* l1, ListNode* l2);
    static bool eq(TreeNode* t1, TreeNode* t2);
    static bool eq(QuadTree::Node* t1, QuadTree::Node* t2);
};
