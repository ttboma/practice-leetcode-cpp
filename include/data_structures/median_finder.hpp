#pragma once

#include <functional>
#include <queue>
#include <vector>

/// # 295. Find Median from Data Stream
///
/// <https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150>
///
/// The **median**  is the middle value in an ordered integer list. If the size of the list is even, there is no middle
/// value, and the median is the mean of the two middle values.
///
/// - For example, for <code>arr = [2,3,4]</code>, the median is <code>3</code>.
/// - For example, for <code>arr = [2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code>.
///
/// Implement the MedianFinder class:
///
/// - <code>MedianFinder()</code> initializes the <code>MedianFinder</code> object.
/// - <code>void addNum(int num)</code> adds the integer <code>num</code> from the data stream to the data structure.
/// - <code>double findMedian()</code> returns the median of all elements so far. Answers within <code>10^-5</code> of
/// the actual answer will be accepted.
///
/// **Example 1:**
///
/// ```
/// Input
///
/// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
/// [[], [1], [2], [], [3], []]
/// Output
///
/// [null, null, null, 1.5, null, 2.0]
///
/// Explanation
///
/// MedianFinder medianFinder = new MedianFinder();
/// medianFinder.addNum(1);    // arr = [1]
/// medianFinder.addNum(2);    // arr = [1, 2]
/// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
/// medianFinder.addNum(3);    // arr[1, 2, 3]
/// medianFinder.findMedian(); // return 2.0
/// ```
///
/// **Constraints:**
///
/// - <code>-10^5 <= num <= 10^5</code>
/// - There will be at least one element in the data structure before calling <code>findMedian</code>.
/// - At most <code>5 * 10^4</code> calls will be made to <code>addNum</code> and <code>findMedian</code>.
///
/// **Follow up:**
///
/// - If all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your
/// solution?
/// - If <code>99%</code> of all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you
/// optimize your solution?
class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::less<>> maxHeap;     // Lower half
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;  // Upper half
public:
    MedianFinder() = default;
    void addNum(int num);
    double findMedian();
};
