#include <iostream>
#include <vector>
using namespace std;

bool compareTo(vector<int> &v1, vector<int> &v2){
    int sum1 =0, sum2=0;
    for(int i=0; i<v1.size(); i++){
        sum1+=v1[i];
        sum2+=v2[i];
    }
    if(sum1 == sum2){
        for(int i=0; i<v1.size(); i++){
            if(v1[i]<v2[i]){
                return true;
            }
            else if(v1[i]>v2[i]){
                return false;
            }
        }
    }
    return sum1<sum2;
}

vector<vector<int>> merge(vector<vector<int>> &v1, vector<vector<int>> &v2){
    vector<vector<int>> f;
    int l=0, r=0;
    while(l < v1.size() && r < v2.size()){
        if(compareTo(v1[l],v2[r])){
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

vector<vector<int>> merge_sort(vector<vector<int>> a, int l,int r){
    if(l == r){
        vector<vector<int>> f;
        f.push_back(a[l]);
        return f;
    }
    int m = l + (r-l)/2;
    vector<vector<int>> left = merge_sort(a, l, m);
    vector<vector<int>> right = merge_sort(a, m+1, r);
    return merge(left, right);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        vector<int> vv;
        for(int j=0; j<m; j++){
            int x; cin>>x;
            vv.push_back(x);
        }
        v.push_back(vv);
    }

    auto first = merge_sort(v, 0, v.size()-1);
    for(auto i: first){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}