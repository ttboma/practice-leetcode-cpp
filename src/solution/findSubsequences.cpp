#include "solution.hpp"

std::vector<std::vector<int>> Solution::findSubsequences(std::vector<int> &nums) {
    std::set<std::vector<int>> result;
    std::vector<int> sequence;
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
    return std::vector<std::vector<int>>(std::make_move_iterator(result.begin()),
                                         std::make_move_iterator(result.end()));
}
