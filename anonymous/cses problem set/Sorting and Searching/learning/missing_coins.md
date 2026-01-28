## 📌 Problem Statement (Brief)

You are given **n coins**, each with a **positive integer value**. You may choose **any subset** of these coins.

Your task is to find the **smallest positive sum** that **cannot** be formed using any subset of the coins.

---

## 🧠 Key Observation

This is **not** a DP problem.
This is a **Greedy + Sorting** problem.

Why?

* Coin values can be as large as **1e9**
* `n` can be **2 * 10^5`
* DP on sums is impossible

So we must think **mathematically**, not brute force.

---

## 🎯 Core Greedy Idea (Most Important)

Maintain a variable:

> **S = largest sum such that all values from `1` to `S` are constructible**

Initially:

```
S = 0   // we cannot form anything
```

Coins are processed in **sorted order**.

---

## 🔍 Why Sorting is Mandatory

If coins are not sorted:

* You may skip a small coin
* A gap appears that can NEVER be fixed later

👉 Greedy rule: **Always use the smallest available coin first**.

---

## ⚙️ Greedy Transition Rule

Let the current coin be `c`.

### Case 1️⃣: `c > S + 1`

* You cannot form `S + 1`
* Even combining all previous coins, the smallest missing sum is `S + 1`
* **Answer found**

### Case 2️⃣: `c ≤ S + 1`

* You can now form **all sums up to `S + c`**
* Extend the reachable range

Update:

```
S = S + c
```

---

## 🧪 Small Example Walkthrough

Coins:

```
1 2 2 7 9
```

Step-by-step:

* S = 0
* coin = 1 → 1 ≤ 1 → S = 1
* coin = 2 → 2 ≤ 2 → S = 3
* coin = 2 → 2 ≤ 4 → S = 5
* coin = 7 → 7 > 6 ❌

👉 Smallest unreachable sum = **6**

---

## ❓ How to Identify This is a Greedy Problem (Interview Trick)

Ask yourself:

✅ Can I sort the input?
✅ Can I build the answer step-by-step?
✅ Does a wrong early choice break everything?

If YES → **Greedy**

❌ If problem asks for ALL combinations → DP
❌ If order matters → DP / Two pointers

---

## 🧠 Why This Greedy is Correct (Intuition Proof)

If you can already make:

```
1 to S
```

And next coin is `c ≤ S + 1`, then:

* You can make:

```
(c + 1) to (c + S)
```

So new range becomes:

```
1 to S + c
```

But if `c > S + 1`, the value `S + 1` is a **permanent gap**.

---

## 📦 Complexity

* Sorting: `O(n log n)`
* Loop: `O(n)`
* Extra space: `O(1)`

Perfect for large constraints.

---

## 🧩 Pattern Name (Remember This!)

🔑 **"Smallest Missing / Reachable Prefix Greedy"**

Used in:

* Coin sum problems
* Interval coverage
* Range extension problems

---

## 🧠 One-Line Interview Summary

> "We sort the coins and greedily maintain the maximum reachable sum. If the next coin creates a gap, that gap is the smallest unreachable sum."
