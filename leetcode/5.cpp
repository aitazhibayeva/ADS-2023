// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".    

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    string longestCommonPrefix(vector<string> &strs){
        if(strs.empty()){
            return "";
        }
        string pref = strs[0];
        for(int i=1; i<strs.size(); i++){
            while(strs[i].find(pref) != 0){
                pref = pref.substr(0, pref.length()-1);
                if(pref.empty()){
                    return "";
                }
            }
        }
        return pref;
    }
};

int main(){
    Solution solution;

    vector<string> ex = {"flower", "flow", "flight"};
    cout<<solution.longestCommonPrefix(ex);
}