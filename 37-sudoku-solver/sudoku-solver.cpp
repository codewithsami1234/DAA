class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == ch) 
            return false;      // check row
            if(board[i][col] == ch)
             return false;      // check column

            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;
            if(board[r][c] == ch) 
            return false;         // check 3x3 box
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isValid(board, row, col, ch)){
                            board[row][col] = ch;
                            if(solve(board)) return true;
                            board[row][col] = '.';  // backtrack
                        }
                    }
                    return false; // no valid number
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
