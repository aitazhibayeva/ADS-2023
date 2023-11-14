#include <bits/stdc++.h>
using namespace std;
int count(string s1,string s2, string p, int mod=1e9+7, int d=31){
    long long hash1=0, hash2=0, hashP=0, h=1, cnt=0;
    for(int i=0; i<p.size()-1; i++){
        h = (h*d)%mod;
    }
    for(int i=0; i<p.size(); i++){
        hash1 = (hash1 * d + s1[i]) % mod;
        hash2 = (hash2 * d + s2[i]) % mod;
        hashP = (hashP * d + p[i]) % mod;
    }
    long long size = min(s1.size(), s2.size());
    for(int i=0; i<=size - p.size(); i++){
        if(hashP == hash1 && hashP == hash2){
            cnt++;
        }
        if(i < size - p.size()){
            hash1 = (d * (hash1 - s1[i] * h) + s1[i + p.size()]) % mod;
            hash2 = (d * (hash2 - s2[i] * h) + s2[i + p.size()]) % mod;
            if(hash1<0){
                hash1 += mod;
            }
            if(hash2<0){
                hash2 += mod;
            }
        }
    }
    return cnt;
}

int main(){
    string s1,s2,p;
    cin>>s1>>s2>>p;
    cout<<count(s1,s2,p);
}