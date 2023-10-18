#include <iostream>
using namespace std;

void search(int a[], int size, int x){
    int cnt = 0, sum = 0;
    for(int i = 0; i < size; i++){
        if(a[i]  <= x){
            cnt++;
            sum += a[i];
        }
    }
    cout << cnt << " " << sum << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int p;
    cin >> p;
    int g[p];
    for(int i = 0; i < p; i++){
        cin >> g[i];
        search(a, n, g[i]);
    }
}