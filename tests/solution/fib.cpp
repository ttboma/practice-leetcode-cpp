#include <gtest/gtest.h>

#include "solution/solution.hpp"

TEST(fib, example1) { EXPECT_EQ(Solution{}.fib(0), 0); }

TEST(fib, example2) { EXPECT_EQ(Solution{}.fib(1), 1); }

TEST(fib, example3) { EXPECT_EQ(Solution{}.fib(2), 1); }

TEST(fib, example4) { EXPECT_EQ(Solution{}.fib(3), 2); }

TEST(fib, example5) { EXPECT_EQ(Solution{}.fib(4), 3); }

TEST(fib, example6) { EXPECT_EQ(Solution{}.fib(5), 5); }
