#include <iostream>
using namespace std;

int part(string &a, int l, int r){
    int pivot = a[r];
    int idx = l;
    for(int i=l; i<r; i++){
        if(a[i]<pivot){
            swap(a[i], a[idx]);
            idx++;
        }
    }
    swap(a[idx], a[r]);
    return idx;
}

void quick_sort(string &a, int l, int r){
    if(l<r){
        int p = part(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

int main(){
    string s;
    cin>>s;
    quick_sort(s, 0, s.size()-1);
    cout<<s;
}