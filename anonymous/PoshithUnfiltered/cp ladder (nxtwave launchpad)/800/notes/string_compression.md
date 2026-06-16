# String Compression (Remove Consecutive Duplicates)

## Problem

Given a string, compress every consecutive block of the same character into a single character.

Example:

Input:
00111000111000

Blocks:
00 | 111 | 000 | 111 | 000

Output:
01010

---

## Key Observation

A new character should be added to the answer only when it is different from the previous character.

Example:

String:
00111000111000

Start:
ans = "0"

Next character:
0 == previous 0
Skip

Next character:
1 != previous 0
Add 1

ans = "01"

Next character:
1 == previous 1
Skip

Next character:
1 == previous 1
Skip

Next character:
0 != previous 1
Add 0

ans = "010"

Continue similarly.

Final answer:
01010

---

## Code

```cpp
string ans;

ans.push_back(s[0]);

for(int i = 1; i < s.size(); i++) {
    if(s[i] != s[i - 1]) {
        ans.push_back(s[i]);
    }
}
```

---

## Why Does This Work?

For every position i:

Compare:

s[i]
with
s[i - 1]

Case 1:

s[i] == s[i - 1]

Example:

111

Current character belongs to the same block.

Do not add it.

---

Case 2:

s[i] != s[i - 1]

Example:

000111

At the first '1':

1 != 0

A new block starts.

Add it to answer.

---

## Dry Run

s = "00111000111000"

Initially:

ans = "0"

i=1:
0 == 0
Skip

i=2:
1 != 0
ans = "01"

i=3:
1 == 1
Skip

i=4:
1 == 1
Skip

i=5:
0 != 1
ans = "010"

i=8:
1 != 0
ans = "0101"

i=11:
0 != 1
ans = "01010"

Final:
01010

---

## Edge Cases

s = "0000"
Output: "0"

s = "1111"
Output: "1"

s = "01010"
Output: "01010"

s = "1"
Output: "1"

s = "0"
Output: "0"

---

## Template

```cpp
string compress(string s) {
    string ans;

    ans.push_back(s[0]);

    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i - 1]) {
            ans.push_back(s[i]);
        }
    }

    return ans;
}
```

Time Complexity: O(n)

Space Complexity: O(n)

```
```
