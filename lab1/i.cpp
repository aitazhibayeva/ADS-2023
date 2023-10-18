#include <iostream>
#include <deque>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    deque<int> dq1, dq2;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='K'){
            dq1.push_back(i);
        }
        else{
            dq2.push_back(i);
        }
    }
    while(!dq1.empty() && !dq2.empty()){
        int x = dq1.front();
        dq1.pop_front();
        int y = dq2.front();
        dq2.pop_front();

        if(x<y){
            dq1.push_back(x+n);
        }
        else{
            dq2.push_back(y+n);
        }       
    }
    if (!dq1.empty()){
        cout<<"KATSURAGI";
    }
    else{
        cout<<"SAKAYANAGI";
    }
}