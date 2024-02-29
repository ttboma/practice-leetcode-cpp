#include "solution.h"

std::vector<int> Solution::countSubTrees(int n,
                                         std::vector<std::vector<int>> &edges,
                                         std::string labels) {
  auto ret = std::vector<int>(n, 0);

  std::vector<std::vector<int>> adjM(n, std::vector<int>{});
  for (auto const &e : edges) {
    adjM[e[0]].push_back(e[1]);
    adjM[e[1]].push_back(e[0]);
  }

  std::vector<int> freq_map(26, 0);

  auto F = [&](int index, int prev, auto &&F) -> void {
    auto offset = labels[index] - 'a';
    auto prev_value = freq_map[offset]++;
    for (auto next : adjM[index]) {
      if (next != prev) {
        F(next, index, F);
      }
    }
    ret[index] = freq_map[offset] - prev_value;
  };
  F(0, 0, F);

  return ret;
}
