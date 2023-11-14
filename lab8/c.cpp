#include <bits/stdc++.h>
using namespace std;

int mod =1e9+7;
int p=31;

int get_hash(string s){
    int h=0;
    for(int i=0; i<s.size(); i++){
        h = h * p +(s[i]-'a'+1);
    }
    return h;
}

void RK(string s, string t, vector<bool> &a){
    int hashS = get_hash(s.substr(0, t.length()));
    int hashT = get_hash(t);
    int pm = 1;
    for(int i=0; i<t.length()-1; i++){
        pm *= p;
    }
    for(int i=0; i+t.length()<=s.length(); i++){
        if(hashS == hashT){
            for(int j=i; j<i+t.length(); j++){
                a[j] = true;
            }
        }
        if(i + t.length() < s.length()){
            hashS = (hashS - pm * (s[i]-'a'+1)) *p+(s[i+t.length()]-'a'+1); 
        }
    }
}
int main(){
    string s; cin>>s;
    int n; cin>>n;
    vector<bool> v(s.size(), false);
    for(int i=0; i<n; i++){
        string t; cin>>t;
        RK(s, t, v);
    }
    for(int i=0; i<s.size(); i++){
        if(!v[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}