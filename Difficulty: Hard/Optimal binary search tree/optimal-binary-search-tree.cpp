class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefix(n + 1, 0);

        // Correct prefix sum
        for(int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + freq[i];

        // Base case: cost of a single key
        for(int i = 0; i < n; i++)
            dp[i][i] = freq[i];

        // L = chain length
        for(int L = 2; L <= n; L++) {
            for(int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                dp[i][j] = INT_MAX;

                int sumFreq = prefix[j + 1] - prefix[i];

                for(int r = i; r <= j; r++) {
                    int left = (r > i) ? dp[i][r - 1] : 0;
                    int right = (r < j) ? dp[r + 1][j] : 0;

                    dp[i][j] = min(dp[i][j], left + right + sumFreq);
                }
            }
        }

        return dp[0][n - 1];
    }
};
