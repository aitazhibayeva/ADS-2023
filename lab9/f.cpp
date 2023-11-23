#include <iostream>
#include <vector>
using namespace std;

void LPS(string s, int m, vector<int> &lps){
    int len = 0;
    int i = 1;
    while(i<m){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            len++;
            i++;
        }
        else if(len != 0){
            len = lps[len-1];
        }
        else{
            lps[i] = 0;
            i++;
        }
    }
}

void KMP(string s, string t){
    int n = s.size();
    int m = t.size();
    int cnt=0;
    vector<int> lps(m, 0);
    vector<int> p;
    LPS(s, m, lps);
    int i=0, j=0;
    while(i<n){
        if(s[i] == t[j]){
            i++;
            j++;
        }
        else if(j != 0){
            j = lps[j-1];
        }
        else{
            i++;
        }
        if(j == m){
            cnt++;
            p.push_back(i+1-m);
            j = lps[j-1];
        }
    }
    cout<<cnt<<endl;
    for(auto i: p){
        cout<<i<<" ";
    }
}

int main(){
    string s, t;
    cin>>s>>t;
    KMP(s,t);
}