**Merge Sort: Building the Foundation**

To understand how we can count “inversions” (or “reverse pairs”) efficiently, it helps to first grasp **merge sort**, because the optimal counting methods modify merge sort slightly. Here’s merge sort in simple steps:

1. **Divide**

   * Take the array you want to sort and split it roughly in half.
   * You now have two smaller arrays: the “left half” and the “right half.”

2. **Conquer (Sort Each Half Recursively)**

   * If an array has only one element, it’s already sorted—so return it.
   * Otherwise, keep splitting each half until you get down to single-element arrays.

3. **Merge**

   * When you come back up from the recursion, you take two sorted subarrays (left and right) and **merge** them into one bigger sorted array.
   * Merging is done by maintaining two pointers (one for each subarray), repeatedly picking the smaller current element, and writing it into a temporary array.
   * Once one subarray is exhausted, you append whatever is left from the other subarray.

Because each split roughly halves the array, and each merge step takes linear time in the size of the two halves, merge sort runs in **O(n log n)** time overall.

---

## 1. Counting Inversions: The Core Idea

### 1.1 What Is an Inversion?

* Given an array `A[]` of length `n`, an **inversion** is a pair of indices `(i, j)` such that:

  * `i < j`, and
  * `A[i] > A[j]`.
* Intuitively, it’s a pair of elements out of order if you wanted the array in **ascending** sequence.

**Why do we care?**

* Counting inversions tells us how “far” the array is from being sorted.
* If the array is fully sorted in ascending order, it has **0 inversions**.
* If it’s sorted in descending order, it has the maximum possible inversions, which is `n*(n-1)/2`.

---

### 1.2 Brute-Force Method (O(n²))

The simplest way to count inversions is:

1. Initialize `count = 0`.
2. For each index `i` from `0` to `n-2`, do:

   * For each index `j` from `i+1` to `n-1`, do:

     * If `A[i] > A[j]`, increment `count`.
3. Return `count`.

Because we explicitly check every pair `(i,j)` with `i<j`, this runs in **O(n²)** time. For small arrays (e.g. `n` up to a few thousands), that might be okay. But for large `n`, it’s too slow.

**Brute-Force Pseudocode:**

```cpp
long long countInversionsBrute(vector<int>& A) {
    int n = A.size();
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                count++;
            }
        }
    }
    return count;
}
```

* Notice the use of `long long` for `count`, because the number of inversions can be as large as `n*(n-1)/2`, which may exceed the range of a 32-bit integer.

---

### 1.3 Optimal Method: Merge Sort + Counting (O(n log n))

Instead of checking every pair, we can count inversions “on the fly” while we do a merge sort. The insight is:

* During the **merge** step of merge sort, you have two sorted halves:

  * Left half: `L[]` (sorted), size = `nL`
  * Right half: `R[]` (sorted), size = `nR`
* You merge them into a single sorted array. You keep two pointers, say `i` (over `L`) and `j` (over `R`).
* Normally, to merge, you repeatedly compare `L[i]` and `R[j]`, pick the smaller, and copy it to the merged array.
* **Key observation for inversions**:

  * If `L[i] ≤ R[j]`, then no new inversions are discovered—just copy `L[i]` and move `i++`.
  * **But** if `L[i] > R[j]`, then `L[i]` is bigger than `R[j]`. Since `L[]` is sorted, **every remaining element** `L[i], L[i+1], …, L[nL−1]` will also be ≥ `L[i]`, hence all of them are greater than `R[j]`. That means:

    * There are `(nL − i)` inversions at once, because each of `L[i], L[i+1], …` pairs with `R[j]` to form an inversion.
  * So, when `L[i] > R[j]`, we do:

    ```cpp
    count += (nL - i);
    copy R[j] into merged array, and do j++.
    ```
* By accumulating these “block counts” during every merge, we get the total number of inversions in **O(n)** for each merge, and the recursion depth is **O(log n)**. Thus overall **O(n log n)**.

---

#### Detailed Steps of Merge-Sort + Count

1. **Recursive Function**:
   Let’s define a function `mergeCount(A, left, right)` that returns the number of inversions in the subarray `A[left..right]` and also sorts `A[left..right]` in place.

   * Base case: if `left >= right`, the subarray has 0 or 1 element—no inversions. Return 0.
   * Otherwise, compute `mid = (left + right) / 2`.
   * Let `countLeft = mergeCount(A, left, mid)`.
   * Let `countRight = mergeCount(A, mid+1, right)`.
   * Let `countMerge = mergeAndCount(A, left, mid, right)`:

     * This merges the two sorted halves and counts cross-inversions.
   * Return `countLeft + countRight + countMerge`.

2. **Merge-and-Count Function**:

   * Input: `A[left..mid]` and `A[mid+1..right]` are each sorted.
   * Create two temporary arrays:

     * `L[i] = A[left + i]`, for `i` in `[0..nL-1]`, where `nL = mid - left + 1`.
     * `R[j] = A[mid + 1 + j]`, for `j` in `[0..nR-1]`, where `nR = right - (mid+1) + 1 = right - mid`.
   * Initialize pointers `i = 0` (for L), `j = 0` (for R), and `k = left` (for writing back into A). Initialize `invCount = 0`.
   * While both `i < nL` and `j < nR`:

     * If `L[i] <= R[j]`, copy `A[k++] = L[i++]`.
       *(No new inversions here, because L\[i] is not bigger than R\[j].)*
     * Else (`L[i] > R[j]`):

       * We know `L[i] > R[j]`. Since the entire remaining tail `L[i..nL−1]` is ≥ `L[i]`, each of those elements is > `R[j]`.
       * So `invCount += (nL - i)`.
       * Copy `A[k++] = R[j++]`.
   * Copy any leftover elements from `L` (if `i < nL`) or from `R` (if `j < nR`). These leftover copies do not introduce new inversions because either `R` was exhausted (so everything left in `L` is bigger than all in `R` that have been merged) or `L` was exhausted (no cross pair left).
   * Return `invCount`.

---

#### C++ Code for Counting Inversions (Optimal O(n log n))

```cpp
#include <bits/stdc++.h>
using namespace std;

// Merge two sorted halves A[left..mid] and A[mid+1..right].
// Count how many cross-inversions exist between the two halves.
long long mergeAndCount(vector<int>& A, int left, int mid, int right) {
    int nL = mid - left + 1;
    int nR = right - mid;
    vector<int> L(nL), R(nR);
    for (int i = 0; i < nL; i++)
        L[i] = A[left + i];
    for (int j = 0; j < nR; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long invCount = 0;

    // Merge step, with inversion counting
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            // L[i] > R[j] ⇒ all L[i..nL-1] are > R[j]
            invCount += (long long)(nL - i);
            A[k++] = R[j++];
        }
    }

    // Copy any remaining elements
    while (i < nL) {
        A[k++] = L[i++];
    }
    while (j < nR) {
        A[k++] = R[j++];
    }

    return invCount;
}

// Recursively sort A[left..right] and count inversions in it.
long long mergeCount(vector<int>& A, int left, int right) {
    if (left >= right) return 0;  // 0 or 1 element: no inversions

    int mid = left + (right - left) / 2;
    long long countLeft  = mergeCount(A, left, mid);
    long long countRight = mergeCount(A, mid + 1, right);
    long long countMerge = mergeAndCount(A, left, mid, right);

    return countLeft + countRight + countMerge;
}

// Helper to call from outside
long long countInversions(vector<int>& A) {
    return mergeCount(A, 0, (int)A.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long totalInversions = countInversions(A);
    cout << totalInversions << "\n";
    return 0;
}
```

* **How this works**:

  * We do a standard merge sort, except in the `mergeAndCount` function we also accumulate how many inversions cross from the left half into the right half.
  * Because we only add `(nL − i)` when `L[i] > R[j]`, we count exactly the number of pairs `(p, q)` where `p` is in the left half (index ≥ `i`) and `q` is the right-half element `R[j]`.
  * Summing these counts over all merges yields the total number of inversions in the entire array.
* **Time Complexity**: O(n log n).
* **Space Complexity**: O(n) extra for temporary arrays in each level (which in total is O(n) if implemented carefully, though this code does allocate new vectors on each merge).

---

## 2. Reverse Pairs: Generalizing the Inversion Count

### 2.1 Problem Statement

The **Reverse Pairs** problem (e.g., on LeetCode) is stated as:

> Given an array `nums[]` of length `n`, count the number of **reverse pairs**.
> A reverse pair is a pair of indices `(i, j)` such that:
>
> 1. `0 ≤ i < j < n`, and
> 2. `nums[i] > 2 * nums[j]`.
>
> Return the total number of such pairs.

This is very similar to counting inversions (`nums[i] > nums[j]`), but with the stricter condition `nums[i] > 2 * nums[j]`.

* If you tried the naive approach, you’d check every `(i, j)` with `i < j` and test `nums[i] > 2*nums[j]`. That’s **O(n²)**.
* We want something faster—ideally **O(n log n)**, using a technique very close to the merge-sort-based inversion count.

---

### 2.2 Brute‐Force Approach (O(n²))

1. Initialize `count = 0`.
2. For `i = 0` to `n−1`:

   * For `j = i + 1` to `n−1`:

     * If `nums[i] > 2LL * nums[j]`, then `count++`.
3. Return `count`.

```cpp
long long reversePairsBrute(vector<int>& nums) {
    long long count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)nums[i] > 2LL * nums[j]) {
                count++;
            }
        }
    }
    return count;
}
```

* Again, we use `long long` to ensure we do the multiplication `2LL * nums[j]` safely and to accumulate a potentially large `count`.
* **Time Complexity**: O(n²).
* **When is this acceptable?** Only for small `n` (e.g., n up to a few thousands). For `n` around 10⁵, it’s too slow.

---

### 2.3 Optimal Method: Merge Sort + Counting (O(n log n))

We adapt the same idea as counting inversions, but instead of checking `L[i] > R[j]`, we check `L[i] > 2 * R[j]`. We do this *before* the actual merge, during a special counting step.

#### Key Idea

* Suppose we have two sorted halves (just like before):

  * Left half sorted: `L[]` (length `nL`, representing `nums[left..mid]` sorted)
  * Right half sorted: `R[]` (length `nR`, representing `nums[mid+1..right]` sorted)

* We want to count all pairs `(x, y)` where:

  * `x` comes from the left half, at index `iL` with value `L[iL]`.
  * `y` comes from the right half, at index `jR` with value `R[jR]`.
  * Condition: `L[iL] > 2 * R[jR]`.

* Because both `L` and `R` are sorted (ascending), we can use two pointers **iL** and **jR** to count how many `jR` satisfy the condition for each `iL`. Concretely:

  1. Initialize `count = 0`.
  2. Let `iL = 0` (pointing into `L`) and `jR = 0` (pointing into `R`).
  3. While `iL < nL` and `jR < nR`:

     * If `L[iL] ≤ 2 * R[jR]`, then `iL++` (no new “reverse pairs” formed with this `iL` at the current `jR`, because if `L[iL]` is not greater than `2 * R[jR]`, it won’t be greater for any larger `jR` either—*BUT* wait, careful: since `R` is sorted, if `L[iL] <= 2*R[jR]`, then for any future `jR′ > jR`, we have `R[jR′] ≥ R[jR]`, so `2*R[jR′] ≥ 2*R[jR]`, so `L[iL] <= 2*R[jR] ≤ 2*R[jR′]`. Hence no pairs with this `iL` and any `jR′` will satisfy `L[iL] > 2*R[jR′]`. We must increment `iL`.\*
     * Else (`L[iL] > 2 * R[jR]`):

       * Then for this fixed `jR`, **all** elements `L[iL], L[iL+1], …, L[nL−1]` are > `2*R[jR]`, because `L[iL]` is the smallest remaining in `L`.
       * So there are `(nL − iL)` such pairs involving `R[jR]`.
       * Add `(nL − iL)` to `count`.
       * Then do `jR++` to move to the next element in `R`.

* **After** this counting loop, we do the usual merge (comparing `L[i]` and `R[j]`) to reassemble them into sorted order.

This two-pointer counting step is **O(nL + nR)**, just like merging. And of course we do it at every level of recursion—so across the whole array we pay **O(n log n)** time.

---

#### Detailed Steps of Merge‐Sort + Reverse‐Pair Counting

1. **Recursive Function** `reverseCount(nums, left, right)`:

   * If `left >= right`, return 0.
   * Compute `mid = (left + right) / 2`.
   * `countLeft = reverseCount(nums, left, mid)`.
   * `countRight = reverseCount(nums, mid + 1, right)`.
   * `countCross = countWhileMerge(nums, left, mid, right)`.
   * Return `countLeft + countRight + countCross`.

2. **Count+Merge Function** `countWhileMerge(nums, left, mid, right)`:

   * Copy `L[] = nums[left..mid]` and `R[] = nums[mid+1..right]` into separate vectors. Let `nL = mid - left + 1`, `nR = right - mid`.
   * **Count step** (two pointers):

     ```cpp
     long long count = 0;
     int i = 0, j = 0;
     // L and R are both sorted
     while (i < nL && j < nR) {
         if ((long long)L[i] <= 2LL * R[j]) {
             i++;
         } else {
             // L[i] > 2*R[j]: every L[k] for k >= i also forms a reverse pair with R[j]
             count += (long long)(nL - i);
             j++;
         }
     }
     ```
   * **Merge step** (standard merging to keep sorted):

     ```cpp
     i = 0; 
     j = 0;
     int k = left;
     while (i < nL && j < nR) {
         if (L[i] <= R[j]) {
             nums[k++] = L[i++];
         } else {
             nums[k++] = R[j++];
         }
     }
     while (i < nL) nums[k++] = L[i++];
     while (j < nR) nums[k++] = R[j++];
     ```
   * Return `count`.

---

#### C++ Code for Reverse Pairs (Optimal O(n log n))

```cpp
#include <bits/stdc++.h>
using namespace std;

// Count cross reverse pairs where nums[i] > 2*nums[j], 
// for i in [left..mid] and j in [mid+1..right], 
// then merge the two sorted halves.
long long countWhileMerge(vector<int>& nums, int left, int mid, int right) {
    int nL = mid - left + 1;
    int nR = right - mid;
    vector<int> L(nL), R(nR);

    for (int i = 0; i < nL; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < nR; j++)
        R[j] = nums[mid + 1 + j];

    // 1) Counting step
    long long count = 0;
    int i = 0, j = 0;
    while (i < nL && j < nR) {
        // If L[i] <= 2*R[j], no reverse pair for this i with any future j's 
        if ((long long)L[i] <= 2LL * R[j]) {
            i++;
        } else {
            // L[i] > 2*R[j], so all L[i..nL-1] > 2*R[j]
            count += (long long)(nL - i);
            j++;
        }
    }

    // 2) Merge step
    i = 0; 
    j = 0;
    int k = left;
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
        }
    }
    while (i < nL) {
        nums[k++] = L[i++];
    }
    while (j < nR) {
        nums[k++] = R[j++];
    }

    return count;
}

long long reversePairsRec(vector<int>& nums, int left, int right) {
    if (left >= right) 
        return 0;  // single element has no reverse pairs

    int mid = left + (right - left) / 2;
    long long countLeft  = reversePairsRec(nums, left, mid);
    long long countRight = reversePairsRec(nums, mid + 1, right);
    long long countMerge = countWhileMerge(nums, left, mid, right);
    return countLeft + countRight + countMerge;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) 
        cin >> nums[i];

    long long ans = reversePairsRec(nums, 0, n - 1);
    cout << ans << "\n";
    return 0;
}
```

* **Explanation of Key Lines**:

  * We first split the array in half recursively.
  * In `countWhileMerge`, before we merge, we use two pointers (`i` for the left subarray, `j` for the right subarray) to count how many pairs satisfy `L[i] > 2 * R[j]`. Because `L` and `R` are sorted, once `L[i] > 2*R[j]`, we know all of `L[i], L[i+1], …` are also > `2*R[j]`, so we add `(nL - i)` at once and move `j` forward.
  * After counting, we do a normal merge to stitch the two halves back together in sorted order. Sorting is essential so that when we go one level up in recursion, the halves remain sorted for future cross-counting.

* **Time Complexity**: O(n log n).

* **Space Complexity**: O(n) extra at each level (temporary arrays), which overall is O(n) if implemented well.

---

## 3. Putting It All Together: Why This Works

1. **Merge Sort Skeleton**

   * We rely on “divide and conquer.” Each recursive call works on a smaller portion of the array.
   * By the time we do the merge at any level, the left and right halves are individually sorted.

2. **Counting During the Merge**

   * For **inversion count**: we look for `L[i] > R[j]`. Once that holds, everything from `L[i]` to the end is greater than `R[j]`, so add `(nL - i)`.
   * For **reverse pairs**: we look for `L[i] > 2*R[j]`. Once that holds, everything from `L[i]` onward is also > `2*R[j]`, so add `(nL - i)`.

3. **Why We Can Count Correctly**

   * At each merge step, **all inversions (or reverse pairs) that have one index in the left half and the other index in the right half** must be counted now, because future merges won’t mix these two halves again.
   * The recursion already counted pairs entirely inside the left half (`countLeft`) and pairs entirely inside the right half (`countRight`).
   * Adding `countMerge` captures exactly the “cross” pairs (left vs. right). Summing them yields the global total.

---

## 4. Summary & Tips

* **Merge Sort Basics**

  * Always remember: split → recursively sort → merge. Merge takes O(size of both halves).
  * You can adapt any “comparison-based” counting problem into merge sort by noticing that when you compare two pointers during merge, you can count how many elements in one half pair with the current element in the other half.

* **Counting Inversions vs. Counting Reverse Pairs**

  * Inversion condition: `A[i] > A[j]`.
  * Reverse-pair condition: `A[i] > 2 * A[j]`.
  * The structure of the code is almost identical—just change the comparison.
  * In both cases, sorting while counting is the key to getting from O(n²) down to O(n log n).

* **Edge Cases**

  * Very large arrays might have millions of inversions or reverse pairs, so always store counts in a 64-bit type (`long long`).
  * Watch out for integer overflow when you do `2 * nums[j]`: either cast to `long long` or do `2LL * nums[j]`.

* **When to Use the Brute Approach**

  * If `n` is small (e.g. `n ≤ 2,000`), an O(n²) solution can pass in practice.
  * Otherwise, implement the merge‐sort‐based method.

---

### Full C++ Code Snippets

#### 4.1 Inversion Count (Merge Sort, O(n log n))

```cpp
#include <bits/stdc++.h>
using namespace std;

// Merge two sorted subarrays and count inversions between them.
long long mergeAndCount(vector<int>& A, int left, int mid, int right) {
    int nL = mid - left + 1;
    int nR = right - mid;
    vector<int> L(nL), R(nR);
    for (int i = 0; i < nL; i++) 
        L[i] = A[left + i];
    for (int j = 0; j < nR; j++) 
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long invCount = 0;

    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            // L[i] > R[j] ⇒ all L[i..nL-1] form inversions with R[j]
            invCount += (long long)(nL - i);
            A[k++] = R[j++];
        }
    }
    while (i < nL) 
        A[k++] = L[i++];
    while (j < nR) 
        A[k++] = R[j++];
    return invCount;
}

long long mergeCount(vector<int>& A, int left, int right) {
    if (left >= right) 
        return 0;
    int mid = left + (right - left) / 2;
    long long countLeft  = mergeCount(A, left, mid);
    long long countRight = mergeCount(A, mid + 1, right);
    long long countMerge = mergeAndCount(A, left, mid, right);
    return countLeft + countRight + countMerge;
}

long long countInversions(vector<int>& A) {
    return mergeCount(A, 0, (int)A.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) 
        cin >> A[i];

    cout << countInversions(A) << "\n";
    return 0;
}
```

---

#### 4.2 Reverse Pairs (Merge Sort, O(n log n))

```cpp
#include <bits/stdc++.h>
using namespace std;

// Count cross reverse pairs nums[i] > 2*nums[j], then merge sorted halves.
long long countWhileMerge(vector<int>& nums, int left, int mid, int right) {
    int nL = mid - left + 1;
    int nR = right - mid;
    vector<int> L(nL), R(nR);

    for (int i = 0; i < nL; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < nR; j++)
        R[j] = nums[mid + 1 + j];

    // 1) Count reverse pairs with two pointers
    long long count = 0;
    int i = 0, j = 0;
    while (i < nL && j < nR) {
        if ((long long)L[i] <= 2LL * R[j]) {
            i++;
        } else {
            // L[i] > 2 * R[j], so all L[i..nL-1] pair with this R[j]
            count += (long long)(nL - i);
            j++;
        }
    }

    // 2) Merge the two sorted halves
    i = 0; 
    j = 0;
    int k = left;
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
        }
    }
    while (i < nL) nums[k++] = L[i++];
    while (j < nR) nums[k++] = R[j++];

    return count;
}

long long reversePairsRec(vector<int>& nums, int left, int right) {
    if (left >= right) 
        return 0;
    int mid = left + (right - left) / 2;
    long long countLeft  = reversePairsRec(nums, left, mid);
    long long countRight = reversePairsRec(nums, mid + 1, right);
    long long countMerge = countWhileMerge(nums, left, mid, right);
    return countLeft + countRight + countMerge;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long ans = reversePairsRec(nums, 0, n - 1);
    cout << ans << "\n";
    return 0;
}
```

---

## 5. Final Remarks

* Start by ensuring you understand **merge sort** thoroughly—split, sort each half recursively, merge.
* Once merge sort is crystal‐clear, notice how you can piggyback on the merge step to count any “pair‐based” condition between left and right halves.
* **Counting Inversions** is simply checking `L[i] > R[j]`.
* **Counting Reverse Pairs** is checking `L[i] > 2*R[j]`.
* Both can be done in **O(n log n)** with almost identical code, just changing the comparison.
* Always test on small examples by hand (e.g. `nums = [3, 1, 2]` for inversions or `nums = [2,4,3,5,1]` for reverse pairs) to see how the pointers move and how counts accumulate.

With this detailed breakdown—merge sort mechanics, brute‐force baseline, and then the optimal modifications—you should have a clear, step‐by‐step intuition and ready-to‐use C++ implementations.
