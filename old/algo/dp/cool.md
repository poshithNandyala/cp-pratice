Below is the detailed story of how—and **only when**—you can turn an LCS problem into an LIS problem in O(N log N), and why **uniqueness** of one sequence’s elements is absolutely key.

---

## 1. Why LCS is usually O(N·M)

For two sequences

```text
A = a₁,a₂,…,aₙ  
B = b₁,b₂,…,bₘ
```

the classic DP is

```
dp[i][j] = LCS‐length of A[i…] and B[j…]
if aᵢ == bⱼ:  dp[i][j] = 1 + dp[i+1][j+1]
else:        dp[i][j] = max(dp[i+1][j], dp[i][j+1])
```

Filling that 2D table costs Θ(n·m).

---

## 2. The “map‐to‐indices + LIS” trick

If **all elements of A are distinct**, you can do:

1. **Index‐map** A:
   Build a hash map

   ```cpp
   unordered_map< T, int > pos;
   for(int i = 0; i < n; i++)
     pos[A[i]] = i;      // each A[i] appears exactly once
   ```

2. **Filter & translate** B into a sequence of indices in A:

   ```cpp
   vector<int> P;
   for (auto &x : B) {
     if (pos.count(x))
       P.push_back(pos[x]);
   }
   ```

   — now P contains exactly those indices i in A that also appear in B, **in B’s order**.

3. **LCS = LIS** on P:
   The longest increasing subsequence of P corresponds 1–1 to the longest common subsequence of A and B!
   Why?

   * “Increasing” ↔ preserves original A‐order
   * “Subsequence of P” ↔ picking a subset of B’s elements in order
   * Together they pick the largest set of elements that appear in both, in increasing A‐index order.

4. **Solve LIS in O(N log N)**

   ```cpp
   vector<int> tail;
   for(int x : P) {
     auto it = lower_bound(tail.begin(), tail.end(), x);
     if (it == tail.end())
       tail.push_back(x);
     else
       *it = x;
   }
   int LCS_length = tail.size();
   ```

Because each `lower_bound` costs O(log |tail|) and you do it O(|P|) ≤ O(m), overall O(m log n).

---

## 3. Why **uniqueness** matters

* **Injectivity** of the map from A’s values → A’s indices is what lets us treat each value as a single integer.
* **If A has duplicates**, say A = `[2,5,2,7]`, then mapping value “2” → which index?

  * You’d have to keep **all** of them, e.g. pos\[2] = {0,2}, and then for each “2” in B you’d get two possible positions.
  * Now P becomes a sequence of **sets** of positions, and finding the maximum chain of picks across those sets is back to a 2D DP (or a more complicated DAG‐DP), not an O(N log N) LIS.

In short:

* **Unique A ⇒** simple one‐to‐one map ⇒ P is a flat integer array ⇒ LIS in O(m log n) ⇒ LCS.
* **Non‑unique A ⇒** map is one‑to‑many ⇒ P is a “sequence of choices,” you can’t reduce it to a single LIS pass.

---

## 4. What if **both** have duplicates?

You cannot get away from the Θ(n·m) DP (or some specialized near‑linear algorithm in very restricted alphabets). The classic O(n·m) table or Hirschberg’s space‑optimized recursion is the safe, general‑purpose solution.

---

### TL;DR

* \*\*When A’s elements are all **distinct**, build `pos[value]→index_in_A`, translate B→P (indices), and do an O(m log n) LIS on P.
* **If A has duplicates**, that reduction breaks—elements map to multiple indices—so you must fall back to O(n·m) LCS DP.
