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

    void push_front(Node* newNode){
        if(head==nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void print(){
        Node* cur = head;

        while(cur != nullptr){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
    }

    void pop_back(){
        if(head == nullptr){
            cout<<"loser";
            return;
        }
        else if(head == tail){
            head = nullptr;
            tail = nullptr;
            return;
        }


        Node* cur = head;
        while(cur != nullptr){
            if(cur==tail){
                break;
            }
            cur = cur->next;
        }
        tail = cur;
        cur->next = nullptr;
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

    void remove(int p){
        if(head == nullptr){
            cout<<"loser";
            return;
        }
        else if(head == tail){
            head = nullptr;
            tail = nullptr;
            return;
        }else if(p==0){
            head=head->next;
            return;

        }
        
        Node* cur = head;
        Node* temp = head; 
        int i=0;
        while(i!=p){
            
            if(i==p-1){
                temp=cur;
            }
            cur=cur->next;
            i++;
        }
        temp->next = cur->next;
        cur = nullptr;

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

    void reverse(){
        Node* cur = head;
        Node* temp = head;
        Node* prev = nullptr;
        Node* hhead = head;
        while(cur!=nullptr){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        head = tail;
        tail = hhead;
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


    l.reverse();
    l.print();
    return 0;
}