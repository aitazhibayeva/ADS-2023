#include <iostream>
#include <vector>
using namespace std;

void LPS(string s, int n, vector<int> &lps){
    int len = 0;
    int i = 1;
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

int KMP(string s, int k){ 
    int n = s.size();
    vector<int> lps(n, 0);
    LPS(s, n, lps); // asas 0012, 2*2+4
    int size = (n-lps[n-1])*(k-1)+n;
    return size;
}

int main(){
    int n; cin>>n;
    while(n--){
        string s; cin>>s;
        int k; cin>>k;
        cout<<KMP(s, k)<<endl;
    }
}