//List modes
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

struct LinkedList{
    int size = 0;
    ListNode *head,*tail;
    void add(int val){
        ListNode* newNode = new ListNode(val);
        if(this->size == 0){
            this->head = newNode;
            this->tail = newNode;
        }
        else{
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }
};

int main(){
    LinkedList* list = new LinkedList();
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        list->add(a[i]);
    }
    ListNode* cur = list->head;
    map<int,int> mp;
    while(cur){
        mp[cur->val]++;
        cur= cur->next;
    }
    vector <int> v;
    int counter = 0;
    for(auto i: mp){
        if(i.second > counter){
            counter=i.second;
        }
    }
    for(auto i: mp){
        if(i.second == counter){
            v.push_back(i.first);
        }
    }
    sort(v.begin(), v.end());
    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i]<<" ";
    }
}