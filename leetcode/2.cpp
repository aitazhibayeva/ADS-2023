// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); ++i) {
            int com = target - nums[i];
            if (numMap.find(com) != numMap.end()) {
                return {numMap[com], i};
            }
            numMap[nums[i]] = i;
        }
        return {}; 
    }
};

int main(){
    Solution solution;

    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> v = solution.twoSum(nums, target);
    cout<<v[0]<<' '<<v[1];
}