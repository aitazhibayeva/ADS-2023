#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int uniq = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[uniq] = nums[i];
                ++uniq;
            }
        }

        return uniq;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = solution.removeDuplicates(nums);

    for (int i = 0; i < k; ++i) {
        cout << nums[i]<<" ";
    }
    return 0;
}