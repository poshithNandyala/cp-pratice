Here's a concise breakdown of the **Two Sum** problem variants, solutions, and approaches discussed in your reference from TakeUForward:

---

### ✅ **Problem Variants**

1. **Variant 1**: Return `"YES"` if **any** two distinct elements sum to target, else `"NO"`.
2. **Variant 2**: Return **indices** `[i, j]` of such two numbers, else `[-1, -1]`.

---

### 🧪 **Example**

```text
Input: arr = [2,6,5,8,11], target = 14

Output:
Variant 1 → YES (Because 6+8 = 14)
Variant 2 → [1, 3]
```

---

### 🚀 **Approaches Overview**

#### 1. **Brute Force (Naive)**

* **Time**: O(N²)
* **Space**: O(1)
* **Logic**: Try all pairs `(i, j)` with `i < j`, check `arr[i] + arr[j] == target`.

```cpp
// Variant 1 (YES/NO)
string twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == target)
                return "YES";
    return "NO";
}
```

```cpp
// Variant 2 (Indices)
vector<int> twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == target)
                return {i, j};
    return {-1, -1};
}
```

---

#### 2. **Better Approach (Hash Map)**

* **Time**: O(N)
* **Space**: O(N)
* **Logic**: Store elements in a map while checking if `target - arr[i]` already exists.

```cpp
// Variant 1 (YES/NO)
string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        if (mpp.count(target - arr[i])) return "YES";
        mpp[arr[i]] = i;
    }
    return "NO";
}
```

```cpp
// Variant 2 (Indices)
vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        if (mpp.count(target - arr[i]))
            return {mpp[target - arr[i]], i};
        mpp[arr[i]] = i;
    }
    return {-1, -1};
}
```

---

#### 3. **Optimized (Two Pointer)**

* **Time**: O(N log N) due to sorting
* **Space**: O(1) (unless index tracking is needed)
* **Logic**: Sort array and use two pointers to find sum.

> ⚠️ Doesn’t give original indices unless stored pre-sort.

```cpp
string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return "YES";
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
```

---

### ✅ **Best Choice in Interviews**

* Use **Hashing Approach** for **Variant 2** (gives indices efficiently).
* Use **Two Pointer** for space-optimized **YES/NO** checks (Variant 1), only if modifying the array is allowed.

---

Would you like the Python version or a Java solution as well?
