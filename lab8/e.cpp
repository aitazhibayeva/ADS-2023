#include <bits/stdc++.h>
using namespace std;

string getStr(vector<long long> &v, long long mod=1e16){
    long long p=1;
    string s="";
    for(int i=0; i<v.size(); i++){
        if(i==0){
            s += (v[i]/p)+97;
        }
        else{
            s += ((v[i]-v[i-1])/p)+97;
        }
        p = (p*2)%mod;
    }
    return s;
}

int main(){
    long long n; cin>>n;
    vector<long long> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<getStr(v);
}