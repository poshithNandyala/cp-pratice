[grid_path_description](https://youtu.be/KoWNN6Xvr30)

The Problem Without Optimization
==============================================

Path length = 48

Each ? can be 4 directions

Worst case brute force =

4^48
≈
10^28
Impossible
4^48
≈
10^28
Impossible

So we must prune aggressively.

Key Insight
------------------------

Most paths die early if they trap themselves.

We only explore valid partial paths and kill paths early when they become impossible.

State Representation
-------------------

We simulate the path step-by-step using:

* Current position (x, y)
* Step index i (0 → 48)
* Visited grid 7 × 7

We use DFS + Backtracking.

Pruning Rules
--------------

### 1. Boundary + Visited Pruning (Basic but Mandatory)

At every move:

* If next cell is outside grid
* If next cell is already visited

Stop recursion immediately

This already removes most invalid paths.

### 2. Dead-End Pruning (MOST IMPORTANT)

The Key Observation
-------------------------

If we create a situation where:

* Left & Right are blocked
* Up & Down are free
The path must split the grid into two disconnected parts

That means:

* One part will be unreachable later

So this path will never reach destination correctly

Kill this path immediately

Horizontal Dead-End Pattern
# . #
. X .
# . #

Condition:

* Left is blocked
* Right is blocked
* Up is free
* Down is free

Return immediately

Vertical Dead-End Pattern
. # .
# X #
. # .

Condition:

* Up is blocked
* Down is blocked
* Left is free
* Right is free

Return immediately

Why This Works
-------------------

This avoids creating sealed corridors that force unreachable cells later.

This single pruning rule reduces complexity by orders of magnitude.

### 3. Forced Move Optimization

If at a cell:

* Only one direction is possible
* But the path says ?

We must take that move
No need to try other directions

This avoids useless branching.

### 4. End Condition Check (Strict)

At step 48:

Check path only if

* We are at (6, 0) (lower-left)

Otherwise discard

Also:

* If we reach (6,0) before step 48, discard
(because we can’t revisit cells)

Final Complexity Reduction
--------------------------------

Method	Effect
Boundary & visited	Removes invalid moves
Dead-end pruning	Major cut (~99%)
Forced moves	Reduces branching
Exact end check	Avoids false paths

Result
-------------

Total explored paths ≈ ~100k
Fits easily in 1 second

One-Line Mental Model (For Revision)
------------------------------------

Never allow the path to split the grid into two disconnected regions.
