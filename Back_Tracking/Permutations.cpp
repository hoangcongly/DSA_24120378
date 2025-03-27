#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backTrack_Permutations(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backTrack_Permutations(nums, index + 1, result);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backTrack_Permutations(nums, 0, result);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> result = solution.permute(nums);
    
    cout << "Permutations of the input array: " << endl;
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
