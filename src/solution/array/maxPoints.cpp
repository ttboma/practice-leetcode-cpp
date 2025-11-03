#include "solution.hpp"

/// # 149. Max Points on a Line
///
/// https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150
///
/// Given an array of <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a
/// point on the **X-Y**  plane, return the maximum number of points that lie on the same straight line.
///
/// **Example 1:**
/// <img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg" style="width: 300px; height: 294px;">
///
/// ```
/// Input: points = [[1,1],[2,2],[3,3]]
/// Output: 3
/// ```
///
/// **Example 2:**
/// <img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg" style="width: 300px; height: 294px;">
///
/// ```
/// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
/// Output: 4
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= points.length <= 300</code>
/// - <code>points[i].length == 2</code>
/// - <code>-10^4 <= x<sub>i</sub>, y<sub>i</sub> <= 10^4</code>
/// - All the <code>points</code> are **unique** .
int Solution::maxPoints(std::vector<std::vector<int>>& points) {
    int maxNumPoints = 0;
    for (size_t i = 0; i != points.size(); ++i) {
        std::unordered_map<double, int> slopeCount;
        for (size_t j = 0; j != points.size(); ++j) {
            if (i == j)
                continue;
            auto const& p1 = points[i];
            auto const& p2 = points[j];
            auto slope = double(p2[1] - p1[1]) / double(p2[0] - p1[0]);
            maxNumPoints = std::max(++slopeCount[slope], maxNumPoints);
        }
    }
    return maxNumPoints + 1;
}
