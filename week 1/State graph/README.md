# Stick Game: State Graph Rules

This stick game introduces new rules for determining the allowed moves in each state. In this version of the game:

- In each state `k`, it is allowed to remove any number `x` of sticks such that:
  - `x` is smaller than `k`
  - `x` divides `k` evenly (i.e., `k % x == 0`)

## Examples of Allowed Moves

- **State 8**: 
  - The possible moves are to remove **1**, **2**, or **4** sticks because:
    - `1 < 8` and `8 % 1 == 0`
    - `2 < 8` and `8 % 2 == 0`
    - `4 < 8` and `8 % 4 == 0`

- **State 7**: 
  - The only allowed move is to remove **1** stick because:
    - `1 < 7` and `7 % 1 == 0`
    - No other numbers smaller than 7 divide it evenly.

## State Graph

In this game, the transitions between states depend on the allowed moves. The graph of states represents the following:

- Each state `k` is connected to states `k - x`, where `x` is an allowed move based on the rules.
- The goal is to analyze whether a state is a **winning** or **losing** state, using the same principles as the previous game:
  - A state is a **losing state** if all possible moves lead to a **winning state** for the opponent.
  - Otherwise, the state is a **winning state**.

## Observations

- The game's complexity increases because the allowed moves depend not only on the current state `k` but also on the divisors of `k`.

## Strategy

To play optimally:
1. Analyze the divisors of the current state to determine the possible moves.
2. Choose a move that forces the opponent into a **losing state**.
3. Continue this strategy until no sticks are left, and the opponent loses.

This README provides the foundational rules for analyzing and strategizing in this stick game.

