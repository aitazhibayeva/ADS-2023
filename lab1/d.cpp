#include <iostream>
#include <stack>
using namespace std;

bool Balance(string s){
    stack<int> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(st.top()==s[i]){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    string s;
    cin>>s;
    if(Balance(s)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}