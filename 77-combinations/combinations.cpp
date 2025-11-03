class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int start, int n, int k) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            backtrack(i + 1, n, k);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};
