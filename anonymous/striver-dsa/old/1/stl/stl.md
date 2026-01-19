```markdown
## Introduction to C++ STL

The **C++ Standard Template Library (STL)** is a collection of pre-built components that simplify programming by providing ready-made **algorithms**, **containers**, **iterators**, and **functions**. It allows developers to focus on problem-solving rather than implementing common data structures and algorithms from scratch.

---

## Skeleton of a C++ Program

A basic C++ program structure looks like this:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here
    return 0;
}
```

### Key Components

1. **`#include <bits/stdc++.h>`**:
   - Includes all standard C++ libraries.
   - Commonly used in competitive programming for convenience.
   - For larger projects, include only the necessary headers for faster compilation.

2. **`using namespace std;`**:
   - Brings all names from the `std` namespace into the current scope.
   - Allows using `cout`, `cin`, `vector`, etc., without the `std::` prefix.
   - Avoid in larger projects to prevent name collisions.

3. **`int main()`**:
   - The entry point of the program.
   - `return 0;` indicates successful execution.

---

## Functions in C++

### Void Functions

A function that **does not return any value**.

```cpp
void printName() {
    cout << "Raj" << endl;
}

int main() {
    printName(); // Output: Raj
    return 0;
}
```

### Return Type Functions

A function that **returns a value**.

```cpp
int sum(int a, int b) {
    return a + b;
}

int main() {
    int s = sum(1, 5); // s = 6
    cout << s << endl; // Output: 6
    return 0;
}
```

---

## Components of C++ STL

The STL is divided into four main components:

1. **Algorithms**: Functions for sorting, searching, etc.
2. **Containers**: Data structures like vectors, lists, sets, maps, etc.
3. **Functions**: Callable entities like function objects (functors).
4. **Iterators**: Objects to traverse containers.

---

## Pairs

A **pair** stores exactly two elements, which can be of different types.

### Declaration and Initialization

```cpp
pair<int, int> p = {1, 3};
```

### Accessing Elements

```cpp
cout << p.first << endl; // Output: 1
cout << p.second << endl; // Output: 3
```

### Nested Pairs

```cpp
pair<int, pair<int, int>> nested_p = {1, {3, 4}};
cout << nested_p.first << endl;         // Output: 1
cout << nested_p.second.first << endl;  // Output: 3
cout << nested_p.second.second << endl; // Output: 4
```

### Pair Arrays

```cpp
pair<int, string> arr[] = {{101, "Alice"}, {102, "Bob"}, {103, "Charlie"}};
cout << arr[1].first << " " << arr[1].second << endl; // Output: 102 Bob
```

---

## Vectors

A **vector** is a dynamic array that can grow or shrink in size.

### Declaration

```cpp
vector<int> v;          // Empty vector of integers
vector<double> v_double; // Empty vector of doubles
vector<string> v_string; // Empty vector of strings
```

### Adding Elements

```cpp
v.push_back(1); // Adds 1 to the end
v.emplace_back(2); // Adds 2 to the end (more efficient)
```

### Accessing Elements

```cpp
cout << v[0] << endl; // Access using index
cout << v.at(0) << endl; // Access with bounds checking
```

### Iterators

```cpp
vector<int>::iterator it = v.begin(); // Points to the first element
cout << *it << endl; // Dereference to access value
it++; // Move to the next element
```

### Printing a Vector

```cpp
for (int x : v) {
    cout << x << " ";
}
```

### Deletion

```cpp
v.erase(v.begin() + 1); // Removes the second element
v.erase(v.begin(), v.begin() + 2); // Removes the first two elements
```

### Insertion

```cpp
v.insert(v.begin(), 300); // Inserts 300 at the beginning
v.insert(v.begin() + 1, 2, 100); // Inserts two 100s at position 1
```

### Other Functions

- `v.size()`: Returns the number of elements.
- `v.pop_back()`: Removes the last element.
- `v.clear()`: Removes all elements.
- `v.empty()`: Checks if the vector is empty.

---

## Summary

This document provides a structured overview of the **C++ STL** and its components, focusing on **pairs** and **vectors**. Practice these concepts to build a strong foundation in C++ programming.

```

```markdown
### List

A **list** in C++ STL is a sequential container implemented as a **doubly linked list**. It is dynamic in nature and provides efficient insertion and deletion at any position.

#### Key Features
- **Efficient Front Operations**:
    - `push_front(element)`: Adds an element to the **beginning** of the list.
    - `emplace_front(element)`: Constructs and adds an element at the **beginning** of the list.
- **Efficient Insertion/Deletion**:
    - Insertion and deletion at any position are efficient (constant time) if you have an iterator to the position.
- **Inefficient Random Access**:
    - Accessing elements by index is slower (linear time) compared to vectors.

#### Example
```cpp
#include <list>
#include <iostream>
using namespace std;

int main() {
        list<int> lst = {1, 2, 3};
        lst.push_front(0); // Adds 0 to the front
        lst.push_back(4);  // Adds 4 to the back

        for (int x : lst) {
                cout << x << " "; // Output: 0 1 2 3 4
        }
        return 0;
}
```

#### Common Functions

- `push_back(element)`: Adds an element to the end.
- `pop_back()`: Removes the last element.
- `push_front(element)`: Adds an element to the beginning.
- `pop_front()`: Removes the first element.
- `insert(iterator, element)`: Inserts an element at the specified position.
- `erase(iterator)`: Removes the element at the specified position.
- `size()`: Returns the number of elements.
- `clear()`: Removes all elements.
- `empty()`: Checks if the list is empty.

---

### Deque (Double-Ended Queue)

A **deque** is a container that allows efficient insertion and deletion at both the front and the back. It combines features of both vectors and lists.

#### Key Features

- **Efficient Front and Back Operations**:
  - `push_front(element)`: Adds an element to the front.
  - `push_back(element)`: Adds an element to the back.
  - `pop_front()`: Removes the front element.
  - `pop_back()`: Removes the back element.
- **Random Access**:
  - Supports random access using `[]` or `at()`.

#### Example

```cpp
#include <deque>
#include <iostream>
using namespace std;

int main() {
        deque<int> dq = {2, 3};
        dq.push_front(1); // Adds 1 to the front
        dq.push_back(4);  // Adds 4 to the back

        for (int x : dq) {
                cout << x << " "; // Output: 1 2 3 4
        }
        return 0;
}
```

#### Common Functions

- `push_back(element)`, `push_front(element)`: Add elements to the back/front.
- `pop_back()`, `pop_front()`: Remove elements from the back/front.
- `front()`, `back()`: Access the first/last element.
- `size()`, `clear()`, `empty()`: Work similarly to other containers.

---

### Stack

A **stack** is a container that follows the **LIFO (Last-In, First-Out)** principle. The last element added is the first to be removed.

#### Key Features

- **No Random Access**:
  - Only the top element can be accessed.
- **Efficient Operations**:
  - All operations (`push`, `pop`, `top`) are constant time.

#### Example

```cpp
#include <stack>
#include <iostream>
using namespace std;

int main() {
        stack<int> s;
        s.push(1); // Pushes 1 onto the stack
        s.push(2); // Pushes 2 onto the stack

        cout << s.top() << endl; // Output: 2
        s.pop(); // Removes the top element (2)
        cout << s.top() << endl; // Output: 1
        return 0;
}
```

#### Common Functions

- `push(element)`: Adds an element to the top.
- `pop()`: Removes the top element.
- `top()`: Returns the top element.
- `size()`, `empty()`: Work similarly to other containers.

---

### Queue

A **queue** is a container that follows the **FIFO (First-In, First-Out)** principle. The first element added is the first to be removed.

#### Key Features

- **No Random Access**:
  - Only the front and back elements can be accessed.
- **Efficient Operations**:
  - All operations (`push`, `pop`, `front`, `back`) are constant time.

#### Example

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
        queue<int> q;
        q.push(1); // Adds 1 to the queue
        q.push(2); // Adds 2 to the queue

        cout << q.front() << endl; // Output: 1
        q.pop(); // Removes the front element (1)
        cout << q.front() << endl; // Output: 2
        return 0;
}
```

#### Common Functions

- `push(element)`: Adds an element to the back.
- `pop()`: Removes the front element.
- `front()`, `back()`: Access the front/back element.
- `size()`, `empty()`: Work similarly to other containers.

---

### Priority Queue

A **priority queue** is a container where elements are ordered by priority. By default, it is implemented as a **max-heap** (largest element has the highest priority).

#### Key Features

- **Max-Heap by Default**:
  - The largest element is at the top.
- **Min-Heap**:
  - Use `priority_queue<int, vector<int>, greater<int>>` for a min-heap.

#### Example

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
        priority_queue<int> pq;
        pq.push(3); // Adds 3
        pq.push(1); // Adds 1
        pq.push(4); // Adds 4

        cout << pq.top() << endl; // Output: 4
        pq.pop(); // Removes the top element (4)
        cout << pq.top() << endl; // Output: 3
        return 0;
}
```

#### Common Functions

- `push(element)`: Adds an element while maintaining the heap property.
- `pop()`: Removes the top element.
- `top()`: Returns the top element.
- `size()`, `empty()`: Work similarly to other containers.

---

### Set

A **set** is a container that stores **unique elements** in **sorted order**.

#### Key Features

- **Unique Elements**:
  - Duplicate elements are not allowed.
- **Sorted Order**:
  - Elements are stored in ascending order by default.

#### Example

```cpp
#include <set>
#include <iostream>
using namespace std;

int main() {
        set<int> s = {3, 1, 4};
        s.insert(2); // Adds 2
        s.insert(3); // Duplicate, not added

        for (int x : s) {
                cout << x << " "; // Output: 1 2 3 4
        }
        return 0;
}
```

#### Common Functions

- `insert(element)`: Adds an element.
- `erase(value)`: Removes an element by value.
- `find(value)`: Returns an iterator to the element or `end()` if not found.
- `size()`, `empty()`, `clear()`: Work similarly to other containers.
- `lower_bound(value)`, `upper_bound(value)`: Find ranges of elements.

---

### Multiset

A **multiset** is similar to a set but allows **duplicate elements**.

#### Key Features

- **Duplicates Allowed**:
  - Multiple occurrences of the same value are allowed.
- **Sorted Order**:
  - Elements are stored in ascending order.

#### Example

```cpp
#include <set>
#include <iostream>
using namespace std;

int main() {
        multiset<int> ms = {3, 1, 3};
        ms.insert(2); // Adds 2
        ms.insert(3); // Adds another 3

        for (int x : ms) {
                cout << x << " "; // Output: 1 2 3 3 3
        }
        return 0;
}
```

#### Common Functions

- `insert(element)`: Adds an element.
- `erase(value)`: Removes all occurrences of a value.
- `count(value)`: Returns the number of occurrences of a value.
- `size()`, `empty()`, `clear()`: Work similarly to other containers.

---

### Unordered Set

An **unordered set** is a container that stores **unique elements** without any specific order. It uses a **hash table** for fast operations.

#### Key Features

- **No Sorted Order**:
  - Elements are stored in arbitrary order.
- **Fast Operations**:
  - Average time complexity for insertion, deletion, and search is **O(1)**.

#### Example

```cpp
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
        unordered_set<int> us = {3, 1, 4};
        us.insert(2); // Adds 2
        us.insert(3); // Duplicate, not added

        for (int x : us) {
                cout << x << " "; // Output: 3 1 4 2 (order may vary)
        }
        return 0;
}
```

#### Common Functions

- `insert(element)`: Adds an element.
- `erase(value)`: Removes an element by value.
- `find(value)`: Returns an iterator to the element or `end()` if not found.
- `size()`, `empty()`, `clear()`: Work similarly to other containers.

---

```

### Map

A **map** is a container that stores **key-value pairs**, where each **key is unique** and the map keeps the key-value pairs **sorted based on the keys**.

#### Declaration
```cpp
map<int, string> m;      // Key is int, value is string
map<string, int> m2;     // Key is string, value is int
map<int, pair<int, int>> m3; // Key is int, value is a pair of ints
map<pair<int, int>, int> m4; // Key is a pair of ints, value is int
```

#### Insertion

```cpp
// Using [] operator
map<int, int> m;
m[1] = 2; // Inserts or updates key 1 with value 2
m[3] = 1; // Inserts key 3 with value 1

// Using insert()
m.insert({2, 4}); // Inserts key-value pair {2, 4}

// Using emplace()
m.emplace(4, 5); // Constructs pair in place
```

#### Iteration

```cpp
map<int, int> m = {{1, 2}, {2, 4}, {3, 1}};

// Using iterator
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " => " << it->second << '\n';
}

// Using range-based for loop
for (const auto& [key, val] : m) {
    cout << key << " => " << val << '\n';
}
```

#### Accessing Values

```cpp
map<int, int> m = {{1, 2}};
cout << m[1] << '\n';  // Access existing key
cout << m[5] << '\n';  // Creates new key with default value

// Using find()
auto it = m.find(3);
if (it != m.end()) {
    cout << "Value: " << it->second << '\n';
}
```

### Multimap

- Allows duplicate keys
- Maintains sorted order
- No [] operator support
- Use insert(), emplace() for insertion
- Use equal_range(), lower_bound(), upper_bound() for searching

### Unordered Map

```cpp
unordered_map<int, string> um;
```

- No sorted order
- O(1) average time complexity
- Same interface as map except no lower/upper bound

### Algorithms

#### Sort

```cpp
// Array sort
int a[] = {3, 1, 4, 2};
sort(a, a + 4);

// Vector sort
vector<int> v = {3, 1, 4, 2};
sort(v.begin(), v.end());

// Descending order
sort(v.begin(), v.end(), greater<int>());

// Custom comparator
bool comparePairs(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first > p2.first;
}
```

#### Bit Operations

```cpp
int n = 7;
int bits32 = __builtin_popcount(n);    // For 32-bit int
long long bits64 = __builtin_popcountll(n); // For 64-bit long long
```

#### Permutations

```cpp
string s = "123";
sort(s.begin(), s.end());
do {
    cout << s << '\n';
} while (next_permutation(s.begin(), s.end()));
```

#### Min/Max Elements

```cpp
vector<int> v = {1, 8, 5, 6};
auto max_it = max_element(v.begin(), v.end());
auto min_it = min_element(v.begin(), v.end());
cout << "Max: " << *max_it << ", Min: " << *min_it << '\n';
```
