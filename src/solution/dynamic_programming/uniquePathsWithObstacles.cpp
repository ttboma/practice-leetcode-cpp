#include "solution.hpp"

/// # 63. Unique Paths II
///
/// <https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// You are given an <code>m x n</code> integer array <code>grid</code>. There is a robot initially located at the
/// <b>top-left corner</b> (i.e., <code>grid[0][0]</code>). The robot tries to move to the **bottom-right corner**
/// (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.
///
/// An obstacle and space are marked as <code>1</code> or <code>0</code> respectively in <code>grid</code>. A path that
/// the robot takes cannot include **any**  square that is an obstacle.
///
/// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
///
/// The testcases are generated so that the answer will be less than or equal to <code>2 * 10^9</code>.
///
/// **Example 1:**
/// <img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" style="width: 242px; height: 242px;">
///
/// ```
/// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
/// Output: 2
/// Explanation: There is one obstacle in the middle of the 3x3 grid above.
/// There are two ways to reach the bottom-right corner:
/// 1. Right -> Right -> Down -> Down
/// 2. Down -> Down -> Right -> Right
/// ```
///
/// **Example 2:**
/// <img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" style="width: 162px; height: 162px;">
///
/// ```
/// Input: obstacleGrid = [[0,1],[0,0]]
/// Output: 1
/// ```
///
/// **Constraints:**
///
/// - <code>m == obstacleGrid.length</code>
/// - <code>n == obstacleGrid[i].length</code>
/// - <code>1 <= m, n <= 100</code>
/// - <code>obstacleGrid[i][j]</code> is <code>0</code> or <code>1</code>.
int Solution::uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    auto sol = std::vector<std::vector<int>>(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size()));
    auto isObstacle = [](auto const& g) { return g == 1; };
    auto it = std::find_if(obstacleGrid[0].begin(), obstacleGrid[0].end(), isObstacle);
    std::fill(sol[0].begin(), sol[0].begin() + std::distance(obstacleGrid[0].begin(), it), 1);
    for (int i = 1; i != static_cast<int>(sol.size()); ++i) {
        for (int j = 0; j != static_cast<int>(sol[0].size()); ++j) {
            if (isObstacle(obstacleGrid[i][j]))
                continue;
            sol[i][j] = (i != 0 ? sol[i - 1][j] : 0) + (j != 0 ? sol[i][j - 1] : 0);
        }
    }
    return *sol.rbegin()->rbegin();
}
