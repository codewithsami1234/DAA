#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(int row, int col, vector<string> &board, int n) {
        // check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void solve(int row, vector<string> &board, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return ans;
    }
};

// int main() {
//     int n = 4;
//     Solution s;
//     vector<vector<string>> res = s.solveNQueens(n);

//     for (auto &sol : res) {
//         for (auto &row : sol)
//             cout << row << endl;
//         cout << endl;
//     }
//     return 0;
// }
