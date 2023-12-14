// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public: 
    int findSpecialInteger(vector<int> &v){
        int SpeInt = v.size()/4;

        for(int i=0; i<v.size()-SpeInt; i++){
            if(v[i] == v[i+SpeInt]){
                return v[i];
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;

    vector<int> v1 = {1,2,2,6,6,6,6,7,10};
    vector<int> v2 = {1,1};

    cout<<solution.findSpecialInteger(v1);
    // cout<<solution.findSpecialInteger(v2);
}