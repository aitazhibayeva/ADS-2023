//delete each second element
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

    void push_back(Node* newNode){
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }
    void printEven(){
        Node* cur = head;
        int i = 0;
        while(cur != nullptr){
            if( i%2==0 ){
                cout<<cur->data<<" ";
            }
            i++;
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


    //l.insert(new Node(3), 2);

    l.printEven();

    return 0;
}
