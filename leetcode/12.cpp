// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double res = 1.0;
        long long power = n; 
        if (n < 0) {
            x = 1 / x;
            power = -power;
        }
        while (power > 0) {
            if (power % 2 == 1) {
                res *= x;
            }
            x *= x;
            power /= 2;
        }
        return res;
    }
};

int main(){
    Solution solution;
    double x = 2.0000;
    int n = 10;
    cout<<solution.myPow(x,n);
}
