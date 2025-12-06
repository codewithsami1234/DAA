class Solution {
public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                
                long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
                long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                long long z = (i <= j - 2) ? dp[i][j - 2] : 0;

                dp[i][j] = max(
                    arr[i] + min(x, y),
                    arr[j] + min(y, z)
                );
            }
        }
        return dp[0][n - 1];
    }
};
