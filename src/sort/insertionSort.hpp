#pragma once

#include <algorithm>
#include <iterator>

template <typename RandomAccessIterator, typename Cmp>
void binaryInsertionSort(RandomAccessIterator first, RandomAccessIterator last, Cmp cmp) {
    if (first == last) return;
    for (auto it = first + 1; it != last; ++it) {
        auto current = *it;

        // Find the insertion position using binary search
        auto insert_pos = std::upper_bound(first, it, current, cmp);

        // Move elements [insert_pos, it) one position to the right
        std::move_backward(insert_pos, it, it + 1);

        // Insert current element
        *insert_pos = current;
    }
}

template <typename RandomAccessIterator, typename Cmp>
void insertionSort(RandomAccessIterator first, RandomAccessIterator last, Cmp cmp) {
    if (first == last) return;
    for (auto it = first + 1; it != last; ++it) {
        auto current = *it;

        // Find the insertion position using binary search
        auto insert_pos = std::find_if(first, it, [&](const auto& em) { return cmp(current, em); });

        // Move elements [insert_pos, it) one position to the right
        std::move_backward(insert_pos, it, it + 1);

        // Insert current element
        *insert_pos = current;
    }
}
