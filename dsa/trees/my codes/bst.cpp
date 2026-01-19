#include<bits/stdc++.h>
using namespace std;

class Bst
{
public:
    class Node{
 public:
         int value;
         int height;
         Node* left;
         Node* right;

    	Node(int val){
    		value=val;
    		height=0;
    		left=nullptr;
    		right=nullptr;
    	}

    	// Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
        int getvalue() const{
        	return value;
        }
        void setHeight(int h) {
            height = h;
        }

        int getHeight() const {
           return height;
        }
        Node* getLeft() const {
        return left;
    }

    Node* getRight() const {
        return right;
    }

    };

private:
	Node* root=nullptr;
	void display(Node* node, string details) {
          if (node == nullptr) {
            return;
          }

    cout << details << node->getvalue() << endl;

    // Convert int to string using to_string()
    display(node->left, "left node of " + to_string(node->getvalue()) + " : ");
    display(node->right, "right node of " + to_string(node->getvalue()) + " : ");
    }


    Node* insert(Node* node,int value){
    	if(node==nullptr){
    		Node *newNode= new Node(value);
    		return newNode;
    	}
        if(node->value > value){
        	node->left= insert(node->left,value);
        }
        else{
        	node->right=insert(node->right,value);
        }
        node->height = 1 + max(height(node->left), height(node->right));
        return node;
    }

    void preorder(Node *node){
        if(node==nullptr){
        	return;
        }
    	cout<<node->value<<" ";
    	preorder(node->left);
    	preorder(node->right);
    }
    void inorder(Node *node){
    	if(node==nullptr){
    		return;
    	}
    	inorder(node->left);
    	cout<<node->value<<" ";
    	inorder(node->right);
    }
     void postorder(Node *node){
        if(node==nullptr){
        	return;
        }

    	postorder(node->left);
    	postorder(node->right);
    	cout<<node->value<<" ";
    }
   unordered_map<Node*, int> heightCache;

    int getHeight(Node* node) {
        if (!node) return 0;
        if (heightCache.count(node)) return heightCache[node];
        heightCache[node] = 1 + max(getHeight(node->left), getHeight(node->right));
        return heightCache[node];
    }

    void printTree(Node* root) {
        if (!root) return;

        int height = getHeight(root);
        int rows = height * 2 - 1;
        int cols = (int)pow(2, height) * 3;
        vector<string> res(rows, string(cols, ' '));

        function<void(Node*, int, int, int)> dfs = [&](Node* node, int row, int col, int offset) {
            if (!node) return;
            string val = to_string(node->value);
            int valStart = col - val.length() / 2;
            for (int i = 0; i < val.length(); ++i) {
                if (valStart + i >= 0 && valStart + i < cols)
                    res[row][valStart + i] = val[i];
            }

            if (node->left) {
                res[row + 1][col - offset] = '/';
                dfs(node->left, row + 2, col - offset * 2, offset / 2);
            }

            if (node->right) {
                res[row + 1][col + offset] = '\\';
                dfs(node->right, row + 2, col + offset * 2, offset / 2);
            }
        };

        int rootCol = cols / 2;
        int offset = (int)pow(2, height - 2);
        dfs(root, 0, rootCol, offset);

        for (const string& line : res) {
            cout << line << endl;
        }

        heightCache.clear(); // clear after each print
    }
public:
int height(Node* node){
   return node==nullptr?-1:node->getHeight();
}
bool isEmpty(){
	return root==nullptr;
}
void display(){
	display(root,"Root Node : ");
}
void insert(int value){
	root=insert(root,value);
}

void alltraversals(){
	cout<<"preorder :";
	preorder(root);
	cout<<endl;
	cout<<"inorder :";
	inorder(root);
	cout<<endl;
	cout<<"postorder :";
	postorder(root);
	cout<<endl;

}
	  void prettyPrint() {
        printTree(root);
    }
};


int main(){
   Bst tree;
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
   	 int x;
         cin >> x;
         tree.insert(x);
   }
   // tree.display();
   tree.prettyPrint();
   tree.alltraversals();
   
}