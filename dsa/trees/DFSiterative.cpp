#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return ans;
    }
    
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (true) {
            if (node) {
                s.push(node);
                node = node->left;
            }
            else {
                if (s.empty()) break;
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
    
    vector<int> postOrder(TreeNode* root) {
        vector<int> postorder;
        if (root == nullptr) return postorder;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left) st1.push(root->left);
            if (root->right) st1.push(root->right);
        }
        while (!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> post;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            TreeNode* temp = st.top()->right;
            if (temp == nullptr) {
                temp = st.top();
                st.pop();
                post.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);
                }
            }
            else {
                curr = temp;
            }
        }
    }

    return post;
}

