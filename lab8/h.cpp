#include <bits/stdc++.h>
using namespace std;

long long p=31;

long long get_hash(string s){
    long long h=0;
    for(int i=0; i<s.length(); i++){
        h = (h*p+(s[i]-'a'+1));
    }
    return h;
}

bool RK(string s, string t){
    int hashS = get_hash(s.substr(0, t.length()));
    int hashT = get_hash(t);
    int pm=1;
    for(int i=0; i<t.length()-1; i++){
        pm *= p;
    }
    for(int i=0; i + t.length()<=s.length(); i++){
        if(hashS == hashT){
            return true;
        }
        if( i + t.length()<s.length()){
            hashS = (hashS - pm*(s[i]-'a'+1))*p+(s[i+t.length()]-'a'+1);
        }
    }
    return false;
}

int main(){
    int n; cin>>n;
    string a[n];
    int minSize = INT_MAX;
    string min_s;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        if(minSize>s.size()){
            minSize = s.size();
            min_s = s;
        }
        a[i] = s;
    }
    int maxSize = 0;
    string res="";
    for(int i=0; i<minSize; i++){
        for(int j=i; j<minSize; j++){
            string sub = min_s.substr(i, minSize - j);
            bool temp = true;
            for(int k=0; k<n; k++){
                if(!RK(a[k], sub)){
                    temp = false;
                    break;
                }
            }
            if(temp){
                if(maxSize<sub.size()){
                    maxSize = sub.size();
                    res = sub;
                }
            }
        }
    }
    cout<<res;
}