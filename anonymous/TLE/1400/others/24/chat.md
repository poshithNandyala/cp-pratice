Let’s walk through this problem step by step, build up the intuition, and then see why the “prefix-parity” trick gives us an $O(n)$ algorithm.

---

## 1. Restating the problem

We have an array of $n$ **nonzero** integers:

$$
a_1,\;a_2,\;\dots,\;a_n,\quad a_i \neq 0.
$$

A **subsegment** (sometimes called a subarray) is any contiguous slice

$$
a_\ell, a_{\ell+1}, \dots, a_r
$$

with $1 \le \ell \le r \le n$.

We want:

1. **$\displaystyle \text{neg}$** = the number of subsegments whose product is **negative**.
2. **$\displaystyle \text{pos}$** = the number of subsegments whose product is **positive**.

There are in total

$$
\binom{n}{2} + n = \frac{n(n+1)}{2}
$$

subsegments altogether (because choosing $(\ell,r)$ with $\ell\le r$ is the same as choosing 2 endpoints in order).

---

## 2. Why zero-elements would break things—but here there aren’t any

If zeros were allowed, any subsegment containing a zero has product zero, and we’d have to count those separately.  Here, since **all** $a_i\neq0$, every subsegment’s product is either **positive** or **negative**, never zero.  Thus

$$
\text{neg} + \text{pos}
= \frac{n(n+1)}{2}.
$$

So if we can compute one of them (say $\text{pos}$), we get the other by subtraction.

---

## 3. A naïve approach is too slow

You could imagine:

* For each $\ell$ from 1 to $n$:

  * For each $r$ from $\ell$ to $n$:

    * Multiply $a_\ell \times a_{\ell+1} \times \cdots \times a_r$, check its sign, increment a counter.

But that’s $O(n^2)$ subsegments, and for each you might spend $O(1)$ to track the running product, so still $O(n^2)$ overall in the worst case.  With $n$ up to $2\cdot10^5$, $n^2$ is $4\times10^{10}$ operations—far too big.

---

## 4. Key insight: only the **parity** of the count of negative numbers in the subsegment matters

* A product is **positive** exactly when it has an **even** number of negative factors.
* A product is **negative** exactly when it has an **odd** number of negative factors.

So for each subsegment $(\ell,r)$, all we need to know is:

$$
\underbrace{\#\{\text{negatives in }a_\ell,\dots,a_r\}}_{\text{call this }k}
\quad\Longrightarrow\quad
\begin{cases}
\text{positive product} & k\text{ is even},\\
\text{negative product} & k\text{ is odd}.
\end{cases}
$$

---

## 5. Prefix-parity array

Define a helper array $p$ of length $n$, where

$$
p[i] = \text{(number of negatives among }a_1,\dots,a_i)\bmod 2.
$$

Thus $p[i]\in\{0,1\}$.  Specifically

* $p[i] = 0$ means “up to position $i$, the total count of negatives is even.”
* $p[i] = 1$ means “... is odd.”

Now consider any subsegment $(\ell,r)$.  The count of negatives in it is

$$
\bigl(\text{negatives in }1\ldots r\bigr)
\;-\;\bigl(\text{negatives in }1\ldots (\ell-1)\bigr).
$$

Taking both sides mod 2 means

$$
\bigl(\#_{\ell\to r}\bigr)\bmod 2
\;=\;
\bigl(p[r]\bigr)\;-\;\bigl(p[\ell-1]\bigr)\quad(\bmod 2).
$$

But subtraction mod 2 is the same as XOR, so

$$
(\#\text{neg in }\ell..r)\bmod2
=
p[r]\;\oplus\;p[\ell-1].
$$

* If $p[r]\oplus p[\ell-1] = 0$, then the subsegment has **even** negatives → **positive** product.
* If $p[r]\oplus p[\ell-1] = 1$, then **odd** negatives → **negative** product.

---

## 6. Counting subsegments by pairing prefix-parity values

We want to count how many pairs $(\ell,r)$ with $1\le\ell\le r$ satisfy

$$
p[r]\;\oplus\;p[\ell-1]=0\quad(\text{for pos}),
\quad
p[r]\;\oplus\;p[\ell-1]=1\quad(\text{for neg}).
$$

It’s convenient to let

$$
p[0]\;=\;0
$$

(i.e.\ “before the array starts, we’ve seen 0 negatives, which is even”).

Then every prefix parity $p[i]$ for $i=0,1,\dots,n$.  We need to count pairs $(i,j)$ with $0\le i<j\le n$ such that:

* **positive** subarray → $p[i] = p[j]$
* **negative** subarray → $p[i] \neq p[j]$

But that’s just the classic: among the $n+1$ values $p[0],p[1],\dots,p[n]$:

* Count how many are 0; call that $c_0$.
* Count how many are 1; call that $c_1$.

Then:

1. Number of ways to pick two equal-parity prefixes both 0’s is $\binom{c_0}{2}$.
2. ... both 1’s is $\binom{c_1}{2}$.
3. Those two sums give **pos**.
4. Total pairs $(i<j)$ is $\binom{n+1}{2}$.  Subtract pos to get **neg**.

Equivalently, one can accumulate as we scan from left to right, keeping counters of how many 0-parities and 1-parities we’ve seen so far.

---

## 7. Implementing in $O(n)$ time, $O(1)$ extra space

* Initialize

  ```
  cnt[0] = 1   // we’ve “seen” one prefix of parity 0: p[0]=0
  cnt[1] = 0
  current_parity = 0
  pos = 0      // answer accumulator for positive subsegments
  ```

* Loop $i$ from 1 to $n$:

  1. If $a_i<0$, flip parity: `current_parity ^= 1`.
  2. Now **any** previously seen prefix $j<i$ with the *same* parity will form a positive subsegment $(j+1$,…,$i)$.  There are `cnt[current_parity]` of them.  So do

     ```cpp
     pos += cnt[current_parity];
     ```
  3. Record that we have now seen one more prefix of this parity:

     ```cpp
     cnt[current_parity] += 1;
     ```

* After the loop,

  $$
  \text{pos} = \sum_{i=1}^n \; \bigl|\{\,j < i : p[j]=p[i]\}\bigr|,
  $$

  exactly $\binom{c_0}{2} + \binom{c_1}{2}$.

* Total subsegments = $n(n+1)/2$.  So

  $$
  \text{neg} 
  = \frac{n(n+1)}{2} - \text{pos}.
  $$

This is $O(n)$ time, uses just a few integer variables, and handles up to $n=2\cdot10^5$ in a fraction of a second.

---

## 8. Example

Take the sample

$$
a = [\,5,\,-3,\,3,\,-1,\,1\,].
$$

* $i=0$: parity = 0.  counts: $\;cnt[0]=1,\;cnt[1]=0$.
* $i=1$, $a_1=5>0$: parity stays 0.

  * Add $cnt[0]=1$ to pos → pos=1.
  * Increment cnt\[0] → cnt\[0]=2.
* $i=2$, $a_2=-3<0$: parity flips to 1.

  * Add $cnt[1]=0$ → pos stays 1.
  * cnt\[1]=1.
* $i=3$, $a_3=3>0$: parity stays 1.

  * Add $cnt[1]=1$ → pos=2.
  * cnt\[1]=2.
* $i=4$, $a_4=-1<0$: parity flips  → 0.

  * Add $cnt[0]=2$ → pos=4.
  * cnt\[0]=3.
* $i=5$, $a_5=1>0$: parity stays 0.

  * Add $cnt[0]=3$ → pos=7.
  * cnt\[0]=4.

Total subsegments = $\tfrac{5\cdot6}{2}=15$.
So

$$
\text{pos}=7,\quad
\text{neg}=15-7=8,
$$

matching the sample output.

---

### Why it’s so slick

* **No nested loops.** We do a single pass.
* We never multiply big products; we only track a **single bit** of information per prefix.
* We leverage the combinatorial identity “number of equal‐parity pairs” in a dynamic way as we scan.

---

### Related topics you might want to understand more deeply

* **Prefix sums (or here, prefix parities)** — a fundamental trick for turning “sum/product over arbitrary subarray” queries into $O(1)$ queries given precomputation.
* **Combinatorial pairs counting** $\binom{k}{2} = k(k-1)/2$ and the dynamic variant “as you scan, if you’ve seen $c$ items of type X so far, you can form $c$ new pairs with the next such item.”
* **XOR** as addition mod 2: flipping a bit each time you encounter a negative number.

Once you see this pattern, it recurs in many problems about “number of subarrays whose sum is divisible by $K$,” or “number of subarrays with even sum,” etc.—you just replace parity with “sum mod $K$” or similar.

I hope this clears up both **what** is being counted and **why** the prefix-parity method is the ideal $O(n)$ solution!
