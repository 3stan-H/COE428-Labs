# Lab 3 — Sorting

## Overview
A two-week lab implementing and analyzing two sorting algorithms — InsertionSort and MergeSort — using a shared `mySort()` interface and a provided metrics framework that tracks comparisons, copies, and swaps for performance analysis.

## Objectives
- Implement InsertionSort and MergeSort, each conforming to the `mySort()` signature
- Use the provided metrics framework (`myCompare()`, `myCopy()`, `mySwap()`) instead of native C comparison/assignment operators, so algorithm performance can be measured
- Derive theoretical best-, average-, and worst-case complexity equations (in terms of *n*) for both algorithms
- Use `make` to build the project

## Tools Required
- `gcc`
- `make`

## Files
- `insertionSort.c` — InsertionSort implementation
- `mergeSort.c` — MergeSort implementation
- `mySort.h` — shared signature: `void mySort(int data[], unsigned int first, unsigned int last);`
- Metrics framework files (provided) — implements `myCompare()`, `myCopy()`, `mySwap()` and reports statistics to `stderr`
- `README` — write-up including complexity analysis

## Instructions
1. Run `make` to confirm the provided stub project builds cleanly out of the box.
2. Implement InsertionSort in `insertionSort.c` first, without metrics: for each unsorted element, find its correct position in the sorted portion and insert it there.
3. Modify the InsertionSort implementation to use the metrics framework — replace direct comparisons (`<`, `>`, etc.) with `myCompare()`, and replace element movement with `myCopy()`/`mySwap()`. Confirm the output is still correctly sorted and that `stderr` now reports comparison/swap counts.
4. Complete a theoretical analysis of InsertionSort: derive equations (as a function of *n*) for the number of compares/copies/swaps in the best, average, and worst cases.
5. Implement MergeSort in `mergeSort.c`, using a local temporary array (no dynamic allocation required) for the merge step, again using the metrics framework instead of direct operators.
6. Complete the same theoretical best-/average-/worst-case analysis for MergeSort.
7. In the `README`, summarize what was completed (and any known bugs/incomplete parts), plus both algorithms' complexity analysis.

## Notes
- `insertionSort < /dev/null` (sorting nothing) is a useful sanity check — it should report zero comparisons/moves/swaps rather than crashing.
- The `mySwap()`/`myCopy()`/`myCompare()` contract is mandatory — bypassing it with native operators defeats the metrics tracking and will produce incorrect performance statistics even if the sort itself works.
- Aim to finish InsertionSort (implementation + analysis) in the first week, since MergeSort's merge step is more involved to implement correctly.
