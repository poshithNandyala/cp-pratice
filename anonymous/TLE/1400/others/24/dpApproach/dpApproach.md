# Dynamic Programming Approach: Counting Positive and Negative Product Subarrays

Let’s peel back all the formality and look at exactly **what’s happening**, step by step, with a tiny example.

---

## 1. The big picture in everyday terms

> **Goal:** Count all contiguous slices (“subarrays”) whose product is positive or negative.
>
> **Key fact:** Multiplying by a positive keeps the sign the same; multiplying by a negative flips it.

So imagine you’re standing at index *i* in the array.  You ask yourself:

> “How many nice slices ending exactly here are positive?  How many are negative?”

Write those two numbers down for each *i*, then at the end you just add them all up.

---

## 2. Think in “piles” of slices

At each index *i* we keep two little piles:

* **P₊** = number of subarrays ending at *i* that are positive
* **P₋** = number of subarrays ending at *i* that are negative

When we move from *i–1* to *i*, two things happen:

1. **Extend every slice** that ended at *i–1* by adding *a\[i]* to its right end.
2. **Start a brand-new slice** consisting of just the single element *a\[i]*.

Whether extending flips a slice from positive→negative or keeps it depends only on the sign of *a\[i]*.

---

## 3. The two “extension” rules

1. **If *a\[i]* is positive**

   * Extending a positive slice stays positive.
   * Extending a negative slice stays negative.
   * Plus the new single‐element slice is **positive**.

   So

   $$
   \begin{aligned}
   P₊(i) &= \;(\text{all the }P₊(i-1)\text{ slices you extended}) \;+\;1\quad
           \bigl(\text{the new }[i,i]\bigr),\\
   P₋(i) &= \;(\text{all the }P₋(i-1)\text{ slices you extended}).  
   \end{aligned}
   $$

2. **If *a\[i]* is negative**

   * Extending a positive slice flips it to negative.
   * Extending a negative slice flips it to positive.
   * Plus the new single‐element slice is **negative**.

   So

   $$
   \begin{aligned}
   P₊(i) &= \;(\text{all the }P₋(i-1)\text{ slices you extended}),\\
   P₋(i) &= \;(\text{all the }P₊(i-1)\text{ slices you extended}) \;+\;1\quad
           \bigl(\text{the new }[i,i]\bigr).
   \end{aligned}
   $$

That’s **all** there is to it: at step *i* you look at the sign of *a\[i]*, shuffle your previous piles over, add 1 for the brand‐new slice, and you’ve got your two new piles.

---

## 4. A concrete mini‐example

Take

$$
a = [-1,\;2,\;-3,\;4].
$$

We’ll make a little table.  Let `P+` = positive‐ending count, `P–` = negative‐ending.

|   i   | a\[i] | rule                      | P₊(i–1) | P₋(i–1) |           P₊(i)          |          P₋(i)          |
| :---: | :---: | :------------------------ | :-----: | :-----: | :----------------------: | :---------------------: |
| **1** |   –1  | new slice is neg; no prev |    0    |    0    |    0 (from prev P–=0)    | 1 (= prev P+ + 1 = 0+1) |
| **2** |   2   | positive                  |    0    |    1    | P₊ = prev P₊ +1 = 0+1 =1 |     P₋ = prev P₋ = 1    |
| **3** |   –3  | negative                  |    1    |    1    |     P₊ = prev P₋ = 1     | P₋ = prev P₊+1 = 1+1 =2 |
| **4** |   4   | positive                  |    1    |    2    |  P₊ = prev P₊+1 = 1+1 =2 |     P₋ = prev P₋ = 2    |

* At **i=1**: there’s exactly one slice \[1,1], and it’s negative, so `P–=1`.
* At **i=2**: you extend that one negative slice by +2 (stays negative) and you get a new \[2,2] (positive), so `P–=1`, `P+=1`.
* And so on.

Finally, to get **totals**:

$$
\text{total positive} = \sum_{i=1}^4 P₊(i) = 0 + 1 + 1 + 2 = 4,
$$

$$
\text{total negative} = \sum_{i=1}^4 P₋(i) = 1 + 1 + 2 + 2 = 6.
$$

Indeed there are $\tfrac{4\cdot5}{2}=10$ subarrays in all, $4$ of them positive and $6$ negative.

---

## 5. Why it’s so intuitive and fast

* We **only** ever look at what happened at the previous index (“piles” $P_+,P_-$ at $i-1$) plus the sign of one number.
* No nested loops, no big products—just two counters that shift and grow.
* Each element contributes exactly $O(1)$ work (extend two counts and maybe add one).
* **Total time:** $O(n)$.
* **Extra space:** a handful of integers, $O(1)$.

---

### Prerequisites you should be comfortable with

1. **Contiguous subarrays** and how many there are in total ($n(n+1)/2$).
2. **Sign‐multiplication rule:** pos×pos=pos, pos×neg=neg, neg×neg=pos.
3. **Recursive thinking / DP state:** “If I know the answer up to index *i–1*, how does adding position *i* change things?”
4. **Accumulating a running total:** once you have your per-index counts $\{P₊(i),P₋(i)\}$, just sum them.

That’s it—no more mysterious formulas or extra data structures.  You keep two running numbers, update them in one step per element, and accumulate your grand totals.  Super‐clean, super‐fast, and (I hope) crystal clear!
