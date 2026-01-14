This is a **classic expected value DP problem** from AtCoder (often called **Sushi DP**).
I’ll explain it **from zero**, step-by-step, intuitively, and then give **clean C++ code**.

---

## 🔍 Problem Rephrased Simply

* You have **N dishes**
* Each dish has **1, 2, or 3 sushi**
* Every operation:

  * You randomly choose **one dish uniformly**
  * If it has sushi → eat **1 piece**
  * Else → nothing happens
* Question:
  👉 **Expected number of operations** until **all sushi is eaten**

---

## 🧠 Key Difficulty

You **may choose empty dishes**, which wastes operations.

So we must account for **failed attempts** probabilistically.

---

## 💡 Core Idea

Instead of tracking every dish individually, we track:

* `x` = number of dishes with **1 sushi**
* `y` = number of dishes with **2 sushi**
* `z` = number of dishes with **3 sushi**

Let:

```
dp[x][y][z] = expected number of operations
             to finish all sushi from this state
```

---

## 📌 State Size

* `x + y + z ≤ N`
* `N ≤ 300`

Total states ≈ **O(N³ / 6)** → ~4.5 million
✔️ Feasible with DP

---

## 🎯 Base Case

```
dp[0][0][0] = 0
```

No sushi → no operations needed.

---

## 🔄 Transition Logic

Let:

```
s = x + y + z   (number of non-empty dishes)
```

Probability cases when we roll the die:

| Event                    | Probability |
| ------------------------ | ----------- |
| Choose dish with 1 sushi | x / N       |
| Choose dish with 2 sushi | y / N       |
| Choose dish with 3 sushi | z / N       |
| Choose empty dish        | (N - s) / N |

---

### 🎲 What happens?

* **1 sushi dish → disappears**

  ```
  (x, y, z) → (x-1, y, z)
  ```
* **2 sushi dish → becomes 1**

  ```
  (x, y, z) → (x+1, y-1, z)
  ```
* **3 sushi dish → becomes 2**

  ```
  (x, y, z) → (x, y+1, z-1)
  ```
* **Empty dish → no change**

---

## 📐 Expected Value Equation

Let `E = dp[x][y][z]`

```
E =
1
+ (x/N) * dp[x-1][y][z]
+ (y/N) * dp[x+1][y-1][z]
+ (z/N) * dp[x][y+1][z-1]
+ ((N - s)/N) * E
```

Why `+1`?
👉 Because **we performed one operation**

---

## ✏️ Solve for `E`

Move `(N - s)/N * E` to left:

```
E * (s/N) =
1
+ (x/N) * dp[x-1][y][z]
+ (y/N) * dp[x+1][y-1][z]
+ (z/N) * dp[x][y+1][z-1]
```

Multiply both sides by `N/s`:

```
dp[x][y][z] =
N/s
+ (x/s) * dp[x-1][y][z]
+ (y/s) * dp[x+1][y-1][z]
+ (z/s) * dp[x][y+1][z-1]
```

🔥 **This is the final DP formula**

---

## 🧩 Implementation Strategy

1. Count how many dishes have 1, 2, 3 sushi
2. Fill DP table bottom-up
3. Answer = `dp[cnt1][cnt2][cnt3]`

---

## ✅ C++ Implementation (Fully Explained & Clean)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int cnt[4] = {};
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    // dp[x][y][z] = expected operations
    static double dp[305][305][305];

    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            for (int z = 0; z <= N; z++) {
                if (x + y + z == 0) continue;

                int s = x + y + z;
                double expected = (double)N / s;

                if (x > 0)
                    expected += (double)x / s * dp[x - 1][y][z];
                if (y > 0)
                    expected += (double)y / s * dp[x + 1][y - 1][z];
                if (z > 0)
                    expected += (double)z / s * dp[x][y + 1][z - 1];

                dp[x][y][z] = expected;
            }
        }
    }

    cout << fixed << setprecision(15)
         << dp[cnt[1]][cnt[2]][cnt[3]] << "\n";

    return 0;
}
```

---

## 🧪 Sample Check

Input:

```
3
1 1 1
```

Output:

```
5.5
```

✔️ Matches expected result

---

## 🧠 Key Takeaways

* This is **Expected Value DP**
* Trick:
  👉 **Move probability of no-change to LHS**
* State compression is crucial (counts instead of individual dishes)
* Standard technique for **random processes with wasted moves**

---

If you want:

* ❓ Visualization of state transitions
* 🧠 Why this DP works mathematically
* 🚀 Optimization & memory tricks
* 🧩 Similar problems list

Just tell me 👍
