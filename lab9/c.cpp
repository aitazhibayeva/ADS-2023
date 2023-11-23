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
        else if(len!=0){
            len = lps[len-1];
        }
        else{
            lps[i] = 0;
            i++;
        }
    }
}
 
void KMP(string s, string t){ //zabcdzabcd //abcdz
    int n = s.size();
    int m = t.size();
    vector<int> lps(m, 0);
    LPS(s, m, lps);
    int i=0, j=0;
    while(i<n){
        if(s[i] == t[j]){
            i++;j++;
        }
        else if(j!=0){
            j = lps[j-1];
        }
        else{
            i++;
        }
        if(j == m){
            cout<<n-i;
            j = lps[j-1];
            return ;
        }
    }
    cout<< -1;
}

int main(){
    string s, t;
    cin>>s>>t;
    s += s;
    KMP(s,t);
}