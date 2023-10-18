#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Heap {

    vector<ll> heap;
    ll cpt, cookies;

    Heap(ll cpt){
        this->cpt = cpt;
        this->cookies = 0;
    }

    ll parent(int i){
        return (i-1)/2;
    }
    ll left(int i){
        return 2*i+1;
    }
    ll right(int i){
        return 2*i+2;
    }

    void insert(ll val){
        this->heap.push_back(val);
        ll i = this->heap.size()-1;
        while(i != 0 && this->heap[parent(i)] > this->heap[i]){
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
            swap(this->heap[small], this->heap[i]);
            heapif(small);
        }
    }

    int extract(){
        if(this->heap.size()==0) return 0;
        if(this->heap.size()==1){
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

    void print(int x){
        if(this->heap.size() == this->cpt){
            ll min = this->extract();
            if(min>=x){
                this->insert(min);
                return;
            }
            else{
                this->insert(x);
                this->cookies -=min;
                this->cookies +=x;

            }
        }
        else{
            this->insert(x);
            this->cookies +=x;
        }
    }
};

int main(){
    
    ll n,k;
    cin>>n>>k;
    Heap heap(k);
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        int x;
        if(s == "insert"){
            cin>>x;
            heap.print(x);
        }
        else if(s == "print"){
            cout<<heap.cookies<<endl;
        }
    }
}