#include <bits/stdc++.h>
using namespace std;

string hashRes(string s, int mod=1e9+7, int in=11){
    long long res=0; 
    long long p=1;
    for(int i=0; i<s.size(); i++){
        res = (res + ((s[i]-47)*p)%mod)%mod;
        p = (p*in)%mod;
    }
    return to_string(res);
}
int main(){
    int n; cin>>n;
    vector<string> v;
    map<string, string> hash;
    for(int i=0; i<n*2; i++){
        string s; cin>>s;
        v.push_back(s);
        hash.insert({s,hashRes(s)});
    }

    int cnt=0;
    for(auto i: v){
        string s = hashRes(i);
        if(hash.find(s)!=hash.end()){
            cout<<"Hash of string \""<<i<<"\" is "<<s<<endl;
            cnt++;
        }
        if(cnt==n){
            break;
        }
    }
}