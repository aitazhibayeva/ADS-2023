#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right ;
    Node(int val){
        this->val = val;
        right = left = nullptr;
    }
};

struct BST{
    Node *root;
    BST(){
        root = nullptr;
    }

private:
    Node *insert_(Node *cur, int val){
        if(cur == nullptr){
            return new Node(val);
        }
        if(cur->val>val){
            cur->left = insert_(cur->left, val);
        }
        else{
            cur->right = insert_(cur->right, val);
        }
        return cur;
    }  

    Node *search_(Node *cur, int val){
        if(cur == nullptr){
            return nullptr;
        }
        if(cur->val == val){
            return cur;
        }
        else if(cur->val > val){
            search_(cur->left, val);
        }
        else{
            search_(cur->right, val);
        }
    } 

    int getSize(Node *cur){
        if(cur == nullptr){
            return 0;
        }
        return getSize(cur->right) + getSize(cur->left)+ 1;
    }

public:
    void insert(int val){
        Node *newNode = insert_(root, val);
        if(root == nullptr){
            root = newNode;
        }
    }

    void size(int trg){
        Node *cur = root;
        cur = search_(root, trg);
        cout<<getSize(cur);
    }

};

int main(){
    BST bst;
    int n,k;
    cin>>n;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        bst.insert(x);
    }

    cin>>k;
    bst.size(k);
}