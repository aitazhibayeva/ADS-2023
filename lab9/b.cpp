#include <iostream>
#include <vector>
using namespace std;

void LPS (string t, int m, vector<int> &lps) {
    int len = 0; //helloThomashelloArthurhelloJohnhello
    int i = 1;  // 5
    while (i < m) {
        if (t[i] == t[len]) { //e!=h, l!=h, l!=h o!=h
            lps[i] = len + 1;
            len++;
            i++;
        }
        else if (len != 0) {  
            len = lps[len - 1]; //len = lps[-1] = -1;
        }
        else {
            lps[i] = 0;  //lps[1]=0, lps[2]=0, lps[3]=0  lps[4]=0
            i++;
        }
    }
}

void KMP (string t, string s, int k) {
    int n = t.size(); //36
    int m = s.size(); //5
    vector <int> lps(m, 0); //5 0
    LPS(t, m, lps);
    int i = 0, j = 0;
    while (i < n) { //0 36
        if (t[i] == s[j]) { //j=i=1 
            j++;
            i++;
        }
        else if (j != 0) {
            j = lps[j - 1];
        }
        else { 
            i++;
        }
        if (j == m) { //j=5=5
            k--; //1
            j = lps[j - 1]; //j=0
            if (k == 0) { 
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}

int main() {
    string s; cin >> s;
    int k; cin >> k;
    string t; cin >> t;
    KMP(t, s, k);
}