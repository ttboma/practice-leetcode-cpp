#pragma once
#include <algorithm>
#include <iterator>

template <typename ForwardIterator, typename Cmp>
void selection_sort(ForwardIterator begin, ForwardIterator end, Cmp cmp) {
    for (ForwardIterator it = begin; it != end; ++it)
        std::iter_swap(it, std::min_element(it, end, cmp));
}
