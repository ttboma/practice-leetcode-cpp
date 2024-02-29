#include "solution.h"

int Solution::maxProfit(std::vector<int> &prices) {
  int profit = 0;
  for (unsigned i = 1; i != prices.size(); ++i) {
    auto diff = prices[i] - prices[i - 1];
    if (diff > 0) {
      profit += diff;
    }
  }
  return profit;
}
