#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n][4];
    int max_l=0;
    for(int i=0; i<n; i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
        int local_max = *max_element(a[i], a[i]+4);
        if(local_max >max_l){
            max_l = local_max;
        }
    }
    int l=1, r=max_l, mid, res;
    while(l<=r){
        mid = l + (r-l)/2;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(mid>=a[i][0]&&mid>=a[i][1]&&mid>=a[i][2]&&mid>=a[i][3]){
                cnt ++;
            }
        }
        if(cnt>=k){
            res = mid;
            r = mid-1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<res;
}