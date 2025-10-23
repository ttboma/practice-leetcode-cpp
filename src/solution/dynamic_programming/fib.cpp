#include "solution.hpp"

namespace {
#if defined(FIB_IMPL_RECURSIVE)
int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
#elif defined(FIB_IMPL_RECURSIVE_PRUNE_WITH_CACHE)
    #include <vector>
int fib_cache(int n, std::vector<int>& cache) {
    if (n < cache.size()) {
        return cache[n];
    }
    cache.push_back(fib_cache(n - 1, cache) + fib_cache(n - 2, cache));
    return cache[n];
}

int fib(int n) {
    std::vector<int> cache{0, 1};
    return fib_cache(n, cache);
}
#elif defined(GENERAL_RECURSIVE_PRUNE_WITH_CACHE)
// Recursive memoization wrapper
template <class Sig, class F>
class memoize_recursive_helper;

template <class Result, class... Args, class F>
class memoize_recursive_helper<Result(Args...), F> {
private:
    using args_tuple_type = std::tuple<std::decay_t<Args>...>;

    F f;
    mutable std::map<args_tuple_type, Result> m_cache;
    mutable std::recursive_mutex m_cache_mutex;

public:
    template <typename Function>
    explicit memoize_recursive_helper(Function&& f_) : f(std::forward<Function>(f_)) {}

    Result operator()(Args... args) const {
        std::unique_lock<std::recursive_mutex> lock{m_cache_mutex};
        args_tuple_type args_tuple{args...};

        if (auto it = m_cache.find(args_tuple); it != m_cache.end()) {
            return it->second;
        }

        // Call lambda with recursive handle (*this) and args
        Result result = f(*this, std::forward<Args>(args)...);
        m_cache[args_tuple] = result;
        return result;
    }
};

template <class Sig, class F>
auto make_memoized_r(F&& f) {
    return memoize_recursive_helper<Sig, std::decay_t<F>>(std::forward<F>(f));
}
#elif defined(FIB_IMPL_TAIL_RECURSIVE)
int fib_start_with(int n, int prev, int curr) {
    if (n == 0)
        return prev;
    return fib_start_with(n - 1, curr, prev + curr);
}

int fib(int n) {
    // expresses "fib starts with 0 and 1"
    return fib_start_with(n, 0, 1);
}
#elif defined(FIB_IMPL_TAIL_RECURSIVE_EQUIVALENT_LOOP)
int fib(int n) {
    int prev = 0, curr = 1;
    while (n > 0) {
        int next = prev + curr;
        prev = curr;
        curr = next;
        n--;  // same as fib_start_with(n - 1, ...)
    }
    return prev;
}
#elif defined(FIB_IMPL_DYNAMIC_PROGRAMMING)
int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}
#endif
}  // namespace

/// # 509. Fibonacci Number
///
/// <https://leetcode.com/problems/fibonacci-number/>
///
/// The <b>Fibonacci numbers</b>, commonly denoted `F(n)` form a sequence,
/// called the <b>Fibonacci sequence</b>, such that each number is the sum of
/// the two preceding ones, starting from `0` and `1`. That is,
///
/// ```
/// F(0) = 0, F(1) = 1
/// F(n) = F(n - 1) + F(n - 2), for n > 1.
/// ```
///
/// Given `n`, calculate `F(n)`.
///
/// **Example 1:**
///
/// ```txt
/// Input: n = 2
/// Output: 1
/// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
/// ```
///
/// **Example 2:**
///
/// ```txt
/// Input: n = 3
/// Output: 2
/// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
/// ```
///
/// **Example 3:**
///
/// ```txt
/// Input: n = 4
/// Output: 3
/// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
/// ```
///
/// **Constraints:**
///
/// - `0 <= n <= 30`
int Solution::fib(int n) {
#if defined(FIB_IMPL_RECURSIVE)
    return ::fib(n);
#elif defined(FIB_IMPL_RECURSIVE_PRUNE_WITH_CACHE)
    return ::fib(n);
#elif defined(GENERAL_RECURSIVE_PRUNE_WITH_CACHE)
    auto fibmemo = make_memoized_r<unsigned int(unsigned int)>([](auto& fib, unsigned int n) -> unsigned int {
        return n == 0 ? 0 : n == 1 ? 1 : fib(n - 1) + fib(n - 2);
    });
    return fibmemo(n);
#elif defined(FIB_IMPL_TAIL_RECURSIVE)
    return fib_start_with(n, 0, 1);
#elif defined(FIB_IMPL_TAIL_RECURSIVE_EQUIVALENT_LOOP)
    return ::fib(n);
#elif defined(FIB_IMPL_DYNAMIC_PROGRAMMING)
    return ::fib(n);
#else
    #error "No FIB_IMPL_* defined"
#endif
}
