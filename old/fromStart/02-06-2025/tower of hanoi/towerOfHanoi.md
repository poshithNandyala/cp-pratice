Below is a step-by-step, in-depth walkthrough of why the minimum number of moves for n disks in Towers of Hanoi is $2^n - 1$, how the recursive process actually “works,” and finally a complete C++ implementation that prints out the move sequence in the required format.

---

## 1. Intuition Behind the $2^n - 1$ Formula

1. **Base case ($n = 1$):**
   If there is exactly one disk (disk 1, the smallest), you simply move it directly from the source peg (1) to the destination peg (2).

   * Number of moves required for $n = 1$ is clearly $1$, which equals $2^1 - 1$.

2. **Suppose you have $n$ disks stacked on peg 1, and you want to move them all to peg 2.**
   Label the disks so that disk 1 is the smallest (on top), disk 2 is next, and so on, up to disk n being the largest (on bottom). At no point may a larger disk sit on top of a smaller one.

3. **Key observation:**
   To move disk n (the largest) from peg 1 to peg 2, you cannot place it on top of any smaller disk. Therefore, **before** you ever touch disk n, you must have already moved all the smaller disks $\{1,\,2,\,\dots,\,n-1\}$ off of peg 1 and out of the way.

   * But *where* can they go? They cannot go to peg 2 if you plan to put disk n there at that moment—so they must temporarily go to the only other peg, peg 3.

4. **So the process “splits” cleanly into three phases:**

   1. **Phase 1 (move top $n-1$ disks from peg 1 → peg 3):**
      Use peg 2 as a “helper” to shuttle those $n-1$ disks over to peg 3.
      Let’s call the minimum number of moves needed for that “step” $T(n-1)$.
   2. **Phase 2 (move disk n from peg 1 → peg 2):**
      Once the top $n-1$ are safe on peg 3, you make exactly **one move**: move the largest disk n directly from peg 1 to peg 2.
   3. **Phase 3 (move the $n-1$ disks from peg 3 → peg 2):**
      Finally, you have to take all those $n-1$ disks on peg 3 and move them on top of disk n (which now sits alone on peg 2). To do that, you use peg 1 as the temporary helper. Again, the minimum moves to transfer $n-1$ disks from one peg to another is $T(n-1)$.

5. **Recurrence relation:**

   * Phase 1 costs $T(n-1)$.
   * Phase 2 costs $1$.
   * Phase 3 costs $T(n-1)$.
     Hence, for $n$ disks,

   $$
     T(n)\;=\;T(n-1)\;+\;1\;+\;T(n-1)\;=\;2\,T(n-1)\;+\;1.
   $$

   We also know $T(1) = 1$.

6. **Solving the recurrence:**

   * $T(1) = 1$.
   * $T(2) = 2\,T(1) + 1 = 2\cdot 1 + 1 = 3.$
   * $T(3) = 2\,T(2) + 1 = 2\cdot 3 + 1 = 7.$
   * $T(4) = 2\,T(3) + 1 = 2\cdot 7 + 1 = 15.$
     If you expand this pattern, you can see by induction that

   $$
     T(n) \;=\; 2^n \;-\; 1.
   $$

   You can prove it formally by induction:

   * **Base**: $n=1$. $2^1 - 1 = 1$. That matches $T(1)=1$.
   * **Inductive step**: Assume $T(k) = 2^k - 1$. Then

     $$
       T(k+1) \;=\; 2\,T(k)\;+\;1
       = 2\,(2^k - 1) + 1
       = 2^{\,k+1} - 2 + 1
       = 2^{\,k+1} - 1,
     $$

     which completes the inductive proof.

Therefore, the **minimum** (and exact) number of moves to transfer $n$ disks from peg 1 to peg 2 (using peg 3 as auxiliary) is

$$
  \boxed{T(n)\;=\;2^n \;-\; 1.}
$$

---

## 2. Step‐by‐Step Process (Why the Recursion “Makes Sense”)

To really internalize how the recursion “thinks,” imagine you have three pegs: **1 (source), 2 (destination),** and **3 (auxiliary)**. Your goal is to get all $n$ disks from peg 1 to peg 2.

1. **Look at the largest disk, disk n:**

   * It sits at the bottom of peg 1. You can’t move it until everything smaller is out of the way. “Out of the way” means none of the smaller disks $\{1,\dots,n-1\}$ sits on top of it.

2. **So we ask: what’s the best way to get the sub‐stack $\{1,\dots,n-1\}$ off of peg 1?**

   * We decide to move those $n-1$ disks onto peg 3. But we cannot place a larger disk onto a smaller one, so we do that in the exact same “best‐possible” fashion (i.e. recursively solve the problem of moving $n-1$ disks from peg 1 to peg 3), *using peg 2 as the auxiliary*.

3. **After those $n-1$ disks are sitting neatly on peg 3 (in correct order), peg 1 is now free to hold disk n alone.**

   * We perform exactly one move: move disk n from peg 1 → peg 2.

4. **Now peg 2 has disk n at its bottom, and peg 3 has $n-1$ disks in the correct order (largest of those on the bottom).**

   * Our final task is to put those $n-1$ disks on top of disk n (on peg 2).
   * But that is *exactly* the same shape of problem: “move $n-1$ disks from peg 3 to peg 2 (destination), using peg 1 as auxiliary.”

Because each “move $n-1$\” sub‐task is identical in structure to the original, we naturally arrive at a recursion. Each sub‐problem has size strictly smaller ($n - 1$ instead of $n$), so eventually we bottom out at the case $n=1$, which is trivial (just one direct move).

You can sketch the recursion as a tree:

```
T(n)                           Move stack of size n from 1 → 2
│
├─ T(n-1)   “move n-1 from 1 → 3” (using 2 as aux)
│
├─ Move disk n “1 → 2”
│
└─ T(n-1)   “move n-1 from 3 → 2” (using 1 as aux)
```

Since each T(n-1) expands in the same pattern, you see exactly $2 T(n-1) + 1$ total moves.

---

## 3. How to Approach Writing the Recursion (Conceptual Checklist)

1. **Identify arguments:**
   A typical recursive function for Towers of Hanoi needs to know:

   * `n`: how many disks remain to be moved in this sub‐call.
   * `src`: which peg currently holds these `n` disks (the “source”).
   * `dst`: which peg we ultimately want them to end up on (the “destination”).
   * `aux`: the third peg (the “auxiliary” peg we can use as temporary storage).

2. **Base case:**
   If `n == 1`, there is exactly one disk to move. You simply print/make the move: “move disk 1 from `src` to `dst`,” and return. No further recursion.

3. **Recursive step** (when `n > 1`):

   * **Step A (recurse):** Move the top `n-1` disks from `src` → `aux`, using `dst` as the helper. That is:

     $$
       \text{hanoi}(n-1,\;\text{src},\;\text{aux},\;\text{dst}).
     $$
   * **Step B (single move):** After Step A, peg `src` has only disk `n` left. We do exactly one move:

     ```
     move disk n from src → dst
     ```
   * **Step C (recurse):** Now move those `n-1` disks (currently stacked on peg `aux`) down onto peg `dst`, using `src` as helper. That is:

     $$
       \text{hanoi}(n-1,\;\text{aux},\;\text{dst},\;\text{src}).
     $$

4. **Why this never violates the “larger-on-smaller” rule:**

   * In Step A, you are obeying the same rule because you only ever move smaller stacks by the same strategy.
   * The single move in Step B is guaranteed legal, because after Step A, peg `aux` holds exactly all disks $\{1,\dots,n-1\}$ (in proper stacked order), and peg `dst` is empty. So you can safely move disk n from peg `src` (where it was bottom) onto peg `dst` (which is empty).
   * In Step C, you move the smaller $n-1$ disks from peg `aux` onto peg `dst`. Since peg `dst` already has disk n (which is larger than any of $\{1,\dots,n-1\}$), you won’t be violating the rule by placing smaller disks on top of the larger disk n.

5. **Why it always finishes:**

   * Each recursive call is invoked with a strictly smaller value of `n` → eventually you hit the base case `n=1`. So there is no infinite recursion.

6. **Counting moves:**

   * Every time you call `hanoi(n, ...)` for `n > 1`, you generate exactly $2\,T(n-1)$ moves from the two recursive calls, plus 1 move to transfer disk n. Hence $T(n) = 2\,T(n-1) + 1$. With $T(1)=1$, you get $T(n) = 2^n - 1$.

---

## 4. Detailed C++ Implementation

Below is a full C++ program that:

1. Reads the integer $n$ (between 1 and 15) from standard input.
2. Prints the total number of moves $k = 2^n - 1$.
3. Recursively prints each move in the format:

   ```
   <disk> <from_peg> <to_peg>
   ```

   one move per line.

> **Important:** Because $n$ can be as large as 15, $2^{15}-1 = 32767$ moves, you should use fast I/O (e.g. `ios::sync_with_stdio(false)` and `cin.tie(nullptr)`) to avoid timeouts.

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Recursive function to generate the sequence of moves for
  moving 'n' disks from peg 'src' to peg 'dst', using 'aux' as auxiliary.
  Each move is printed immediately in the format: "<disk> <from> <to>".
*/
void hanoi(int n, int src, int dst, int aux) {
    if (n == 1) {
        // Base case: only one disk to move
        // Move disk '1' from peg 'src' to peg 'dst'
        cout << 1 << " " << src << " " << dst << "\n";
        return;
    }
    // Step A: move top (n-1) disks from src -> aux, using dst as helper
    hanoi(n - 1, src, aux, dst);

    // Step B: move disk 'n' from src -> dst
    cout << n << " " << src << " " << dst << "\n";

    // Step C: move the (n-1) disks from aux -> dst, using src as helper
    hanoi(n - 1, aux, dst, src);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;               // Read the number of disks (1 ≤ n ≤ 15)

    // Calculate total moves = 2^n - 1
    long long total_moves = (1LL << n) - 1;
    cout << total_moves << "\n";

    // Generate and print each move
    // We move n disks from peg 1 → peg 2, using peg 3 as auxiliary.
    hanoi(n, /*src=*/1, /*dst=*/2, /*aux=*/3);

    return 0;
}
```

### Explanation of the C++ Code

1. **Fast I/O setup:**

   ```cpp
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   ```

   * Disables C++’s synchronization with C I/O (printf/scanf), and unties `cin`/`cout` so that outputs aren’t flushed automatically on input. This speeds up reading/writing, especially since we might print up to 32 767 lines.

2. **Reading $n$:**

   ```cpp
   int n;
   cin >> n;
   ```

   * We read an integer $n$ from standard input. The problem guarantees $1 \le n \le 15$.

3. **Computing total moves $\;2^n - 1$:**

   ```cpp
   long long total_moves = (1LL << n) - 1;
   cout << total_moves << "\n";
   ```

   * We use a 64-bit integer `long long` just in case; `1LL << n` is the same as $2^n$ (left‐shift). Subtracting 1 yields $2^n - 1$.
   * For $n=15$, that’s $2^{15} - 1 = 32767$, which easily fits in a 64-bit integer.

4. **Recursive function `hanoi(int n, int src, int dst, int aux)`:**

   * **Signature:**

     * `n` = how many disks remain to move.
     * `src` = integer label of the current source peg (1, 2, or 3).
     * `dst` = integer label of the destination peg (1, 2, or 3).
     * `aux` = integer label of the auxiliary peg (1, 2, or 3).
   * **Base Case (`n == 1`):**

     ```cpp
     if (n == 1) {
         cout << 1 << " " << src << " " << dst << "\n";
         return;
     }
     ```

     * When there is exactly one disk to move, you simply print:

       ```
       1 <src> <dst>
       ```

       and return—no further recursion needed.
   * **Recursive Step (`n > 1`):**

     1. **Move the top $n-1$ disks from `src` → `aux`:**

        ```cpp
        hanoi(n - 1, src, aux, dst);
        ```

        Notice we pass arguments in precisely the order `(n-1, current_source, new_destination, new_aux)`. That “new aux” is the original `dst`.

     2. **Move disk n from `src` → `dst`:**

        ```cpp
        cout << n << " " << src << " " << dst << "\n";
        ```

        We literally print one line recording “move disk n from peg `src` to peg `dst`.”

     3. **Move the $n-1$ disks from `aux` → `dst`:**

        ```cpp
        hanoi(n - 1, aux, dst, src);
        ```

        Here, the roles rotate again: to move disks from the former aux to the final destination, we treat the old source (`src`) as the new auxiliary.

Because every recursive call always reduces the argument `n` by 1, eventually you hit `n = 1` and unwind, thus printing exactly $(2^n - 1)$ moves in the correct legal sequence.

---

## 5. Putting It All Together

1. **Full run for $n = 2$ (as an example):**

   * Input: `2`
   * Total moves printed: `3`
   * Sequence of moves (in order):

     1. Move disk 1 from peg 1 → peg 3
        (that is, `1 1 3`)
     2. Move disk 2 from peg 1 → peg 2
        (that is, `2 1 2`)
     3. Move disk 1 from peg 3 → peg 2
        (that is, `1 3 2`)

   This matches the known optimal solution for $n=2$.

2. **Full run for $n = 3$ (quick check):**

   * Input: `3`
   * Total moves: $2^3 - 1 = 7$.
   * Moves printed in order:

     1. `1 1 2`  (move top disk 1 from 1→2)
     2. `2 1 3`  (move disk 2 from 1→3)
     3. `1 2 3`  (move disk 1 from 2→3, stacking on disk 2)
     4. `3 1 2`  (move largest disk 3 from 1→2)
     5. `1 3 1`  (move disk 1 from 3→1)
     6. `2 3 2`  (move disk 2 from 3→2, stacking on disk 3)
     7. `1 1 2`  (move disk 1 from 1→2)

3. **Complexity:**

   * Time complexity is $O(2^n)$, since you must explicitly print $2^n - 1$ lines.
   * Space complexity (recursion stack) is $O(n)$, because the deepest recursion occurs when you peel off one disk at a time until `n=1`, then unwind.

---

### Summary

* **Why $2^n - 1$?**
  Because each time you want to relocate $n$ disks, you must first move $n-1$ disks out of the way, then move the single largest disk, then move those $n-1$ disks back on top. This gives the exact recurrence $T(n)=2T(n-1)+1$ with $T(1)=1$, which solves to $2^n - 1$.

* **How the recursion “thinks”:**

  1. Recursively solve the smaller subproblem of size $n-1$.
  2. Perform one move of the largest disk.
  3. Recursively solve the $n-1$ subproblem again in the new configuration.

* **C++ code provided** above prints the total number of moves, then each move in the required `(disk, from_peg, to_peg)` format.

This completes the detailed intuition, derivation, and a ready-to-compile C++ solution.
