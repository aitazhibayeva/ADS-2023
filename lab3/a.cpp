#include <iostream>
using namespace std;

int binary_search_even(int a[], int i, int y){
    int l=0, r=y-1, mid;
    while(l<=r){
        mid = l + (r - l) / 2;
        if(i > a[mid]){
            r = mid - 1;
        }
        else if( i < a[mid]){
            l = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int binary_search_odd(int a[], int i, int y){
    int l=0, r=y-1, mid;
    while(l<=r){
        mid = l + (r - l) / 2;
        if(i > a[mid]){
            l = mid + 1;
        }
        else if(i < a[mid]){
            r = mid - 1;
        }
        else {
            return mid;
        }
    } 
    return -1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int x,y;
    cin>>x>>y;
    int b[x][y];
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin>>b[i][j];
        }
    }
    int idx=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<x; j++){
            if(j%2==0){
                idx = binary_search_even(b[j], a[i] ,y);
                if(idx != -1){
                    cout<<j<<" "<<idx<<endl;
                    break;
                }
                else if(idx == -1 && j == x-1){
                    cout<<-1<<endl;
                }
            }
            else if(j%2==1){
                idx = binary_search_odd(b[j], a[i], y);
                if(idx !=-1){
                    cout<<j<<" "<<idx<<endl;
                    break;
                }
                else if(idx == -1 && j == x - 1){
                    cout<<-1<<endl;
                }
            }
        }
    }
    return 0;
}
