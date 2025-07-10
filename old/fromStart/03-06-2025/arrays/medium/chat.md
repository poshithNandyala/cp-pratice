Below you’ll find **14** classic array/matrix problems, each broken down into:

1. **Problem Statement**
2. **Brute‐Force Approach** (often O(n²) or worse)
3. **“Better” Approach** (when applicable)
4. **Optimal Approach** (final, most efficient)
5. **Intuition** (why it works)
6. **C++ Code** for the **optimal** solution, with line‐by‐line comments.

---

## 1. Two Sum

### 1.1 Problem Statement

> Given an integer array `nums` and an integer `target`, find ***any two distinct indices*** `i` and `j` (with `i ≠ j`) such that
>
> ```
> nums[i] + nums[j] == target.
> ```
>
> Return the pair of indices `[i, j]`. You may return them in any order.
> You can assume exactly one such pair exists.

---

### 1.2 Brute‐Force Approach

* **Idea**: Check **all possible pairs** `(i, j)` with two nested loops.
* **Pseudocode**:

  ```
  for i from 0 to n−2:
    for j from i+1 to n−1:
      if nums[i] + nums[j] == target:
        return [i, j]
  ```
* **Time**: O(n²) since we check \~n(n−1)/2 pairs.
* **Space**: O(1), aside from output.

---

### 1.3 Better Approach (Two‐Pointer on Sorted Array)

* **Idea**:

  1. Copy the original array into a vector of `(value, original_index)`.
  2. Sort that vector by `value`.
  3. Use two pointers `L` at start, `R` at end, and move inward:

     * If `V[L].value + V[R].value > target`, decrement `R`.
     * Else if `< target`, increment `L`.
     * Else, you found a match; return their original indices.
* **Time**: O(n log n) for sorting + O(n) for the two‐pointer scan = O(n log n).
* **Space**: O(n) to store `(value, index)` pairs.

---

### 1.4 Optimal Approach (Hash Map)

* **Idea**:

  1. Create an empty hash map `map<int,int> mp;` that will map “value → index.”
  2. Iterate `i` from 0 to `n−1`:

     * Let `complement = target − nums[i]`.
     * Check if `complement` is already in `mp`.

       * If yes, return `[mp[complement], i]`.
       * Otherwise, store `nums[i]` in the map: `mp[ nums[i] ] = i;`
* **Why it works**:

  * As you scan from left to right, for each `nums[i]` you ask “Have I seen the number that would pair with `nums[i]` to reach `target`?”
  * If yes, you have your answer immediately; if not, you remember `nums[i]` for future lookups.
* **Time**: O(n) — each lookup or insert in the hash map is O(1) on average.
* **Space**: O(n) — in the worst case you store every element.

---

### 1.5 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Two Sum – Hash Map approach (O(n) time, O(n) space)

  We iterate once through the array, and for each element nums[i], we check
  if (target - nums[i]) has already been seen. If so, return their stored index
  and current index. Otherwise, store nums[i] with its index in the hash map.
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp; 
    // mp[val] = index where nums[index] == val

    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        // Check if complement was seen before
        if (mp.find(complement) != mp.end()) {
            // Found a match: indices = [index_of_complement, i]
            return { mp[complement], i };
        }
        // Otherwise, remember nums[i]
        mp[ nums[i] ] = i;
    }
    // Problem guarantees exactly one solution, so we never actually reach here.
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example usage:
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    // Should print: 0 1
    cout << result[0] << " " << result[1] << "\n";
    return 0;
}
```

* **Line-by-Line Explanation**:

  1. **`unordered_map<int,int> mp;`**

     * Stores `(value → index)`.
     * `mp.find(x)` is O(1) on average.
  2. **Loop `for i in [0..n−1]`**:

     * Compute `complement = target − nums[i]`.
     * If `complement` is already a key in `mp`, you’ve found two indices whose values sum to `target`.
     * Otherwise, store `nums[i]` in `mp` so future elements can pair with it.

---

## 2. Sort an Array of 0s, 1s, and 2s (Dutch National Flag)

### 2.1 Problem Statement

> You have an array `nums[]` of size `n` that contains only the integers `0`, `1`, and `2`.
> Sort them **in‐place** so that all `0`s come first, then all `1`s, then all `2`s.
> Do this in a single pass (one traversal), using only constant extra space.

---

### 2.2 Brute‐Force Approach

* **Count & Overwrite** (Two‐pass):

  1. First pass: count how many `0`s, `1`s, and `2`s → let counts be `cnt0, cnt1, cnt2`.
  2. Second pass: overwrite the original array:

     * First `cnt0` positions put `0`, next `cnt1` positions put `1`, last `cnt2` positions put `2`.
* **Time**: O(n) (because two linear passes).
* **Space**: O(1) (just three integer counters).

---

### 2.3 Optimal Approach (Three‐Pointer / Dijkstra’s)

* **Idea**: Maintain three indices:

  * `low` = boundary for 0s, initially 0.
  * `mid` = current element under inspection, initially 0.
  * `high` = boundary for 2s, initially `n−1`.
* **Algorithm**:

  1. While `mid ≤ high`:

     * If `nums[mid] == 0`, swap `nums[low]` and `nums[mid]`, then `low++`, `mid++`.
     * Else if `nums[mid] == 1`, just `mid++`.
     * Else (`nums[mid] == 2`), swap `nums[mid]` and `nums[high]`, then `high--` (do **not** increment `mid` yet).
  2. Terminate once `mid` passes `high`.
* **Why It Works**:

  * Everything to the left of `low` is guaranteed to be `0`.
  * Everything to the right of `high` is guaranteed to be `2`.
  * `mid` scans through “unknown” elements and fixes them by swapping into the correct partition.
* **Time**: O(n)—each element is swapped at most once or twice, but overall linear.
* **Space**: O(1).

---

### 2.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Sort Colors (Dutch National Flag): 
  One‐pass, three pointers (low, mid, high).
  We push 0s to left, 2s to right, 1s naturally end up in middle.

  Time: O(n), Space: O(1).
*/

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = (int)nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap current element with the element at 'low' boundary
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            // Already in the correct region for '1'
            mid++;
        }
        else { // nums[mid] == 2
            // Swap current element with the element at 'high' boundary
            swap(nums[mid], nums[high]);
            high--;
            // Do NOT increment mid here, because the swapped‐in element from nums[high]
            // could be 0 or 1 or 2, so we need to re‐inspect it.
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    // After sorting: [0, 0, 1, 1, 2, 2]
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Initialize `low = 0, mid = 0, high = n−1`.
  2. While there remain unchecked positions (`mid ≤ high`):

     * If `nums[mid] == 0`, swap it into the “0 region” at index `low`, then `low` and `mid` both move right.
     * If `nums[mid] == 1`, it’s already in the “1 region”; just advance `mid`.
     * If `nums[mid] == 2`, swap it with `nums[high]` to push the 2 into the “2 region,” then decrement `high`—do not increment `mid` because the new `nums[mid]` needs inspection.

---

## 3. Majority Element (> ⌊n/2⌋

### 3.1 Problem Statement

> Given an array of size `n`, find the element that appears **more than** ⌊n/2⌋ times. You may assume such an element always exists.

---

### 3.2 Brute‐Force Approach

* **Idea**: For each index `i`, count how many times `nums[i]` appears by scanning the entire array. If any count > n/2, return that element.
* **Time**: O(n²).
* **Space**: O(1).

---

### 3.3 Better Approach (Hash Map)

* **Idea**: Use an `unordered_map<int,int> freq;` to count each element’s occurrences in one pass; then scan the map for a key with count > n/2.
* **Time**: O(n) to build counts + O(n) to scan = O(n).
* **Space**: O(n) for the hash map.

---

### 3.4 Optimal Approach (Boyer‐Moore Voting Algorithm)

* **Idea**:

  1. Maintain a candidate `cand` and a counter `count = 0`.
  2. For each element `x` in the array:

     * If `count == 0`, set `cand = x` and `count = 1`.
     * Else if `cand == x`, `count++`.
     * Else `count--`.
  3. At the end, `cand` is guaranteed to be the majority element (proof relies on the fact that majority > n/2 “cancels out” all minority occurrences).
* **Why It Works**:

  * Each time you see a number different from your current candidate, you “pair‐off” one occurrence of the candidate with that different number.
  * Since the majority element occurs more than half the time, it cannot be fully canceled out.
* **Time**: O(n).
* **Space**: O(1).

---

### 3.5 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Majority Element (Boyer‐Moore Voting Algorithm)
  We do a single pass to find a candidate; because we know a majority
  element exists, that candidate must be the majority.

  Time: O(n), Space: O(1).
*/

int majorityElement(vector<int>& nums) {
    int cand = nums[0];
    int count = 0;

    for (int x : nums) {
        if (count == 0) {
            // Pick a new candidate
            cand = x;
            count = 1;
        }
        else if (cand == x) {
            // Same as current candidate, increment
            count++;
        }
        else {
            // Different from candidate, “cancel out”
            count--;
        }
    }
    // Because the problem guarantees a majority > n/2, `cand` is correct.
    return cand;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(arr) << "\n"; // Should print 2
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Start with `cand = nums[0]`, `count = 0`.
  2. For each `x` in `nums`:

     * If `count == 0`, adopt `x` as new candidate with `count = 1`.
     * Else, if `x == cand` increment; otherwise `count--`.
  3. At the end, `cand` must be the majority, because every time a non‐majority “pushes back,” it gets paired off until the majority still remains.

---

## 4. Kadane’s Algorithm (Maximum Subarray Sum)

### 4.1 Problem Statement

> Given an array of integers `nums[]`, find the **contiguous subarray** (containing at least one number) which has the maximum sum, and return that sum.
> In other words, find
>
> ```
> max_{0 ≤ i ≤ j < n} ( nums[i] + nums[i+1] + … + nums[j] ).
> ```

---

### 4.2 Brute‐Force Approach

* **Idea**: Compute the sum of **every** possible subarray `(i, j)`:

  ```
  bestSum = −∞
  for i in [0..n−1]:
    currSum = 0
    for j in [i..n−1]:
      currSum += nums[j]
      bestSum = max(bestSum, currSum)
  ```
* **Time**: O(n²) (nested loops).
* **Space**: O(1).

---

### 4.3 Optimal Approach (Kadane’s)

* **Idea**: As you traverse, keep track of:

  1. `maxEndingHere` = the maximum subarray sum **ending exactly** at current index `i`.
  2. `maxSoFar` = the maximum subarray sum found anywhere up to index `i`.

  Recurrence:

  ```
  maxEndingHere = max(nums[i], maxEndingHere + nums[i])
  maxSoFar      = max(maxSoFar, maxEndingHere)
  ```

  * If `maxEndingHere + nums[i] < nums[i]`, it’s “better to start fresh” at `i`.
  * Otherwise, “extend” the previous best ending at `i−1`.
* **Why It Works**:

  * At each step you choose between “starting a new subarray at i” or “extending the subarray that ended at i−1.”
  * You only need the previous `maxEndingHere` to make this choice.
* **Time**: O(n).
* **Space**: O(1).

---

### 4.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Kadane’s Algorithm – Maximum Subarray Sum
  We maintain two variables:
    maxEndingHere: best sum ending at the current position i
    maxSoFar:     best sum seen anywhere so far.
  
  Time: O(n), Space: O(1).
*/

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    // Initialize with the first element, handles all-negative array
    int maxEndingHere = nums[0];
    int maxSoFar      = nums[0];

    for (int i = 1; i < n; i++) {
        // Extend the previous segment or start fresh at nums[i]
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        // Update global maximum
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // The max subarray is [4, -1, 2, 1] with sum = 6
    cout << maxSubArray(arr) << "\n"; // Should print 6
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Initialize both `maxEndingHere` and `maxSoFar` to `nums[0]` (handles all‐negative cases).
  2. For each `i` from 1 to `n−1`:

     * `maxEndingHere = max(nums[i], maxEndingHere + nums[i])`.

       * If adding `nums[i]` to the previous subarray is worse than starting fresh, reset.
     * `maxSoFar = max(maxSoFar, maxEndingHere)`.

       * Keep track of the best subarray seen so far.

---

## 5. Print Subarray with Maximum Subarray Sum (Extended Kadane)

### 5.1 Problem Statement

> In addition to returning the maximum subarray sum, also **print the actual subarray** (the indices or values) that achieves that maximum.

---

### 5.2 Approach

* We still use Kadane’s, but we track **start** and **end** indices of the best subarray:

  1. Maintain `maxEndingHere`, `maxSoFar` as before.
  2. Maintain `s = 0` as a potential “start index” for the current `maxEndingHere` segment.
  3. Maintain `beginIndex` and `endIndex` to record the final best subarray when `maxSoFar` updates.

* **Algorithm**:

  ```
  maxEndingHere = nums[0]
  maxSoFar      = nums[0]
  beginIndex = endIndex = 0
  s = 0  // tentative start

  for i = 1 to n-1:
    if nums[i] > maxEndingHere + nums[i]:
      maxEndingHere = nums[i]
      s = i              // start fresh at i
    else:
      maxEndingHere += nums[i]

    if maxEndingHere > maxSoFar:
      maxSoFar    = maxEndingHere
      beginIndex  = s
      endIndex    = i

  // Now the subarray [beginIndex..endIndex] is the maximum sum subarray.
  ```

* **Time**: O(n)

* **Space**: O(1)

---

### 5.3 C++ Code (Extended Kadane)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Extended Kadane’s Algorithm – Print maximum-sum subarray
  We track two extra variables:
    s = tentative starting index of the current subarray
    beginIndex, endIndex = final best subarray boundaries
*/

pair<int, pair<int,int>> maxSubArrayWithIndices(vector<int>& nums) {
    int n = nums.size();
    // Initialize
    int maxEndingHere = nums[0];
    int maxSoFar      = nums[0];
    int beginIndex    = 0;
    int endIndex      = 0;
    int s = 0; // potential start of a new segment

    for (int i = 1; i < n; i++) {
        if (nums[i] > maxEndingHere + nums[i]) {
            // Better to start fresh here
            maxEndingHere = nums[i];
            s = i;
        } else {
            // Extend the previous segment
            maxEndingHere += nums[i];
        }

        if (maxEndingHere > maxSoFar) {
            // Found a better sum
            maxSoFar = maxEndingHere;
            beginIndex = s;
            endIndex = i;
        }
    }
    // Return: {maximum sum, {startIndex, endIndex}}
    return { maxSoFar, { beginIndex, endIndex } };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = maxSubArrayWithIndices(arr);
    int bestSum = result.first;
    int L = result.second.first;
    int R = result.second.second;

    cout << "Max Sum = " << bestSum << "\n";
    cout << "Subarray: ";
    for (int i = L; i <= R; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    // Output should be:
    // Max Sum = 6
    // Subarray: 4 -1 2 1

    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Keep `s` as a “candidate” start index for the current `maxEndingHere`.
  2. Whenever you choose `nums[i]` over `maxEndingHere + nums[i]`, you set `s = i`.
  3. When `maxEndingHere` surpasses `maxSoFar`, update `(beginIndex, endIndex) = (s, i)`.

---

## 6. Stock Buy and Sell (Single Transaction)

### 6.1 Problem Statement

> Given an array `prices[]` where `prices[i]` is the price of a given stock on day `i`,
> find the maximum profit you can get by choosing exactly one day to buy and one day to sell (sell must be after buy).
> If no profit is possible, return 0.

---

### 6.2 Brute‐Force Approach

* **Idea**: Try every pair `(i, j)` with `j > i`, compute `profit = prices[j] − prices[i]`, and keep track of the maximum.
* **Time**: O(n²).
* **Space**: O(1).

---

### 6.3 Optimal Approach (Track Min Price)

* **Idea**:

  1. As you scan from left to right, keep `minPriceSoFar` = smallest price you’ve seen up to index `i`.
  2. At day `i`, the best profit if you sold on day `i` would be `prices[i] − minPriceSoFar`.
  3. Keep a running maximum of `profitSoFar`.
* **Algorithm**:

  ```
  minPriceSoFar = +∞
  maxProfit = 0

  for i in [0..n−1]:
    minPriceSoFar = min(minPriceSoFar, prices[i])
    profit = prices[i] - minPriceSoFar
    maxProfit = max(maxProfit, profit)

  return maxProfit
  ```
* **Why It Works**:

  * You always “pretend” you bought at the lowest possible price you’ve encountered so far and compute profit if you sold today.
  * Keeps track of the global maximum profit.
* **Time**: O(n).
* **Space**: O(1).

---

### 6.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Stock Buy & Sell (Single Transaction)
  As we iterate, we keep:
    minPriceSoFar = lowest buy price seen so far
    maxProfit = best profit we could have gotten (selling at current day minus minPriceSoFar)

  Time: O(n), Space: O(1).
*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    int minPriceSoFar = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        // Update min price if we find a cheaper day to buy
        minPriceSoFar = min(minPriceSoFar, prices[i]);
        // Potential profit if sold today
        int profitToday = prices[i] - minPriceSoFar;
        // Update global maximum profit
        maxProfit = max(maxProfit, profitToday);
    }
    return maxProfit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Best is buy at 1, sell at 6 → profit = 5
    cout << maxProfit(prices) << "\n"; // Should print 5
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Start `minPriceSoFar = prices[0]`, `maxProfit = 0`.
  2. For each day `i`:

     * Update `minPriceSoFar` if `prices[i]` is lower.
     * Compute `profitToday = prices[i] − minPriceSoFar`.
     * Update `maxProfit = max(maxProfit, profitToday)`.

---

## 7. Rearrange Array in Alternating Positive and Negative Items

### 7.1 Problem Statement

> Given an array of integers, `nums[]`, rearrange the array **in-place** so that positive and negative numbers alternate.
> If there are more positive numbers than negative (or vice versa), the extra elements appear at the end.
> **Relative order does not** need to be preserved.

---

### 7.2 Brute‐Force Approach

* **Separate + Merge**:

  1. Create two auxiliary vectors: `pos[]` for positives, `neg[]` for negatives.
  2. Traverse the original array: push positive numbers into `pos[]`, push negative into `neg[]`.
  3. Merge them back into `nums[]` in alternating fashion:

     * `i = 0; idxPos = 0; idxNeg = 0;`
     * While `idxPos < pos.size()` and `idxNeg < neg.size()`:

       * `nums[i++] = pos[idxPos++];`
       * `nums[i++] = neg[idxNeg++];`
     * Then copy any leftover from `pos` or `neg`.
* **Time**: O(n)
* **Space**: O(n) (two auxiliary arrays).

---

### 7.3 Optimal Approach (In‐Place Partition + Swap)

* **High‐level Idea**:

  1. **Partition** the array so that all negative numbers appear on the left, positives on the right (similar to partition step in quicksort).

     * After this step, the array looks like `[negatives …][positives …]`, but unordered within each group.
  2. Then, we want to “interleave” these two halves. Suppose there are `k` negatives and `n−k` positives.

     * If `k ≤ n−k`, we’ll place negatives at even indices `0, 2, 4, …, 2(k−1)`, and positives fill the rest.
     * If `k > n−k`, we do the opposite (positives at even, negatives at odd—“extra” group goes to the end).
  3. Do the interleaving by swapping pairs `(negIndex, posIndex)`.

* **Steps**:

  1. **Partition**:

     * `i = 0, j = n−1`.
     * While `i ≤ j`:

       * If `nums[i] < 0`, `i++`.
       * Else if `nums[j] >= 0`, `j--`.
       * Else swap `nums[i], nums[j]`.
     * After this, `i` = first index of positive region, and `[0..i−1]` are all negative, `[i..n−1]` all non‐negative (≥0).
     * Let `negCount = i`, `posCount = n − i`.
  2. **Interleave**:

     * Let `negIndex = 0` and `posIndex = (negCount < posCount ? negCount : 1)`.

       * Explanation:

         * If there are fewer negatives (`negCount ≤ posCount`), start interleaving by placing the first positive at index `1`.
         * If there are more negatives, place the first positive at index `negCount` (so that the extra negatives occupy even indices starting from 0).
     * While `negIndex < negCount` and `posIndex < n`:

       * `swap(nums[negIndex], nums[posIndex])`
       * `negIndex += 2`
       * `posIndex += 2`

* **Why It Works**:

  * After partitioning, left side = all negatives, right side = all positives. We just weave them by jumping two steps at a time, guaranteeing alternation.

* **Time**: O(n) (one partition + O(n) for swapping).

* **Space**: O(1).

---

### 7.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Rearrange Array (alternating positive and negative) in-place.
  1) Partition all negatives to left, positives to right (like quicksort partition).
  2) Then interleave by swapping pairs from the two partitions.

  Time: O(n), Space: O(1).
*/

void rearrangeAlternate(vector<int>& nums) {
    int n = nums.size();

    // ---------- Step 1: Partition ---------
    int i = 0, j = n - 1;
    while (i <= j) {
        if (nums[i] < 0) {
            i++;
        } else if (nums[j] >= 0) {
            j--;
        } else {
            // nums[i] >= 0 and nums[j] < 0, swap them
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    // After partition, indices [0..i-1] are all negative, [i..n-1] are all positive/non-negative
    int negCount = i;
    int posCount = n - i;

    // ---------- Step 2: Interleave ---------
    // Set negIndex to 0 (first negative)
    int negIndex = 0;
    // If fewer negatives, start pos at index 1; else start pos right after last neg
    int posIndex = (negCount <= posCount ? 1 : negCount);

    while (negIndex < n && posIndex < n) {
        swap(nums[negIndex], nums[posIndex]);
        negIndex += 2;
        posIndex += 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {3, -2, 5, -1, 6, -3, -7, 2};
    rearrangeAlternate(arr);
    // Possible result: [-2, 3, -1, 5, -3, 6, -7, 2]
    // (Any valid alternation is acceptable.)
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. **Partition**: Use two‐pointer approach (`i` from left, `j` from right) to push negatives left and positives right.
  2. **negCount = i** is the total number of negatives.
  3. **Interleave**: If `negCount ≤ posCount`, place the first positive at index 1, then swap every second position. If `negCount > posCount`, the extra negatives occupy even positions starting from 0, so you start placing positives right after the last negative.

---

## 8. Next Permutation

### 8.1 Problem Statement

> Given a permutation of numbers in an array `nums[]`, rearrange them into the **lexicographically next greater** permutation of numbers.
> If such arrangement is not possible (i.e., the array is in descending order), rearrange it into the **lowest possible order** (i.e., sorted in ascending order).
> You must perform this transformation **in-place** and use only constant extra memory.

---

### 8.2 Brute‐Force Approach

* **Generate All Permutations**:

  1. Generate all permutations of `nums[]` (O(n!) time).
  2. Sort them lexicographically.
  3. Find the position of the current `nums[]` and return the next one (or the first if current is last).
* **Time**: O(n! · n) – absolutely impractical for n > 8.

---

### 8.3 Optimal Approach

* **Key Insight**: Any permutation can be divided into a prefix that is non‐increasing (from the right) and a suffix that is “reversed” when you want to form the next greater arrangement.
* **Steps**:

  1. **Find the longest non‐increasing suffix**:

     * Let `i = n − 2`.
     * While `i ≥ 0 && nums[i] ≥ nums[i + 1]`, do `i--`.
     * After this loop, `i` is the pivot index. If `i < 0`, the entire array is non-increasing, so reverse( `nums` ) and return (that yields the lowest permutation).
  2. **Find the rightmost successor to the pivot**:

     * Now the suffix `nums[i+1 ... n−1]` is in non‐increasing order. To get the next permutation, you need to swap `nums[i]` with the smallest element in that suffix that is **>** `nums[i]`.
     * Initialize `j = n − 1`. While `nums[j] ≤ nums[i]`, do `j--`. Now `nums[j]` is the rightmost element in the suffix that is bigger than the pivot `nums[i]`.
  3. **Swap pivot and successor**:

     * `swap(nums[i], nums[j])`.
  4. **Reverse the suffix**:

     * Finally, reverse `nums[i+1 ... n−1]` so that suffix becomes the **lowest possible order** (since it was non‐increasing before, reversing makes it non‐decreasing).
* **Why It Works**:

  * The pivot is the first place (from the right) where you can “increase” the permutation.
  * Swapping with the next bigger element gives the smallest increase.
  * Reversing the suffix then ensures you are at the very next lexicographic arrangement.
* **Time**: O(n) (two scans + one reverse).
* **Space**: O(1).

---

### 8.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Next Permutation – In-place, O(n) time

  1) Find pivot i where nums[i] < nums[i+1], scanning from right.
  2) If no such pivot (i < 0), array is non-increasing; reverse entire array.
  3) Otherwise, find j from the end where nums[j] > nums[i], swap them.
  4) Reverse the suffix nums[i+1 .. n-1].
*/

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    // 1) Find pivot i
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    // If i < 0, entire array is non-increasing (last permutation)
    if (i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // 2) Find rightmost successor to pivot
    int j = n - 1;
    while (nums[j] <= nums[i]) {
        j--;
    }
    // 3) Swap pivot and successor
    swap(nums[i], nums[j]);

    // 4) Reverse the suffix to get the next smallest lex ordering
    reverse(nums.begin() + (i + 1), nums.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3};
    nextPermutation(arr);
    // Should become [1, 3, 2]
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";

    vector<int> arr2 = {3, 2, 1};
    nextPermutation(arr2);
    // Was last perm, so now [1, 2, 3]
    for (int x : arr2) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Scan from `i = n−2` down to `0` until you find `nums[i] < nums[i+1]`. That `i` is your pivot.
  2. If you never found such an `i`, it means the entire sequence is non‐increasing → just reverse the entire array to obtain the smallest permutation.
  3. Otherwise, scan from the end `j = n−1` down until `nums[j] > nums[i]`. Swap them.
  4. Finally, reverse from `i+1` to `n−1` (the suffix), because that suffix was in non‐increasing order; reversing makes it the smallest possible arrangement after your swap.

---

## 9. Leaders in an Array

### 9.1 Problem Statement

> An element `A[i]` is called a **leader** if it is strictly greater than all the elements to its right.
> Return all leaders in the array in the order they appear (or in any order, but usually from left to right).

---

### 9.2 Brute‐Force Approach

* **Idea**: For each `i`, scan all elements `j > i` to see if any `A[j] ≥ A[i]`.

  * If none are ≥ `A[i]`, then `A[i]` is a leader.
* **Time**: O(n²).
* **Space**: O(1) (aside from storing the output).

---

### 9.3 Optimal Approach (Right‐to‐Left Scan)

* **Idea**:

  1. Initialize `maxSoFar = −∞`.
  2. Traverse the array from right to left.

     * If `A[i] > maxSoFar`, then `A[i]` is a leader; update `maxSoFar = A[i]`.
     * Otherwise, skip.
  3. Collect all leaders in a vector (they will be in reverse order because you scanned right to left). Reverse at the end if you need them left‐to‐right.
* **Why It Works**:

  * When scanning from the right, you always know the largest value you’ve seen so far to the right of the current index.
  * If the current value `A[i]` exceeds that, it must be greater than **every** element to its right.
* **Time**: O(n).
* **Space**: O(k) for `k` leaders (plus O(n) if you reverse at the end, but that’s still O(n)).

---

### 9.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Leaders in an Array:
  Traverse from right to left, keep maxSoFar. Whenever A[i] > maxSoFar,
  mark A[i] as a leader and update maxSoFar.
*/

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxSoFar = INT_MIN;

    // Scan from rightmost element down to 0
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > maxSoFar) {
            leaders.push_back(arr[i]);
            maxSoFar = arr[i];
        }
    }
    // leaders[] is in reverse order (right to left). Reverse to get left-to-right.
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {16, 17, 4, 3, 5, 2};
    // Leaders: 17, 5, 2
    vector<int> ans = findLeaders(arr);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Set `maxSoFar = INT_MIN`.
  2. For `i` from `n−1` down to `0`:

     * If `arr[i] > maxSoFar`, that means it’s bigger than everything to its right, so add it to `leaders` and update `maxSoFar`.
  3. At the end, reverse `leaders[]` to present them from left to right.

---

## 10. Longest Consecutive Sequence in an Array

### 10.1 Problem Statement

> Given an unsorted array of integers, find the length of the **longest** sequence of consecutive elements.
> Example: `[100, 4, 200, 1, 3, 2]` → The longest consecutive sequence is `[1, 2, 3, 4]`, so return **4**.
> Your algorithm should run in O(n) time.

---

### 10.2 Brute‐Force Approach

* **Sort + Scan**:

  1. Sort the array (O(n log n)).
  2. Scan through, counting lengths of consecutive runs, keeping track of the maximum. Skip duplicates.
* **Time**: O(n log n).
* **Space**: O(1) or O(n) depending on sorting implementation.

---

### 10.3 Optimal Approach (Hash Set)

* **Idea**:

  1. Insert every element into an `unordered_set<int> st`.
  2. For each element `x` in the set, check if `x−1` is **not** in the set. If `x−1` is missing, then `x` is the **start** of a consecutive sequence.
  3. From that start `x`, count upward `x, x+1, x+2, …` while each successive integer is in the set. Keep track of the length. Update global maximum length.
  4. Because you only “expand” from each sequence start once, the total time is O(n).
* **Why It Works**:

  * By only starting to count when `x−1` is absent, you guarantee you only trace each consecutive block once.
* **Time**: O(n) average (hash‐set operations).
* **Space**: O(n).

---

### 10.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Longest Consecutive Sequence:
  1) Build an unordered_set of all elements.
  2) For each x in the set, if x-1 not in set, that means x is a potential sequence start.
     Then count length by checking x, x+1, x+2, ...
  3) Track max length.

  Time: O(n) average, Space: O(n).
*/

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int best = 0;

    for (int x : st) {
        // Only start counting if (x-1) isn't in the set (i.e. x is the start of a sequence)
        if (st.find(x - 1) == st.end()) {
            int currentNum = x;
            int length = 1;

            // Extend upward: x, x+1, x+2, … while present in set
            while (st.find(currentNum + 1) != st.end()) {
                currentNum++;
                length++;
            }
            best = max(best, length);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {100, 4, 200, 1, 3, 2};
    // Longest consecutive is [1,2,3,4] → length = 4
    cout << longestConsecutive(arr) << "\n"; // Should print 4
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Build `unordered_set<int> st` from all elements of `nums`.
  2. For each `x` in `st`, check if `x−1` is **not** in `st`. If so, `x` is the start of a consecutive run.
  3. Then incrementally check `x+1, x+2, …` until you break. Track the length.
  4. Keep the maximum across all such runs.

---

## 11. Set Matrix Zeros

### 11.1 Problem Statement

> Given an `m × n` matrix. If an element is `0`, set its entire **row** and **column** to `0`. Do this **in-place** using O(1) extra space.

---

### 11.2 Brute‐Force Approach

* **Using Extra Space**:

  1. Create two boolean arrays: `rowFlag[m] = {false}`, `colFlag[n] = {false}`.
  2. First pass: whenever you see `matrix[i][j] == 0`, set `rowFlag[i] = true`, `colFlag[j] = true`.
  3. Second pass: for every cell `(i, j)`, if `rowFlag[i] == true` OR `colFlag[j] == true`, set `matrix[i][j] = 0`.
* **Time**: O(mn).
* **Space**: O(m + n).

---

### 11.3 Optimal Approach (Use First Row & First Column as Markers)

* **Idea**:

  * Instead of two separate arrays for rows/columns, use the **first row** to mark which columns must be zeroed, and use the **first column** to mark which rows must be zeroed.
  * But since the first row and column themselves may need to be zeroed, keep two boolean variables `row0Zero` and `col0Zero` to remember if the first row or first column originally contained any zeros.
* **Steps**:

  1. **Scan first row and column**:

     * If any element in row 0 is 0, set `row0Zero = true`.
     * If any element in column 0 is 0, set `col0Zero = true`.
  2. **Use first row & column as markers** for the rest of the matrix:

     ```
     for i from 1 to m−1:
       for j from 1 to n−1:
         if matrix[i][j] == 0:
           matrix[i][0] = 0;   // Mark row i
           matrix[0][j] = 0;   // Mark column j
     ```
  3. **Zero‐out based on markers** (excluding first row/col for now):

     ```
     for i from 1 to m−1:
       for j from 1 to n−1:
         if matrix[i][0] == 0 OR matrix[0][j] == 0:
           matrix[i][j] = 0;
     ```
  4. **Zero entire first row, if needed**:

     ```
     if row0Zero:
       for j from 0 to n−1: matrix[0][j] = 0;
     ```
  5. **Zero entire first column, if needed**:

     ```
     if col0Zero:
       for i from 0 to m−1: matrix[i][0] = 0;
     ```
* **Why It Works**:

  * Using the first row and column as “flag storages” avoids O(m+n) extra space.
  * We do everything in-place in four passes, each O(mn).
* **Time**: O(mn).
* **Space**: O(1) (only two extra booleans).

---

### 11.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Set Matrix Zeros in-place with O(1) extra space.
  1) Check if first row has any zero → row0Zero
  2) Check if first column has any zero → col0Zero
  3) Use first row/col to mark other rows/cols
  4) Zero cells based on markers, skipping first row/col
  5) Zero-first-row if row0Zero, zero-first-col if col0Zero
*/

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();

    bool row0Zero = false, col0Zero = false;

    // 1) Check first row
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            row0Zero = true;
            break;
        }
    }

    // 2) Check first column
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            col0Zero = true;
            break;
        }
    }

    // 3) Use first row & column as markers for other rows/cols
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // Mark row i
                matrix[0][j] = 0;  // Mark column j
            }
        }
    }

    // 4) Zero out cells based on markers (excluding first row/col)
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // 5) Finally, zero out first row / first column if needed
    if (row0Zero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0Zero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    setZeroes(mat);
    // Should become:
    // [1, 0, 1]
    // [0, 0, 0]
    // [1, 0, 1]
    for (auto &row : mat) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Scan the **first row**: if any zero, `row0Zero = true`.
  2. Scan the **first column**: if any zero, `col0Zero = true`.
  3. For all `i = 1..m−1`, `j = 1..n−1`: if `matrix[i][j] == 0`, mark `matrix[i][0] = 0` and `matrix[0][j] = 0`.
  4. Again for `i = 1..m−1`, `j = 1..n−1`: if `matrix[i][0] == 0` or `matrix[0][j] == 0`, set `matrix[i][j] = 0`.
  5. If `row0Zero` was true, zero out the entire first row. If `col0Zero` was true, zero out the entire first column.

---

## 12. Rotate Matrix by 90 Degrees (Clockwise)

### 12.1 Problem Statement

> Given an `n × n` 2D matrix, rotate it **90 degrees clockwise** **in-place**.
> For example,
>
> ```
> 1 2 3        7 4 1
> 4 5 6   →    8 5 2
> 7 8 9        9 6 3
> ```

---

### 12.2 Brute‐Force Approach

* **Using Extra Matrix**:

  1. Create a new `n × n` matrix `rot` initialized empty.
  2. For each `(i, j)`, set `rot[j][n − 1 − i] = matrix[i][j]`.
  3. Copy `rot` back into `matrix`.
* **Time**: O(n²).
* **Space**: O(n²).

---

### 12.3 Optimal Approach (Transpose + Reverse Rows)

* **Key Insight**:

  1. **Transpose** the matrix (`matrix[i][j] ↔ matrix[j][i]`).
  2. **Reverse each row**.
* **Why It Works**:

  * A 90° clockwise rotation is equivalent to “first flip over the main diagonal” (transpose), then “flip horizontally” (reverse each row).
* **Steps**:

  1. For `i = 0..n−1`:

     * For `j = i+1..n−1`: swap `matrix[i][j]` and `matrix[j][i]`.
     * (This transposes the matrix in-place.)
  2. For each row `i = 0..n−1`: `reverse(matrix[i].begin(), matrix[i].end())`.
* **Time**: O(n²) (two nested loops for transpose + O(n²) to reverse rows).
* **Space**: O(1).

---

### 12.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Rotate Matrix by 90 degrees (clockwise) in-place:
  1) Transpose in-place (swap across main diagonal)
  2) Reverse each row

  Time: O(n^2), Space: O(1)
*/

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 1) Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // 2) Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(mat);
    // Expected output:
    // 7 4 1
    // 8 5 2
    // 9 6 3
    for (auto &row : mat) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. **Transpose**: For each `i < j`, swap `matrix[i][j]` with `matrix[j][i]`.
  2. **Reverse each row**: Simply call `reverse(...)` on each `matrix[i]`.
  3. The combined effect is a 90° clockwise rotation.

---

## 13. Print the Matrix in Spiral Manner

### 13.1 Problem Statement

> Given an `m × n` matrix, return the elements of the matrix in **spiral order** (clockwise).
> Example:
>
> ```
> [ [ 1,  2,  3,  4 ],
>   [ 5,  6,  7,  8 ],
>   [ 9, 10, 11, 12 ] ]
> ```
>
> Spiral order: `[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]`.

---

### 13.2 Approach (Layer‐by‐Layer Simulation)

* **Idea**: Define four boundaries:

  ```
  top = 0, bottom = m − 1,
  left = 0, right = n − 1.
  ```

  Then iterate in a loop, repeatedly doing:

  1. Traverse **left → right** along the `top` row. Then `top++`.
  2. Traverse **top → bottom** along the `right` column. Then `right--`.
  3. If `top ≤ bottom`, traverse **right → left** along the `bottom` row. Then `bottom--`.
  4. If `left ≤ right`, traverse **bottom → top** along the `left` column. Then `left++`.
     Repeat until `top > bottom` or `left > right`.
* **Why It Works**: At each stage you “peel off” one layer of the matrix in a spiral direction.
* **Time**: O(mn) – each cell visited exactly once.
* **Space**: O(mn) for the output list, O(1) extra otherwise.

---

### 13.3 C++ Code (Spiral Print)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Print Matrix in Spiral Order.
  Maintain four boundaries: top, bottom, left, right, and iterate layer by layer.
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    vector<int> result;
    result.reserve(m * n);

    while (true) {
        // 1) Traverse left → right along top row
        for (int j = left; j <= right; j++) {
            result.push_back(matrix[top][j]);
        }
        top++;
        if (top > bottom) break;

        // 2) Traverse top → bottom along right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (left > right) break;

        // 3) Traverse right → left along bottom row
        for (int j = right; j >= left; j--) {
            result.push_back(matrix[bottom][j]);
        }
        bottom--;
        if (top > bottom) break;

        // 4) Traverse bottom → top along left column
        for (int i = bottom; i >= top; i--) {
            result.push_back(matrix[i][left]);
        }
        left++;
        if (left > right) break;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> mat = {
        { 1,  2,  3,  4 },
        { 5,  6,  7,  8 },
        { 9, 10, 11, 12 }
    };
    vector<int> ans = spiralOrder(mat);
    // Expected: 1 2 3 4 8 12 11 10 9 5 6 7
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. Initialize `top = 0, bottom = m−1, left = 0, right = n−1`.
  2. While the boundaries are still valid, do four sub‐steps:

     * **Left→Right** on row `top`, then `top++`.
     * **Top→Bottom** on column `right`, then `right--`.
     * **Right→Left** on row `bottom`, then `bottom--` (only if `top ≤ bottom`).
     * **Bottom→Top** on column `left`, then `left++` (only if `left ≤ right`).
  3. Each break condition checks if we have crossed boundaries.

---

## 14. Count Subarrays with Given Sum

### 14.1 Problem Statement

> Given an array of integers `nums[]` and an integer `k`, return the total **count** of **continuous subarrays** whose sum equals `k`.
> Example: `nums = [1, 1, 1], k = 2` → subarrays `[1,1]` at positions `(0..1)` and `(1..2)`, so return 2.

---

### 14.2 Brute‐Force Approach

* **Check Every Subarray**:

  ```
  count = 0
  for i in [0..n−1]:
    sum = 0
    for j in [i..n−1]:
      sum += nums[j]
      if sum == k:
        count++
  ```
* **Time**: O(n²).
* **Space**: O(1).

---

### 14.3 Optimal Approach (Prefix‐Sum + Hash Map)

* **Key Observation**: If `prefixSum[j] − prefixSum[i−1] = k`, it means the subarray `nums[i..j]` sums to `k`.

  * So for each `j`, if you know how many `i−1` exist with `prefixSum[i−1] = prefixSum[j] − k`, that many subarrays ending at `j` sum to `k`.
* **Algorithm**:

  1. Let `count = 0`, `cursum = 0`.
  2. Maintain a hash map `mp` of “frequency of prefix sums seen so far,” i.e. `mp[x]` = how many times a prefix sum = `x` has occurred.

     * Initialize `mp[0] = 1` to handle any subarray starting from index 0 that sums to `k`.
  3. Loop `j` from `0` to `n−1`:

     * Update `cursum += nums[j]`.
     * Check if `cursum − k` exists in `mp`. If yes, add `mp[cursum − k]` to `count`.

       * (Because each time we saw a prefix sum = `cursum−k` at some earlier index `i−1`, the subarray `(i..j)` sums to `k`.)
     * Then increment `mp[cursum]++` to record that we have another prefix sum = `cursum`.
* **Why It Works**:

  * We’re effectively counting, for every endpoint `j`, how many starting points produce the required sum.
  * In one pass, we keep track of all prefix sums so far and their frequencies.
* **Time**: O(n) average (hash map operations).
* **Space**: O(n) in the worst case (all prefix sums are distinct).

---

### 14.4 C++ Code (Optimal)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Count Subarrays with Sum = k (Prefix‐Sum + Hash Map)
  1) Use `cursum` as the prefix sum up to current index j
  2) mp[x] = # of times a prefix sum of `x` has been seen
  3) At each j, if (cursum − k) exists in mp, add its frequency to count
  4) Then increment mp[cursum]

  Time: O(n) average, Space: O(n).
*/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0] = 1;  // One way to have prefix sum = 0 (empty prefix)

    int count = 0;
    int cursum = 0;

    for (int x : nums) {
        cursum += x;
        // If (cursum - k) was seen before, 
        // any occurrence of that is a valid subarray ending here
        if (mp.find(cursum - k) != mp.end()) {
            count += mp[cursum - k];
        }
        // Record the current prefix sum
        mp[cursum]++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1, 1, 1};
    int k = 2;
    // There are two subarrays that sum to 2: [0..1] and [1..2].
    cout << subarraySum(nums, k) << "\n"; // Should print 2

    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    // Subarrays: [0..1] with sum=3, [2..2] with sum=3 → count=2
    cout << subarraySum(nums2, k2) << "\n"; // Should print 2

    return 0;
}
```

* **Line‐by‐Line Explanation**:

  1. **`mp[0] = 1;`**

     * Because an empty prefix has sum 0, which counts if a subarray from index 0 to `j` has sum `k`.
  2. For each element `x`:

     * Update `cursum += x`.
     * If `mp` already has `cursum − k`, it means “some earlier prefix had sum = `cursum−k`,” so the subarray from that prefix’s end+1 to current `j` sums to `k`. Increase `count` by that frequency.
     * Then do `mp[cursum]++` to record that this prefix‐sum has been seen one more time.

---

## Summary of Complexities

| Problem                             | Brute           | Better           | Optimal     | Time (Optimal) | Space (Optimal) |
| ----------------------------------- | --------------- | ---------------- | ----------- | -------------- | --------------- |
| 1. Two Sum                          | O(n²), O(1)     | O(n log n), O(n) | O(n), O(n)  | O(n)           | O(n)            |
| 2. Sort 0/1/2 (Dutch Flag)          | O(n), O(1)      | —                | O(n), O(1)  | O(n)           | O(1)            |
| 3. Majority Element (> n/2)         | O(n²), O(1)     | O(n), O(n)       | O(n), O(1)  | O(n)           | O(1)            |
| 4. Kadane’s (Max Subarray Sum)      | O(n²), O(1)     | —                | O(n), O(1)  | O(n)           | O(1)            |
| 5. Kadane + Print Subarray          | O(n²), O(1)     | —                | O(n), O(1)  | O(n)           | O(1)            |
| 6. Stock Buy & Sell (1 Transaction) | O(n²), O(1)     | —                | O(n), O(1)  | O(n)           | O(1)            |
| 7. Alternating +/− Rearrangement    | O(n), O(n)      | —                | O(n), O(1)  | O(n)           | O(1)            |
| 8. Next Permutation                 | O(n!), O(n)     | —                | O(n), O(1)  | O(n)           | O(1)            |
| 9. Leaders in Array                 | O(n²), O(1)     | —                | O(n), O(1)  | O(n)           | O(1)            |
| 10. Longest Consecutive Sequence    | O(n log n),O(1) | —                | O(n), O(n)  | O(n)           | O(n)            |
| 11. Set Matrix Zeros                | O(mn), O(m+n)   | —                | O(mn), O(1) | O(mn)          | O(1)            |
| 12. Rotate Matrix 90°               | O(n²),O(n²)     | —                | O(n²), O(1) | O(n²)          | O(1)            |
| 13. Spiral Order                    | O(mn),O(1)      | —                | O(mn), O(1) | O(mn)          | O(1)            |
| 14. Count Subarrays with Sum = k    | O(n²), O(1)     | —                | O(n), O(n)  | O(n)           | O(n)            |

---

These step-by-step explanations, **intuitions**, and **C++ code** samples should equip you to understand—and implement—each problem optimally. Feel free to ask any follow-up questions!
