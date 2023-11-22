#include <iostream>
using namespace std;

const int N = (int)1e5+7;
const int p = 31;
const int mod = (int)1e9+7;

int my_hash(string s){
    int h = 0;
    for(int i=0; i<s.length(); i++){
        h = (h*p+s[i]-'a'+1)%mod;
    }
    return h;
}

int main(){
    int n, m;
    string s, w;
    cin>>s>>w;

    n = s.length();
    m = w.length();

    int hw = my_hash(w);
    int hs = my_hash(s.substr(0, m));

    int pm = 1; //p^(m-1)
    for(int i=0; i<m-1; i++){
        pm = pm * p;
    }
    for(int i=0; i+m<=n; i++){
        if(hs == hw){
            cout<<i<<" ";
        }
        if(i+m<n){
            hs = (hs - pm * (s[i]-'a'+1))*p + (s[i+m]-'a'+1);
        }
    }
}