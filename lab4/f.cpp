#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *right, *left;
    Node(int val){
        this->val = val;
        right = left = nullptr;
    }
};

struct BST {
    Node *root;
    BST() {
        root = nullptr;
    }

private:
    Node *insert_(Node *cur, int val){
        if(cur == nullptr){
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

    int getHeight(Node *cur){
        if(cur == nullptr){
            return 0;
        }
        int left = getHeight(cur->left);
        int right = getHeight(cur->right);
        return max(left, right) + 1;
    }
    
    void insert(int val){
        Node *newNode = insert_(root, val);
        if(root == nullptr){
            root = newNode;
        }
    }

    void getTriangle(Node *cur, int lvl, vector<int> &v) {
        if(cur == nullptr){
            return ;
        }
        if(cur->left != nullptr && cur->right != nullptr){
            v[lvl] ++;
        }
        getTriangle(cur->left, lvl +1, v);
        getTriangle(cur->right, lvl + 1, v);
    }

    


    
};
int main(){
    BST bst;
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        bst.insert(x);
    }
    vector<int> v(bst.getHeight(bst.getRoot()));
    bst.getTriangle(bst.getRoot(), 0, v);
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }

    cout<<sum;
}