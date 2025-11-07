class Solution {
  public:
    int findLast(vector<vector<int>> &jobs, int i) {
        int low = 0, high = i - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid][1] <= jobs[i][0]) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int maxProfit(vector<vector<int>> &jobs) {
        int n = jobs.size();
        
        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        
        for (int i = 1; i < n; i++) {
            int include = jobs[i][2];
            int last = findLast(jobs, i);
            if (last != -1)
                include += dp[last];
            
            dp[i] = max(dp[i - 1], include);
        }
        
        return dp[n - 1];
    }
};
