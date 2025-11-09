#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int dp[51][51][51]; // 3D DP array

    int solve(vector<vector<int>>& mat, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2; 

        // Out of bounds or blocked
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
            mat[r1][c1] == -1 || mat[r2][c2] == -1)
            return INT_MIN;

        // Base case: both reached destination
        if (r1 == n - 1 && c1 == n - 1)
            return mat[r1][c1];

        // Memoization check
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int ans = 0;
        if (r1 == r2 && c1 == c2)
            ans = mat[r1][c1];
        else
            ans = mat[r1][c1] + mat[r2][c2];

        // Explore all four possible moves
        int temp = max({
            solve(mat, r1 + 1, c1, r2 + 1), 
            solve(mat, r1, c1 + 1, r2),     
            solve(mat, r1 + 1, c1, r2),     
            solve(mat, r1, c1 + 1, r2 + 1)  
        });

        ans += temp;
        return dp[r1][c1][r2] = ans;
    }

    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size();
        memset(dp, -1, sizeof(dp));

        int res = solve(mat, 0, 0, 0);
        return max(0, res); 
    }
};

// int main() {
//     Solution obj;

//     vector<vector<int>> mat1 = {{0,1,-1},{1,1,-1},{1,1,2}};
//     cout << obj.chocolatePickup(mat1) << endl; // Output: 7

//     vector<vector<int>> mat2 = {{1,1,0},{1,1,1},{0,1,1}};
//     cout << obj.chocolatePickup(mat2) << endl; // Output: 7

//     vector<vector<int>> mat3 = {{1,0,-1},{2,-1,-1},{1,-1,3}};
//     cout << obj.chocolatePickup(mat3) << endl; // Output: 0
// }
