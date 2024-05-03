# Matrix Addition Profiling

This repository contains the code and analysis for a profiling task performed on two different implementations of matrix addition. In one implementation, the elements of a matrix are summed row-wise, while in the other, they are summed column-wise.

## Overview
Matrix addition is a fundamental operation in linear algebra that involves adding corresponding elements of two matrices. The performance of this operation can be significantly affected by the way data is accessed and processed, particularly in terms of cache behavior.

In this work, we compare two implementations of matrix addition:

1. Row-wise addition: The elements of the matrices are accessed and added row by row. This approach tends to have better cache performance due to the sequential memory access pattern, which results in fewer cache misses.
2. Column-wise addition: The elements of the matrices are accessed and added column by column. This approach tends to have worse cache performance due to the non-sequential memory access pattern, which results in more cache misses.

## Profiling Results
The profiling results show that the row-wise addition implementation performs significantly better than the column-wise addition implementation. This is primarily due to the difference in cache behavior between the two implementations.

In the row-wise addition, the data is accessed sequentially, which aligns well with how data is stored in memory and how the cache works. This results in a higher cache hit rate and fewer cache misses.

On the other hand, in the column-wise addition, the data is accessed in a non-sequential manner. This leads to a lower cache hit rate and more cache misses, which significantly degrades the performance.

Valgrind results after profiling can be seen in 'Statistics' folder

## Conclusion
The profiling results highlight the importance of considering cache behavior when designing and optimizing algorithms, especially for operations involving large data structures like matrices. The row-wise addition implementation, which takes advantage of the cache by accessing data sequentially, performs significantly better than the column-wise addition implementation.
