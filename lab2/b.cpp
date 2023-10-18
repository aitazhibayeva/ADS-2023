//Jonathan the Poet 
#include <iostream>
using namespace std;

class Node {
public:
    string data;
    struct Node* next;

    Node(string data) : data(data), next(nullptr) {}
};

struct list{
    Node* head;
    Node* tail;
    list() : head(nullptr), tail(nullptr) {}

    void push_back(Node* newNode){
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }
    void pop_front(){
        if(head == nullptr){
            cout<<"loser";
            return;
        }
        else if(head == tail){
            head = nullptr;
            tail = nullptr;
            return;
        }

        head = head->next;
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
    
    int n,k; 
    cin>>n>>k;

    for(int i = 0; i < n; i++){
        string a; cin>>a; 
        l.push_back(new Node(a));
        
    }

    for(int i=0; i<k; i++){
        l.push_back(new Node(l.head->data));
        l.pop_front();
    }

    l.print();

    return 0;
}
