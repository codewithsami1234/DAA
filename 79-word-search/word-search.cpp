class Solution {
public:
    int m ,n;
    
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string& word) {
        if(idx == word.size())
            return true;
        
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;
        
        if(board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';  // mark visited
        
        bool found = dfs(i+1, j, idx+1, board, word) ||
                     dfs(i-1, j, idx+1, board, word) ||
                     dfs(i, j+1, idx+1, board, word) ||
                     dfs(i, j-1, idx+1, board, word);  
        
        board[i][j] = temp;  // unmark
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};
