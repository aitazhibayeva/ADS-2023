#include <iostream>
using namespace std;

int part(int a[], int l, int r){
    int pivot = a[r];
    int idx = l;
    for(int i=l; i<r; i++){
        if(a[i]>pivot){
            swap(a[i], a[idx]);
            idx++;
        }
    }
    swap(a[idx], a[r]);
    return idx;
}

void quick_sort(int a[], int l, int r){
    if(l<r){
        int p = part(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[k][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin>>a[j][i];
        }
    }
    for(int i=0; i<k; i++){
        quick_sort(a[i], 0, n-1);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}