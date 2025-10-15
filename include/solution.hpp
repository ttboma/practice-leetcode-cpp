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
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital);
    int rob(std::vector<int>& nums);
    bool wordBreak(std::string s, std::vector<std::string>& wordDict);
    int coinChange(std::vector<int>& coins, int amount);
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);

    // Comparison utilities
   public:
    static bool eq(ListNode* l1, ListNode* l2);
    static bool eq(TreeNode* t1, TreeNode* t2);
    static bool eq(QuadTree::Node* t1, QuadTree::Node* t2);
};

/// # 295. Find Median from Data Stream
///
/// <https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// The **median**  is the middle value in an ordered integer list. If the size of the list is even, there is no middle
/// value, and the median is the mean of the two middle values.
///
/// - For example, for <code>arr = [2,3,4]</code>, the median is <code>3</code>.
/// - For example, for <code>arr = [2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code>.
///
/// Implement the MedianFinder class:
///
/// - <code>MedianFinder()</code> initializes the <code>MedianFinder</code> object.
/// - <code>void addNum(int num)</code> adds the integer <code>num</code> from the data stream to the data structure.
/// - <code>double findMedian()</code> returns the median of all elements so far. Answers within <code>10^-5</code> of
/// the actual answer will be accepted.
///
/// **Example 1:**
///
/// ```
/// Input
///
/// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
/// [[], [1], [2], [], [3], []]
/// Output
///
/// [null, null, null, 1.5, null, 2.0]
///
/// Explanation
///
/// MedianFinder medianFinder = new MedianFinder();
/// medianFinder.addNum(1);    // arr = [1]
/// medianFinder.addNum(2);    // arr = [1, 2]
/// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
/// medianFinder.addNum(3);    // arr[1, 2, 3]
/// medianFinder.findMedian(); // return 2.0
/// ```
///
/// **Constraints:**
///
/// - <code>-10^5 <= num <= 10^5</code>
/// - There will be at least one element in the data structure before calling <code>findMedian</code>.
/// - At most <code>5 * 10^4</code> calls will be made to <code>addNum</code> and <code>findMedian</code>.
///
/// **Follow up:**
///
/// - If all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your
/// solution?
/// - If <code>99%</code> of all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you
/// optimize your solution?
class MedianFinder {
   private:
    std::priority_queue<int, std::vector<int>, std::less<>> maxHeap;     // Lower half
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;  // Upper half
   public:
    MedianFinder() = default;
    void addNum(int num);
    double findMedian();
};
