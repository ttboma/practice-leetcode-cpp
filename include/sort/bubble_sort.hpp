#pragma once
#include <algorithm>
#include <iterator>

template <typename BidirectionalIterator, typename Cmp>
void bubbleSort(BidirectionalIterator first, BidirectionalIterator last, Cmp cmp) {
    if (first == last)
        return;
    for (bool isSorted = false; !isSorted; --last) {
        isSorted = true;
        for (BidirectionalIterator i = first, j = std::next(first); j != last; ++i, ++j) {
            if (cmp(*i, *j))
                continue;
            std::iter_swap(i, j);
            isSorted = false;
        }
    }
}
