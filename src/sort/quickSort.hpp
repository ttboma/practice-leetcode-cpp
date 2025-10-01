#pragma once

#include <algorithm>
#include <iterator>

template <typename RandomAccessIterator, typename Cmp>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Cmp cmp) {
    if (first == last) return;

    // More balanced pivot selection for a sorted range
    auto pivot = *std::next(first, std::distance(first, last) / 2);

    // Three-way partitioning to handle duplicates efficiently
    auto middle1 = std::partition(first, last, [&](const auto& em) { return cmp(em, pivot); });
    auto middle2 = std::partition(middle1, last, [&](const auto& em) { return !cmp(pivot, em); });

    quickSort(first, middle1, cmp);
    quickSort(middle2, last, cmp);
}
