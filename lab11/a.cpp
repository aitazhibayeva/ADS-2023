#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    long long sum=0;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0; i<m; i++){
        int l,r,c;
        cin>>l>>r>>c;
        v.push_back({c,{l,r}});
    }
//2 (1,3)
//3 (3,5)
    sort(v.begin(), v.end());
    int lim = 2;
    while(lim<=n){ //2<=5
        for(int i=0; i<v.size(); i++){
            int x = v[i].second.first; //x = 1 3
            int y = v[i].second.second; //y = 3 5
            int cost = v[i].first; // c = 2
            if(x<lim && lim<=y){ //1<2 
                sum += cost; // s = 10
                lim++; //5
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}