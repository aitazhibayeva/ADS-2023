// Given two binary strings a and b, return their sum as a binary string.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = ""; 
        int carry = 0;     
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = 0;
            if (i >= 0) {
                sum += (a[i] - '0');
                i--;
            }
            if (j >= 0) {
                sum += (b[j] - '0');
                j--;
            }
            sum += carry;
            result = to_string(sum % 2) + result;
            carry = sum / 2;
        }
        return result;
    }
};
int main(){
    Solution solution;
    string a = "11";
    string b = "1";
    cout<<solution.addBinary(a,b);
}
