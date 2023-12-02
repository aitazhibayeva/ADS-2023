#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int cnt=0;
    int a[n][n];
    queue <int> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    x--;y--;
    if(x == y){
        cout<<cnt;
        return 0;
    }
    q.push(x);
    vector<bool> s(n); //5
    s[x] = true; //s[2]
    while(!q.empty()){
        int qq = q.front(); //true
        cnt++;
        for(int i=0; i<n; i++){
            if(!s[i] && a[qq][i]){ 
                if(i == y){ // 0=3
                    cout<<cnt;
                    return 0;
                }
                s[i] = true;
                q.push(i);
            }
        }
        q.pop();
    }
    cout<<-1;
}