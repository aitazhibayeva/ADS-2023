#include <iostream>
#include <vector>
using namespace std;

void LPS(string s, int n, vector<int> &lps){
    int len=0;
    int i=1;
    while(i<n){
        if(s[i] == s[len]){
            lps[i] = len+1;
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

int KMP(string s){
    int n = s.size();
    vector<int> lps(n,0);
    LPS(s, n, lps); //000123
    
    return n-lps[n-1];
}

int main(){
    string s;
    cin>>s;
    cout<<KMP(s);
}