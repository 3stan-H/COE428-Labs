# Lab 5 — XML-Based Heap and Stack

## Overview
A two-week, two-part lab. Part 1 implements a Stack data structure to validate whether nested XML-style start/end tags are balanced. Part 2 implements a Heap (backed by a Stack) to build a binary heap from integer input, output its structure as an XML tree, and print the values in sorted and reverse-sorted order.

## Objectives
- Implement a string Stack (`push`, `pop`, `isEmpty`) and use it to validate XML tag balancing
- Implement an integer Heap and Stack to build a heap tree, represent it as XML, and extract sorted/reverse-sorted output
- Understand the relationship between XML's nested tag structure and tree data structures

## Tools Required
- `gcc`
- `make`

## Files
**Part 1:**
- `part1Main.c` — reads `stdin`, parses tags, runs the balance-checking algorithm (skeleton provided)
- `stringStack.c` — string Stack implementation (`push`, `pop`, `isEmpty` — to be completed)

**Part 2:**
- `part2Main.c` — reads integers from `stdin`, builds the heap, and drives the output (skeleton provided)
- `intStack.c` — integer Stack implementation (`push`, `pop`, `isEmpty` — to be completed)
- `intHeap.c` — integer Heap implementation (`heapAdd`, `heapDelete`, `heapSize` — to be completed)

- `README` — write-up answering the lab's required question

## Instructions

### Part 1 — XML Tag Balance Validator
1. Implement `push()`, `pop()`, and `isEmpty()` in `stringStack.c`.
2. In `part1Main.c`, read `stdin` character by character, detecting the start of each tag (`<` for a start-tag, `</` for an end-tag) and extracting its identity.
3. For each start-tag, push its identity onto the Stack. For each end-tag, pop the Stack and verify the popped identity matches; if the stack is empty when a pop is attempted, or the identities don't match, the input is invalid.
4. After all input is processed, the XML is valid only if the Stack is empty.
5. Test against the example cases in the lab manual (e.g. `<a></a>` valid, `<a><b></a></b>` invalid, tag names are case-sensitive).

### Part 2 — Heap-to-XML Tree
1. Implement `heapAdd()`, `heapDelete()`, and `heapSize()` in `intHeap.c`, and `push()`/`pop()`/`isEmpty()` in `intStack.c`.
2. In `part2Main.c`, read integers from `stdin` one per line, adding each to the heap.
3. Print the heap's tree structure as an XML expression, using `<node id="value">...</node>` for each node, with children nested inside their parent's tags.
4. Delete items one-by-one from the heap (printing each as it's deleted, and pushing it onto a Stack), producing a descending sorted sequence.
5. Pop the Stack and print each item, producing the ascending (reverse-sorted) sequence.
6. Answer the required question in the `README`: how would Requirement 1's algorithm need to change to support self-closing/stand-alone tags (e.g. `<foo/>`)?

## Notes
- Tag names can be arbitrary-length, upper/lower-case alphabetic strings — don't assume single-character tag names.
- The heap's XML output order matters: children should appear in the same left-to-right order used to construct the example in the lab manual.
- Part 1 and Part 2 are independent (different Stack implementations, `stringStack.c` vs. `intStack.c`) — don't try to reuse one for the other.
