Below is a **detailed yet precise** explanation of `std::next_permutation` in C++, with clear logic, edge-case behavior, and worked examples. The explanation is structured the way it is typically expected in **interviews, competitive programming, and algorithm design**.

---

## 1. What is `next_permutation`?

`std::next_permutation` is a **STL algorithm** that rearranges a sequence into the **next lexicographically greater permutation**.

**Header**

```cpp
#include <algorithm>
```

**Syntax**

```cpp
bool next_permutation(BidirectionalIterator first,
                      BidirectionalIterator last);
```

---

## 2. Lexicographical Order (Very Important)

Lexicographical order is the same as **dictionary order**.

For example, permutations of `{1,2,3}` in lexicographical order:

```
123
132
213
231
312
321
```

Calling `next_permutation` moves you **one step forward** in this order.

---

## 3. What Does the Function Return?

| Situation                           | Return Value | Effect                                                        |
| ----------------------------------- | ------------ | ------------------------------------------------------------- |
| Next permutation exists             | `true`       | Sequence is modified                                          |
| Current permutation is the last one | `false`      | Sequence becomes the **first (sorted ascending)** permutation |

---

## 4. Core Algorithm (How It Works Internally)

This is **critical for understanding and interviews**.

### Step-by-step logic:

Given a sequence `a[0...n-1]`:

### **Step 1: Find the pivot**

Scan from **right to left** and find the **first index `i` such that**:

```
a[i] < a[i + 1]
```

This identifies where the next permutation can be made.

If no such index exists → sequence is in **descending order** → last permutation.

---

### **Step 2: Find the successor**

Again scan from the **right**, find the **smallest element greater than `a[i]`**.

---

### **Step 3: Swap**

Swap `a[i]` and its successor.

---

### **Step 4: Reverse the suffix**

Reverse the subarray:

```
a[i + 1 ... end]
```

This ensures the **smallest possible lexicographical increase**.

---

## 5. Dry Run Example (Most Important Section)

### Example 1: `[1, 2, 3]`

```
Current: 1 2 3
```

**Step 1 (pivot):**

```
2 < 3 → pivot = index 1
```

**Step 2 (successor):**

```
3 > 2
```

**Step 3 (swap):**

```
1 3 2
```

**Step 4 (reverse suffix):**

```
Suffix after index 1 → only 2 → unchanged
```

✅ **Next permutation:** `1 3 2`

---

### Example 2: `[1, 3, 2]`

**Step 1:**

```
3 < 2 → false
1 < 3 → pivot = index 0
```

**Step 2:**

```
Smallest > 1 is 2
```

**Step 3:**

```
2 3 1
```

**Step 4:**

```
Reverse suffix → 1 3
```

✅ **Next permutation:** `2 1 3`

---

### Example 3 (Edge Case): `[3, 2, 1]`

No `a[i] < a[i+1]` exists.

* Already the **last permutation**
* Function returns `false`
* Array becomes sorted ascending

Result:

```
1 2 3
```

---

## 6. Complete Example Program

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    do {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
```

### Output

```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

---

## 7. Time and Space Complexity

| Metric | Value               |
| ------ | ------------------- |
| Time   | **O(n)**            |
| Space  | **O(1)** (in-place) |

---

## 8. Important Observations

1. Works with **duplicates**

   ```
   {1,1,2} → 112 → 121 → 211
   ```

2. Sequence must initially be **sorted** to generate all permutations.

3. Requires **bidirectional iterators**

   * Works with `vector`, `deque`, `string`
   * Does NOT work with `forward_list`

---

## 9. Interview-Relevant Points

* Used in **permutation generation**
* Frequently appears in **LeetCode**, **Codeforces**, **GFG**
* Internal logic is a **greedy + suffix optimization**
* Understanding pivot and suffix is key

---

## 10. When Should You Use It?

* Brute-force permutation problems (small `n`)
* Testing all orderings
* Problems with lexicographical constraints

---

If you want, I can also:

* Implement `next_permutation` **from scratch**
* Explain it with **string examples**
* Show **common mistakes**
* Solve a **LeetCode problem using it**

Just tell me what you want next.
