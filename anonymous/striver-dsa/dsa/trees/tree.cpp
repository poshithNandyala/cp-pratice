#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct  Tree {
    TreeNode* root;
    Tree() {
        root = nullptr;
    }
    void populateTree() {
        cout << "Enter the root value: ";
        int x;
        cin >> x;
        root = new TreeNode(x);
        populate(root);
    }
    void populate(TreeNode* root) {
        cout << "Enter the left child of " << root->val << " : ";
        int x;
        cin >> x;
        if (x != -1) {
            root->left = new TreeNode(x);
            populate(root->left);
        }
        cout << "Enter the right child of " << root->val << " : ";
        cin >> x;
        if (x != -1) {
            root->right = new TreeNode(x);
            populate(root->right);
        }
    }

    void displayTree(TreeNode* root, string indent = "") {
        // Base case: if root is null, return as there's nothing to display
        if (root == nullptr) {
            return;
        }

        // Print the current node's value with the current indentation level
        // indent determines how much spacing to add before printing the value
        // This creates a visual representation of the tree structure
        cout << indent << root->val << endl;

        // Recursively display left subtree
        // Add more indentation (4 spaces) for each level deeper in the tree
        // This makes child nodes appear indented under their parent
        displayTree(root->left, "    " + indent);

        // Recursively display right subtree
        // Same indentation rules apply as with left subtree
        // This ensures right children are aligned with their left siblings
        displayTree(root->right, "    " + indent);
    }

    void prettydisplay(TreeNode* root, int level = 0) {
        if (root == nullptr) {
            return;
        }
        prettydisplay(root->right, level + 1);
        if (level != 0) {
            for (int i = 0; i < level - 1; i++) {
                cout << "|    ";
            }
            cout << "|------>" << root->val << endl;
        }

        else {
            cout << root->val << endl;
        }
        prettydisplay(root->left, level + 1);
    }


        // Memoization map to store heights of subtrees
        unordered_map<TreeNode*, int> heightCache;

        // Get height with memoization to avoid recalculating heights of same subtrees
        int getHeight(TreeNode* root) {
            if (!root) return 0;
        
            // Check if height is already calculated
            if (heightCache.find(root) != heightCache.end()) {
                return heightCache[root];
            }
        
            // Calculate and cache the height
            heightCache[root] = 1 + max(getHeight(root->left), getHeight(root->right));
            return heightCache[root];
        }

        // Recursive pretty-print function that prints tree in a visual hierarchical format
        void printTree(TreeNode* root) {
            if (!root) return;

            // Get the height of tree - now uses memoized version
            int height = getHeight(root);
        
            // Calculate dimensions of the output grid
            int rows = height * 2 - 1;  // Each level takes 2 rows (one for value, one for branches)
            int cols = (int)pow(2, height) * 3;  // Width scales with height, *3 for spacing
        
            // Initialize output grid with spaces
            vector<string> res(rows, string(cols, ' '));

            // Inner function for DFS traversal and printing
            function<void(TreeNode*, int, int, int)> dfs = [&](TreeNode* node, int row, int col, int offset) {
                if (!node) return;
            
                // Convert node value to string and calculate starting position
                string val = to_string(node->val);
                int valStart = col - val.length() / 2;
            
                // Place the node value in the grid
                for (int i = 0; i < val.length(); ++i) {
                    res[row][valStart + i] = val[i];
                }

                // Handle left child
                if (node->left) {
                    res[row + 1][col - offset] = '/';  // Draw left branch
                    dfs(node->left, row + 2, col - offset * 2, offset / 2);
                }
            
                // Handle right child
                if (node->right) {
                    res[row + 1][col + offset] = '\\';  // Draw right branch
                    dfs(node->right, row + 2, col + offset * 2, offset / 2);
                }
            };

            // Calculate initial positions
            int rootCol = cols / 2;  // Start from middle of width
            int offset = (int)pow(2, height - 2);  // Initial offset for branches
        
            // Start the recursive printing
            dfs(root, 0, rootCol, offset);

            // Print the final result
            for (const string& line : res) {
                cout << line << endl;
            }
        
            // Clear the height cache for next use
            heightCache.clear();
    }
};

int main() {
    Tree t;
    t.populateTree();
    t.printTree(t.root);
    return 0;
}