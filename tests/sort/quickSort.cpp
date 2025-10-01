#include "sort/quickSort.hpp"

#include <gtest/gtest.h>

TEST(quickSort, example1) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(quickSort, example2) {
    std::vector<std::string> vec{"banana", "apple", "orange", "grape", "kiwi"};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<std::string>{"apple", "banana", "grape", "kiwi", "orange"}));
}

TEST(quickSort, example3) {
    std::vector<int> vec{1, 2, 3, 4, 5};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(quickSort, example4) {
    std::vector<int> vec{5, 4, 3, 2, 1};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(quickSort, example5) {
    std::vector<int> vec{1, 2, 3, 2};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 2, 3}));
}

TEST(quickSort, example6) {
    std::vector<int> vec{5, 5, 5, 5, 5};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(quickSort, example7) {
    std::vector<int> vec{};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{}));
}

TEST(quickSort, example8) {
    std::vector<int> vec{1};
    quickSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1}));
}

TEST(quickSort, example9) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    quickSort(vec.begin(), vec.end(), std::greater<>{});
    EXPECT_EQ(vec, (std::vector<int>{8, 7, 6, 5, 4, 3, 2, 1}));
}
