#include <iostream>
using namespace std;

int part(char a[], int l, int r){
    char pivot = a[r];
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
        int p = part(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
}

void divide(char a[], char c, int &s){
    for(int i=0; i<s; i++){
        if(int(a[i])<=int(c)){
            swap(a[i], a[s-1]);
            i--;
            s--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    char a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    char least = a[0];
    char c; cin>>c;
    divide(a, c, n);

    cout<<(n ? a[0] : least);
}