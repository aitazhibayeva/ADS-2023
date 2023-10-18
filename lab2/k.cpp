//Submit a solution for K-One-time guests
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node{
    char data;
    Node *next;
    Node(){}
    Node(int x){
        this->data = x;
        this->next = nullptr;
    }
};

int main(){
    int n;
    cin>>n;
    while(n--){
        Node *head = nullptr;
        Node *cur = head;
        map<char, int> mp;
        int k;
        cin>>k;
        for(int i=0; i<k; i++){
            char a;
            cin>>a;
            if(i==0 || head == nullptr){
                head = new Node(a);
                cur = head;
                mp[a]++;
            }else{
                cur->next = new Node(a);
                cur = cur->next;
                mp[a]++;
            }
            while((head->data == cur->data || mp[head->data]>1) && head!=cur){
                Node *temp = head;
                mp[head->data]++;
                head = head->next;
                delete temp;
            }
            if(head == cur && i!=0 && mp[cur->data]>1){
                cout<<-1<<" ";
                head = head->next;
            }
            else{
                cout<<head->data<<" ";
            }   
        }
        cout<<"\n";
    }
}