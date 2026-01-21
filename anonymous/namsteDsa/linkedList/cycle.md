Perfect — this is **the exact code used in interviews**, so I’ll give you a **clean, formal, mathematical proof** that you can **reproduce under pressure**.
No stories, no hand-waving. Just logic.

---

## Given Code (reference)

```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (!fast || !fast->next) return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // cycle start
}
```

---

## Step 1: Define the structure mathematically

Assume the linked list **has a cycle**.

Define:

* `x` = number of nodes **before the cycle starts**
* `c` = **length of the cycle**
* `k` = number of nodes **inside the cycle** from cycle start to the meeting point

```
head → ... (x nodes) ... → cycle_start → ... (k nodes) ... → meeting
```

---

## Step 2: Distances traveled until meeting

When `slow == fast`:

### Slow pointer

Moves **1 step per iteration**

```
distance_slow = x + k
```

### Fast pointer

Moves **2 steps per iteration**

```
distance_fast = 2(x + k)
```

---

## Step 3: Use the meeting condition

Fast laps slow by an **integer number of cycles**.

So the extra distance covered by fast must be a multiple of the cycle length:

```
distance_fast − distance_slow = m · c
```

Substitute values:

```
2(x + k) − (x + k) = m · c
x + k = m · c
```

📌 **This is the key equation.**

---

## Step 4: Rearranging the equation

From:

```
x + k = m · c
```

We get:

```
x = m · c − k
```

Taking modulo `c`:

```
x ≡ −k (mod c)
```

Which means:

```
x ≡ c − k (mod c)
```

---

## Step 5: Why resetting `slow = head` works

After meeting:

* `slow` is reset to `head`
* `fast` stays at meeting point
* Both move **1 step at a time**

### Distance to cycle start

* `slow` needs `x` steps to reach cycle start
* `fast` is `k` steps into the cycle, so needs `c − k` steps

From Step 4:

```
x = c − k
```

✅ **They arrive at the cycle start at the same time**

---

## Step 6: Why the second loop always meets at cycle start

```cpp
while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
}
```

* Same speed
* Same remaining distance
* Unique meeting point = **cycle entry**

Therefore:

```
return slow;
```

returns the **first node of the cycle**

---

## Step 7: Why `nullptr` is correct when no cycle exists

If no cycle exists:

* `fast` reaches `nullptr`
* Loop exits normally
* Condition triggers:

```cpp
if (!fast || !fast->next) return nullptr;
```

So no false positives.

---

## Final Proof Summary (interview-ready)

> Let `x` be the distance to cycle start, `c` the cycle length, and `k` the distance from cycle start to meeting point.
> At meeting, `x + k = m·c`.
> Resetting one pointer to head and moving both at equal speed causes them to meet at the cycle start since both are `x` steps away.

---

## 1-Line Memory Formula (VERY IMPORTANT)

🔥 **Remember this equation**

```
x + k = m · c
```

From that, everything follows.

---

If you want next:

* ultra-short proof for interviews (3 lines)
* ASCII diagram walkthrough
* common mistakes & edge cases
* CP-style explanation without math

Just tell me.
