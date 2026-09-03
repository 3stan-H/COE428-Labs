# Lab 1 — C Review

## Overview
A one-week lab reviewing core C programming fundamentals, with an emphasis on incremental development, testing/debugging practices, and command-line argument handling. The lab builds a simple sorting utility, but the focus is on the development process rather than the sorting algorithm itself.

## Objectives
- Practice incremental development: build and verify the test harness (`main()`) before implementing the real algorithm
- Use `stdout`/`stderr` separation for output vs. debug/error messages
- Use `argc`/`argv` to accept dynamic command-line input instead of hardcoded data

## Tools Required
- `gcc`

## Files
- `sortMain.c` — `main()` driver: declares test data, calls `mySort()`, verifies the result is sorted, prints to `stdout`
- `mySort.h` — provided function signature (not to be edited): `void mySort(int array[], unsigned int num_elements);`
- `mySort.c` — sorting algorithm implementation (author's choice of algorithm)
- `sortMain2.c` — extended version of `sortMain.c` supporting command-line arguments
- `cmdlineArgsDemo.c` — provided demo program illustrating `argc`/`argv` usage
- `README` — write-up answering the lab's required question

## Instructions
1. Implement `sortMain.c` so it declares a hardcoded integer array, calls `mySort(data, nDataItems)`, checks the result is sorted (reporting any error to `stderr` and exiting non-zero), and prints the sorted array to `stdout`.
2. Compile and run the driver **before** writing `mySort()` — with correctly pre-sorted test data, this confirms the test harness itself works.
3. Deliberately un-sort the test data and re-run to confirm the error-detection logic in `sortMain.c` correctly reports the problem via `stderr`.
4. Implement `mySort()` in `mySort.c`, using any sorting algorithm, conforming to the signature in `mySort.h`.
5. Compile and link:
   ```
   gcc -c sortMain.c
   gcc -c mySort.c
   gcc -o testSort mySort.o sortMain.o
   ```
6. Copy `sortMain.c` to `sortMain2.c` and modify it so that if command-line arguments are given, they're converted to integers and used as the data to sort (falling back to the hardcoded test data if none are given).
7. Answer the required question in a `README` file: how would you write `mySort()` to make use of a pre-built `betterSort(int data[], first, last)` function with a different signature?

## Notes
- Error/debug messages must go to `stderr`, not `stdout` — this keeps `stdout` clean for redirection and ensures errors are still visible to the user even if `stdout` is redirected to a file.
- The lab intentionally has you test the harness with data that's already sorted first, to confirm the "no errors" case works before testing the "errors detected" case.
