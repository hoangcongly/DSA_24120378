#include <iostream>
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

int main()
{
    vector<int> nums = {1, 2, 3}; // Mảng đầu vào
    vector<vector<int>> result; // Lưu tập con kết quả
    vector<int> current; // Tập con đang xét

    Subsets(nums);
}
