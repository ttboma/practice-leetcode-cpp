#include <limits>

#include "solution.hpp"

class MaxProfitSolver {
public:
    MaxProfitSolver(std::vector<int>& prices) : mPrices(prices) {}

    int operator()(int k, int day) { return dynamicProgrammingComputeMaxProfit(k, day); }

private:
    std::vector<int>& mPrices;

    int recursivelyComputeMaxProfit(int k, int day) {
        if (k == 0 || day == 0) {
            return 0;
        }

        int maxProfitWithoutTransaction = (*this)(k, day - 1);
        int maxProfitWithTransaction = 0;

        for (int m = 0; m < day; ++m) {
            int profitIfSoldToday = mPrices[day] - mPrices[m] + (*this)(k - 1, m);
            maxProfitWithTransaction = std::max(maxProfitWithTransaction, profitIfSoldToday);
        }

        return std::max(maxProfitWithoutTransaction, maxProfitWithTransaction);
    }

    int dynamicProgrammingComputeMaxProfit(int k, int day) {
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(day + 1, 0));

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= day; ++j) {
                dp[i][j] = dp[i][j - 1];
                for (int m = 0; m < j; ++m) {
                    int profitIfSoldToday = mPrices[j] - mPrices[m] + dp[i - 1][m];
                    dp[i][j] = std::max(dp[i][j], profitIfSoldToday);
                }
            }
        }

        return dp[k][day];
    }

    int accumulatedMaxProfit(int k, int day) {
        std::vector<int> hold(k + 1, std::numeric_limits<int>::min());
        std::vector<int> release(k + 1, 0);

        for (int i = 0; i <= day; ++i) {
            for (int j = 1; j <= k; ++j) {
                hold[j] = std::max(hold[j], release[j - 1] - mPrices[i]);
                release[j] = std::max(release[j], hold[j] + mPrices[i]);
            }
        }

        return release[k];
    }
};

/// # 188. Best Time to Buy and Sell Stock IV
///
/// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/?envType=study-plan-v2&envId=top-interview-150
///
/// You are given an integer array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the
/// <code>i^th</code> day, and an integer <code>k</code>.
///
/// Find the maximum profit you can achieve. You may complete at most <code>k</code> transactions: i.e. you may buy at
/// most <code>k</code> times and sell at most <code>k</code> times.
///
/// **Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy
/// again).
///
/// **Example 1:**
///
/// ```
/// Input: k = 2, prices = [2,4,1]
/// Output: 2
/// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
/// ```
///
/// **Example 2:**
///
/// ```
/// Input: k = 2, prices = [3,2,6,5,0,3]
/// Output: 7
/// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0)
/// and sell on day 6 (price = 3), profit = 3-0 = 3.
/// ```
///
/// **Constraints:**
///
/// - <code>1 <= k <= 100</code>
/// - <code>1 <= prices.length <= 1000</code>
/// - <code>0 <= prices[i] <= 1000</code>
int Solution::maxProfit(int k, std::vector<int>& prices) {
    MaxProfitSolver solver(prices);
    return solver(k, prices.size() - 1);
}
