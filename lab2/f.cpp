//Insertion of Node
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    struct Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

struct list{
    Node* head;
    Node* tail;
    list() : head(nullptr), tail(nullptr) {}

    void push_front(Node* newNode){
        if(head==nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }
    void push_back(Node* newNode){
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    int length(){
        Node* cur = head;
        int n = 0;
        while(cur!=nullptr){
            n+=1;
            cur = cur->next;
        } 
        return n;
    }

    void insert(Node* newNode, int pos){
        if(length() <= pos){
            cout<<"Index out of range";
            return;
        }else if(0 == pos){
            push_front(newNode);
        }
        Node* cur = head;
        int i = 0;
        while(i < pos - 1){
            cur = cur->next;
            i++;
        }

        Node* temp = cur->next;
        cur->next = newNode;
        newNode->next = temp;
    }

    void print(){
        Node* cur = head;

        while(cur != nullptr){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
    }

};

int main() {
    list l;
    
    int n; cin>>n;

    for(int i = 0; i < n; i++){
        int a; cin>>a; 
        l.push_back(new Node(a));
    }
    int k,p;
    cin>>k>>p;
    l.insert(new Node(k), p);

    l.print();

    return 0;
}
