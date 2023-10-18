#include <bits/stdc++.h> 
using namespace std; 
 
long long timeWork(vector<long long> &bag, long long mid) { 
    long long res = 0; 
    for(auto i : bag) { 
        res += i/mid; 
        if(i%mid) 
            res++; 
    } 
    return res; 
} 
 
int main() { 
 
    long long n, h; 
    cin >> n >> h; 
    vector<long long> bag(n); 
    for(auto &i: bag) 
        cin >> i; 
    long long low = 0, r = 1e13; 
    while(low + 1 < r) { 
        long long mid = (low+r)/2; 
        long long time = timeWork(bag, mid); 
        if(time <= h) 
            r = mid; 
        else 
            low = mid; 
    } 
    cout << r; 
    return 0; 
}