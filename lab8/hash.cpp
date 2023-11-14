#include <iostream>
#include <map>
#include <vector>
using namespace std;

int mod = 9e9 + 9;


int get_hash(string s){
    int hash;
    for(int i=0; i<s.length(); i++){
        hash += (s[i] - 'a' + 1) % mod;
    }
    return hash;
}


int main(){

    vector<string> v;
    string s;
    getline(cin, s);    
    for(int i=0; i<s.size(); i++){
        if(s[i]!=' '){
            v.push_back(s);
        }
    }
    return 0;
}