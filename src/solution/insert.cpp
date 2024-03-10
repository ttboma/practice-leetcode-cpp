#include "solution.h"

std::vector<std::vector<int>> Solution::insert(
    std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) {
  auto cmp = [](int a, std::vector<int> const &b) { return a < b[0]; };
  auto it =
      std::upper_bound(intervals.begin(), intervals.end(), newInterval[0], cmp);
  auto it_end = std::upper_bound(it, intervals.end(), newInterval[1], cmp);

  if (it != intervals.begin() && newInterval[0] <= (*std::prev(it))[1]) {
    newInterval[0] = (*--it)[0];
  }
  if (it != it_end && newInterval[1] <= (*std::prev(it_end))[1]) {
    newInterval[1] = (*std::prev(it_end))[1];
  }
  it = intervals.erase(it, it_end);
  intervals.insert(it, std::move(newInterval));

  return intervals;
}
