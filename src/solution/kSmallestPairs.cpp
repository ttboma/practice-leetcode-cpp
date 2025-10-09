#include "solution/solution.hpp"

namespace {
std::vector<std::vector<int>> kSmallestPairs_impl_1(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    using size_t = std::vector<int>::size_type;

    std::vector<std::vector<int>> result;
    auto cmp = [&](const std::tuple<size_t, size_t, int>& a, const std::tuple<size_t, size_t, int>& b) {
        return std::get<2>(a) > std::get<2>(b);
    };
    std::priority_queue<std::tuple<size_t, size_t, int>, std::vector<std::tuple<size_t, size_t, int>>, decltype(cmp)>
        minHeap(cmp);
    std::set<std::pair<size_t, size_t>> visited;

    minHeap.emplace(0, 0, nums1[0] + nums2[0]);
    visited.emplace(0, 0);

    while (k-- > 0 && !minHeap.empty()) {
        auto [i, j, sum] = minHeap.top();
        minHeap.pop();
        result.push_back({nums1[i], nums2[j]});

        // i + 1, j
        if (i + 1 < nums1.size() && visited.find({i + 1, j}) == visited.end()) {
            minHeap.emplace(i + 1, j, nums1[i + 1] + nums2[j]);
            visited.emplace(i + 1, j);
        }

        if (j + 1 < nums2.size() && visited.find({i, j + 1}) == visited.end()) {
            minHeap.emplace(i, j + 1, nums1[i] + nums2[j + 1]);
            visited.emplace(i, j + 1);
        }
    }

    return result;
}
std::vector<std::vector<int>> kSmallestPairs_impl_2(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    using size_t = std::vector<int>::size_type;

    std::vector<std::vector<int>> result;
    auto cmp = [&](const std::pair<int, size_t> a, const std::pair<int, size_t> b) { return a.first > b.first; };
    std::priority_queue<std::pair<int, size_t>, std::vector<std::pair<int, size_t>>, decltype(cmp)> minHeap(cmp);

    for (size_t i = 0; i < nums1.size(); ++i) {
        minHeap.emplace(nums1[i] + nums2[0], 0);
    }

    while (k-- > 0 && !minHeap.empty()) {
        auto [sum, j] = minHeap.top();
        minHeap.pop();
        result.push_back({sum - nums2[j], nums2[j]});
        if (j + 1 < nums2.size()) {
            minHeap.emplace(sum - nums2[j] + nums2[j + 1], j + 1);
        }
    }

    return result;
}
}  // namespace

/// # [373. Find K Pairs with Smallest
/// Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150)
///
/// You are given two integer arrays <code>nums1</code> and <code>nums2</code> sorted in **non-decreasingorder**  and an
/// integer <code>k</code>.
///
/// Define a pair <code>(u, v)</code> which consists of one element from the first array and one element from the second
/// array.
///
/// Return the <code>k</code> pairs <code>(u<sub>1</sub>, v<sub>1</sub>), (u<sub>2</sub>, v<sub>2</sub>), ...,
/// (u<sub>k</sub>, v<sub>k</sub>)</code> with the smallest sums.
///
/// **Example 1:**
///
/// ```
/// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
/// Output: [[1,2],[1,4],[1,6]]
/// Explanation: The first 3 pairs are returned from the sequence:
/// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
/// Output: [[1,1],[1,1]]
/// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= nums1.length, nums2.length <= 10^5</code>
/// - <code>-10^9 <= nums1[i], nums2[i] <= 10^9</code>
/// - <code>nums1</code> and <code>nums2</code> both are sorted in **non-decreasing order** .
/// - <code>1 <= k <= 10^4</code>
/// - <code>k <=nums1.length *nums2.length</code>
std::vector<std::vector<int>> Solution::kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    return kSmallestPairs_impl_2(nums1, nums2, k);
}
