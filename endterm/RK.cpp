#include<iostream>
#include<unordered_map>
 
using namespace std;
 
const int d = 256;
const int q = 101;

int rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int h = 1;
 
    for (int i = 0; i < m - 1; i ++) {
        h = (h * d) % q;
    }
 
    int pHash = 0;
    int tHash = 0;
 
    for (int i = 0 ; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }
 
    unordered_map<int, int> hashMap;
    hashMap[tHash] = 0;
 
    for (int i = 0; i < n - m; i++) {
        if (pHash == tHash) {
            if (pattern == text.substr(i , m)) {
                return i;
            }
        }
 
        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % q;
 
            if (tHash < 0) {
                tHash += q;
            }
        }
    }
    return -1;
}
int main() {
    string text = "accccacac";
    string pattern = "cca";
 
    int index = rabinKarp(text, pattern);
 
    cout << index << endl;
    cout << 76800 % 101;
}