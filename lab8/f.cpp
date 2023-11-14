#include <bits/stdc++.h>
using namespace std;

long long p = 31;

unordered_set <long long> res;

long long get_hash(string s) {
    long long h = 0;
    for (long long i = 0; i < s.size(); i++) {
        h = (h * p + (s[i] - 'a' + 1));
    }
    return h;
}

void RK(string s) {
    long long hs = get_hash(s);
    long long pm = 1;
    for (long long i = 0; i < s.length() - 1; i++) {
        pm *= p;
    }
    long long pg = 1;
    for (long long i = 0; i < s.length(); i++) {
        long long pt = pg;
        long long ht = hs;
        res.insert(ht);
        for (long long j = s.length() - 1; j > i; j--) {
            ht -= ((s[j] - 'a' + 1) * pt);
            pt *= p;
            res.insert(ht);
        }
        hs = ((hs - pm * (s[i] - 'a' + 1)) * p);
        pg *= p;
    }
}

int main() {
    string s; cin >> s;
    RK(s);
    cout << res.size();
}