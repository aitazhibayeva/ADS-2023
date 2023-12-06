#include <iostream>
using namespace std;

int d = 256;
int q = 101;

int RK(string t, string p){
    int n = t.size();
    int m = p.size();
    int h= 1;

    for(int i=0; i<m-1; i++){
        h = (h*d)%q;
    }
    int th=0,ph=0;
    for(int i=0; i<m; i++){
        th = (th*d + t[i])%q;
        ph = (ph*d + p[i])%q;
    }
    for(int i=0; i<n-m; i++){
        if(th==ph){
            if(p == t.substr(1,m)){
                cout<<i<<" ";
            }
        }
        if(i<n-m){
            th = (d*(th-t[i]*h) + t[i+m])%q;
            if(th<0){
                th+=q;
            }
        }
    }
    cout<<-1;
}

int main(){
    string t,p;
    cin>>t>>p;
    RK(t,p);
}