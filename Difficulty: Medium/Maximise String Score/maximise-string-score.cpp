class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {

        int n = s.size();

        // Allowed jump table
        vector<vector<bool>> can(26, vector<bool>(26, false));
        for (auto &v : jumps)
            can[v[0]-'a'][v[1]-'a'] = true;
        for (int c = 0; c < 26; c++) 
            can[c][c] = true;

        // positions of each character
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++)
            pos[s[i]-'a'].push_back(i);

        // prefix sum of ASCII
        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; i++)
            pref[i+1] = pref[i] + s[i];

        // prefix per character
        vector<vector<long long>> prefChar(26, vector<long long>(n+1, 0));
        for (int c = 0; c < 26; c++) {
            for (int i = 0; i < n; i++) {
                prefChar[c][i+1] = prefChar[c][i] + 
                    ((s[i]-'a' == c) ? s[i] : 0);
            }
        }

        vector<long long> dp(n, -1);
        dp[0] = 0;

        // Pointers so each occurrence is used exactly once
        vector<int> ptr(26, 0);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] < 0) continue;

            int from = s[i] - 'a';

            for (int to = 0; to < 26; to++) {
                if (!can[from][to]) continue;

                auto &v = pos[to];

                // move pointer until v[ptr] > i
                while (ptr[to] < (int)v.size() && v[ptr[to]] <= i)
                    ptr[to]++;

                // now **only one loop** per character
                if (ptr[to] < (int)v.size()) {
                    int j = v[ptr[to]];

                    long long total = pref[j] - pref[i];
                    long long remove = prefChar[to][j] - prefChar[to][i];
                    long long score = total - remove;

                    dp[j] = max(dp[j], dp[i] + score);
                    ans = max(ans, dp[j]);
                }
            }
        }

        return ans;
    }
};
