#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool compareTo(pair<pair<string,string>,double> &v1, pair<pair<string,string>,double> &v2){
    if(v1.second == v2.second){
        if(v1.first.first == v2.first.first){
            return v1.first.second < v2.first.second;
        }
        return v1.first.first < v2.first.first;
    }
    return v1.second < v2.second;
}

int part(vector<pair<pair<string, string>, double>> &v, int l ,int r){
    pair<pair<string,string>,double> pivot = v[r];
    int idx = l;
    for(int i=l; i<r; i++){
        if(compareTo(v[i], pivot)){
            swap(v[i], v[idx]);
            idx++;
        }
    }
    swap(v[idx], v[r]);
    return idx;
}

void quick_sort(vector<pair<pair<string, string>, double>> &v, int l, int r){
    if(l<r){
        int p = part(v, l, r);
        quick_sort(v, l, p-1);
        quick_sort(v, p+1, r);
    }
}

int main(){
    int n, k, cred;
    cin>>n;
    vector<pair<pair<string, string>, double>> v;
    for(int i=0; i<n; i++){
        double gpa=0;
        double sum=0;
        string lname, fname, grade;
        cin>>lname>>fname>>k;
        for(int j=0; j<k; j++){
            cin>>grade>>cred;
            sum+=cred;
            if(grade == "A+"){
                gpa += cred * 4;
            }
            else if(grade == "A"){
                gpa += cred * 3.75;
            }
            else if(grade == "B+"){
                gpa += cred * 3.5;
            }
            else if(grade == "B"){
                gpa += cred * 3;
            }
            else if(grade == "C+"){
                gpa += cred * 2.5;
            }
            else if(grade == "C"){
                gpa += cred * 2;
            }
            else if(grade == "D+"){
                gpa += cred * 1.5;
            }
            else if(grade == "D"){
                gpa += cred * 1;
            }
            else if(grade == "F"){
                gpa += cred * 0;
            }
        }
        v.push_back({{lname, fname}, gpa/sum});
    }
    quick_sort(v, 0, v.size()-1);
    for(auto i: v){
        cout<<i.first.first<<" "<<i.first.second<<" "<<fixed<<setprecision(3)<<i.second<<endl;
    }

}