#include "sort/bubbleSort.hpp"

#include <gtest/gtest.h>

TEST(bubbleSort, example1) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(bubbleSort, example2) {
    std::vector<std::string> vec{"banana", "apple", "orange", "grape", "kiwi"};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<std::string>{"apple", "banana", "grape", "kiwi", "orange"}));
}

TEST(bubbleSort, example3) {
    std::vector<int> vec{1, 2, 3, 4, 5};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(bubbleSort, example4) {
    std::vector<int> vec{5, 4, 3, 2, 1};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(bubbleSort, example5) {
    std::vector<int> vec{1, 2, 3, 2};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 2, 3}));
}

TEST(bubbleSort, example6) {
    std::vector<int> vec{5, 5, 5, 5, 5};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(bubbleSort, example7) {
    std::vector<int> vec{};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{}));
}

TEST(bubbleSort, example8) {
    std::vector<int> vec{1};
    bubbleSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1}));
}

TEST(bubbleSort, example9) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    bubbleSort(vec.begin(), vec.end(), std::greater<>{});
    EXPECT_EQ(vec, (std::vector<int>{8, 7, 6, 5, 4, 3, 2, 1}));
}
