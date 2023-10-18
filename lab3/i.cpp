#include <iostream>
using namespace std;

bool binary_search(int a[], int k, int n){
    int l=0, r = n-1, mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(k<a[mid]){
            r = mid-1;
        }
        else if(k>a[mid]){
            l = mid+1;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    for(int i=0; i<n; i++){
        if(binary_search(a, k, n)){
            cout<<"Yes";
            break;
        }
        else{
            cout<<"No";
            break;
        }
    }
}