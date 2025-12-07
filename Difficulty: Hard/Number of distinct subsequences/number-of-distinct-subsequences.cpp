class Solution {
public:
    int distinctSubseq(string &str) {
        const int MOD = 1e9 + 7;
        int n = str.size();

        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        dp[0] = 1;  

        for (int i = 1; i <= n; i++) {
            int ch = str[i - 1] - 'a';

            // double the subsequences
            dp[i] = (2LL * dp[i - 1]) % MOD;
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + MOD) % MOD;
            }
            last[ch] = i;
        }

        return dp[n];
    }
};
