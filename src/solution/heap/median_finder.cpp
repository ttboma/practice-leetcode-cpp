#include "solution.hpp"

void MedianFinder::addNum(int num) {
    if (maxHeap.empty()) {
        minHeap.push(num);
    } else if (num < minHeap.top()) {
        maxHeap.push(num);
    } else {
        minHeap.push(num);
    }

    // Balance the heaps
    if (maxHeap.size() + 1 < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    } else if (maxHeap.size() > minHeap.size()) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
}

double MedianFinder::findMedian() {
    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    return minHeap.top();
}
