class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        vector<int> dp(m, 0);

        for (int i = 0; i < n; i++) {
            int current_max = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], current_max + 1);
                }
                if (a[i] > b[j]) {
                    current_max = max(current_max, dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
