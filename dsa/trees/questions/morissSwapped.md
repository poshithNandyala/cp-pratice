Sure! Let's dive into **Morris Inorder Traversal** and how it's applied in the **"Recover Binary Search Tree"** problem.

---

## 🔍 Problem Overview

In a **Binary Search Tree (BST)**, if two nodes are **swapped by mistake**, the tree no longer satisfies the BST property.

**Goal:**
Detect the two swapped nodes and return their values in **ascending order**. You are **not required to fix the tree**, only to **identify the swapped nodes**.

---

## 🧠 Why Morris Traversal?

Usually, an **inorder traversal** (which yields a **sorted list** for BSTs) helps detect violations.

But recursive or stack-based traversal uses **O(h)** memory (where h is the height of the tree).

**Morris Traversal** does it in **O(1) space** by:

* Temporarily modifying the tree (threading it).
* Traversing it without stack or recursion.
* Restoring the tree structure after traversal.

---

## 🌳 Morris Inorder Traversal: Key Idea

In a BST:

* **Inorder traversal** = left ➝ root ➝ right.
* Morris uses the **rightmost node** in the left subtree (called **inorder predecessor**) to thread back to the current node.

### Steps:

1. If the current node has no left child:

   * Visit it.
   * Move to the right child.
2. If it has a left child:

   * Find its inorder predecessor.
   * If predecessor’s right is null:

     * Point it to current (thread it).
     * Move left.
   * If predecessor’s right is current:

     * Restore the pointer (remove thread).
     * Visit current.
     * Move to the right.

---

## 🔧 BST Violation Detection Logic

During inorder traversal:

* Keep track of the **previous node** (`prev`).
* If `prev->val > curr->val`, then it's a **BST violation**.

There can be:

* **One violation** → swapped nodes are **adjacent**.
* **Two violations** → swapped nodes are **non-adjacent**.

You track:

* `first` → first node that violates the order (typically `prev`)
* `second` → current node that is out of place

---

## ✅ Code Walkthrough (C++)

```cpp
vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode *prev = nullptr, *curr = A;

    while (curr) {
        if (!curr->left) {
            if (prev && prev->val > curr->val) {
                if (!first) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = nullptr;
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }

    vector<int> res = {first->val, second->val};
    if (res[0] > res[1]) swap(res[0], res[1]);
    return res;
}
```

---

## 🧪 Example

### Input (BST with swapped nodes 2 and 3):

```
    3
   /
  1
   \
    2
```

### Inorder Traversal:

Correct BST: `1 2 3`
Swapped BST: `1 3 2` ➝ Violation: `3 > 2`

Detected: `first = 3`, `second = 2`
Output: `[2, 3]`

---

## 📊 Time and Space Complexity

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n)       |
| Space | O(1)       |

Morris Traversal touches each node a constant number of times and uses no stack or recursion.

---

## 💬 Would You Like More?

I can:

* Convert this solution to **Python or Java**.
* **Explain Morris Traversal** from scratch with visuals.
* Show **how the tree is threaded and unthreaded**.
* Help you write **unit tests** for it.

Let me know how you'd like to proceed!
