class Solution {
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bracket(n, vector<int>(n, 0));

        for (int l = 2; l < n; l++) {
            for (int i = 1; i < n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        function<string(int,int)> build = [&](int i, int j) -> string {
            if (i == j) return string(1, 'A' + i - 1);
            int k = bracket[i][j];
            return "(" + build(i, k) + build(k+1, j) + ")";
        };

        return build(1, n-1);
    }
};
