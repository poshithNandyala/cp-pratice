#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL {
private:
    Node* root;
    
    int height(Node* node) {
        if (node == NULL) return 0;
        return node->height;
    }
    
    int balanceFactor(Node* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }
    
    void updateHeight(Node* node) {
        if (node == NULL) return;
        node->height = max(height(node->left), height(node->right)) + 1;
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    Node* insertHelper(Node* current, int value) {
        if (current == NULL) {
            return new Node(value);
        }
        
        if (value < current->data) {
            current->left = insertHelper(current->left, value);
        } else if (value > current->data) {
            current->right = insertHelper(current->right, value);
        } else {
            return current;
        }
        
        updateHeight(current);
        
        int balance = balanceFactor(current);
        
        // Left Left Case
        if (balance > 1 && value < current->left->data)
            return rightRotate(current);
        
        // Right Right Case
        if (balance < -1 && value > current->right->data)
            return leftRotate(current);
        
        // Left Right Case
        if (balance > 1 && value > current->left->data) {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }
        
        // Right Left Case
        if (balance < -1 && value < current->right->data) {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }
        
        return current;
    }
    
    Node* searchHelper(Node* current, int value) {
        if (current == NULL || current->data == value) {
            return current;
        }
        
        if (value < current->data) {
            return searchHelper(current->left, value);
        }
        return searchHelper(current->right, value);
    }
    
    void inorderHelper(Node* current) {
        if (current != NULL) {
            inorderHelper(current->left);
            cout << current->data << " ";
            inorderHelper(current->right);
        }
    }
    
    Node* findMin(Node* current) {
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }
    
    Node* deleteHelper(Node* current, int value) {
        if (current == NULL) {
            return NULL;
        }
        
        if (value < current->data) {
            current->left = deleteHelper(current->left, value);
        } else if (value > current->data) {
            current->right = deleteHelper(current->right, value);
        } else {
            if (current->left == NULL || current->right == NULL) {
                Node* temp = current->left ? current->left : current->right;
                if (temp == NULL) {
                    temp = current;
                    current = NULL;
                } else {
                    *current = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMin(current->right);
                current->data = temp->data;
                current->right = deleteHelper(current->right, temp->data);
            }
        }
        
        if (current == NULL) return NULL;
        
        updateHeight(current);
        
        int balance = balanceFactor(current);
        
        // Left Left Case
        if (balance > 1 && balanceFactor(current->left) >= 0)
            return rightRotate(current);
        
        // Left Right Case
        if (balance > 1 && balanceFactor(current->left) < 0) {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }
        
        // Right Right Case
        if (balance < -1 && balanceFactor(current->right) <= 0)
            return leftRotate(current);
        
        // Right Left Case
        if (balance < -1 && balanceFactor(current->right) > 0) {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }
        
        return current;
    }

public:
    AVL() {
        root = NULL;
    }
    
    void insert(int value) {
        root = insertHelper(root, value);
    }
    
    bool search(int value) {
        return searchHelper(root, value) != NULL;
    }
    
    void remove(int value) {
        root = deleteHelper(root, value);
    }
    
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
};

int main() {
    AVL tree;
    
    // Example usage
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "Inorder traversal: ";
    tree.inorder();
    
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;
    
    tree.remove(30);
    cout << "After removing 30, inorder traversal: ";
    tree.inorder();
    
    return 0;
}