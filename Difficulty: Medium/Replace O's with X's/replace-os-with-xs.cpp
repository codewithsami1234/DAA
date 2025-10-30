class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 'O')
            return;

        grid[i][j] = '#'; // Mark safe

        dfs(grid, i+1, j, n, m);
        dfs(grid, i-1, j, n, m);
        dfs(grid, i, j+1, n, m);
        dfs(grid, i, j-1, n, m);
    }

    vector<vector<char>> fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Mark all 'O' connected to border as safe
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 'O')
            dfs(grid, i, 0, n, m);
            if(grid[i][m-1] == 'O') 
            dfs(grid, i, m-1, n, m);
        }

        for(int j = 0; j < m; j++){
            if(grid[0][j] == 'O') 
            dfs(grid, 0, j, n, m);
            if(grid[n-1][j] == 'O')
            dfs(grid, n-1, j, n, m);
        }

        // Step 2: Convert surrounded O -> X and restore safe markers
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'O') 
                grid[i][j] = 'X'; // surrounded
                else if(grid[i][j] == '#') 
                grid[i][j] = 'O'; // restore
            }
        }

        return grid;
    }
};
