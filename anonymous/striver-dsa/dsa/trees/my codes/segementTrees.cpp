#include<bits/stdc++.h>
using namespace std;

class segementTree{
public:
	class Node{
	public:
		 int start,end;
		 int value;
		 Node *left;
		 Node* right;
		 Node(int st,int e,int v){
		 	start=st;
		 	end=e;
		 	value=v;
		 	left=nullptr;
		 	right=nullptr;
		 }
	};
    Node*root=nullptr;

    Node* insert(vector<int> &arr,int l,int r){
          if(l==r){
          	 Node*node=new Node(l,r,arr[l]);
          	 return node;
          }
          int mid=(l+r)/2;
          Node* node=new Node(l,r,0);
          node->left=insert(arr,l,mid);
          node->right=insert(arr,mid+1,r);
          node->value=node->left->value+node->right->value;

          return node;
    }
    void insert(vector<int> &arr){
    	root=insert(arr,0,arr.size()-1);
    }
     int getsum(Node *node,int l,int r){
     	  if(node->start > r   || node->end < l){
     	 	return 0;
     	 }
         if (node->start >= l && node->end <= r){
     	 	return node->value;
     	 }
     	
     	return  getsum(node->left, l, r) + getsum(node->right, l, r);
     		 
     }
    int getsum(int l,int r){
    	 return getsum(root,l,r);
    }
    int update(Node*node,int i,int v){
    	if(node->start==node->end && node->start==i){
    		int ans=(v -(node->value));
    		node->value+=ans;
    		return ans;
    	}
    	if(node->left->start<=i && node->left->end>=i){
    		int ans=update(node->left,i,v);
    		 node->value+=ans;
    		 return ans;
    	}
    	else{
    		int ans=update(node->right,i,v);
    		node->value+=ans;
    		return ans;
    	}
    	return 0;
    }
    void update(int i,int v){
    	update(root,i,v);
    }
 unordered_map<Node*, int> heightCache;

int getHeight(Node* node) {
    if (!node) return 0;
    if (heightCache.count(node)) return heightCache[node];
    return heightCache[node] = 1 + max(getHeight(node->left), getHeight(node->right));
}

void printTree(Node* root) {
    if (!root) return;

    struct DisplayNode {
        Node* node;
        int x, y;
    };

    int height = getHeight(root);
    int maxWidth = (1 << height) * 6;  // More space per level
    vector<string> canvas(height * 2, string(maxWidth, ' '));

    function<void(Node*, int, int, int)> draw = [&](Node* node, int depth, int pos, int gap) {
        if (!node) return;

        string val = "[" + to_string(node->start) + "," + to_string(node->end) + "]=" + to_string(node->value);
        int start = pos - val.size() / 2;
        for (int i = 0; i < val.size(); ++i) {
            if (start + i >= 0 && start + i < maxWidth)
                canvas[depth][start + i] = val[i];
        }

        if (node->left) {
            canvas[depth + 1][pos - gap / 2] = '/';
            draw(node->left, depth + 2, pos - gap, gap / 2);
        }
        if (node->right) {
            canvas[depth + 1][pos + gap / 2] = '\\';
            draw(node->right, depth + 2, pos + gap, gap / 2);
        }
    };

    int rootPos = maxWidth / 2;
    draw(root, 0, rootPos, maxWidth / 4);

    for (string& line : canvas) {
        if (line.find_first_not_of(' ') != string::npos)
            cout << line << '\n';
    }

    heightCache.clear();
}

void prettyPrint() {
    printTree(root);
}

};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    segementTree s;
    s.insert(arr);
    
    s.prettyPrint();
    cout<<s.getsum(0,2)<<endl;
    s.update(0,100);
    s.prettyPrint();
 cout<<s.getsum(0,2)<<endl;
}