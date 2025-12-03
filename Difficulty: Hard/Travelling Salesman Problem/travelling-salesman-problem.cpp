class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n == 1) return cost[0][0]; // handle single-city case

        int FULL = (1 << n);
        const int INF = 1e9;
        vector<vector<int>> dp(FULL, vector<int>(n, INF));

        dp[1][0] = 0; // mask with only city 0 visited

        for (int mask = 1; mask < FULL; mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u))) continue;
                if (dp[mask][u] == INF) continue;
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue;
                    int newMask = mask | (1 << v);
                    dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + cost[u][v]);
                }
            }
        }

        int ans = INF;
        int all = FULL - 1;
        for (int i = 1; i < n; i++) {
            ans = min(ans, dp[all][i] + cost[i][0]);
        }

        return ans;
    }
};
