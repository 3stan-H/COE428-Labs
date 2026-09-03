# Lab 2 — Recursion

## Overview
A one-week lab focused on recursive algorithm design and debugging, using the classic Towers of Hanoi problem. The lab emphasizes using `stderr` for debug/trace output while keeping a precisely-formatted move sequence isolated to `stdout`.

## Objectives
- Implement and trace a recursive algorithm (Towers of Hanoi)
- Use `stderr`-based debug output (with recursion-depth indentation) to visualize recursive call behavior without polluting the required `stdout` format
- Fix command-line argument handling bugs in a provided `main()` function

## Tools Required
- `gcc`

## Files
- `towers.c` — recursive Towers of Hanoi implementation, with `stderr` depth-tracing
- `towers.h` — function declaration
- `towersMain.c` — `main()` function (contains bugs to fix: doesn't correctly parse from/dest tower arguments)
- `README` — write-up answering the lab's required questions

## Instructions
1. Implement `towers(unsigned int n, unsigned int from, unsigned int dest)` recursively: compute the spare tower as `6 - from - dest`, recurse to move `n-1` disks to the spare, print the move `from dest` to `stdout`, then recurse to move `n-1` disks from spare to `dest`.
2. Add `stderr`-based tracing: print the recursion depth (via leading `..` per level) and the function call parameters on entry, and print each move description as it's made — all routed to `stderr`, never `stdout`.
3. Compile and run:
   ```
   gcc -o towers towers.c towersMain.c
   towers
   ```
4. Verify output separation using shell redirection:
   ```
   towers > junk1        # stdout only to file, stderr still on screen
   towers 2> junk2        # stderr only to file, stdout still on screen
   towers 2> details > pureStdout   # both redirected separately
   ```
5. Fix the bugs in `towersMain.c`: the command-line arguments for `fromTower`/`destTower` are not currently recognized, and invalid invocations aren't detected. Implement the full spec:
   - No arguments → move 3 disks from Tower 1 to Tower 2
   - One argument (`numberDisks`) → move that many disks from Tower 1 to Tower 2
   - Three arguments (`numberDisks fromID toID`) → move disks between the specified towers, validating that tower IDs are `1`/`2`/`3` and are different
6. Answer the required questions in a `README` file (tracing `towers(5, 2, 3)`'s first recursive call and its return value, and counting output lines for `towers(8, 1, 2)`).

## Notes
- `wc -l someFile` is useful for confirming the number of output lines matches your theoretical move-count calculation.
- Keep the required `stdout` format exact — `FROM_ID SPACE DEST_ID` per line, nothing else — since it's graded precisely.
