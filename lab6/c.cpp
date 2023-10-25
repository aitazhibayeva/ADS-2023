#include <bits/stdc++.h>
using namespace std;

int part(int a[], int l, int r){
    int pivot = a[r];
    int idx = l;
    for(int i=l; i<r; i++){
        if(a[i]<pivot){
            swap(a[i], a[idx]);
            idx++;
        }
    }
    swap(a[idx],a[r]);
    return idx;
}

void quick_sort(int a[], int l, int r){
    if(l<=r){
        int p = part(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

int diff(int a,int b){
    return ((b-a>0) ? (b-a) : -1*(b-a));
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quick_sort(a, 0, n-1);
    int minDiff = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        int dif = diff(a[i], a[i + 1]);
        if(minDiff > dif) minDiff = dif;
    }
    for(int i = 0; i < n - 1; i++){
        if(diff(a[i], a[i + 1]) == minDiff){
            cout << a[i] << ' ' << a[i + 1] << ' ';
        }
    }
}