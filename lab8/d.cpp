#include <bits/stdc++.h>
using namespace std;

#define d 256 
long long mod = 9007199254740881;

int search(string pt, string t){
    int cnt = 0;
    int i, j, hashP = 0, hashT = 0, p = 1; 
    for(i = 0; i < pt.size() - 1; i++){
        p = (p * d) % mod;
    } 
    for(i = 0; i < pt.size(); i++) {
        hashP = (d * hashP + pt[i]) % mod; 
        hashT = (d * hashT + t[i]) % mod; 
    }
    for(i = 0; i <= t.size() - pt.size(); i++){
        if(hashP == hashT){
            for(j = 0; j < pt.size(); j++){
                if(t[i + j] != pt[j]){
                    break;
                } 
            }
            if(j == pt.size()){
                cnt++;
            }
        }
        if(i < t.size() - pt.size()){
            hashT = (((hashT - t[i] * p) * d) + t[pt.size() + i]) % mod; 
            if(hashT < 0){
                hashT += mod; 
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    while(n != 0){
        string arr[n];
        vector<pair<string, int> > v;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        string t;
        cin >> t;
        int mx = 0;
        for(int i = 0; i < n; i++){
            int num = search(arr[i], t);
            if(mx < num) mx = num;
            v.push_back(make_pair(arr[i], num));
        }
        cout << mx << endl;
        for(int i = 0; i < n; i++){
            if(v[i].second == mx){
                cout << v[i].first << endl;
            }
        }
        cin >> n;
    }
    return 0;
}