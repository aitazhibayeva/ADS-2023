#include <iostream>
#include <vector>

using namespace std;

bool compareTo(string &s, string &d){
    int year1 = stoi(s.substr(6,4));
    int year2 = stoi(d.substr(6,4));
    int mon1 = stoi(s.substr(3,2));
    int mon2 = stoi(d.substr(3,2));
    int day1 = stoi(s.substr(0,2));
    int day2 = stoi(d.substr(0,2));

    if(year1 < year2){return true;}
    if(year1 == year2 && mon1<mon2){return true;}
    if(year1 == year2 && mon1 == mon2 && day1<day2){return true;}
    return false;
}

int part(vector<string> &v, int l, int r){
    string pivot = v[r];
    int idx = l;
    for(int i=l; i<r; i++){
        if(compareTo(v[i], pivot)){
            swap(v[i],v[idx]);
            idx++;
        }
    }
    swap(v[idx], v[r]);
    return idx;
}

void quick_sort(vector<string> &v, int l, int r){
    if(l<r){
        int p = part(v, l,  r);
        quick_sort(v, l, p-1);
        quick_sort(v, p+1, r);
    }
}

int main(){
    int n; cin>>n;
    vector<string> v;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        v.push_back(s);
    }
    quick_sort(v, 0 , v.size()-1);
    for(auto i: v){
        cout<<i<<endl;
    }
}