# Lab 4 — State Machine

## Overview
A two-week lab implementing a finite state machine simulator (`simState`) in C that responds to a set of real-time commands over `stdin` — including state transitions, reconfiguration, printing the current machine, identifying unreachable states, and deleting them.

## Objectives
- Parse and represent a text-based finite state machine description
- Implement a command-driven simulator supporting state transitions, dynamic reconfiguration, and printing
- Implement a reachability analysis to identify and optionally delete "garbage" (unreachable) states

## Tools Required
- `gcc`
- `make`

## Files
- `simState.c` — main program implementing the command loop and state machine logic
- State machine description file (custom-generated via the course's `getLab4` utility)
- `README` — diagram of the assigned state machine plus write-up

## Instructions
1. Run `make` to confirm the provided stub project builds cleanly.
2. Obtain your custom state machine assignment (via the course-provided `getLab4` command) and draw a diagram of it for your `README`.
3. Implement the state machine representation: a table where each row is `<StateName> <NextState0> <NextState1>`, with `<NextState0>`/`<NextState1>` being the next state for a `0`/`1` input respectively.
4. Implement each required command:
   - **No commands**: print the starting state before any input is processed
   - **`0` / `1`**: print the next state for the given input and update the current state
   - **`c <0|1> <state>`**: change the state machine's transition table so the given input, from the current state, now leads to `<state>` (no output produced)
   - **`p`**: print the full current state machine configuration
   - **`g`**: identify and print all states unreachable from the current state (`No garbage` if none, otherwise `Garbage: <states>`)
   - **`d [state]`**: delete all unreachable states (or a specific named state), printing `Deleted: <states>`, `No states deleted.`, `Deleted.`, or `Not deleted.` as appropriate
5. Test against the sample input/output sequence in the lab manual to confirm each command behaves exactly as specified.
6. Submit the `README` with your state diagram and any required write-up.

## Notes
- The `g` (garbage identify) and `d` (delete) commands both rely on the same underlying reachability analysis from the current state — implement that once and reuse it for both commands.
- Command parsing needs to be strict: commands are single characters (optionally followed by arguments for `c` and `d`), read one per line from `stdin`.
- `getLab4` only runs correctly on a Sun Workstation — SSH into one if working from a different machine.
