#include <iostream>
using namespace std;

int part(char a[], int l, int r){
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

void quick_sort(char a[], int l, int r){
    if(l<r){
        int p = part(a, l , r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

int main(){
    int n; cin>>n;
    char a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k = sizeof(a)/sizeof(a[0]);
    quick_sort(a,0,k-1);
    for(int i=0; i<k; i++){
        if(a[i]=='a'|| a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
            cout<<a[i];
        }
    }
    for(int i=0; i<k; i++){
        if(a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o'&& a[i]!='u'){
            cout<<a[i];
        }
    }
}