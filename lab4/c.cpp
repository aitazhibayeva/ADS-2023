// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int val;
//     Node *left, *right;
//     Node(int val){
//         this->val = val;
//         left=nullptr;
//         right=nullptr;
//     }
// };

// struct BST{
//     Node *root;
//     BST(){
//         root = nullptr;
//     }

// private:
//     Node *insert_(Node *cur, int val){
//         if(cur == nullptr){
//             return new Node(val);
//         }
//         else if(cur->val > val){
//             cur->left = insert_(cur->left, val);
//         }
//         else {
//             cur->right = insert_(cur->right, val);
//         }
//         return cur;
//     }

// public:
//     Node *getRoot(){
//         return root;
//     }

//     int getHeight(Node *cur){
//         if(cur == nullptr){
//             return 0;
//         }
//         int left = getHeight(cur->left);
//         int right = getHeight(cur->right);
//         return max(left, right) + 1;
//     }

//     void insert(int val){
//         Node *newNode = insert_(root, val);
//         if(root == nullptr){
//             root = newNode;
//         }
//     }
    
//     Node* find(Node *cur, int k){
//         if(cur->val > k){
//             while(cur->left->val != k){
//                 find(cur->left, k);
//             }
//             return cur->left;
//         }
//         else{
//             while(cur->right->val != k){
//                 find(cur->right, k);
//             }
//             return cur->right;
//         }
//     }
    
//     void show(Node* cur){
//         if (cur != NULL)
//         {    
//             cout << cur->val << " ";   
//             show(cur->left);
//             show(cur->right);
            
//         }
//     }
    
// };

// int main(){
//     BST bst;
//     int n;
//     cin>>n;
//     for(int i=0; i<n; i++){
//         int x; cin>>x;
//         bst.insert(x);
//     }

//     int k;
//     cin>>k;
    
//     bst.show(bst.find(bst.getRoot(), k));
// }


#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *right, *left;

    Node(int val){
        this->val = val;
        right = left = nullptr;
    }
};

struct BST{
    Node *root;
    BST(){root = nullptr;}

private:
    Node* _insert(Node* cur, int val){
        if(cur == nullptr) return new Node(val);
        if(cur->val > val) cur->left = _insert(cur->left, val);
        else cur->right = _insert(cur->right, val);
        return cur;
    }

    Node* _search(Node* cur, int target){
        if(cur == nullptr) return nullptr;
        if(cur->val == target) return cur;
        else if(cur->val > target) return _search(cur->left, target);
        else return _search(cur->right, target);
    }

    void _preorder(Node* node){
        if(node == nullptr) return;
        cout << node->val << ' ';
        _preorder(node->left);
        _preorder(node->right);
    }

public:
    void insert(int val){
        Node* newnode = _insert(root, val);
        if(root == nullptr) root = newnode;
    }

    void getSubtree(int val){
        Node* cur = root;
        cur = _search(root, val);
        _preorder(cur);
    }
};

int main(){
    BST bst;
    int n, k; cin >> n;
    for(int i = 0; i < n; i++){int x; cin >> x; bst.insert(x);}
    cin >> k; bst.getSubtree(k);
}