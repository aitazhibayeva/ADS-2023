#include <iostream>
#include <vector>
using namespace std;

vector <string> lines;

bool cmp(string a, string b){
    if(a.size() == b.size()) return true;
    else return a.size()<b.size();
}

void merge(int l, int m, int r){
    int a1 = m - l + 1;
    int a2 = r - m;
    vector<string> left(a1), right(a2);

    for(int i=0; i<a1; i++){
        left[i] = lines[l+i];
    } 
    for(int i=0; i<a2; i++){
        right[i] = lines[m+i+1];
    }

    int i=0, j=0, k=l;
    while(i<a1 && j<a2){
        if(cmp(left[i],right[j])){
            lines[k++] = left[i++];
        }
        else{
            lines[k++] = right[j++];
        }
    }

    while(i<a1){
        lines[k++] = left[i++];
    }
    while(j<a2){
        lines[k++] = right[j++];
    }
}

void merge_sort(int l, int r){
    if(l<r){
        int m = l +(r-l)/2;
        merge_sort(l,m);
        merge_sort(m+1, r);
        merge(l,m,r);
    }
}

void print(){
    for(int i=0; i<lines.size(); i++){
        cout<<lines[i]<<' ';
    }
    cout<<endl;
    lines.clear();
}

int main(){
    int n; cin>>n;
    string s;
    getline(cin, s);
    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);
        string word = "";
        for(int j=0; j<line.size(); j++){
            if(line[j] == ' '){
                lines.push_back(word);
                word="";
            }
            else if(line[j]!=' '){
                word += line[j];
            }
        }
        lines.push_back(word);
        merge_sort(0, lines.size()-1);
        print();
    }
}