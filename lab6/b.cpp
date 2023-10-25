#include <iostream>
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
    swap(a[idx], a[r]);
    return idx;
}

void quick_sort(int a[], int l, int r){
    if(l<r){
        int p = part(a, l , r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int a[n], b[k];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<k; i++){
        cin>>b[i];
    }
    quick_sort(a, 0, n-1);
    quick_sort(b, 0, k-1);
    int i=0, j=0;
    while(i<n && j<k){
        if(a[i] == b[j]){
            cout<<a[i]<<" ";
            i++;j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
}