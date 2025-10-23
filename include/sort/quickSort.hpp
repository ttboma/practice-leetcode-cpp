#pragma once

#include <algorithm>
#include <iterator>

template <typename RandomAccessIterator, typename Cmp>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Cmp cmp) {
    if (first == last)
        return;

    // More balanced pivot selection for a sorted range
    auto pivot = *std::next(first, std::distance(first, last) / 2);

    // Three-way partitioning to handle duplicates efficiently
    auto middle1 = std::partition(first, last, [&](const auto& em) { return cmp(em, pivot); });
    auto middle2 = std::partition(middle1, last, [&](const auto& em) { return !cmp(pivot, em); });

    quickSort(first, middle1, cmp);
    quickSort(middle2, last, cmp);
}

template <typename RandomAccessIterator, typename Cmp, typename IdxType>
RandomAccessIterator quickSelect(RandomAccessIterator first, RandomAccessIterator last, Cmp cmp, IdxType k) {
    if (first == last)
        return first;

    auto pivot = *std::next(first, std::distance(first, last) / 2);

    auto middle1 = std::partition(first, last, [&](const auto& em) { return cmp(em, pivot); });

    if (k < std::distance(first, middle1)) {
        return quickSelect(first, middle1, cmp, k);
    }

    auto middle2 = std::partition(middle1, last, [&](const auto& em) { return !cmp(pivot, em); });

    if (k < std::distance(first, middle2)) {
        return middle1;
    } else {
        return quickSelect(middle2, last, cmp, k - std::distance(first, middle2));
    }
}
