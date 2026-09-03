# COE428 – Data Structures and Algorithms Labs

This repository contains my lab work for **COE428: Data Structures and Algorithms**, a course in the Electrical Engineering program at Toronto Metropolitan University. All labs are written in **C**, compiled with `gcc`/`make`, and developed/tested on a Unix (Sun Workstation) lab environment.

For the official lab manuals and course-specific requirements, see the [COE428 course page](https://www.ecb.torontomu.ca/~courses/coe428/). Each lab also has its own folder with a dedicated `README.md` covering implementation details and answers to the lab's required questions.

## Repository Structure

```
coe428-data-structures-algorithms/
├── Lab1-C-Review/
├── Lab2-Recursion/
├── Lab3-Sorting/
├── Lab4-State-Machine/
├── Lab5-XML-Heap-Stack/
└── README.md
```

## Tools Used

- **C** – language used across all labs
- **gcc** – compiler
- **make** – build automation (Labs 3–5)
- **Unix shell** (stdin/stdout/stderr redirection, `zip`) – testing and submission workflow

## Lab Summaries

### [Lab 1 — C Review](./Lab1-C-Review)
Reviewed core C fundamentals through an incremental development methodology: built a `sortMain.c` driver and stub `mySort()` function first, verified the test harness worked correctly before writing any real sorting logic, then implemented `mySort()` and extended the program to accept command-line arguments (`argc`/`argv`) instead of hardcoded test data.

### [Lab 2 — Recursion](./Lab2-Recursion)
Implemented a recursive Towers of Hanoi solver in C, instrumenting the recursive algorithm with `stderr`-based depth-tracing output while keeping the required move sequence isolated to `stdout`. Fixed bugs in the provided `main()` so the program correctly parses tower/disk-count command-line arguments per the `towers` command specification.

### [Lab 3 — Sorting](./Lab3-Sorting)
Implemented InsertionSort and MergeSort in C, both conforming to a shared `mySort()` signature. Instrumented each algorithm using a provided metrics framework (`myCompare()`, `myCopy()`, `mySwap()`) to track comparisons, copies, and swaps, then derived theoretical best-, average-, and worst-case complexity equations for each algorithm.

### [Lab 4 — State Machine](./Lab4-State-Machine)
Built a C program (`simState`) that reads a custom finite state machine description and responds to real-time stdin commands: state transitions (`0`/`1`), reconfiguration (`c`), printing the current configuration (`p`), identifying unreachable ("garbage") states (`g`), and deleting unreachable states (`d`).

### [Lab 5 — XML-Based Heap and Stack](./Lab5-XML-Heap-Stack)
Part 1: implemented a string Stack (`push`, `pop`, `isEmpty`) in C to validate whether nested XML-style start/end tags are balanced. Part 2: implemented an integer Heap and Stack to build a binary heap from stdin input, output its structure as an XML tree, and print the values in both sorted and reverse-sorted order.

## Notes

- Labs progress from core C fundamentals and debugging practices (Labs 1–2) through algorithm implementation and empirical/theoretical analysis (Lab 3), to more substantial data structure and simulation projects (Labs 4–5).
- Each lab's `README.md` includes required write-up answers (e.g. complexity analysis, recursion trace questions) as specified in that lab's manual, in addition to implementation notes.
