Here's a detailed explanation and implementation in **C++** for the following two stack problems using recursion:

1. **Sort a Stack using Recursion**
2. **Reverse a Stack using Recursion**

These follow the **recursive approach taught by Aditya Verma** on YouTube.

---

## ✅ 1. Sort a Stack Using Recursion (C++)

### 🔍 Idea:

* Use recursion to pop all elements until the stack is empty.
* Then insert each popped element **at its correct position** in the sorted stack using another helper function.

---

### ✅ Code with Comments:

```cpp
#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert an element in a sorted stack
void insertSorted(stack<int> &st, int element) {
    // Base case: If stack is empty or top element is smaller or equal to element
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }

    // Remove the top element
    int temp = st.top();
    st.pop();

    // Recursive call to insert in the remaining sorted stack
    insertSorted(st, element);

    // Push the top element back after inserting the required element
    st.push(temp);
}

// Function to sort the stack using recursion
void sortStack(stack<int> &st) {
    // Base case: If stack has only one or zero elements
    if (st.empty() || st.size() == 1) return;

    // Pop the top element
    int temp = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    // Insert the popped element back in the sorted stack
    insertSorted(st, temp);
}

// Utility function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
```

---

## ✅ 2. Reverse a Stack Using Recursion (C++)

### 🔍 Idea:

* Use recursion to pop all elements until the stack is empty.
* Then insert each popped element **at the bottom** of the stack using a helper function.

---

### ✅ Code with Comments:

```cpp
// Helper function to insert element at the bottom of stack
void insertAtBottom(stack<int> &st, int element) {
    // Base case: If stack is empty, insert the element
    if (st.empty()) {
        st.push(element);
        return;
    }

    // Remove the top element
    int temp = st.top();
    st.pop();

    // Recursive call to reach bottom of stack
    insertAtBottom(st, element);

    // Push the removed elements back
    st.push(temp);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st) {
    // Base case: If stack is empty or has one element
    if (st.empty() || st.size() == 1) return;

    // Pop the top element
    int temp = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the popped element at the bottom
    insertAtBottom(st, temp);
}
```

---

## 🔁 Driver Code:

```cpp
int main() {
    stack<int> st;

    // Sample input
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack: ";
    printStack(st);

    // Sort the stack
    sortStack(st);
    cout << "Sorted Stack: ";
    printStack(st);

    // Reverse the sorted stack
    reverseStack(st);
    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
```

---

## 🧠 Time Complexity:

### Sort Stack:

* **O(N²)** — For each element, we may traverse the whole stack during insertion.

### Reverse Stack:

* **O(N²)** — Inserting at the bottom involves traversing the entire stack recursively.

---

Let me know if you want **visual traces** or a version using `vector`/custom stack class.
