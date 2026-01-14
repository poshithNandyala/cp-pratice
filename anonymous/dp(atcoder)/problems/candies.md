This is **AtCoder DP Contest – Problem M (Candies)**.
Let’s build the solution **step-by-step from recursion → memoization → efficient DP**, exactly the way you should *think* in contests.

---

# 1️⃣ Brute Force Thinking (Why it fails)

Each child `i` can take `0 … a[i]` candies.
We need:

```
x1 + x2 + ... + xN = K
0 ≤ xi ≤ ai
```

Brute force tries all combinations → **exponential** ❌.

---

# 2️⃣ Recursive DP Formulation (Core Idea)

### Define State

```cpp
rec(i, k) = number of ways
            to distribute k candies
            among children i ... N-1
```

### Base Cases

```cpp
if (k == 0) return 1;      // valid distribution
if (i == N) return 0;     // candies left but no children
```

### Transition

Child `i` can take `j` candies:

```
j ∈ [0, a[i]]
```

So:

```cpp
rec(i, k) = Σ rec(i+1, k-j)
            for j = 0 .. min(a[i], k)
```

---

# 3️⃣ Recursive + Memoization (Top-Down DP)

```cpp
int rec(int i, int k) {
    if (k == 0) return 1;
    if (i == N) return 0;
    if (dp[i][k] != -1) return dp[i][k];

    long long ans = 0;
    for (int j = 0; j <= a[i] && j <= k; j++) {
        ans = (ans + rec(i+1, k-j)) % MOD;
    }
    return dp[i][k] = ans;
}
```

### Complexity ❌

```
O(N × K × max(a[i]))
≈ 100 × 10^5 × 10^5  → TLE
```

We must **optimize the transition**.

---

# 4️⃣ Key Optimization Insight (Prefix Sums)

Look at the transition:

```
dp[i][k] = dp[i+1][k]
         + dp[i+1][k-1]
         + ...
         + dp[i+1][k-a[i]]
```

This is a **sliding window sum**.

Instead of recomputing every time, use **prefix sums**.

---

# 5️⃣ Optimized DP Relation

Let:

```
pref[k] = dp[i+1][0] + dp[i+1][1] + ... + dp[i+1][k]
```

Then:

```
dp[i][k] = pref[k] - pref[k - a[i] - 1]
```

(If `k - a[i] - 1 < 0`, subtract 0)

This reduces transition to **O(1)**.

---

# 6️⃣ Efficient Bottom-Up DP (Final)

### DP Meaning

```
dp[i][k] = ways using first i children to get sum k
```

### Initialization

```cpp
dp[0][0] = 1;
```

---

### Code (Efficient & Accepted)

```cpp
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        vector<int> prefix(K + 1, 0);

        prefix[0] = dp[i-1][0];
        for (int k = 1; k <= K; k++) {
            prefix[k] = (prefix[k-1] + dp[i-1][k]) % MOD;
        }

        for (int k = 0; k <= K; k++) {
            int left = k - a[i-1] - 1;
            if (left >= 0)
                dp[i][k] = (prefix[k] - prefix[left] + MOD) % MOD;
            else
                dp[i][k] = prefix[k];
        }
    }

    cout << dp[N][K] << '\n';
}
```

---

# 7️⃣ Complexity Analysis

| Version          | Time         | Space  |
| ---------------- | ------------ | ------ |
| Recursive        | Exponential  | —      |
| Memoized         | O(N·K·A)     | O(N·K) |
| **Optimized DP** | **O(N·K)** ✅ | O(N·K) |

This **passes easily** within limits.

---

# 8️⃣ Intuition Summary (Remember This)

* This is **bounded knapsack counting**
* Recursion is natural but slow
* The bottleneck is **range summation**
* Prefix sums convert `O(A)` → `O(1)`
* This trick appears in **many CF / AtCoder problems**

---

If you want next:

* 🔥 **How to derive prefix sum transition yourself**
* 🧠 **Visual DP table explanation**
* ⚡ **Space optimization to 1D**

Just tell me 👍
