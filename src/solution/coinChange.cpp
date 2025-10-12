#include "solution/solution.hpp"

enum class Color { White, Grey, Black };

int Solution::coinChange(std::vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    std::unordered_map<int, Color> status;
    std::deque<int> queue;

    int depth = 0;
    queue.push_back(0);
    status.insert({0, Color::Grey});
    while (!queue.empty()) {
        std::deque<int> next_queue;
        std::optional<int> min_acc;
        while (!queue.empty()) {
            auto f = queue.front();
            queue.pop_front();
            for (auto const& coin : coins) {
                auto acc = f + coin;
                if (status[acc] != Color::White) {
                    continue;
                }
                if (acc == amount) {
                    return depth + 1;
                }
                if (min_acc.has_value()) {
                    min_acc = std::min(*min_acc, acc);
                } else {
                    min_acc = acc;
                }
                next_queue.push_back(acc);
                status[acc] = Color::Grey;
            }
            status[f] = Color::Black;
        }
        if (amount <= *min_acc) return -1;
        queue = std::move(next_queue);
        ++depth;
    }

    return -1;
}
