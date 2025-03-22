// 120325.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution12032025
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }
        return false;
    }

    bool containsDuplicateQuickSort(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }

    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;
        quickSort(s, 0, s.size() - 1);
        quickSort(t, 0, t.size() - 1);
        return s == t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        vector<string> sorted_word;
        for (string s : strs)
        {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            bool found = false;
            for (size_t i = 0; i < sorted_word.size(); i++)
            {
                if (sorted_word[i] == sorted_s)
                {
                    groups[i].push_back(s);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                groups.push_back({ s });
                sorted_word.push_back(sorted_s);
            }
        }
        return groups;
    }

private:
    void quickSort(vector<int>& nums, int low, int high)
    {
        if (low >= high) return;
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (nums[j] <= pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        int pi = i + 1;
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }

    void quickSort(string& str, int low, int high)
    {
        if (low >= high) return;
        char pivot = str[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (str[j] <= pivot)
            {
                i++;
                swap(str[i], str[j]);
            }
        }
        swap(str[i + 1], str[high]);
        int pi = i + 1;
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
};

class Solution13032025
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    result.push_back({ nums[i],nums[left],nums[right] });
                    while (left < right && nums[left] == nums[left + 1]) left++; // Bỏ qua các phần tử trùng lặp
                    while (left < right && nums[right] == nums[right - 1]) right--; // Bỏ qua các phần tử trùng lặp
                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else right--;
            }
        }
        return result;
   }
    int maxArea(vector<int>& height)
    {
        int left = 0; 
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right)
        {
            int h = min(height[left], height[right]);
            int width = right - left;
            max_area = max(max_area, h * width);
            if (height[left] < height[right])
                left++;
            else right--;
        }
        return max_area;
    }
    int maxSumArray(vector<int>& nums, int k)
    {
        if (nums.size() < k) return -1;
        int max_sum = 0;
        for (int i = 0; i < k; i++)
        {
            max_sum += nums[i];
        }
        int window_sum = max_sum;
        for (int i = k; i < nums.size(); i++)
        {
            window_sum = window_sum + nums[i] - nums[i - k];
            max_sum = max(max_sum, window_sum);
        }
        return max_sum;
    }
    int maxProfit(vector<int>& prices)
    {
        int min_price = prices[0];
        int max_profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];
            }
            else
            {
                int profit = prices[i] - min_price; 
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
            }
        }
        return max_profit;
    }
    int lengthOfLongesSubstring(string s)
    {
        vector<int> charIndex(256, -1);
        int maxLength = 0;
        int left = 0;
        for (int right = 0; right < s.size();right++)
        {
            if (charIndex[s[right]] != -1)
            {
                left = max(left, charIndex[s[right]] + 1);
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength,right-left+1);
        }
        return maxLength;
    }
    bool isValid(const string& s)
    {
        stack<char> stack;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty()) return false;
                char top = stack.top();
                if (c == ')' && top != '('
                    || c == ']' && top != '['
                    || c == '}' && top != '{')
                    return false;
                    stack.pop();
            }
        }
        return stack.empty();
    }
private:

};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
