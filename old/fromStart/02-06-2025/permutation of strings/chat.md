Below is a step-by-step breakdown of how to generate **all permutations** of a given string in **lexicographical order** using **recursion** (backtracking), but implemented in C++. After the detailed explanation, you’ll find a full C++ solution and, finally, an illustrated recursion tree (using a simple example) to show exactly how the algorithm “walks” through all possibilities.

---

## 1. High-Level Idea

1. **Sort the input string** so that we start from the smallest lexicographical arrangement.
2. Use a **recursive/backtracking** function that builds a partial permutation (“path”) one character at a time.
3. Maintain a boolean array (`used[]`) of length *N* to mark which positions (in the sorted array of characters) have already been picked in the current path.
4. At each recursion level, loop over all indices `i = 0 … N−1`, and:

   * If `used[i]` is `true`, skip it (already included in this path).
   * If `i > 0` and `s[i] == s[i−1]` but `used[i−1] == false`, skip it to **avoid generating the same permutation twice** (this is the classic “duplicate-skip” rule).
   * Otherwise, mark `used[i] = true`, append `s[i]` to the path, recurse deeper, then backtrack (undo, mark `used[i] = false`).
5. Whenever the “path” has length *N*, we have a full permutation; print it (or store it).

Because the source string is sorted at the very beginning, and because we only ever pick characters in increasing index order (subject to skipping duplicates), each complete permutation will be output in **lexicographical order**.

---

## 2. Detailed Intuition & Pseudocode

Let’s say the input is `"bca"`. First, we sort it to `"abc"`.

* We maintain:

  * `vector<bool> used(N, false)`
  * A temporary buffer (e.g. `string path;`) that we build up character by character.
  * A container (e.g. `vector<string> result;`) to accumulate completed permutations.

### 2.1 Recursion Signature

```cpp
void backtrack(const string &s,
               vector<bool> &used,
               string &path,
               vector<string> &result);
```

* **Parameters**:

  * `s` — the sorted input (e.g. `"abc"`)
  * `used[i]` — whether the character at index `i` of `s` is already in the current `path`
  * `path` — current partial permutation (initially empty)
  * `result` — list of all complete permutations (accumulate when `path.size() == N`)

### 2.2 Core Recursion Logic

1. **Base Case**
   If `path.size() == s.size()`:

   ```cpp
   result.push_back(path);
   return;
   ```

2. **For loop over all indices**

   ```cpp
   for (int i = 0; i < (int)s.size(); ++i) {
       if (used[i]) 
           continue;  
       // Duplicate‐skip: if this is the “same character as before” 
       // but that previous copy has not yet been used in this level of recursion,
       // then picking s[i] now would generate the same permutation as picking s[i−1] earlier.
       if (i > 0 && s[i] == s[i-1] && !used[i-1])
           continue;

       // Choose s[i]:
       used[i] = true;
       path.push_back(s[i]);

       backtrack(s, used, path, result);

       // Undo choice (backtrack):
       path.pop_back();
       used[i] = false;
   }
   ```

Because we sorted `s` at the start, whenever `s[i] == s[i−1]`, the first copy will be considered before the second. By checking `!used[i−1]`, we ensure that at any given recursion “layer,” we only pick one of the identical characters in that position in the path—thus eliminating duplicate permutations.

---

## 3. Full C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Generates all permutations of a string in lexicographical order.
 * - Sorts the string first.
 * - Uses backtracking with a 'used' array to track which characters are in the current path.
 * - Skips duplicates by checking (i > 0 && s[i] == s[i-1] && !used[i-1]).
 */
class Solution {
public:
    vector<string> permuteLex(string s) {
        int n = s.size();
        sort(s.begin(), s.end());              // 1) Sort to start in lex order
        vector<bool> used(n, false);            // 2) Track which indices are used
        vector<string> result;
        string path;
        backtrack(s, used, path, result);
        return result;
    }

private:
    void backtrack(const string &s,
                   vector<bool> &used,
                   string &path,
                   vector<string> &result) {
        // Base case: if path length == s length, we have a full permutation
        if ((int)path.size() == (int)s.size()) {
            result.push_back(path);
            return;
        }

        // Try to place each character s[i] that is not used yet
        for (int i = 0; i < (int)s.size(); ++i) {
            if (used[i]) 
                continue;

            // If s[i] is the same as the previous character, and the previous
            // one has not been used in this recursion level, we skip to avoid duplicates.
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
                continue;

            // Choose s[i]:
            used[i] = true;
            path.push_back(s[i]);

            // Recurse deeper
            backtrack(s, used, path, result);

            // Backtrack
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cout << "Enter string: ";
    cin >> input;

    Solution sol;
    vector<string> perms = sol.permuteLex(input);

    cout << "All permutations in lexicographical order:\n";
    for (auto &p : perms) {
        cout << p << "\n";
    }
    return 0;
}
```

**Key points in the code**:

* We sort the string at the very beginning (`sort(s.begin(), s.end())`).
* We maintain `vector<bool> used` to mark which characters have already been “placed” in the current partial permutation.
* The **duplicate-skip check**

  ```cpp
  if (i > 0 && s[i] == s[i-1] && !used[i-1])
      continue;
  ```

  ensures that if you have two identical characters next to each other in the sorted array, you only use the “first” copy at that particular level of recursion. Otherwise, you’d generate the same exact permutation twice—once by picking index `i`, once by picking index `i−1`, when both hold the same letter.

---

## 4. Detailed Recursion Tree Example

Let’s build a complete recursion tree for the input `"bca"`. After sorting, `s = "abc"`. We’ll show how the algorithm explores each branch, step by step. Whenever we “choose” a character, we mark it as used and go one level deeper, then eventually backtrack.

---

### 4.1 Setup

* **Sorted string**: `s = ['a', 'b', 'c']`
* `used = [false, false, false]` initially
* `path = ""` initially

---

### 4.2 Level 0 (root)

```
path = ""
used = [F, F, F]   (F = false)
```

At this topmost level, the loop `for i in [0..2]` tries:

1. **i = 0** → pick `'a'`
2. **i = 1** → pick `'b'`
3. **i = 2** → pick `'c'`

We will expand each choice in turn.

---

### 4.3 Level 1

#### 4.3.1 Branch A: pick i = 0 → `'a'`

* Now:

  ```
  path = "a"
  used = [T, F, F]
  ```
* Next loop at this level (for Level 2) tries i = 0..2, but `i = 0` is skipped since `used[0] == true`. So we try:

  * **i = 1** → pick `'b'`
  * **i = 2** → pick `'c'`

  ##### 4.3.1.1 Branch A1: from "a", pick i = 1 → `'b'`

* Now:

  ```
  path = "ab"
  used = [T, T, F]
  ```
* Next (Level 3) tries i = 0..2, but `i=0,1` are used. So only `i = 2` → pick `'c'`.

   ###### 4.3.1.1.1 Branch A1a: from "ab", pick i = 2 → `'c'`

* Now:

  ```
  path = "abc"
  used = [T, T, T]
  ```

* Since `path.size() == 3` (the string length), we record `"abc"`.

* Then backtrack: un‐choose `'c'`:

  ```
  path = "ab"
  used = [T, T, F]
  ```

* Backtracker returns to Level 2 under branch (A1).

* Backtracking at Level 2: pop `'b'` →

  ```
  path = "a"
  used = [T, F, F]
  ```

  ##### 4.3.1.2 Branch A2: from "a", pick i = 2 → `'c'`

* Now:

  ```
  path = "ac"
  used = [T, F, T]
  ```
* Next (Level 3) tries only `i = 1` (since 0 & 2 are used): pick `'b'`.

   ###### 4.3.1.2.1 Branch A2a: from "ac", pick i = 1 → `'b'`

* Now:

  ```
  path = "acb"
  used = [T, T, T]
  ```

* Record `"acb"`.

* Backtrack → un‐choose `'b'`:

  ```
  path = "ac"
  used = [T, F, T]
  ```

* Backtrack further: un‐choose `'c'` →

  ```
  path = "a"
  used = [T, F, F]
  ```

* Done exploring all choices under "a". Backtrack to Level 1: un‐choose `'a'` →

  ```
  path = ""
  used = [F, F, F]
  ```

#### 4.3.2 Branch B: pick i = 1 → `'b'`

* Now:

  ```
  path = "b"
  used = [F, T, F]
  ```
* Level 2 loop (i = 0..2) tries:

  * **i = 0** → `'a'`
  * **i = 1** is skipped (used)
  * **i = 2** → `'c'`

  ##### 4.3.2.1 Branch B1: from "b", pick i = 0 → `'a'`

* Now:

  ```
  path = "ba"
  used = [T, T, F]
  ```
* Level 3: only i = 2 → `'c'`.

   ###### 4.3.2.1.1 Branch B1a: from "ba", pick i = 2 → `'c'`

* Now:

  ```
  path = "bac"
  used = [T, T, T]
  ```
* Record `"bac"`.
* Backtrack: un‐choose `'c'` →

  ```
  path = "ba"
  used = [T, T, F]
  ```
* Backtrack: un‐choose `'a'` →

  ```
  path = "b"
  used = [F, T, F]
  ```

  ##### 4.3.2.2 Branch B2: from "b", pick i = 2 → `'c'`

* Now:

  ```
  path = "bc"
  used = [F, T, T]
  ```
* Level 3: only i = 0 → `'a'`.

   ###### 4.3.2.2.1 Branch B2a: from "bc", pick i = 0 → `'a'`

* Now:

  ```
  path = "bca"
  used = [T, T, T]
  ```

* Record `"bca"`.

* Backtrack: un‐choose `'a'` →

  ```
  path = "bc"
  used = [F, T, T]
  ```

* Backtrack: un‐choose `'c'` →

  ```
  path = "b"
  used = [F, T, F]
  ```

* Finished with "b". Backtrack: un‐choose `'b'` →

  ```
  path = ""
  used = [F, F, F]
  ```

#### 4.3.3 Branch C: pick i = 2 → `'c'`

* Now:

  ```
  path = "c"
  used = [F, F, T]
  ```
* Level 2 loop tries:

  * i = 0 → `'a'`
  * i = 1 → `'b'`
  * i = 2 skipped

  ##### 4.3.3.1 Branch C1: from "c", pick i = 0 → `'a'`

* Now:

  ```
  path = "ca"
  used = [T, F, T]
  ```
* Level 3: only i = 1 → `'b'`.

   ###### 4.3.3.1.1 Branch C1a: from "ca", pick i = 1 → `'b'`

* Now:

  ```
  path = "cab"
  used = [T, T, T]
  ```
* Record `"cab"`.
* Backtrack: un‐choose `'b'` →

  ```
  path = "ca"
  used = [T, F, T]
  ```
* Backtrack: un‐choose `'a'` →

  ```
  path = "c"
  used = [F, F, T]
  ```

  ##### 4.3.3.2 Branch C2: from "c", pick i = 1 → `'b'`

* Now:

  ```
  path = "cb"
  used = [F, T, T]
  ```
* Level 3: only i = 0 → `'a'`.

   ###### 4.3.3.2.1 Branch C2a: from "cb", pick i = 0 → `'a'`

* Now:

  ```
  path = "cba"
  used = [T, T, T]
  ```
* Record `"cba"`.
* Backtrack: un‐choose `'a'` →

  ```
  path = "cb"
  used = [T, T, T]  (actually [T, T, T], but then we unset a moment later)
  ```
* Backtrack: un‐choose `'b'` →

  ```
  path = "c"
  used = [F, F, T]
  ```
* Backtrack: un‐choose `'c'` →

  ```
  path = ""
  used = [F, F, F]
  ```
* END.

---

### 4.4 Final List (in the exact order they were recorded)

1. `"abc"`
2. `"acb"`
3. `"bac"`
4. `"bca"`
5. `"cab"`
6. `"cba"`

Because we sorted `"bca"` → `"abc"` at the start, and then always picked characters in increasing‐index order (with the duplicate‐skip guard), we naturally generate them in **lexicographical order**.

---

## 5. ASCII-Style View of the Recursion Tree

Below is a more compact, indented, ASCII-style representation of that same tree. Each level shows:

* Which character got appended to `path` at that stage.
* The partial `path` built so far.
* Which indices remain available.

```
Level 0 (path = "")
│
├── i=0: pick 'a'   → path = "a"
│   ├── i=1: pick 'b' → path = "ab"
│   │   └── i=2: pick 'c' → path = "abc"   [record "abc"]
│   └── backtrack to path="a"
│   └── i=2: pick 'c' → path = "ac"
│       └── i=1: pick 'b' → path = "acb"   [record "acb"]
│   └── backtrack to path=""
│
├── i=1: pick 'b'   → path = "b"
│   ├── i=0: pick 'a' → path = "ba"
│   │   └── i=2: pick 'c' → path = "bac"   [record "bac"]
│   └── backtrack to path="b"
│   └── i=2: pick 'c' → path = "bc"
│       └── i=0: pick 'a' → path = "bca"   [record "bca"]
│   └── backtrack to path=""
│
└── i=2: pick 'c'   → path = "c"
    ├── i=0: pick 'a' → path = "ca"
    │   └── i=1: pick 'b' → path = "cab"   [record "cab"]
    └── backtrack to path="c"
    └── i=1: pick 'b' → path = "cb"
        └── i=0: pick 'a' → path = "cba"   [record "cba"]
    └── backtrack to path=""
```

At the bottom of each branch where `path.length() == 3`, we record a complete permutation, then “pop back” one level at a time until all branches are exhausted.

---

## 6. Summary

1. **Sorting upfront** guarantees that the very first leaf we reach is `"abc"`, then `"acb"`, and so on, producing a lex-ordered list of permutations.
2. The **`used[]` array** enforces “each character only once per path.”
3. The **duplicate-skip check**

   ```cpp
   if (i>0 && s[i]==s[i-1] && !used[i-1])
       continue;
   ```

   guarantees that, if there are any repeated letters, we don’t generate the same permutation more than once.
4. The **recursion tree** above makes it crystal-clear how each character is chosen level by level, and how we eventually backtrack to explore all possible branches.

You can copy the C++ code into your favorite editor, compile with `g++ filename.cpp -std=c++17 -O2`, and run. It will print every permutation in lexicographical order.

If you have any follow-up questions—e.g., how this changes if you need to *print to stdout immediately* instead of collecting into a `vector<string>`, or if you want to handle extremely long strings without using `vector<string>`—just let me know!
