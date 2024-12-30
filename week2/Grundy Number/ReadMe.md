## What is Mex?

**Minimum Excludant (Mex):**  
The `Mex` of a set of numbers is the smallest non-negative integer that is not present in the set.

### Example:
For the set `{0, 1, 3}`, the `Mex` is `2` (as it is the smallest non-negative integer not in the set).

---

## How to Calculate Grundy Numbers?

The **Grundy Number** for a game is defined as follows:

1. The Grundy Number is `0` for a game that is lost immediately by the first player.
2. For any other game, the Grundy Number is equal to the `Mex` of the Grundy Numbers of all possible next positions.
