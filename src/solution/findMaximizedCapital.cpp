#include "solution/solution.hpp"

/// # 502. IPO
///
/// <https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// Suppose LeetCode will start its **IPO**  soon. In order to sell a good price of its shares to Venture Capital,
/// LeetCode would like to work on some projects to increase its capital before the **IPO** . Since it has limited
/// resources, it can only finish at most <code>k</code> distinct projects before the **IPO** . Help LeetCode design the
/// best way to maximize its total capital after finishing at most <code>k</code> distinct projects.
///
/// You are given <code>n</code> projects where the <code>i^th</code> project has a pure profit <code>profits[i]</code>
/// and a minimum capital of <code>capital[i]</code> is needed to start it.
///
/// Initially, you have <code>w</code> capital. When you finish a project, you will obtain its pure profit and the
/// profit will be added to your total capital.
///
/// Pick a list of **at most**  <code>k</code> distinct projects from given projects to **maximize your final capital**
/// , and return the final maximized capital.
///
/// The answer is guaranteed to fit in a 32-bit signed integer.
///
/// **Example 1:**
///
/// ```
/// Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
/// Output: 4
/// Explanation: Since your initial capital is 0, you can only start the project indexed 0.
/// After finishing it you will obtain profit 1 and your capital becomes 1.
/// With capital 1, you can either start the project indexed 1 or the project indexed 2.
/// Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
/// Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
/// Output: 6
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= k <= 10^5</code>
/// - <code>0 <= w <= 10^9</code>
/// - <code>n == profits.length</code>
/// - <code>n == capital.length</code>
/// - <code>1 <= n <= 10^5</code>
/// - <code>0 <= profits[i] <= 10^4</code>
/// - <code>0 <= capital[i] <= 10^9</code>
int Solution::findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
    using idx_t = std::vector<int>::size_type;

    std::vector<idx_t> index(profits.size(), 0);
    std::iota(index.begin(), index.end(), 0);
    std::sort(index.begin(), index.end(), [&](const auto& a, const auto& b) { return capital[a] < capital[b]; });

    auto cmp = [&](const auto& a, const auto& b) { return profits[a] < profits[b]; };
    std::priority_queue<idx_t, std::vector<idx_t>, decltype(cmp)> heap(cmp);

    for (auto first = index.begin(); k > 0; --k) {
        auto p = std::upper_bound(first, index.end(), w, [&](int value, int idx) { return value < capital[idx]; });
        while (first != p) heap.push(*first++);
        if (heap.empty()) break;
        w += profits[heap.top()];
        heap.pop();
    }

    return w;
}
