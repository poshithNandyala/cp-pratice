### Isomorphic Strings (LeetCode 205) — **clear intuition + clean C++**

#### 🔹 Problem in simple words

Two strings `s` and `t` are **isomorphic** if:

* Each character in `s` can be replaced to get `t`
* **One-to-one mapping** (no two chars map to the same char)
* Order must be preserved

👉 Characters map, **not values**.

---

### 🔹 Key Idea (easy to remember)

You must ensure **both directions** of mapping are consistent:

* `s → t` (forward mapping)
* `t → s` (reverse mapping)

Why both?

* To avoid cases like `a → b` and `c → b` (invalid)

---

### ❌ Example (NOT isomorphic)

```
s = "foo"
t = "bar"

f → b
o → a
o → r   ❌ conflict (same char maps to two different chars)
```

---

### ✅ Example (isomorphic)

```
s = "egg"
t = "add"

e → a
g → d
```

---

## ✅ Correct C++ Solution (Most Standard)

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mp1, mp2;

        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];

            if (mp1.count(a) && mp1[a] != b) return false;
            if (mp2.count(b) && mp2[b] != a) return false;

            mp1[a] = b;
            mp2[b] = a;
        }
        return true;
    }
};
```

---

### 🧠 How to **remember logic** (exam / interview trick)

Think:

> “If I replace characters in **both directions**, result should stay consistent.”

Or shorter:

> **Mapping must be reversible**

---

### ⏱️ Complexity

* **Time:** `O(n)`
* **Space:** `O(1)` (at most 256 chars)

---

### 🔥 One-liner intuition

> Two strings are isomorphic if **their pattern structure is identical**.

If you want:

* **Array-based version**
* **Python version**
* **Pattern-encoding trick (very cool)**
* **Edge-case walkthrough**

Just tell me 👍
