#include <iostream>
#include <deque>
using namespace std;
int main(){
    int a[5],b[5], s=0;
    deque<int> dq1;
    deque<int> dq2;
    for(int i=0; i<5; i++){
        cin>>a[i];
        dq1.push_back(a[i]);
    }
    for(int i=0; i<5; i++){
        cin>>b[i];
        dq2.push_back(b[i]);
    }
    while(!dq1.empty() && !dq2.empty()){
        if(1000000<s){
            cout<<"blin nichya";
            return 0;
        }
        if(dq1.front()==9 && dq2.front()==0){
            dq2.push_back(dq1.front());
            dq2.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        else if(dq1.front()==0 && dq2.front()==9){
            dq1.push_back(dq1.front());
            dq1.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        else if(dq1.front() > dq2.front()){
            dq1.push_back(dq1.front());
            dq1.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        else if(dq1.front() < dq2.front()){
            dq2.push_back(dq1.front());
            dq2.push_back(dq2.front());
            dq1.pop_front();
            dq2.pop_front();
        }
        s++;
    }
    if(dq1.empty()){
        cout<<"Nursik "<<s;
    }
    if(dq2.empty()){
        cout<<"Boris "<<s;
    }
    return 0;
}