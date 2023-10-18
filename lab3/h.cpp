#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        if(i==0){
            a[i]=t;
        }
        else{
            a[i]= a[i-1]+t;
        }
    }
    int k;
    for(int i=0; i<m; i++){
        int l=0, r=n-1, mid, cnt=0;
        cin>>k;
        while(l<=r){
            mid = l + (r-l)/2;
            if(a[mid] == k){
                cnt = mid;
                break;
            }
            else if(a[mid]>k){
                cnt = mid;
                r = mid-1;
            }
            else{
                l = mid +1;
            }
        }
        cnt +=1;
        cout<<cnt<<endl;
    }
    return 0;
}