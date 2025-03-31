#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backTrack_letterCombinations(string digits, int index, const vector<string>& phone, string& current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = phone[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backTrack_letterCombinations(digits, index + 1, phone, current, result);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;
        backTrack_letterCombinations(digits, 0, phone, current, result);
        return result;
    }
};
int main() {
    Solution solution;
    string digits;
    cout << "Enter digits: ";
    cin >> digits;
    
    vector<string> combinations = solution.letterCombinations(digits);
    
    cout << "Combinations are: ";
    for (const string& combo : combinations) {
        cout << combo << " ";
    }
    cout << endl;
    
    return 0;
}