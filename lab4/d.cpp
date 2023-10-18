#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    int val;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

struct BST{
    Node *root;
    BST(){
        root= nullptr;
    }

private:
    Node *insert_(Node *cur, int v){
        if(cur == nullptr){
            return new Node(v);
        }
        else if(cur->val > v){
            cur->left=insert_(cur->left, v);
        }
        else if(cur->val < v){
            cur->right = insert_(cur->right, v);
        }
        return cur;
    }

public: 
    void insert(int val){
        Node *newNode = insert_(root, val);
        if(root == nullptr){
            root = newNode;
        }
    }

    Node *getRoot(){
        return root;
    }

    int getHeight(Node *node){
        if(node == nullptr){
            return 0;
        }
        
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return max(left, right) +1;
    }

    void getSum(Node *cur, int lvl, vector<int> &v){
        if(cur == nullptr){
            return;
        }
        v[lvl] += cur->val;
        getSum(cur->left, lvl+1, v);
        getSum(cur->right, lvl+1, v);
    }
};

int main(){
    BST bst;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        bst.insert(x);
    }

    vector<int> v(bst.getHeight(bst.getRoot()));
    bst.getSum(bst.getRoot(), 0, v);
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
   
}