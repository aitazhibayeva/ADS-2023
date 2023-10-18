#include <bits/stdc++.h>
using namespace std;

struct Heap {
    vector<long long> heap;
    long long parent(int i){
        return (i-1)/2;
    }
    long long left(int i){
        return 2*i+1;
    }
    long long right(int i){
        return 2*i+2;
    }

    void insert(long long val){
        this->heap.push_back(val);
        long long i = this->heap.size()-1;
        while(i!=0 && this->heap[parent(i)]<this->heap[i]){
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }

    void heapif(long long i){
        long long l = this->left(i);
        long long r = this->right(i);
        long long small = i;
        if(l<this->heap.size() && this->heap[l] > this->heap[small]){
            small = l;
        }
        if(r<this->heap.size() && this->heap[r] > this->heap[small]){
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
            long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size()-1];
        this->heap.pop_back();
        this->heapif(0);
        return root;
    }
};

int main(){
    Heap heap;
    long long n, k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        heap.insert(x);
    }

    long long sum=0;
    for(int i=0; i<k; i++){
        long long root = heap.extra();
        sum+=root;
        heap.insert(root-1);
    }
    cout<<sum;

}