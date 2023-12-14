// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int k=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<target){
                k++;
            }
        }
        return k;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0, 1, 1, 2, 2, 3, 3, 4};
    int target = 3;

    cout<<solution.searchInsert(nums, target);
}