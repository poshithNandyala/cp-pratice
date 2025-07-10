Below is a step-by-step, in-depth walkthrough of the “Reverse Pairs” problem—showing exactly **why** and **how** the merge-sort approach counts every qualifying pair `(i, j)` with `i < j` and `nums[i] > 2·nums[j]`. We’ll start from first principles, build intuition via a small example, and then describe each line of the algorithm in simple words.

---

## 1. Restating the Problem in Plain Language

> **Given** an array of integers `nums[]` of length `n`,
> **Count** the number of pairs `(i, j)` such that:
>
> 1. `0 ≤ i < j < n`, and
> 2. `nums[i] > 2 × nums[j]`.

Each such pair is called a **reverse pair**. Intuitively, you’re looking for all “out-of-order” pairs where an element on the left is strictly more than twice an element on the right.

---

## 2. Why Brute-Force Is Too Slow

A naive way:

```text
count = 0
for i = 0 to n–2:
    for j = i+1 to n–1:
        if nums[i] > 2 * nums[j]:
            count += 1
```

* You explicitly compare **every** pair `(i, j)` with `i < j`.
* That is `n–1 + n–2 + … + 1 = n·(n–1)/2` checks ≈ **O(n²)** time.
* For `n = 100,000`, that’s about 5 billion checks—too large to finish in a reasonable time.

Hence we look for an **O(n log n)** strategy, which arises naturally once you see how **merge sort** can be adapted to count certain kinds of “out-of-order” pairs.

---

## 3. Key Insight: Merging Two Sorted Halves

Imagine you have split the array into two halves:

1. **Left half**: `L = nums[left..mid]` (sorted)
2. **Right half**: `R = nums[mid+1..right]` (sorted)

Because `L` and `R` are individually sorted, we can very quickly count how many `(x in L, y in R)` satisfy `x > 2·y`—**without checking every single pair**—by using two pointers. Concretely:

* Let `i = 0` be the pointer into `L` (so `L[i]` is the current element in the left half).
* Let `j = 0` be the pointer into `R` (so `R[j]` is the current element in the right half).
* Because `L` is sorted ascending, if `L[i] > 2·R[j]`, then **every** element `L[i], L[i+1], …, L[nL–1]` in the left half is also > `2·R[j]` (since once one element in a sorted list is bigger than a threshold, all later ones are, too).
* That means:

  * As soon as we find `L[i] > 2·R[j]`, we can add `(nL – i)` to our reverse-pair count (all left-half elements from index `i` onward qualify against this single `R[j]`).
  * We then move **only** `j` forward by 1, because we want to see what happens with the next `R[j+1]`. Meanwhile, we keep `i` where it is, since the same `L[i]` might also be > `2·R[j+1]`, or it might not.

If, instead, `L[i] ≤ 2·R[j]`, then `L[i]` is *not* large enough to form a reverse pair with that particular `R[j]`. But also—because `R[j+1] ≥ R[j]`, we know

```
L[i] ≤ 2·R[j] ≤ 2·R[j+1] ≤ 2·R[j+2] ≤ ⋯
```

so none of the elements in `R[j], R[j+1], …` can satisfy `L[i] > 2·R[*]`. Thus, if `L[i] ≤ 2·R[j]`, we definitely should move **i → i+1** (advance the left pointer), because we’ve “ruled out” every possible right pointer for that `L[i]`. In other words:

* **Case 1:** `L[i] > 2·R[j]`
  → All of `L[i], L[i+1], …` are > `2·R[j]`.
  → Count `(nL – i)` new reverse pairs.
  → Move `j → j+1`.

* **Case 2:** `L[i] ≤ 2·R[j]`
  → For this fixed `i`, no `R[j], R[j+1], …` can make `L[i] > 2·R[*]`.
  → Move `i → i+1`.

In each step, we move exactly one pointer (either `i` or `j`). Since `i` goes from `0` to `nL–1` at most once, and `j` goes from `0` to `nR–1` at most once, the entire “counting” across those two sorted subarrays takes **O(nL + nR)** time.

---

## 4. Full “Merge-Sort + Reverse-Pair Counting” Workflow

### 4.1 Top-Level Recursion

Define a function `countReversePairs(nums, left, right)` that:

1. **Base Case**: If `left ≥ right`, the subarray has 0 or 1 element → no pairs → return 0.

2. **Split**: Compute `mid = (left + right) // 2`.

3. **Recurse Left**: `countLeft = countReversePairs(nums, left, mid)`.

   * This sorts `nums[left..mid]` in place and counts all reverse pairs **within** the left half.

4. **Recurse Right**: `countRight = countReversePairs(nums, mid+1, right)`.

   * This sorts `nums[mid+1..right]` in place and counts all reverse pairs **within** the right half.

5. **Count “Cross” Pairs + Merge**:

   * Both halves `[left..mid]` and `[mid+1..right]` are now individually sorted.
   * Call `countMerge = countWhileMerge(nums, left, mid, right)`, which does two things in one O(right–left+1) pass:

     1. **Count** how many `(i in [left..mid], j in [mid+1..right])` satisfy `nums[i] > 2·nums[j]`.
     2. **Merge** the two sorted halves back into a single sorted array `[left..right]`.

6. **Return** `countLeft + countRight + countMerge`.

Because each level of recursion costs O(segment\_length) for the “count + merge,” and the recursion depth is ≈ log₂n, the total running time is **O(n log n)**.

---

### 4.2 Detailed `countWhileMerge` Steps

Suppose `nums[left..mid]` is sorted, call it subarray **L**, and `nums[mid+1..right]` is sorted, call it subarray **R**. We create temporary copies:

```
L[0..nL–1]   = nums[left..mid]
R[0..nR–1]   = nums[mid+1..right]
where
    nL = mid  – left + 1,
    nR = right – (mid+1) + 1 = right – mid.
```

Now:

1. **Counting Phase (two pointers i, j)**

   ```cpp
   long long count = 0;
   int i = 0;     // pointer into L[ ]
   int j = 0;     // pointer into R[ ]
   while (i < nL && j < nR) {
       // Compare L[i] vs. 2 * R[j]
       if ((long long)L[i] <= 2LL * R[j]) {
           // This means L[i] is NOT > 2∙R[j], and since R[j] ≤ R[j+1] ≤ …,
           // no R[k] for k ≥ j can satisfy L[i] > 2∙R[k]. So move i forward.
           i++;
       }
       else {
           // We found L[i] > 2∙R[j].
           // Because L is sorted, EVERY element L[i], L[i+1], …, L[nL–1]
           // is ≥ L[i], so all of them are also > 2∙R[j].
           count += (long long)(nL - i);
           // Now we “finish counting” all pairs involving R[j]. Move to next R element.
           j++;
       }
   }
   ```

   * At each step, if `L[i]` is “too small” (i.e. ≤2·R\[j]), we know it cannot form a pair with *any* current or future `R[j]`. So we discard `L[i]` (by incrementing `i`).
   * If `L[i]` is “too big” (i.e. >2·R\[j]), we know that *all* of `L[i..nL–1]` outdo `2·R[j]`. So we add `(nL – i)` and then move the right pointer `j` forward—because we’ve finished counting every pair that uses this particular `R[j]`.

2. **Merging Phase (i = 0, j = 0 again)**
   After the above loop terminates, we still have two sorted lists `L` and `R` that need to be merged into one sorted list in `nums[left..right]`. Classic “merge” logic:

   ```cpp
   i = 0;  
   j = 0;
   int k = left;  // write position in the original array

   while (i < nL && j < nR) {
       if (L[i] <= R[j]) {
           nums[k++] = L[i++];
       } else {
           nums[k++] = R[j++];
       }
   }
   // Copy any leftover
   while (i < nL) nums[k++] = L[i++];
   while (j < nR) nums[k++] = R[j++];
   ```

   * At the end, `nums[left..right]` is fully sorted (so higher recursion calls can correctly rely on sorting).

3. **Return** the total `count` from the Counting Phase. That represents the number of reverse-pairs that cross from the left half to the right half.

---

## 5. A Worked-Out Example Step by Step

Let’s take a concrete (small) example and run through every recursion, every pointer move, and every time we add to our count. This clarifies the algorithm in action.

### 5.1 Example Array

```
nums = [ — 1, 3, 2, 3, 1 — ]
 index  0  1  2  3  4
```

We want to find all `(i < j)` such that `nums[i] > 2·nums[j]`.

#### 5.1.1 Brute-Force Check (just to see final answer)

* Pairs to check:

  1. `(0,1): 1 > 2·3 ?` → 1 > 6 ? No.
  2. `(0,2): 1 > 2·2 ?` → 1 > 4 ? No.
  3. `(0,3): 1 > 2·3 ?` → 1 > 6 ? No.
  4. `(0,4): 1 > 2·1 ?` → 1 > 2 ? No.
  5. `(1,2): 3 > 2·2 ?` → 3 > 4 ? No.
  6. `(1,3): 3 > 2·3 ?` → 3 > 6 ? No.
  7. `(1,4): 3 > 2·1 ?` → 3 > 2 ? **Yes** → count 1
  8. `(2,3): 2 > 2·3 ?` → 2 > 6 ? No.
  9. `(2,4): 2 > 2·1 ?` → 2 > 2 ? No (must be strictly greater).

10. `(3,4): 3 > 2·1 ?` → 3 > 2 ? **Yes** → count 2

So the answer should be **2** reverse pairs: they are `(1,4)` = `(nums[1]=3, nums[4]=1)` and `(3,4)` = `(nums[3]=3, nums[4]=1)`.

---

### 5.2 Merge-Sort Breakdown

We call `countReversePairs(nums, 0, 4)` on `[1, 3, 2, 3, 1]`.

#### 5.2.1 Level 1: Entire Array `[0..4]`

* `left = 0`, `right = 4`.
* `mid = (0+4)//2 = 2`.
* We will recurse on `[0..2]` and `[3..4]`.

——

#### 5.2.2 Level 2 Left: Subarray `[0..2] = [1, 3, 2]`

* `left = 0`, `right = 2`, `mid = 1`.
* Recurse on `[0..1]` and `[2..2]`.

##### 5.2.2.1 Left of Left: Subarray `[0..1] = [1,3]`

* `left = 0`, `right = 1`, `mid = 0`.
* Recurse on `[0..0]` and `[1..1]`.

###### 5.2.2.1.1 Base Cases

* `[0..0]` is a single element `[1]` → no pairs → return 0.
* `[1..1]` is a single element `[3]` → no pairs → return 0.

###### 5.2.2.1.2 Merge & Count Between `[1]` and `[3]`

* Copy `L = [1]` (nL=1) and `R = [3]` (nR=1).
* **Counting Phase**:

  * `i=0, j=0`. Compare `L[0]=1` vs. `2·R[0]=2·3=6`.
    → `1 ≤ 6`. So no reverse pair. Move `i → 1` (now `i == nL`, exit).
  * We counted **0** cross-pairs here.
* **Merge Phase**:

  * Merge `[1]` and `[3]` → results in `[1, 3]`.
* Return total **0** for this subarray `[0..1]`. Now `nums[0..1]` is sorted as `[1, 3]`.

##### 5.2.2.2 Right of Left: Subarray `[2..2] = [2]`

* Single element, return **0**. It is already “sorted” by definition.

##### 5.2.2.3 Merge & Count Between `[1,3]` and `[2]`

* Now we have left half = `[1,3]` (sorted) and right half = `[2]`.
* Copy `L = [1, 3]` (nL=2), `R = [2]` (nR=1).

1. **Counting Phase**:

   * `i=0, j=0`. Compare `L[0]=1` vs. `2·R[0]=4`.
     → `1 ≤ 4`. No pair. Move `i → 1`.
   * `i=1, j=0`. Now compare `L[1]=3` vs. `2·R[0]=4`.
     → `3 ≤ 4`. No pair. Move `i → 2`.
   * `i == nL`, stop. **Count = 0**.

2. **Merge Phase** (merge `[1,3]` with `[2]`):

   * `i=0, j=0, k=left=0`.

     * Compare `L[0]=1` vs. `R[0]=2`. → `1 ≤ 2`: pick `1` → `nums[0]=1`, `i→1`.
   * Now `i=1, j=0, k=1`.

     * Compare `L[1]=3` vs. `R[0]=2`. → `3 > 2`: pick `2` → `nums[1]=2`, `j→1`.
   * Now `j == nR`, so copy leftover from `L`:

     * `nums[2] = L[1] = 3`, `i→2`.
   * Final merged subarray `[0..2]` is now `[1, 2, 3]`.

* Return **0** for the entire left section `[0..2]`. Now `nums[0..2]` is `[1, 2, 3]`.

——

#### 5.2.3 Level 2 Right: Subarray `[3..4] = [3, 1]`

* `left = 3`, `right = 4`, `mid = 3`.
* Recurse on `[3..3]` and `[4..4]`.

##### 5.2.3.1 Base Cases `[3..3] = [3]` → return 0, `[4..4] = [1]` → return 0.

##### 5.2.3.2 Merge & Count Between `[3]` and `[1]`

* `L = [3]` (nL=1), `R = [1]` (nR=1).

* **Counting Phase**:

  * `i=0, j=0`. Compare `L[0]=3` vs. `2·R[0]=2`.
    → `3 > 2`. So **all** of `L[i..nL–1]` = `[3]` are > `2·1`. That is `(nL – i) = (1 – 0) = 1` new reverse pair: specifically `(i=0 in L, j=0 in R)`, which corresponds to original indices `(3, 4)`.

    * Add `count += 1`.
    * Move `j → 1`. Now `j == nR`, so stop the loop.
  * **Count = 1** from this merge.

* **Merge Phase**:

  * Merge `[3]` and `[1]` into sorted order:

    * Compare `3` vs. `1`. Since `1 < 3`, write `1` first → `nums[3]=1`, `j→1`.
    * Now copy leftover `L[0]=3` → `nums[4]=3`.
  * Subarray `[3..4]` becomes `[1, 3]`.

* Return **1** for the right section `[3..4]`. Now `nums[3..4]` is `[1, 3]`.

——

#### 5.2.4 Level 1 Merge & Count Between Left `[1,2,3]` and Right `[1,3]`

Now we have:

* Left half (sorted): `nums[0..2] = [1, 2, 3]` (call it `L` with nL=3).
* Right half (sorted): `nums[3..4] = [1, 3]` (call it `R` with nR=2).

We do:

```cpp
L = [1, 2, 3];   nL = 3
R = [1, 3];      nR = 2
i = 0, j = 0, count = 0
```

1. **Counting Phase**:

   * Step A: `i=0, j=0`. Compare `L[0]=1` vs. `2·R[0]=2`. → `1 ≤ 2`. So no pair here.
     → Move `i → 1`.
   * Step B: `i=1, j=0`. Compare `L[1]=2` vs. `2·R[0]=2`. → `2 ≤ 2`. Still not “>,” so no pair.
     → Move `i → 2`.
   * Step C: `i=2, j=0`. Compare `L[2]=3` vs. `2·R[0]=2`. → `3 > 2`. So *all* of `L[2..2]` (just the single value `3`) is > `2·1`. That is `(nL – i) = (3 – 2) = 1` new pair: it corresponds to original indices `(2, 3)` in 0-based indexing → that is `(nums[2] = 3, nums[3] = 1)`.
     → `count += 1`.
     → Move `j → 1`.
   * Step D: Now `i=2, j=1`. Compare `L[2]=3` vs. `2·R[1]=2·3=6`. → `3 ≤ 6`. No pair formed.
     → Move `i → 3`.
   * Now `i == nL`, stop.

   Total cross-count from this merge = **1**. This pair is `(2,3)` in original terms, but in the whole array indexing that’s `(nums index 2 = 3, nums index 3 = 1)`. Indeed, `3 > 2·1`.

2. **Merge Phase** (to reconstruct sorted order from `[1,2,3]` and `[1,3]`):

   * `i=0, j=0, k=0` (writing into `nums[0..4]`).

     1. Compare `L[0]=1` vs. `R[0]=1`.
        → tie → pick from `L` (either side would be okay, but we choose left first by `<=`).
        → `nums[0] = 1`. → `i→1`.
     2. Now `i=1 (L[1]=2), j=0 (R[0]=1), k=1`.
        Compare `2` vs. `1`. → `1 < 2`, so pick `R[0]=1`.
        → `nums[1] = 1`. → `j→1`.
     3. Now `i=1 (L[1]=2), j=1 (R[1]=3), k=2`.
        Compare `2` vs. `3`. → pick `2`. → `nums[2]=2`. → `i→2`.
     4. Now `i=2 (L[2]=3), j=1 (R[1]=3), k=3`.
        Compare `3` vs. `3`. → tie → pick `L[2]=3`. → `nums[3]=3`. → `i→3`.
     5. Now `i==nL`, so copy leftover `R[1]=3` → `nums[4]=3`.

   Final merged array `[0..4]` becomes:

   ```
   [1, 1, 2, 3, 3]
   ```

3. **Sum of Counts**:

* Left half `[0..2]` contributed **0** (no reverse pairs inside `[1,3,2]`).
* Right half `[3..4]` contributed **1** (the pair `(3,1)`).
* Cross-pairs contributed **1** (the pair `(3 at index 2, 1 at index 3)`).

Total = 0 + 1 + 1 = **2**, which matches our brute-force check.

---

## 6. Why This Counts *All* Reverse Pairs

1. **Pairs Entirely in the Left Half**

   * Those get counted (and the left half becomes sorted) by the recursive call `countReversePairs(nums, left, mid)`.

2. **Pairs Entirely in the Right Half**

   * Those get counted by `countReversePairs(nums, mid+1, right)`.

3. **Pairs Crossing Left→Right**

   * Exactly the pairs with `i ≤ mid < j`.
   * By the time both halves are individually sorted, we know all “cross” pairs must have one element in the left sorted subarray `L` and one in the right subarray `R`.
   * The two-pointer loop in `countWhileMerge` examines precisely every possible pairing exactly once (through pointer movement) and counts exactly those `(L[i], R[j])` where `L[i] > 2·R[j]`.

Because we never skip or double-count any combination, the sum of “left only” + “right only” + “cross” yields the total. And each merge step sorts the subarray so that, as we climb back up recursion, we maintain sorted halves for future merges, ensuring correctness.

---

## 7. Line-By-Line Explanation of the Counting Loop

Below is a re-examination of the critical loop in `countWhileMerge`, with commentary on each line.

```cpp
long long count = 0;
int i = 0, j = 0;

// L[0..nL–1] is the sorted copy of nums[left..mid]
// R[0..nR–1] is the sorted copy of nums[mid+1..right]

while (i < nL && j < nR) {
    // Compare the current L[i] to 2 * R[j]
    if ((long long)L[i] <= 2LL * R[j]) {
        // Case: L[i] is NOT greater than 2 * R[j].
        // Since R[j] ≤ R[j+1] ≤ ... (R is sorted), if L[i] ≤ 2*R[j]
        // then L[i] ≤ 2*R[k] for all k ≥ j. So L[i] cannot form a
        // reverse pair with any R[k], k ≥ j.
        //
        // Advance i to check the next L[i+1].
        i++;
    }
    else {
        // Case: L[i] > 2 * R[j].
        // Since L is sorted, L[i], L[i+1], L[i+2], ..., L[nL–1] are
        // all ≥ L[i]. Thus every one of those is also > 2 * R[j].
        // That is exactly (nL – i) distinct reverse pairs:
        //   (L[i], R[j]), (L[i+1], R[j]), ..., (L[nL–1], R[j]).
        count += (long long)(nL - i);

        // We have counted all pairs involving R[j]. To avoid counting
        // R[j] again, move j → j+1, so the next iteration compares
        // the same L[i] to the next R[j+1].
        j++;
    }
}
// At this point, either i == nL (exhausted left) or j == nR (exhausted right).
// We have counted every cross-pair. Now we proceed to the standard merge.
```

**Why this is correct**:

* Whenever `L[i] > 2·R[j]`, *all* bigger indices in `L` also exceed `2·R[j]`. So we add them in one batch.
* Whenever `L[i] ≤ 2·R[j]`, *all* bigger `R[k]` will make `2·R[k] ≥ 2·R[j] ≥ L[i]`, so none can pair with `L[i]` to satisfy `L[i] > 2·R[k]`. Hence advance the left pointer `i`.

Because each pointer only ever moves forward (never goes back), we do exactly `(nL + nR)` pointer‐increments at most, so it is linear time in that subproblem size.

---

## 8. Edge Cases & Common Pitfalls

1. **Integer Overflow**

   * Always write `2LL * R[j]` or cast to `long long` before doubling, to avoid overflow when `nums[j]` is close to `2¹⁰⁻¹` or greater.
   * Store the running count in a `long long` because the number of reverse pairs can be as large as `n·(n–1)/2` (≈ 10¹⁰ for `n = 100,000`).

2. **Strict vs. Non-Strict Comparison**

   * Problem requires `nums[i] > 2·nums[j]` (strictly greater).
   * If you accidentally write `>=` or `<=` incorrectly, you may overcount or undercount.
   * In code, the key line is `if (L[i] <= 2LL * R[j]) i++; else { … }`. Notice the `<=`, which means “not strictly greater.” Only when `L[i] > 2·R[j]` do we add counts.

3. **Merging Reorders Data**

   * After counting, you must still merge the two halves into sorted order. If you omit the merge‐step, then higher levels of recursion will no longer have sorted subarrays, and the counting logic will break.

4. **Off-By-One in Indices**

   * Be very consistent with how you compute `mid = (left + right) / 2`.
   * When you copy into `L[]` and `R[]`, make sure:

     * `L[k] = nums[left + k]` for `k = 0..(mid − left)`.
     * `R[k] = nums[mid + 1 + k]` for `k = 0..(right − (mid+1))`.

---

## 9. Pseudocode Summary

Putting it all together, here is concise pseudocode:

```
function countReversePairs(nums, left, right):
    if left >= right: 
        return 0
    mid = (left + right) // 2

    // 1. Count in left half
    countLeft = countReversePairs(nums, left, mid)

    // 2. Count in right half
    countRight = countReversePairs(nums, mid+1, right)

    // 3. Count cross-pairs and merge
    countCross = countWhileMerge(nums, left, mid, right)

    // 4. Return total for this segment
    return countLeft + countRight + countCross


function countWhileMerge(nums, left, mid, right):
    // Copy two sorted halves into temporary arrays
    nL = mid – left + 1
    nR = right – mid
    L[0..nL−1] = nums[left..mid]
    R[0..nR−1] = nums[mid+1..right]

    // Counting phase (two pointers)
    count = 0
    i = 0, j = 0
    while i < nL AND j < nR:
        if L[i] <= 2 * R[j]:
            i = i + 1
        else:
            // L[i] > 2*R[j], so all L[i..nL−1] qualify against this R[j]
            count += (nL − i)
            j = j + 1

    // Merging phase (standard)
    i = 0, j = 0, k = left
    while i < nL AND j < nR:
        if L[i] <= R[j]:
            nums[k] = L[i]
            i = i + 1
        else:
            nums[k] = R[j]
            j = j + 1
        k = k + 1

    // Copy any leftovers
    while i < nL:
        nums[k] = L[i]
        i = i + 1
        k = k + 1
    while j < nR:
        nums[k] = R[j]
        j = j + 1
        k = k + 1

    return count
```

**Key points in plain words**:

1. **Divide** the array into halves until you reach single elements.
2. **Recursively count** reverse pairs *within* each half. At this point, each half is sorted.
3. **Count the “cross-pairs”** between the two halves in a single linear scan, exploiting the fact that both halves are already sorted.
4. **Merge** them back into one sorted segment so that higher-level recursion can also count correctly.
5. **Sum** all counts from subcalls and this merge to get the total.

---

## 10. Final Intuition & Takeaways

* The magic of merge sort is in how it reduces a big problem (“count every reverse pair between any i\<j”) into smaller subproblems (“count pairs in left half” + “count pairs in right half” + “count pairs that cross from left to right”).
* The **sortedness** of each half is what makes the two-pointer counting possible in O(n) instead of O(n²).
* Every time you see a condition of the form “`A[i] > k * A[j]` where `k` is a constant” (and you’re asked to count how many such `(i, j)` pairs), think:

  1. Sort left half, sort right half.
  2. Use two pointers to skip over large blocks at once.
  3. That yields an O(n log n) count.

By practicing this on small examples (like above), you’ll internalize how each pointer move corresponds to ruling out many comparisons “in bulk” rather than one at a time. Once that basic pattern “sorted halves + two pointers” clicks, you can adapt it to count inversions, reverse pairs, or even more exotic conditions (e.g. triples `(i, j, k)` with some inequality) by the same merging philosophy.

I hope this deeper, step-by-step explanation makes it crystal-clear **why** and **how** the merge-sort approach for Reverse Pairs works in **O(n log n)** instead of O(n²). Good luck coding and testing it on your own examples!
