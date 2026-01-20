**[1] THE ANSWER**

`n & (n - 1)` **removes the lowest (rightmost) set bit** of `n`.

* If `n` has **only one set bit** (power of 2), the result is **0**
* Otherwise, it clears the last `1` in binary

Example:

```
n = 12  -> 1100
n-1=11 -> 1011
&       ----
         1000  (8)
```

So the lowest `1` bit is removed.

---

**[2] ENGLISH AUDIT**

❌ Your input:
`n&(n-1) gives`

Issues:

* Incomplete sentence
* Missing article and verb

✅ **PROFESSIONAL REWRITE (SDE-level):**
👉 **“What does `n & (n - 1)` give?”**

---

**[3] SDE GROWTH ZONE — CP/DSA TRICK**

🔥 **Bit Trick (Very Important for Interviews)**

👉 **Check if a number is a power of 2**

```cpp
if (n > 0 && (n & (n - 1)) == 0)
    // n is a power of 2
```

Why?
Power of 2 has **only one set bit**.
Removing it makes the number **0**.

