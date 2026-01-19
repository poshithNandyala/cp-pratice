Sure! Let's break this down into simpler explanations.

### **Kadane’s Algorithm (Maximum Sum Subarray)**
Kadane’s algorithm is a widely used method to find the maximum sum of a contiguous subarray in an array of numbers. The core idea is based on dynamic programming.

#### **Problem Statement**
Given an array **A[]** of size **N**, find a contiguous subarray whose sum is maximum.

#### **Solution 1 (Using Dynamic Programming)**
We define a **DP[i]** array such that **DP[i]** stores the maximum sum subarray ending at index **i**.

##### **Recurrence Relation**
For each index **i**, the maximum sum subarray ending at **i** can be:
1. **Extending the best subarray ending at (i-1)** → `DP[i-1] + A[i]`
2. **Starting a new subarray at i** → `A[i]` (if previous sum is negative)

Thus, we get:
```
DP[i] = max(DP[i-1] + A[i], A[i])
```
The base case is:
```
DP[0] = A[0]
```

##### **Implementation**
```cpp
int GetMaxSumSubarray(vector<int>& A) {
    vector<int> DP(A.size());
    DP[0] = A[0];
    
    for (int i = 1; i < A.size(); i++) {
        DP[i] = max(DP[i-1] + A[i], A[i]);
    }
    
    return *max_element(DP.begin(), DP.end());
}
```
##### **Time Complexity**
- **O(N)** because we iterate through the array once.
- **O(N) space** because we maintain an extra array **DP[]**.

#### **Solution 2 (Optimized for Space)**
Since **DP[i]** depends only on **DP[i-1]**, we don’t need to store the entire array. Instead, we keep only one variable tracking the previous best.

```cpp
int GetMaxSumSubarray(vector<int>& A) {
    int prevBest = A[0], ans = A[0];
    
    for (int i = 1; i < A.size(); i++) {
        prevBest = max(prevBest + A[i], A[i]);
        ans = max(ans, prevBest);
    }
    
    return ans;
}
```
##### **Time Complexity**
- **O(N) time**, **O(1) space** (optimized!).

---

### **Circular Kadane (Maximum Sum Circular Subarray)**
If the array is circular, we need to consider subarrays that "wrap around" the end of the array.

#### **Solution 1: Doubling Array Trick**
We create a new array by doubling the original array (appending it to itself). Then, we run standard Kadane’s algorithm.

**Time Complexity:** **O(N) time, O(N) space**

#### **Solution 2: Invert Sum Trick**
We handle wrap-around subarrays by:
1. Running Kadane normally to find the best sum without wrapping.
2. Finding the smallest contiguous sum and subtracting it from the total sum.
3. Edge case: If all numbers are negative, return the maximum individual element.

```cpp
int GetMaxSumSubarrayInCircle(vector<int>& A) {
    int cur_max = 0, cur_min = 0, overall_max = A[0], overall_min = A[0], total_sum = 0;
    
    for (int i = 0; i < A.size(); i++) {
        cur_max = max(cur_max + A[i], A[i]);
        overall_max = max(overall_max, cur_max);
        cur_min = min(cur_min + A[i], A[i]);
        overall_min = min(overall_min, cur_min);
        total_sum += A[i];
    }
    
    return (total_sum == overall_min) ? overall_max : max(overall_max, total_sum - overall_min);
}
```
**Time Complexity:** **O(N) time, O(1) space**

---

### **Double Slice Kadane (Skipping One Element)**
Given an array **A[]**, we want to find the maximum sum subarray while **skipping** exactly one element.

#### **Key Observations**
1. This problem is similar to Kadane’s algorithm, except we have to exclude one element from the sum.
2. Instead of directly finding the best sum, we can compute two subarrays:
   - **Left-to-Right Kadane:** Best sum up to a certain index
   - **Right-to-Left Kadane:** Best sum starting from a certain index
3. Our answer is `DP_LeftToRight[y-1] + DP_RightToLeft[y+1]`.

##### **Implementation**
```cpp
int DoubleSliceKadane(vector<int>& A) {
    vector<int> DP_LR(A.size()), DP_RL(A.size());
    
    // Left-to-Right Kadane
    DP_LR[0] = A[0];
    for (int i = 1; i < A.size(); i++) {
        DP_LR[i] = max(DP_LR[i-1] + A[i], A[i]);
    }
    
    // Right-to-Left Kadane
    DP_RL[A.size()-1] = A[A.size()-1];
    for (int i = A.size()-2; i >= 0; i--) {
        DP_RL[i] = max(DP_RL[i+1] + A[i], A[i]);
    }
    
    int ans = INT_MIN;
    for (int y = 1; y < A.size()-1; y++) {
        ans = max(ans, DP_LR[y-1] + DP_RL[y+1]);
    }
    
    return ans;
}
```
**Time Complexity:** **O(N) time, O(N) space**

#### **Optimized Approach (State Change Kadane)**
Instead of maintaining separate arrays, redefine Kadane’s recurrence relation:
1. **`DP[i][0]`** → Best sum ending at **i** without dropping an element.
2. **`DP[i][1]`** → Best sum ending at **i**, after dropping at most one element.

Recurrence:
```
DP[i][0] = max(DP[i-1][0] + A[i], A[i])
DP[i][1] = max(DP[i-1][0], DP[i-1][1] + A[i])
```
Final answer: **`DP[N][1]`**

---

### **K-Hole Kadane (Dropping K Elements)**
We extend the previous problem by allowing up to **K** contiguous elements to be skipped.

#### **Solution 1: Leveraging 1-Hole Kadane**
Instead of handling multiple skipped elements, we compute:
- **Left-to-Right Kadane**
- **Right-to-Left Kadane**
and maximize `DP_LeftToRight[i] + DP_RightToLeft[j]` for `i ≤ j`.

#### **Solution 2: Optimized Redefinition**
Instead of considering all **(i,j) pairs**, redefine:
```
DP_LeftToRight[i] = Max sum in range [0,i]
DP_RightToLeft[i] = Max sum in range [i+1,N]
```
Final answer: **`max(DP_LeftToRight[i] + DP_RightToLeft[i])`**

---

### **Max Sum Subset (No Two Adjacent Elements)**
Given an array **A[]**, find the maximum sum subset such that **no two adjacent elements are chosen**.

#### **Recurrence Relation**
```
DP[i] = max(DP[i-2] + A[i], DP[i-1])
```
At any step:
- Either select the current element (and skip the previous).
- Or skip the current element and retain the best sum so far.

##### **Implementation**
```cpp
int GetMaxSumSubsetNonAdjacent(vector<int>& A) {
    int prevBest = 0, curBest = 0;
    
    for (int i = 0; i < A.size(); i++) {
        int temp = max(prevBest + A[i], curBest);
        prevBest = curBest;
        curBest = temp;
    }
    
    return curBest;
}
```
**Time Complexity:** **O(N) time, O(1) space**

Let me know if you need any deeper clarifications! 🚀
