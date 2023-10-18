#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
        this->right = this->left = nullptr;
    }
};

struct BST{
    Node *root;
    BST(){
        root = nullptr;
    }

private:

    Node *insert_(Node *cur, int val){
        if(cur==nullptr){
            return new Node(val);
        }
        if(cur->val > val){
            cur->left = insert_(cur->left, val);
        }
        else{
            cur->right = insert_(cur->right, val);
        }
        return cur;
    }

public:
    
    Node *getRoot(){
        return root;
    }

    void insert(int val){
        Node *newNode = insert_(root, val);
        if(root == nullptr){
            root = newNode;
        }
    }

    int getHeight(Node *cur, int &val){
        if(cur == nullptr){
            return 0;
        }
        
        int left = getHeight(cur->left, val);
        int right = getHeight(cur->right, val);
        val = max(val, left+right+1);
        return max(left, right) + 1;
    }
};

int main(){
    BST bst;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        bst.insert(x);
    }
    int val=0;
    bst.getHeight(bst.getRoot(), val);

    cout<<val;
}