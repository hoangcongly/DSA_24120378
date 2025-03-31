#include <iostream>
#include <string>
#include <vector>
using namespace std;

void back_Tracking_SubSets(vector<int>&nums, int index, vector<int> & current, vector<vector<int>> &result)
{
    cout << "Them mang con vao ket qua: ";
    for (int num : current) 
    {
    cout << num << " ";
    }
    cout << endl;

    result.push_back(current);
    for(int i=index; i<nums.size(); i++)
    {
        current.push_back(nums[i]);
        back_Tracking_SubSets(nums, i+1, current,result);
        cout << "Backtracking: Removing element: " << nums[i] << "---"<< i << "--- from subset.\n";
        current.pop_back(); 
    }
}
/*
nums={1,2,3}
1. gọi backtrack(nums,0)
index=0 current={}, for chạy từ 0 đến 3,
chạy for với i=0, chọn current={1}, gọi backtrack(nums,1)
2. gọi backtrack(nums,1)
index=1, current= {{},{1}}, for chạy từ 1 đến 3,
chạy for với i=1, chọn current={1,2}, gọi backtrack(nums,2)
3. gọi backtrack(nums,2)
index=2, current={{},{1},{1,2}}, for chạy từ 2 đến 3,
chạy for với i=2, chọn current={1,2,3}, gọi backtrack(nums,3)
4. gọi backtrack(nums,3)
index=3, for chạy từ 3-> 3 false kết thúc đệ quy
Sau đó quay lui loại {3}, quay lại backtrack(nums,2), tiếp tục chạy for ở i=2 nhưng đã hết nên quay lại backtrack(nums,1);
Tiếp tục for với i=2
*/
vector<vector<int>> Subsets(vector<int>&nums)
{
    vector<vector<int>> result;
    vector<int> current;
    back_Tracking_SubSets(nums,0, current,result);
    return result;
}

bool backTrack(vector<vector<char>>&board, string word,int index, int i, int j)
    {
        if(index==word.length()) return true;
        if(i<0|| i>=board.size()||j<0||j>=board[0].size()|| word[index]!=board[i][j]) return false;
        char temp= board[i][j];
        board[i][j]= '#';
        bool check= backTrack(board, word, index+1,i-1, j)||
                    backTrack(board, word, index+1,i+1, j)||
                    backTrack(board, word, index+1, i, j-1)||
                    backTrack(board, word, index+1, i, j+1);
        board[i][j]= temp;
        return check;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size();j++)
            {
                if(backTrack(board, word, 0, i, j))
                return true;
            }
        }
        return false;
    }
    void backTrack_letterCombinations(string digits, int index,const vector<string>&phone,string&current, vector<string>& result)
    {
        if(index==digits.length())
        {
            result.push_back(current);
            return;
        }
        string letters= phone[digits[index]-'0'];
        for(char letter:letters)
        {
            current.push_back(letter);
            backTrack_letterCombinations(digits,index+1,phone,current,result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty()) return {};
        vector<string> phone= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        string current;
        backTrack_letterCombinations(digits,0,phone,current,result);
        return result;
    }
        // combinations sum
        void backTrack_combinations_I(vector<int>&candidates, int index, vector<int>&current, vector<vector<int>>& result, int target, int sum_cur)
    {
        if(sum_cur==target)
        {  
            result.push_back(current);
            return;
        }
        if(sum_cur>target) return;
        for(int i=index; i<candidates.size(); i++)
        {
            //sum_cur+=candidates[i];
            current.push_back(candidates[i]);
            backTrack_combinations_I(candidates,i,current,result, target, sum_cur+candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum_I(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> current;
        int sum_cur=0;
        backTrack_combinations_I(candidates,0, current, result, target,sum_cur);
        return result;
    }
    // combinations sum II
    void backTrack_combinationSum_II(vector<int>&candidates, int index, vector<int>&current, vector<vector<int>>&result,int target, int sum_cur)
    {
        if(sum_cur==target)
        {
            result.push_back(current);
            return;
        }
        if(sum_cur>target) return;
        for(int i=index; i<candidates.size(); i++)
        {
            current.push_back(candidates[i]);
            backTrack_combinationSum_II(candidates,i+1,current,result,target,sum_cur+candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>&candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        int sum_cur=0;
        backTrack_combinationSum_II(candidates,0,current,result,target,sum_cur);
        return result;
    }
    // Permutations
    void backTrack_Permutations(vector<int>&nums, int index, vector<int>&current,vector<vector<int>>&result)
    {
        if(index==nums.size())
        result.push_back(current);
        for(int i=index; i<nums.size(); i++ )
        {
            current.push_back(nums[i]);
            backTrack_Permutations(nums,i,current,result);
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>&nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        backTrack_Permutations(nums,0,current,result);
        return result;
    }   
    
int main()
{
    vector<int> nums = {1, 2, 3}; // Mảng đầu vào
    vector<vector<int>> result; // Lưu tập con kết quả
    vector<int> current; // Tập con đang xét

    Subsets(nums);
}
