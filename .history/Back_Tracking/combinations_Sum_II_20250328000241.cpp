#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backTrack_combinationSum_II(vector<int>& candidates, int index, vector<int>& current, vector<vector<int>>& result, int target, int sum_cur) {
        if (sum_cur == target) {
            result.push_back(current);
            return;
        }
        if (sum_cur > target) return;

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            backTrack_combinationSum_II(candidates, i + 1, current, result, target, sum_cur + candidates[i]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        int sum_cur = 0;
        backTrack_combinationSum_II(candidates, 0, current, result, target, sum_cur);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 5};
    int target = 8;
    
    vector<vector<int>> result = solution.combinationSum2(candidates, target);
    
    cout << "Combinations that sum to " << target << ": " << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
