#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    string longestCommonPrefix(vector<string> &strs){
        if(strs.empty()){
            return "";
        }

        string prefix = strs[0];
        for(int i=1; i<strs.size(); i++){
            while(strs[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.length()-1);
                if(prefix.empty()){
                    return "";
                }
            }
        }
        return prefix;
    }
};

int main(){
    Solution solution;

    vector<string> ex1 = {"flower", "flow", "flight"};
    vector<string> ex2 = {"dog", "rececar", "car"};

    cout<<solution.longestCommonPrefix(ex1);
}