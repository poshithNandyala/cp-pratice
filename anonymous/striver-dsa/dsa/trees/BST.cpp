#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;
    
    Node* insertHelper(Node* current, int value) {
        // If we reach an empty spot, create and return a new node
        if (current == NULL) {
            return new Node(value);
        }
        
        // If value is less than current node, insert in left subtree
        if (value < current->data) {
            current->left = insertHelper(current->left, value);
        } 
        // If value is greater than current node, insert in right subtree
        else if (value > current->data) {
            current->right = insertHelper(current->right, value);
        }
        
        // Return the unchanged node pointer
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
            if (current->left == NULL) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == NULL) {
                Node* temp = current->left;
                delete current;
                return temp;
            }
            
            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteHelper(current->right, temp->data);
        }
        return current;
    }

public:
    BST() {
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
    BST tree;
    
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