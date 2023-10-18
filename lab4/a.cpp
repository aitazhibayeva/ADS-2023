#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
        right, left = nullptr;
    }
};

struct BST {
    Node * root;
    BST(){
        root = nullptr;
    }

private:
    Node *_insert(Node * cur, int val){
        if(cur == nullptr){
            return new Node(val);
        }
        if(cur->val > val){
            cur->left = _insert(cur->left, val);
        }
        else{
            cur->right = _insert(cur->right, val);
        }
        return cur;
    }
    
public: 
    void insert(int val){
        Node *newNode = _insert(root, val);
        if(root == nullptr){
            root = newNode;
        }
    }
    bool search(string s){
        Node *cur = root;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'L'){
                cur = cur->left;
            }else{
                cur = cur->right;
            }
            if(cur == nullptr){
                return false;
            }
        }
        return true;
    }
};

int main(){
    BST bst;
    int n,k; cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        bst.insert(x);
    }
    for(int i=0; i<k; i++){
        string s;
        cin>>s;
        if(bst.search(s)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}