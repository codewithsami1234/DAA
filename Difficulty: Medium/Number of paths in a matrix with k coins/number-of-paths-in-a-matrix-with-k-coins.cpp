class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();  // fixed typo

        // 3D DP: dp[i][j][sum] = number of ways to reach (i, j) with sum = 'sum'
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        // Base case
        if (mat[0][0] <= k)
            dp[0][0][mat[0][0]] = 1;

        // Fill DP table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int sum = 0; sum <= k; sum++) {
                    if (i == 0 && j == 0)
                        continue;

                    if (sum >= mat[i][j]) {
                        int fromTop  = (i > 0) ? dp[i - 1][j][sum - mat[i][j]] : 0;
                        int fromLeft = (j > 0) ? dp[i][j - 1][sum - mat[i][j]] : 0;
                        dp[i][j][sum] = fromTop + fromLeft;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][k];
    }
};
