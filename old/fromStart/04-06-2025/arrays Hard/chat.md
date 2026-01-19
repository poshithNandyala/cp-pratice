Below is an in‐depth, step‐by‐step explanation for each of the four problems—Pascal’s Triangle, Majority Element (appearing > ⌊n/3⌋ times), 3-Sum, and 4-Sum. For each, you’ll find:

1. **Problem Statement** (with examples)
2. **Brute-Force Approach** (straightforward but inefficient)
3. **Improved/Beter Approaches** (how sorting, two-pointers, or special techniques improve things)
4. **Optimal/Generalized Approach** (when applicable)
5. **Detailed Intuition** (why each step works, what the key insight is)

---

## 1. Pascal’s Triangle

### 1.1 Problem Statement

> **“Given an integer `numRows`, generate the first `numRows` of Pascal’s triangle.”**
> In Pascal’s triangle, each row corresponds to the binomial coefficients for that row index. Concretely:
>
> * Row 0: \[1]
> * Row 1: \[1, 1]
> * Row 2: \[1, 2, 1]
> * Row 3: \[1, 3, 3, 1]
> * Row 4: \[1, 4, 6, 4, 1]
>
> In general, if row k (0-indexed) is `[c₀, c₁, …, cₖ]`, then row (k+1) is `[1, c₀+c₁, c₁+c₂, …, c_{k−1}+c_k, 1]`.

```
Example:
Input:  numRows = 5
Output: [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
]
```

You must return a 2D list (list of lists), each inner list being one row of Pascal’s triangle, up to `numRows` rows.

---

### 1.2 Brute-Force / “Build Each Row from the Previous”

#### Approach

1. **Initialize** a list `triangle = []`.
2. For each `i` from 0 to `numRows−1` (inclusive):

   1. If `i == 0`, then row 0 is simply `[1]`. Append `[1]`.
   2. Otherwise, let the previous row be `prev = triangle[i−1]`.
   3. Create a new row of length `i+1`. We know the first and last elements are always `1`.
   4. For each index `j` from 1 to `i−1`:

      * Set `current[j] = prev[j−1] + prev[j]`.
   5. Append `[1] + (all those sums) + [1]` to `triangle`.
3. Return `triangle`.

```python
def generate_pascal(numRows):
    triangle = []
    for i in range(numRows):
        if i == 0:
            triangle.append([1])
        else:
            prev = triangle[i-1]
            row = [1] * (i+1)  # start with all 1's
            for j in range(1, i):
                row[j] = prev[j-1] + prev[j]
            triangle.append(row)
    return triangle
```

#### Time and Space Complexity

* **Time Complexity:**

  * For each `i` from 0 to `numRows−1`, we do O(i) work to sum neighboring values. Summing over `i = 0,…,n−1` gives O(0 + 1 + 2 + … + (numRows−1)) = O(numRows²).
* **Space Complexity:**

  * We build a 2D structure containing roughly 1 + 2 + 3 + … + numRows = O(numRows²) elements. So O(numRows²) space.

#### Drawbacks

* This is already quite straightforward—there’s no obvious sub-O(n²) method to list out **all** entries, because you must at least write down \~n²/2 numbers. But if one only needed one particular row or one particular value, there are faster formulas.

---

### 1.3 “Optimal” via Binomial Coefficients

If you only want to compute a single row `k` (0-indexed) of Pascal’s triangle, there’s a well‐known formula:

$$
\text{value at position } j \text{ in row } k \;=\; \binom{k}{j} \;=\; \frac{k!}{\,j!\, (k-j)!}\,.
$$

Moreover, you can compute consecutive entries without full factorials using:

$$
\binom{k}{0} = 1,\quad
\binom{k}{j} = \binom{k}{\,j-1\,} \times \frac{k - (j - 1)}{\,j\,}.
$$

So you can generate row k in O(k) time and O(k) space by starting with 1 and iteratively doing:

```text
current = 1  # this is C(k, 0)
for j in 1..k:
   current = current * (k - (j - 1)) // j
   output current as C(k, j)
```

If the problem asked “return row k only,” you’d use that O(k) approach. But here, the requirement is all rows 0 through numRows−1. Generating each row in turn via adjacent‐sum (the brute-force nested‐loop approach) is already O(n²), and if you tried to use binomial coefficients for every single row, you’d still end up paying O(0 + 1 + 2 + … + (n−1)) = O(n²) time. Thus, building row by row is asymptotically optimal for generating the whole triangle.

---

### 1.4 Detailed Intuition

1. **Why does “sum of the two above” work?**

   * Pascal’s triangle encodes binomial coefficients: entry at row k, column j = “number of ways to choose j items out of k,” which is $\binom{k}{j}$. If you look at $\binom{k}{j} = \binom{k-1}{\,j-1} + \binom{k-1}{\,j}$, that exactly matches “the two numbers above it.”
   * In every row, the first and last are always 1 because $\binom{k}{0} = 1$ and $\binom{k}{k} = 1$.

2. **Row-by-row construction is intuitive:**

   * If you already know row (k−1), you know every $\binom{k-1}{\,j}$ value. Then row k’s interior entries $\binom{k}{\,j} = \binom{k-1}{\,j-1} + \binom{k-1}{\,j}$. Therefore, reading off two neighbors in row (k−1) gives you each interior entry of row k.

3. **Why O(n²) is inevitable for printing all rows:**

   * If `numRows = n`, row 0 has 1 entry, row 1 has 2 entries, …, row (n−1) has n entries. That sums to roughly n(n+1)/2 entries total. Writing that many integers in the output is Ω(n²) time. Our nested‐loop approach does exactly that in Θ(n²).

---

## 2. Majority Element (More Than ⌊n/3⌋ Times)

### 2.1 Problem Statement

> **“Given an array `nums` of length `n`, return all elements that appear more than ⌊n/3⌋ times.**
> You may assume the answer will have at most two such elements because if more than two distinct elements each appeared more than n/3 times, that would exceed n.”

```
Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1,1,1,3,3,2,2,2]
Output: [1,2]
```

* Here n = 8, so ⌊n/3⌋ = 2. Elements appearing strictly more than 2 times are 1 (appears 3 times) and 2 (appears 3 times).
* No third element can satisfy > ⌊8/3⌋ = 2, because that would require at least 3 + 3 + 3 = 9 total occurrences, which is impossible in an array of length 8.

---

### 2.2 Brute-Force / “Count Frequencies with a Hash Map”

#### Approach

1. Create an empty hash map (dictionary) `count = {}`.
2. Iterate through `nums`:

   * For each `x` in `nums`, do `count[x] = count.get(x, 0) + 1`.
3. After counting, collect all keys `k` for which `count[k] > ⌊n/3⌋`.
4. Return that list.

```python
def majority_element_n3(nums):
    n = len(nums)
    threshold = n // 3
    count = {}
    for x in nums:
        count[x] = count.get(x, 0) + 1
    result = []
    for k, freq in count.items():
        if freq > threshold:
            result.append(k)
    return result
```

#### Time and Space Complexity

* **Time Complexity:**

  * Counting all elements → O(n).
  * Scanning the dictionary (at most n keys) → O(n).
  * Total O(n).
* **Space Complexity:**

  * O(n) in the worst case, because if all n elements are distinct, you store n counts.

---

### 2.3 Optimal Approach: Extended Boyer-Moore Voting

#### Key Observation

* In an array of length `n`, at most **two distinct elements** can appear more than ⌊n/3⌋ times. Why?

  * Suppose there were three such elements, each appearing more than n/3 times. Then total occurrences ≥ 3 \* (⌊n/3⌋ + 1) ≥ 3 \* (n/3 + 1) = n + 3, which exceeds n. Contradiction.

Therefore, we only ever need to track up to two “candidate” values. By analogy to the classical Majority Element (> ⌊n/2⌋) case (which tracks one candidate), we can extend the idea to track two candidates.

#### Two-Pass Algorithm

We do two main phases:

1. **Phase 1 (Candidate Selection)—“Voting” Round**

   * Maintain two candidate variables `cand1` and `cand2`, and two counters `count1 = 0`, `count2 = 0`.
   * Iterate each `x` in `nums`:

     1. If `x == cand1`, increment `count1`.
     2. Else if `x == cand2`, increment `count2`.
     3. Else if `count1 == 0`, set `cand1 = x` and `count1 = 1`. (We “adopt” x as a new candidate 1.)
     4. Else if `count2 == 0`, set `cand2 = x` and `count2 = 1`. (We “adopt” x as new candidate 2.)
     5. Else, decrement both `count1--` and `count2--`.
   * At the end of this pass, `cand1` and `cand2` are the only two possible values that could exceed ⌊n/3⌋ occurrences (or one or none of them).

2. **Phase 2 (Verification Pass)**

   * Reset `count1 = 0`, `count2 = 0`.
   * Iterate through `nums` again and count how many times `cand1` and `cand2` actually appear.
   * Collect those candidates whose final count > ⌊n/3⌋.

```python
def majority_element_n3(nums):
    # Phase 1: find up to two candidates
    cand1, cand2 = None, None
    count1, count2 = 0, 0

    for x in nums:
        if cand1 is not None and x == cand1:
            count1 += 1
        elif cand2 is not None and x == cand2:
            count2 += 1
        elif count1 == 0:
            cand1, count1 = x, 1
        elif count2 == 0:
            cand2, count2 = x, 1
        else:
            count1 -= 1
            count2 -= 1

    # Phase 2: verify actual counts
    count1, count2 = 0, 0
    for x in nums:
        if x == cand1:
            count1 += 1
        elif x == cand2:
            count2 += 1

    result = []
    n = len(nums)
    if count1 > n // 3:
        result.append(cand1)
    if count2 > n // 3:
        result.append(cand2)
    return result
```

#### Why This Works (Intuition)

1. **“Cancelling Out” Mechanism**

   * Whenever we see an element that is neither `cand1` nor `cand2`, but both `count1` and `count2` are positive, we decrement *both* counts. You can think of it like pairing up that new element with one occurrence of each candidate and discarding them both. In effect, if there truly is an element that appears > n/3 times, it cannot be completely “cancelled out” by other distinct values, because there simply aren’t enough other elements to cancel all of its occurrences.
2. **Maintaining At Most Two Candidates**

   * Because we only track 2 candidates, whenever one candidate’s count drops to 0, we forget it and adopt a new element. This ensures that at the end, any element that could possibly exceed n/3 occurrences must still survive as one of our two candidates. All other elements would have been eliminated by pairwise cancellation.
3. **Verification Pass**

   * The first pass only *suggests* potential candidates. We still need a second pass to confirm they truly exceed ⌊n/3⌋.

#### Time and Space Complexity

* **Time Complexity:** O(n) for two passes through the array.
* **Space Complexity:** O(1) extra (just a few integers to hold counts and candidates).

Because the brute‐force hash map uses O(n) space, Boyer-Moore Voting (extended) is strictly better on space, and still O(n) time.

---

### 2.4 Detailed Intuition Summary

* **Key Insight:** In any array of length n, you cannot have more than two different elements each appearing more than ⌊n/3⌋ times. That fact lets you track just two “candidates” with a cancellation scheme instead of storing all frequencies.
* **Cancellation Logic:** Each time you see a “new” element (neither candidate1 nor candidate2) and both counters > 0, you do `count1--` and `count2--`. This models “pairing off” that new element with one occurrence of each candidate, effectively discarding three occurrences at once (the new element + one of cand1 + one of cand2). Because a true majority-(n/3) element cannot be fully eliminated via pairing with distinct other elements (there aren’t enough distinct elements to do so), it will “survive” as a final candidate.
* **Verification Step:** Because the pairing/cancellation only guarantees any candidate truly appears at least once, we must confirm it appears > n/3 times by counting again.

---

## 3. 3-Sum Problem

### 3.1 Problem Statement

> **“Given an integer array `nums`, return all unique triplets `[nums[i], nums[j], nums[k]]` such that:**
>
> 1. `i`, `j`, and `k` are distinct indices (i.e., i ≠ j ≠ k).
> 2. `nums[i] + nums[j] + nums[k] = 0`.
>    You may return the triplets in any order, but no duplicate triplets should appear in the output.”

```
Example:
Input: nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]
```

Notes:

* We treat `[-1, -1, 2]` as one valid triplet even though `-1` appears twice in the array; the indices of those two `-1`s must be different.
* We must avoid returning the same combination of values more than once (duplicates).

---

### 3.2 Brute-Force Approach: Three Nested Loops

#### Approach

1. **Initialize** an empty set (or list) for results. If using a set, store triplets as tuples sorted in ascending order so duplicates get collapsed.
2. For `i` from 0 to n−3:

   * For `j` from i+1 to n−2:

     * For `k` from j+1 to n−1:

       1. Check if `nums[i] + nums[j] + nums[k] == 0`.
       2. If yes, form a sorted tuple `(a, b, c) = sorted((nums[i], nums[j], nums[k]))`, and add to the set of solutions.
3. Convert the set of tuples back to a list of lists and return.

```python
def three_sum_bruteforce(nums):
    n = len(nums)
    found = set()
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if nums[i] + nums[j] + nums[k] == 0:
                    trip = tuple(sorted((nums[i], nums[j], nums[k])))
                    found.add(trip)
    return [list(trip) for trip in found]
```

#### Time and Space Complexity

* **Time Complexity:** O(n³) from three nested loops.
* **Space Complexity:**

  * If we store results in a set of size at worst O(n³) (though in practice far fewer), but in terms of big-O, O(n³) auxiliary in the worst‐case sense.

Clearly too slow for n > \~200 or so.

---

### 3.3 Optimal Approach: Sort + Two-Pointer

#### Key Idea

1. **Sort the array**.
2. **Fix one index** `i` from 0 to n−3 (so that there are at least two elements after it).
3. Now we want two elements among the subarray `nums[i+1 … n−1]` whose sum = `-nums[i]`.

   * That is precisely a 2-Sum problem on a sorted list: find all pairs `(left, right)` such that `nums[left] + nums[right] = target2`, where `target2 = -nums[i]`.
4. Use the classic two-pointer technique on the sorted subarray:

   * Initialize `left = i + 1`, `right = n − 1`.
   * While `left < right`:

     * Compute `s = nums[left] + nums[right]`.
     * If `s == target2`, record `[nums[i], nums[left], nums[right]]` as a valid triplet. Then increment `left` and decrement `right`, **but also skip duplicates** by moving `left` forward while `nums[left] == nums[left−1]`, and similarly for `right`.
     * If `s < target2`, we need a larger sum, so do `left += 1`.
     * If `s > target2`, we need a smaller sum, so do `right -= 1`.
5. **Skip duplicates for the fixed index `i`** as well:

   * If `i > 0` and `nums[i] == nums[i−1]`, continue to next `i` (to avoid generating the same first element twice).

```python
def three_sum(nums):
    nums.sort()  # O(n log n)
    n = len(nums)
    result = []
    for i in range(n):
        # If this is the same value as the previous, skip to avoid duplicates
        if i > 0 and nums[i] == nums[i-1]:
            continue

        target2 = -nums[i]
        left, right = i + 1, n - 1
        while left < right:
            s = nums[left] + nums[right]
            if s == target2:
                result.append([nums[i], nums[left], nums[right]])
                left += 1
                right -= 1
                # skip duplicates for left
                while left < right and nums[left] == nums[left - 1]:
                    left += 1
                # skip duplicates for right
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
            elif s < target2:
                left += 1
            else:
                right -= 1
    return result
```

#### Time and Space Complexity

* **Sorting:** O(n log n).
* **Main loop (i from 0 to n−1):**

  * For each fixed `i`, the two-pointer scan is O(n) in the worst case.
  * So total is O(n log n + n × n) = O(n²).
* **Space Complexity:**

  * O(log n) for the sort’s recursion (if the sorting algorithm is in-place), plus O(k) for output, where k is the number of valid triplets.

---

### 3.4 Detailed Intuition

1. **Why sort first?**

   * Sorting lets you do two things simultaneously:

     1. Quickly move pointers inward / outward to adjust sum.
     2. Easily skip duplicates by checking if `nums[left] == nums[left−1]` or `nums[right] == nums[right+1]`.

2. **Why fix one index and reduce to 2-Sum?**

   * The naive brute force tries all 3-tuples in O(n³). Instead, by fixing `i`, we only need to find pairs in the remainder whose sum cancels `nums[i]`. In a sorted array, two pointers can find 2-Sum in O(n) time. That reduces O(n³) → O(n²).

3. **Duplicate avoidance:**

   * If you allow “same value” at the fixed index multiple times, you’ll generate the same triplets over and over. For example, if `nums[i] == nums[i−1]`, then any triple built with `nums[i]` would already have been built with `nums[i−1]`. Hence skip.
   * Likewise, once you find a valid pair `(left, right)`, you move both pointers and skip any equal adjacent values to avoid listing the same pair again.

4. **Handling negative, zero, positive mix:**

   * Sorting places negative numbers first, then zeros, then positives. If `nums[i]` is negative, then `target2 = -nums[i]` is positive; we look for one negative + one positive (or zero + (target2)). The two pointers start at the leftmost “unfixed” and rightmost elements, scanning inward to find that exact pair.
   * If `nums[i]` is zero, `target2` is 0, so we look for pairs that sum to 0 (like `(-1, +1)` or `(0,0)`).
   * If `nums[i]` is positive, then `target2` is negative; but since all numbers to the right of `i` are ≥ `nums[i]`, once `nums[i] > 0`, you know no two subsequent numbers can sum to a negative `target2`. So in fact, you can break out early when `nums[i] > 0`.

```python
# Minor optimization: once nums[i] > 0, break entirely
for i in range(n):
    if nums[i] > 0:
        break
    # … rest of algorithm …
```

5. **Why O(n²) is unavoidable?**

   * In the worst case (e.g. all zeros, or many negative/positive pairs), you may end up checking almost every pair for each fixed `i`. Thus Ω(n²) time. O(n²) is optimal for listing all unique triplets in general.

---

## 4. 4-Sum Problem

### 4.1 Problem Statement

> **“Given an array `nums` of length `n` and an integer `target`, return all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:**
>
> 1. `0 ≤ a < b < c < d < n` (all indices distinct).
> 2. `nums[a] + nums[b] + nums[c] + nums[d] = target`.
>    You may return the quadruplets in any order but must not include duplicates.\*\*

```
Example:
Input: nums = [1, 0, -1, 0, -2, 2], target = 0
Output: [
  [-2, -1, 1, 2],
  [-2,  0, 0, 2],
  [-1,  0, 0, 1]
]
```

---

### 4.2 Brute-Force Approach: Four Nested Loops

#### Approach

1. **Initialize** a set `found = set()` for deduplicated quadruplets (store them as sorted tuples).
2. For `i` from 0 to n−4:

   * For `j` from i+1 to n−3:

     * For `k` from j+1 to n−2:

       * For `ℓ` from k+1 to n−1:

         1. Check if `nums[i] + nums[j] + nums[k] + nums[ℓ] == target`.
         2. If yes, do `quad = tuple(sorted([nums[i], nums[j], nums[k], nums[ℓ]]))` and add to `found`.
3. Convert each tuple back to a list and return the list of lists.

```python
def four_sum_bruteforce(nums, target):
    n = len(nums)
    found = set()
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                for l in range(k+1, n):
                    if nums[i] + nums[j] + nums[k] + nums[l] == target:
                        quad = tuple(sorted((nums[i], nums[j], nums[k], nums[l])))
                        found.add(quad)
    return [list(x) for x in found]
```

#### Time and Space Complexity

* **Time Complexity:** O(n⁴), since there are four nested loops.
* **Space Complexity:** Potentially O(n⁴) if you store all quadruplets in the set (in the absolute worst case).

Unusable for n > \~200. We need better.

---

### 4.3 Better Approach: Sort + Two-Pointer on Two Fixed Indices

#### Key Idea

1. **Sort** `nums`.

2. **Fix two indices:** `i` in \[0 … n−4], then `j` in \[i+1 … n−3]. You’ve “chosen” two numbers `nums[i]` and `nums[j]`. You want two more numbers from the subarray `nums[j+1 … n−1]` whose sum = `target2 = target − nums[i] − nums[j]`.

3. Now reduce to a 2-Sum problem (two pointers) on the sorted subarray from index `j+1` to `n−1`:

   * Set `left = j+1`, `right = n−1`.
   * While `left < right`:

     * Compute `curr_sum = nums[left] + nums[right]`.
     * If `curr_sum == target2`, record `[nums[i], nums[j], nums[left], nums[right]]`, then `left += 1`, `right -= 1`, skipping duplicates on `left` and `right`.
     * If `curr_sum < target2`, do `left += 1`.
     * If `curr_sum > target2`, do `right -= 1`.

4. **Skip duplicates** at each stage:

   * If `i > 0` and `nums[i] == nums[i−1]`, `continue`.
   * If `j > i+1` and `nums[j] == nums[j−1]`, `continue`.
   * After finding a valid pair `(left, right)`, increment `left` while `nums[left] == nums[left−1]`, and decrement `right` while `nums[right] == nums[right+1]`.

```python
def four_sum(nums, target):
    nums.sort()
    n = len(nums)
    results = []
    for i in range(n):
        # Skip duplicate i
        if i > 0 and nums[i] == nums[i-1]:
            continue
        for j in range(i+1, n):
            # Skip duplicate j
            if j > i+1 and nums[j] == nums[j-1]:
                continue

            target2 = target - nums[i] - nums[j]
            left, right = j+1, n-1
            while left < right:
                curr_sum = nums[left] + nums[right]
                if curr_sum == target2:
                    results.append([nums[i], nums[j], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    # skip duplicates for left
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                    # skip duplicates for right
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1
                elif curr_sum < target2:
                    left += 1
                else:
                    right -= 1
    return results
```

#### Time and Space Complexity

* **Sorting:** O(n log n).
* **Fixing i (n choices) and j (\~n choices) plus two-pointer O(n)**:

  * Roughly O(n × n × n) = O(n³).
* **Space Complexity:** O(log n) for the sort (in-place) + O(k) for storing results.

When n is up to \~2000 (with careful constant factors), an O(n³) solution can still be borderline; often constraints are n ≤ 200 or n ≤ 500 for 4-Sum. But definitely O(n³) is a huge improvement over O(n⁴).

---

### 4.4 Optimal / Generalized k-Sum via Recursion

Because both 3-Sum and 4-Sum share the pattern “fix (k−2) indices, then do 2-Sum with two pointers,” one can generalize to **k-Sum**:

* **General signature:**

  ```python
  def k_sum(nums, target, k, start):
      """
      Return a list of all unique k-tuples in sorted nums[start:] that sum to target.
      """
  ```
* **Base case:**

  * If `k == 2`, do the standard two-pointer 2-Sum on `nums[start:]`.
  * If `k > 2`, do:

    1. For `i` from `start` to `len(nums)−k` (inclusive):

       * If `i > start` and `nums[i] == nums[i−1]`, skip to avoid duplicates.
       * For each subset `subset` returned by `k_sum(nums, target − nums[i], k−1, i+1)`, prepend `nums[i]` to `subset` and add to result.

```python
def two_sum(nums, target, start):
    res = []
    left, right = start, len(nums) - 1
    while left < right:
        s = nums[left] + nums[right]
        if s == target:
            res.append([nums[left], nums[right]])
            left += 1
            right -= 1
            # skip duplicates
            while left < right and nums[left] == nums[left-1]:
                left += 1
            while left < right and nums[right] == nums[right+1]:
                right -= 1
        elif s < target:
            left += 1
        else:
            right -= 1
    return res

def k_sum(nums, target, k, start):
    res = []
    n = len(nums)
    # Early termination: if not enough numbers or smallest/largest sums can't reach target
    if k == 2:
        return two_sum(nums, target, start)

    for i in range(start, n - k + 1):
        if i > start and nums[i] == nums[i-1]:
            continue
        # Further early stopping if nums[i]*k is already too large or nums[-1]*k is too small
        if nums[i] * k > target:
            break
        if nums[-1] * k < target:
            break

        for subset in k_sum(nums, target - nums[i], k - 1, i + 1):
            res.append([nums[i]] + subset)
    return res

def four_sum(nums, target):
    nums.sort()
    return k_sum(nums, target, 4, 0)
```

* **Why this is “optimal” for k-Sum?**

  * In the worst case, the time complexity is O(n^(k−1)). For 4-Sum, that is O(n³).
  * Any approach that lists out all unique quadruplets must be Ω(n³) in the worst case (imagine every triple forming a new pair that hits the target, etc.), so O(n³) is optimal up to constant factors.

---

### 4.5 Detailed Intuition

1. **Reduction to 2-Sum at the core**

   * Both 3-Sum and 4-Sum rely on the fact that once you fix (k−2) elements, you only need to solve a 2-Sum for the remaining two elements.
   * 2-Sum on a sorted array can be done in O(n) by the “two-pointer” technique (left pointer starts at the beginning of the subarray, right pointer at the end; move them inward depending on whether current sum is too large or too small).

2. **Avoiding duplicates**

   * Sorting places duplicates next to each other.
   * Whenever we “fix” an index i, if `nums[i]` is the same as `nums[i−1]`, then any tuple starting with `nums[i]` would have been found in the previous iteration when we used `nums[i−1]`. So we skip.
   * Similarly, once a valid pair (left, right) is found in the 2-Sum stage, we must move left→left+1 until the value changes, and right→right−1 until the value changes. That ensures we don’t record the same pair multiple times.

3. **Early termination / bounds checks (optional optimizations)**

   * Before even recursing or doing two-pointers, you can check:

     * If `nums[i] * k` > target, break out, because even the smallest possible sum using `k` copies of `nums[i]` is already too big.
     * If `nums[-1] * k` < target, continue to next `i`, because even the largest possible sum using the top `k` remaining elements is too small.
   * These cuts can prune large portions of the search space when `k` is large.

4. **Why O(n³) is unavoidable for 4-Sum**

   * Suppose there are many valid quadruplets (e.g., all numbers = 0, and target = 0). Then every choice of (i, j, left, right) is a valid solution, and there are Θ(n⁴) of those. However, the uniqueness constraint (sorted + skip duplicates) collapses them down to a single quadruplet \[0,0,0,0].
   * In a more typical scenario with random data, you still must consider O(n³) index‐fixings (i, j, and then scanning left/right). You cannot do fundamentally better than “consider each pair (i,j) exactly once and then do an O(n) two-pointer sweep,” which is O(n³).

---

## Final Takeaways

* **Pascal’s Triangle**

  * Building row by row via adjacent sums is O(n²), which is optimal to list all rows.
  * If you only need a single row (say row k), use the binomial‐coefficient formula in O(k) time.

* **Majority Element (> ⌊n/3⌋)**

  * Brute‐force frequency count is O(n) time and O(n) space.
  * Boyer-Moore Voting (extended) finds up to two candidates in O(n) time and O(1) space, then verifies them in a second pass.

* **3-Sum**

  * Brute force is O(n³).
  * Sort + fix one index + two-pointer on the remainder = O(n²). Must carefully skip duplicates to avoid repeating triplets.

* **4-Sum**

  * Brute force is O(n⁴).
  * Sort + fix two indices + two-pointer for the final two = O(n³).
  * Generalize further to k-Sum by recursion: fix one index at a time until you reduce to 2-Sum, always skipping duplicates.

---

With these detailed breakdowns and the underlying “why” behind each optimization, you should now have a clear understanding of problem statements, straightforward brute-force methods, progressively better approaches, and the final “optimal” methods—plus the core intuitions that make them work. If you’d like concrete code examples, pseudocode walkthroughs, or step-by-step traces on sample inputs for any of these, just let me know!
