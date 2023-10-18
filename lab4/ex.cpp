#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node *left, *right;
}Node;

Node *create_element(int val){
    Node *elem = new Node;
    elem->val = val;
    elem->left = nullptr;
    elem->right = nullptr;
}

void insert_element(Node *root, Node *elem){
    if(root->val > elem->val){
        if(root->left == nullptr){
            root->left = elem;
        }
        else{
            insert_element(root->left, elem);
        }
    }
    else{
        if(root->right == nullptr){
            root->right = elem;
        }
        else{
            insert_element(root->right, elem);
        }
    }
}

void print_element(Node *cur){
    if(cur->left != nullptr){
        print_element(cur->left);
    }
    cout<<"Value: "<<cur->val<<endl;
    if(cur->right != nullptr){
        print_element(cur->right);
    }
}

int main(){

    int a[7] = {-2, 3, 4, 45, 8, -6, -1};
    Node *root= create_element(0);

    for(int i =0; i<7; i++){
        Node *el = create_element(a[i]);
        insert_element(root, el);
    }

    cout<<"My tree: "<<endl;
    print_element(root);
    return 0;
}