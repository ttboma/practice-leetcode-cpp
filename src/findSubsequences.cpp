#include "solution.h"
#include <set>

template <typename T> using Vec = std::vector<T>;

Vec<Vec<int>> Solution::findSubsequences(Vec<int> &nums) {
  std::set<Vec<int>> result;
  Vec<int> sequence;
  auto backtrack = [&](int index, auto &&backtrack) -> void {
    // if we have checked all elements
    if (index == nums.size()) {
      if (sequence.size() >= 2) {
        result.insert(sequence);
      }
      return;
    }
    // if the sequence remains increasing after appending nums[index]
    if (sequence.empty() || sequence.back() <= nums[index]) {
      // append nums[index] to the sequence
      sequence.push_back(nums[index]);
      // call recursively
      backtrack(index + 1, backtrack);
      // delete nums[index] from the end of the sequence
      sequence.pop_back();
    }
    // call recursively not appending an element
    backtrack(index + 1, backtrack);
  };
  backtrack(0, backtrack);
  return Vec<Vec<int>>(std::make_move_iterator(result.begin()),
                       std::make_move_iterator(result.end()));
}
