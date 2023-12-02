#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector <bool> saw;
vector <vector <int> > v;


void DFS(int w){
    saw[w] = true;
    for(int i = 0; i < v[w].size(); i++){
        if(!saw[v[w][i]]){
            if(v[v[w][i]].size() > v[w].size()){
                cnt++;
            }
            DFS(v[w][i]);
        }
    }
}


int main(){
    cin >> n >> m;
    saw.resize(n); v.resize(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
    }
    for(int i = 0; i < m; i++){
        if(!saw[i]){
            DFS(i);
        }
    }
    cout << cnt + abs(n-m);
}