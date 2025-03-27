#include <iostream>
#include <vector>
using namespace std;

void back_Tracking_SubSets(vector<int>&nums, int index, vector<int> & current, vector<vector<int>> &result)
{
    // cout << "Them mang con vao ket qua: ";
    // for (int num : current) 
    //{
    //cout << num << " ";
    //}
    //cout << endl;

    result.push_back(current);
    for(int i=index; i<nums.size(); i++)
    {
        current.push_back(nums[i]);
        back_Tracking_SubSets(nums, i+1, current,result);
       // cout << "Backtracking: Removing element: " << nums[i] << "---"<< i << "--- from subset.\n";
        current.pop_back(); 
    }
}
int main() 
{
    vector<int> nums = {1, 2, 3};  // Input test
    vector<vector<int>> result;
    vector<int> current;

    cout << "Cac tap con cua mang: {1, 2, 3} la:\n";
    back_Tracking_SubSets(nums, 0, current, result);

    cout << "\nDanh sach tap con duoc tao:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
}