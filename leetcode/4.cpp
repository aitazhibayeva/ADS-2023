#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = 
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res=0;

        for(int i=0; i<s.size(); i++){
            if(i<s.size()-1 && roman[s[i]]<roman[s[i+1]]){
                res += roman[s[i+1]] - roman[s[i]];
                i++;   
            }
            else{
                res += roman[s[i]];
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    string s = "III";
    cout<<solution.romanToInt(s);
}