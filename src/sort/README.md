# 📊 Sorting Algorithms Complexity Table

| Algorithm          | Best Case Time | Average Time | Worst Case Time | Space Complexity | Notes                                                        |
| ------------------ | -------------- | ------------ | --------------- | ---------------- | ------------------------------------------------------------ |
| **Bubble Sort**    | O(n)           | O(n²)        | O(n²)           | O(1)             | Best case O(n) when already sorted (with flag)               |
| **Insertion Sort** | O(n)           | O(n²)        | O(n²)           | O(1)             | Adaptive, good for small/partially sorted data               |
| **Selection Sort** | O(n²)          | O(n²)        | O(n²)           | O(1)             | Does minimum swaps, useful when swaps are expensive          |
| **Merge Sort**     | O(n log n)     | O(n log n)   | O(n log n)      | O(n)             | Stable, guarantees O(n log n), needs extra memory            |
| **Quick Sort**     | O(n log n)     | O(n log n)   | O(n²)           | O(log n) (avg)   | In-place, very fast in practice, but worst case O(n²)        |
| **Heap Sort**      | O(n log n)     | O(n log n)   | O(n log n)      | O(1)             | In-place, not stable, slower constants than quicksort        |
| **Counting Sort**  | O(n + k)       | O(n + k)     | O(n + k)        | O(k)             | Works only for integers in limited range [0..k]              |
| **Radix Sort**     | O(n·k)         | O(n·k)       | O(n·k)          | O(n + k)         | Depends on digit count `k`, uses counting sort as subroutine |
| **Bucket Sort**    | O(n + k)       | O(n + k)     | O(n²)           | O(n + k)         | Distribution-based, efficient for uniform input              |
