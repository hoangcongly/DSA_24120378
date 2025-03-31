#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backTrack(vector<vector<char>>& board, string word, int index, int i, int j) {
        if (index == word.length()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool check = backTrack(board, word, index + 1, i - 1, j) ||
                     backTrack(board, word, index + 1, i + 1, j) ||
                     backTrack(board, word, index + 1, i, j - 1) ||
                     backTrack(board, word, index + 1, i, j + 1);
        board[i][j] = temp;
        return check;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backTrack(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    
    if (sol.exist(board, word)) {
        cout << "Word exists in the board!" << endl;
    } else {
        cout << "Word does not exist in the board!" << endl;
    }
    
    return 0;
}
