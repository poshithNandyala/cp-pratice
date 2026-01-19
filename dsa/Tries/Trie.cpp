#include<bits/stdc++.h>
using namespace std;


struct Node
{
	Node * links[26];
	bool flag;
  Node() {
    for (int i = 0; i < 26; i++) links[i] = nullptr;
    flag = false;
}

bool contains(char ch) { return links[ch - 'a'] != nullptr; }
void put(char ch, Node *node) { links[ch - 'a'] = node; }
Node *get(char ch) { return links[ch - 'a']; }
void setEnd() { flag = true; }

bool isEnd() { return flag; }
};

 class Trie{
	
private:
	Node * root;
public:
Trie(){
		root = new Node();
	}
	

	void insert(string word){
		Node *node=root;
		 for(int i=0;i<word.size();i++){
		 	if(!node->contains(word[i])){
                  node->put(word[i],new Node());
		 	}
		 	node=node->get(word[i]);
		 }
		 node->setEnd();
	}

	bool search(string word){
		Node *node=root;
		for(int i=0;i<word.size();i++){
			if(!node->contains(word[i])){
				return false;
			}
			node=node->get(word[i]);
		}
		return node->isEnd();
	}
   
	bool startswith(string word){
		Node *node=root;
		for(int i=0;i<word.size();i++){
			if(!node->contains(word[i])){
                          return false;
                        }
			node=node->get(word[i]);
		}
		return true;
	}
};
int main(){
   Trie trie;
    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    
    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    
    cout << "Search if Strike exists in trie: " <<
   ( trie.search("strike") ? "True" : "False" )<< endl;
    
    cout << "If words is Trie start with Stri: " <<
    (trie.startswith("stri") ? "True" : "False" )<< endl;

    return 0;
}
