// Given an integer x, return true if x is a 
// palindrome, and false otherwise.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
     bool isPalindrome(int x) {
        string first = to_string(x);
        string second = first;
        reverse(second.begin(), second.end());

        if(first == second){
            return true;
        }
        return false;
    }
};

int main(){
    Solution solution;
    int x = 121;
    cout<<solution.isPalindrome(x);
}