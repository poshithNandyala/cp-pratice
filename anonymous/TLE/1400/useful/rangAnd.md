Below is a step‑by‑step recipe to get **O(1)** bitwise‑AND over any static subarray `[L..R]` in C++.

---

## 1. Precompute a log‐table

We need, for any length `len`, to know `k = ⌊log₂ len⌋` in **O(1)**.  
```cpp
int N = arr.size();
vector<int> lg(N+1);
lg[1] = 0;
for(int i = 2; i <= N; ++i)
    lg[i] = lg[i/2] + 1;  
// Now lg[x] = floor(log2(x))
```

---

## 2. Build a sparse‐table for AND

Let `K = lg[N]` be the maximum power of two we’ll ever need.  
We create a 2D array `st[k][i]` meaning  
> “the AND of the block of length 2ᵏ starting at index `i`.”

```cpp
int K = lg[N];
vector<vector<int>> st(K+1, vector<int>(N));

// Level 0: blocks of size 1 are just the original elements
for(int i = 0; i < N; ++i)
    st[0][i] = arr[i];

// Build higher levels
for(int k = 1; k <= K; ++k) {
    int half = 1 << (k-1);            // half‑block size
    for(int i = 0; i + 2*half <= N; ++i) {
        // AND of [i .. i+2^k-1] = AND( [i .. i+half-1] , [i+half .. i+2*half-1] )
        st[k][i] = st[k-1][i] & st[k-1][i + half];
    }
}
```

- **Space:** O(N log N)  
- **Time:**  O(N log N)

---

## 3. Answer any query \[L..R\] in O(1)

1. Compute the length:  
   ```cpp
   int len = R - L + 1;
   ```
2. Find the largest power of two that fits:  
   ```cpp
   int k = lg[len];   // so 2^k ≤ len < 2^(k+1)
   ```
3. Cover the interval [L..R] by **two** length‑2ᵏ blocks:
   ```cpp
   int left_block  = st[k][L];                     // covers [L .. L+2^k-1]
   int right_block = st[k][R - (1<<k) + 1];        // covers [R-2^k+1 .. R]
   return left_block & right_block;
   ```
Because bitwise‑AND is associative, commutative, and idempotent,  
```cpp
( A & B & … & Z ) & (   overlap  & …   ) === A & B & … & Z
``` 
— the overlap doesn’t change the final AND.

```cpp
int range_and(int L, int R){
    int len = R - L + 1;
    int k   = lg[len];
    return st[k][L] & st[k][R - (1<<k) + 1];
}
```

---

## 4. Quick example

```cpp
// arr = [7, 3, 5, 6, 1, 4, 2, 8]
// N = 8, so K = lg[8] = 3

// Suppose you ask for L=2, R=6 (0‑based):
//   Elements are [ arr[2]=5, 6, 1, 4, 2 ]
//   True AND = 5 & 6 & 1 & 4 & 2 = 0

int len = 6 - 2 + 1;      // = 5
int k   = lg[5];          // = 2, since 2^2 = 4 ≤ 5 < 8
// left_block  = st[2][2] covers [2..5] = 5&6&1&4 = 0
// right_block = st[2][6-4+1=3] covers [3..6] = 6&1&4&2 = 0
// 0 & 0 = 0  ✔
```

---

### Complexity summary

- **Preprocessing:** O(N log N) time, O(N log N) space  
- **Query:** O(1) time  

That’s all you need to return `a[L] & a[L+1] & … & a[R]` in constant time!