#include "solution.hpp"

/// # 221. Maximal Square
///
/// <https://leetcode.com/problems/maximal-square/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// Given an <code>m x n</code> binary <code>matrix</code> filled with <code>0</code>'s and <code>1</code>'s, find the
/// largest square containing only <code>1</code>'s and return its area.
///
/// **Example 1:**
/// <img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg" style="width: 400px; height: 319px;">
///
/// ```
/// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
/// Output: 4
/// ```
///
/// **Example 2:**
/// <img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg" style="width: 165px; height: 165px;">
///
/// ```
/// Input: matrix = [["0","1"],["1","0"]]
/// Output: 1
/// ```
///
/// **Example 3:**
///
/// ```
/// Input: matrix = [["0"]]
/// Output: 0
/// ```
///
/// **Constraints:**
///
/// - <code>m == matrix.length</code>
/// - <code>n == matrix[i].length</code>
/// - <code>1 <= m, n <= 300</code>
/// - <code>matrix[i][j]</code> is <code>'0'</code> or <code>'1'</code>.
int Solution::maximalSquare(std::vector<std::vector<char>>& matrix) {
    auto n = matrix.size();
    auto m = matrix[0].size();
    std::vector<std::vector<int>> square(n, std::vector<int>(m));
    auto width = 0;
    for (auto i = 0; i != n; ++i) {
        for (auto j = 0; j != m; ++j) {
            if (matrix[i][j] == '1') {
                width = 1;
                square[i][j] = 1;
            } else {
                square[i][j] = 0;
            }
        }
    }
    for (auto i = 1; i != n; ++i) {
        for (auto j = 1; j != m; ++j) {
            if (square[i][j] == 0) continue;
            int l[] = {square[i - 1][j], square[i][j - 1], square[i - 1][j - 1]};
            square[i][j] = 1 + *std::min_element(std::begin(l), std::end(l));
            width = width < square[i][j] ? square[i][j] : width;
        }
    }
    return width * width;
}
