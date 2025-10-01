#include "sort/insertionSort.hpp"

#include <gtest/gtest.h>

TEST(insertionSort, example1_1) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(insertionSort, example1_2) {
    std::vector<std::string> vec{"banana", "apple", "orange", "grape", "kiwi"};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<std::string>{"apple", "banana", "grape", "kiwi", "orange"}));
}

TEST(insertionSort, example1_3) {
    std::vector<int> vec{1, 2, 3, 4, 5};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(insertionSort, example1_4) {
    std::vector<int> vec{5, 4, 3, 2, 1};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(insertionSort, example1_5) {
    std::vector<int> vec{1, 2, 3, 2};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 2, 3}));
}

TEST(insertionSort, example1_6) {
    std::vector<int> vec{5, 5, 5, 5, 5};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(insertionSort, example1_7) {
    std::vector<int> vec{};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{}));
}

TEST(insertionSort, example1_8) {
    std::vector<int> vec{1};
    insertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1}));
}

TEST(insertionSort, example1_9) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    insertionSort(vec.begin(), vec.end(), std::greater<>{});
    EXPECT_EQ(vec, (std::vector<int>{8, 7, 6, 5, 4, 3, 2, 1}));
}

TEST(insertionSort, example2_1) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(insertionSort, example2_2) {
    std::vector<std::string> vec{"banana", "apple", "orange", "grape", "kiwi"};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<std::string>{"apple", "banana", "grape", "kiwi", "orange"}));
}

TEST(insertionSort, example2_3) {
    std::vector<int> vec{1, 2, 3, 4, 5};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(insertionSort, example2_4) {
    std::vector<int> vec{5, 4, 3, 2, 1};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(insertionSort, example2_5) {
    std::vector<int> vec{1, 2, 3, 2};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1, 2, 2, 3}));
}

TEST(insertionSort, example2_6) {
    std::vector<int> vec{5, 5, 5, 5, 5};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{5, 5, 5, 5, 5}));
}

TEST(insertionSort, example2_7) {
    std::vector<int> vec{};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{}));
}

TEST(insertionSort, example2_8) {
    std::vector<int> vec{1};
    binaryInsertionSort(vec.begin(), vec.end(), std::less<>{});
    EXPECT_EQ(vec, (std::vector<int>{1}));
}

TEST(insertionSort, example2_9) {
    std::vector<int> vec{5, 3, 8, 6, 2, 7, 4, 1};
    binaryInsertionSort(vec.begin(), vec.end(), std::greater<>{});
    EXPECT_EQ(vec, (std::vector<int>{8, 7, 6, 5, 4, 3, 2, 1}));
}
