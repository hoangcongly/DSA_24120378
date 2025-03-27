#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backTrack_combinations_I(vector<int>& candidates, int index, vector<int>& current, vector<vector<int>>& result, int target, int sum_cur) {
        if(sum_cur == target) {
            result.push_back(current);
            return;
        }
        if(sum_cur > target) return;
        
        for(int i = index; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backTrack_combinations_I(candidates, i, current, result, target, sum_cur + candidates[i]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum_I(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        int sum_cur = 0;
        backTrack_combinations_I(candidates, 0, current, result, target, sum_cur);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> result = solution.combinationSum_I(candidates, target);
    
    cout << "Combinations that sum to " << target << ": " << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
