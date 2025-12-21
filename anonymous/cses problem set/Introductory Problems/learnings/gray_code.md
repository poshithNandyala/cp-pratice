
# Gray Code — Clear Explanation and Recursive Generation

## 1. What Is Gray Code?

**Gray Code** is a sequence of binary strings of length `n` such that:

- There are exactly `2ⁿ` strings.
- Each consecutive string differs from the previous one by **exactly one bit**.
- This one-bit difference is known as **Hamming Distance = 1**.

### Example (n = 2)
```

00 → 01 → 11 → 10

```
Each step changes only one bit.

---

## 2. Why Gray Code Is Important

Gray Code is widely used in hardware and digital systems because it minimizes errors during state transitions.

### Key Advantages

1. **Reduces Transition Errors**
   - In normal binary counting, multiple bits can change at once.
   - In Gray Code, only one bit changes, reducing ambiguity and noise.
   - This is critical in **analog-to-digital converters** and sensors.

2. **Simplifies Logic Design**
   - Fewer bit changes lead to simpler and more reliable circuits.

3. **Saves Power**
   - Changing fewer bits means less switching activity, reducing power consumption.

---

## 3. Gray Code Examples

### n = 1
```

0
1

```

### n = 2
```

00
01
11
10

```

### n = 3
```

000
001
011
010
110
111
101
100

```
# Gray Code — Clear Explanation and Recursive Generation

## 1. What is Gray Code?

**Gray Code** is a list of binary strings of length `n` with the following properties:

- There are exactly $2^n$ strings.
- Each consecutive string differs from the previous one by exactly one bit (Hamming distance = 1).

### Example (n = 2)

```

00 → 01 → 11 → 10

```

---

## 2. Why Gray Code matters

Gray Code is widely used in hardware and digital systems because it minimizes errors during state transitions.

### Key advantages

- **Reduces transition errors**: normal binary counting may flip multiple bits; Gray Code flips only one bit.
- **Simplifies logic design**: fewer simultaneous transitions make circuits more reliable.
- **Saves power**: fewer bit changes reduce switching activity.

---

## 3. Examples

### n = 1

```

0
1

```

### n = 2

```

00
01
11
10

```

### n = 3

```

000
001
011
010
110
111
101
100

```

Only one bit changes between consecutive codes in each list above.

---

## 4. Reflective (mirror) construction

An elegant way to generate Gray Code for `n` bits uses reflection:

1. Start with the Gray Code list for `n-1` bits.
2. Create a mirrored (reversed) copy of that list.
3. Prefix `0` to every code in the original list.
4. Prefix `1` to every code in the mirrored list.
5. Concatenate the two lists — this is the Gray Code for `n` bits.

---

## 5. Construction examples

### Build `n = 2` from `n = 1`

Original (`n=1`):

```

0
1

```

Mirrored:

```

1
0

```

Prefix `0` to original and `1` to mirrored, then concatenate:

```

00
01
11
10

```

### Build `n = 3` from `n = 2`

Original (`n=2`):

```

00
01
11
10

```

Mirrored:

```

10
11
01
00

```

Prefix `0` / `1` and concatenate:

```

000
001
011
010
110
111
101
100

```

---

## 6. Recursive algorithm (conceptual)

1. If `n == 1`, return `["0", "1"]`.
2. Recursively generate Gray Code for `n-1`.
3. Let `L` be that list and `R` be `reverse(L)`.
4. Return `['0'+x for x in L] + ['1'+x for x in R]`.

This produces the reflective Gray Code sequence.

---

## 7. Complexity

- Time: $O(n \\times 2^n)$ — there are $2^n$ codes of length $n$, and constructing them costs proportional to their length.
- Space: $O(2^n)$ to store the list of codes (plus an $O(n)$ recursion stack).

---

## 8. Summary

- Gray Code guarantees a one-bit change between consecutive values.
- The reflective construction is simple and efficient in practice.
- Useful in ADCs, encoders, and other systems that benefit from minimal transition errors.

---

This document presents a concise, well-formatted explanation and step-by-step construction of Gray Code.
- The **reflective property** provides a clean and intuitive way to generate Gray Codes.
```
