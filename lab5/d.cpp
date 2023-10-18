#include <bits/stdc++.h>
using namespace std;
#define ll long long  
struct Heap {
    vector<ll> heap;
    ll parent(int i){
        return (i-1)/2;
    }
    ll left(int i){
        return 2*i + 1;
    }
    ll right(int i){
        return 2*i + 2;
    }

    void insert(ll val){
        this->heap.push_back(val);
        ll i = this->heap.size()-1;
        while(i!=0 && this->heap[parent(i)]>this->heap[i]){
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }

    void heapif(ll i){
        ll l = this->left(i);
        ll r = this->right(i);
        ll small = i;
        if(l<this->heap.size() && this->heap[l]<this->heap[small]){
            small = l;
        }
        if(r<this->heap.size() && this->heap[r]<this->heap[small]){
            small = r;
        }
        if(small != i){
            swap(this->heap[i], this->heap[small]);
            this->heapif(small);
        }
    }

    int extra(){
        if(this->heap.size() == 0) return 0;
        if(this->heap.size() == 1){
            ll root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        ll root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size()-1];
        this->heap.pop_back();
        this->heapif(0);
        return root;
    }

    ll getSize(){
        return this->heap.size();
    }

};

int main(){
    Heap heap;
    
    ll n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        heap.insert(x);
    }

    ll x, cnt=0;
    while(heap.getSize()>=2){
        ll d1 = heap.extra();
        if(d1>=k){
            x = d1;
            break;
        }
        ll d2 = heap.extra();
        x = d1 + d2*2;
        heap.insert(x);
        cnt++;
    }
    if(x >= k){
        cout<<cnt;
    }
    else{
        cout<<-1;
    }
}