#include <iostream>
#include <vector>
using namespace std;

bool compareTo(pair<string, string> v1, pair<string, string> v2){
    return v1.first<v2.first;
}

int part(vector<pair<string, string>> &v, int l, int r){
    pair<string, string> pivot = v[r];
    int idx = l;
    for(int i=l; i<r; i++){
        if(compareTo(v[i], pivot)){
            swap(v[i], v[idx]);
            idx++;
        }
    }
    swap(v[idx], v[r]);
    return idx;
}

void quick_sort(vector <pair<string, string>> &v, int l, int r){
    if(l<r){
        int p = part(v, l ,r);
        quick_sort(v, l, p-1);
        quick_sort(v, p+1, r);
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<string, string>> v;
    for(int i=0; i<n; i++){
        bool trg = false;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0; i<v.size(); i++){
            if(s1 == v[i].second){
                v[i].second = s2;
                trg = true;
                break;
            }
        }
        if(!trg){
            v.push_back({s1,s2});
        }
    }
    quick_sort(v, 0, v.size()-1);
    cout<<v.size()<<endl;
    for(auto i: v){
        cout<<i.first<<" "<<i.second<<endl;
    }
}