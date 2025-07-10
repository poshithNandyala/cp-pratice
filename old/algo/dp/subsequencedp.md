**Detailed Guide to Subsequence DP in C++**

---

## Table of Contents

- [Table of Contents](#table-of-contents)
- [1. Fundamentals of Subsequence DP](#1-fundamentals-of-subsequence-dp)
- [2. Longest Common Subsequence (LCS)](#2-longest-common-subsequence-lcs)
  - [2.1 Memoization (Top‑Down)](#21-memoization-topdown)
  - [2.2 Tabulation (Bottom‑Up)](#22-tabulation-bottomup)
  - [2.3 Reconstruction of LCS](#23-reconstruction-of-lcs)
- [3. Longest Increasing Subsequence (LIS)](#3-longest-increasing-subsequence-lis)
  - [3.1 O(n²) DP Approach](#31-on-dp-approach)
  - [3.2 O(n log n) Patience Sorting](#32-on-log-n-patience-sorting)
- [4. Clown’s Shoes Problem (2D → LIS)](#4-clowns-shoes-problem-2d--lis)
- [5. Knight’s Minimum Moves (Grid + BFS)](#5-knights-minimum-moves-grid--bfs)
- [6. Key Intuitions \& Tips](#6-key-intuitions--tips)

---

<a name="fundamentals"></a>

## 1. Fundamentals of Subsequence DP

* **Subsequence**: Sequence derived by deleting zero or more elements from the original, **without** reordering.
* **DP State**: Encodes indices or parameters capturing "where you are".
* **Transition**: Choice to include/exclude current element or compare two positions.
* **Two Styles**:

  * **Memoization (Top‑Down)**: Recursively solve, cache results in `dp[...]` to avoid recomputation.
  * **Tabulation (Bottom‑Up)**: Fill `dp` table/array iteratively from base cases.

Key Steps:

1. Define state dimensions and meaning (e.g., `dp[i][j]` = LCS length of suffixes starting at `i`, `j`).
2. Write recurrence (choices).
3. Identify base cases.
4. Implement memoization or tabulation.
5. (Optional) Reconstruct solution from DP table.

---

<a name="lcs"></a>

## 2. Longest Common Subsequence (LCS)

**Problem**: Given `string A` of length `n` and `string B` of length `m`, find the length (and sequence) of the longest subsequence common to both.

### 2.1 Memoization (Top‑Down)

```cpp
#include <bits/stdc++.h>
using namespace std;

string A, B;
int n, m;
vector<vector<int>> dp;

int solveLCS(int i, int j) {
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (A[i] == B[j])
        return dp[i][j] = 1 + solveLCS(i+1, j+1);
    else
        return dp[i][j] = max(solveLCS(i+1, j), solveLCS(i, j+1));
}

int main() {
    cin >> A >> B;
    n = A.size(); m = B.size();
    dp.assign(n, vector<int>(m, -1));
    cout << solveLCS(0, 0) << "\n";
    return 0;
}
```

* **State**: `(i,j)` indices into A & B.
* **Base**: `i==n||j==m` → no characters left.
* **Transition**: match yields +1+`dp(i+1, j+1)`; else choose max of skipping one.

---

### 2.2 Tabulation (Bottom‑Up)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (A[i] == B[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    cout << dp[0][0] << "\n";
    return 0;
}
```

### 2.3 Reconstruction of LCS

```cpp
string buildLCS(const string &A, const string &B, const vector<vector<int>> &dp) {
    string res;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            res.push_back(A[i]);
            ++i; ++j;
        } else if (dp[i+1][j] >= dp[i][j+1]) {
            ++i;
        } else {
            ++j;
        }
    }
    return res;
}
```

---

<a name="lis"></a>

## 3. Longest Increasing Subsequence (LIS)

**Problem**: Given array `arr` of size `n`, find length of the longest strictly increasing subsequence.

### 3.1 O(n²) DP Approach

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    vector<int> dp(n, 1);
    int best = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        best = max(best, dp[i]);
    }
    cout << best << "\n";
    return 0;
}
```

* **State**: `dp[i]` = LIS ending at `i`.
* **Transition**: `dp[i] = max(dp[i], dp[j]+1)` for all `j<i` with `arr[j]<arr[i]`.

---

### 3.2 O(n log n) Patience Sorting

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    vector<int> sub;
    for (int x : arr) {
        auto it = lower_bound(sub.begin(), sub.end(), x);
        if (it == sub.end()) sub.push_back(x);
        else *it = x;
    }
    cout << sub.size() << "\n";
    return 0;
}
```

* **`sub`** stores the smallest tail of all increasing subsequences of each length.
* **`lower_bound`** finds where to replace/extend.

---

<a name="clown"></a>

## 4. Clown’s Shoes Problem (2D → LIS)

**Problem**: Two arrays `L[]` and `R[]` of equal length. Each clown has left‐foot size `L[i]` and right‐foot size `R[i]`. Maximize a sequence so that both sizes strictly increase.

**Solution Outline**:

1. Pair up: `vector<pair<int,int>> v;` push `{L[i], R[i]}`.
2. Sort by `L` asc, and if tie by `R` **desc**.
3. Extract `R` values into a 1D array.
4. Run LIS (O(n log n)) on this `R` array.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    vector<int> R;
    for (auto &p : v) R.push_back(p.second);

    // LIS on R[]
    vector<int> sub;
    for (int x : R) {
        auto it = lower_bound(sub.begin(), sub.end(), x);
        if (it == sub.end()) sub.push_back(x);
        else *it = x;
    }
    cout << sub.size() << "\n";
    return 0;
}
```

---

<a name="knight"></a>

## 5. Knight’s Minimum Moves (Grid + BFS)

**Problem**: `N×M` board, knight starts `(0,0)`, target `(N-1,M-1)`. Find minimum number of moves.

**Solution**: Model as unweighted graph, each cell a node, edges = valid knight moves. Run BFS.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    vector<pair<int,int>> moves = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

    queue<tuple<int,int,int>> q;
    q.emplace(0,0,0);
    vis[0][0] = true;

    while (!q.empty()) {
        auto [x,y,d] = q.front(); q.pop();
        if (x == N-1 && y == M-1) {
            cout << d << '\n';
            return 0;
        }
        for (auto &mv : moves) {
            int nx = x + mv.first;
            int ny = y + mv.second;
            if (nx>=0 && nx<N && ny>=0 && ny<M && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.emplace(nx, ny, d+1);
            }
        }
    }
    // unreachable
    cout << -1 << '\n';
    return 0;
}
```

---

<a name="tips"></a>

## 6. Key Intuitions & Tips

* **Define clear states**: Dimensions correspond exactly to parameters needed.
* **Sort + 1D DP** trick: reduces 2D to LIS (e.g., envelopes, clown’s shoes).
* **Memo → Tab**: convert recursion into loops; watch indices (reverse vs forward).
* **Reconstruction**: store parent pointers or retrace decisions after filling DP.
* **Optimization**: binary search tail array for LIS → O(n log n).
* **Graph vs DP**: BFS for shortest path in grid; DP for subsequence/sequence.

---

*Feel free to ask questions or for further clarifications on any section!*
