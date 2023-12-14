#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int target, int start) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            backtrack(result, combination, candidates, target - candidates[i], i);
            combination.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, candidates, target, 0);
        return result;
    }
};


int main() {
    Solution solution;
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = solution.combinationSum(candidates1, target1);

    for (auto& res : result1) {
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
        }
    }

}
