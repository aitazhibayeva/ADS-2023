#include <bits/stdc++.h>
using namespace std;

int search(string s, string p, int mod=1e9+7, int d=31){
    int hashP = 0;
    int hashS = 0;
    int h = 1, cnt = 0;
    for(int i=0; i<p.size()-1; i++){
        h =(h*d)%mod;
    }
    for(int i=0; i<p.size(); i++){
        hashP = (hashP*d+p[i])%mod;
        hashS = (hashS*d+s[i])%mod;
    }
    for(int i=0; i<=s.size()-p.size(); i++){
        if(hashP == hashS){
            cnt++;
        }
        if(i<s.size()-p.size()){
            hashS = (d*(hashS-s[i]*h)+s[i+p.size()])%mod;
            if(hashS<0){
                hashS += mod;
            }
        }
    }
    if(cnt==0){
        return 1;
    }
    return cnt;

}

int main(){
    string s; cin>>s;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        cout<<search(s, s.substr(x, y-x+1))<<endl;
    }
}