#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2){
    vector<int> f;
    int l=0, r=0;
    while((l<v1.size() && r<v2.size())){
        if(v1[l]<=v2[r]){
            f.push_back(v1[l]);
            l++;
        }
        else {
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

vector<int> mergesort(vector<int> v, int l,int r){
    if(l==r){
        vector<int> f;
        f.push_back(v[l]);
        return f;
    }
    int m = l + (r-l)/2;
    vector<int> left = mergesort(v, l, m);
    vector<int> right = mergesort(v, m+1, r);
    return merge(left, right);
}
int main(){
    int n,m,l=0,r=0;
    cin>>n>>m;
    vector<int> v1, v2;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v1.push_back(x);
    }
    for(int i=0; i<m; i++){
        int y; cin>>y;
        v2.push_back(y);
    }
    if(n==0||m==0){
        return 0;
    }

    auto u1 = mergesort(v1, 0, v1.size()-1);
    auto u2 = mergesort(v2, 0, v2.size()-1);

    while(l<u1.size() && r<u2.size()){
        if(u1[l] == u2[r]){
            cout<<u1[l]<<" ";
            l++;r++;
        }
        else if(u1[l]>u2[r]){
            r++;
        }
        else if(u1[l]<u2[r]){
            l++;
        }
    }
}