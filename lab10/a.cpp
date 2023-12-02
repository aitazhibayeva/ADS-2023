#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>g, queue<pair<int,int>>q, int n, int m, int one, int two){
    vector<vector<bool>> vis(n, vector<bool> (m,false));
    vis[q.front().first][q.front().second] = true;
    int cnt=0;
    while(!q.empty()){
        int tmp=0;
        bool ok = false;
        while(two--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 && g[i-1][j] == 1 && vis[i-1][j]==false){
                ok = true;
                vis[i-1][j]=true;
                q.push(make_pair(i-1, j));
                tmp++;
                one--;
            }
            if(j-1>=0 && g[i][j-1]==1 && vis[i][j-1]==false){
                ok = true;
                vis[i][j-1]=true;
                q.push(make_pair(i, j-1));
                tmp++;
                one--;
            }
            if(i+1<n && g[i+1][j]==1 && vis[i+1][j]==false){
                ok=true;
                vis[i+1][j]=true;
                q.push(make_pair(i+1, j));
                tmp++;
                one--;
            }
            if(j+1<m && g[i][j+1]==1 && vis[i][j+1]==false){
                ok=true;
                vis[i][j+1]=true;
                q.push(make_pair(i,j+1));
                tmp++;
                one--;
            }
        }
        if(ok){
            cnt++;
        }
        two = tmp;
    }
    if(one==0){
        cout<<cnt;
    }
    else{
        cout<<-1;
    }
}

int main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> g(n, vector<int> (m));
    queue<pair<int,int>> q;
    int one=0,two=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>g[i][j];
            if(g[i][j]==2){
                two++;
                q.push(make_pair(i, j));
            }
            if(g[i][j]==1){
                one++;
            }
        }
    }
    if(one == 0){
        cout<<0;
        return 0;
    }
    BFS(g, q, n, m, one, two);
}