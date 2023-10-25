#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> v1, vector<int>v2){
    vector<int> f;
    int l=0, r=0;
    while(l<v1.size() && r<v2.size()){
        if(v1[l]<v2[r]){
            f.push_back(v1[l]);
            l++;
        }
        else{
            f.push_back(v2[r]);
            r++;
        }
    }
    while(l<v1.size()){
        f.push_back(v1[l]);
        l++;
    }
    while(r<v2.size()){
        f.push_back(v2[r]);
        r++;
    }
    return f;
}

int main(){
    vector<int> v1,v2;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v1.push_back(x);
    }
    int m; cin>>m;
    for(int i=0; i<m; i++){
        int y; cin>>y;
        v2.push_back(y);
    }
    auto v = merge(v1,v2);
    for(auto u: v){
        cout<<u<<" ";
    }
}