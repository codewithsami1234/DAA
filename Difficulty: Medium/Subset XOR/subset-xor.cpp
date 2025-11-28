class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // Step 1: Compute XOR(1..n) using pattern
        int X;
        if (n % 4 == 0) X = n;
        else if (n % 4 == 1) X = 1;
        else if (n % 4 == 2) X = n + 1;
        else X = 0;

        int R = X ^ n;   // XOR of the elements we must remove

        vector<int> ans;

        // Case 1: No removal needed
        if (R == 0) {
            ans.reserve(n);
            for (int i = 1; i <= n; i++)
                ans.push_back(i);
            return ans;
        }

        // Case 2: Remove one number
        if (R >= 1 && R <= n) {
            ans.reserve(n - 1);
            for (int i = 1; i <= n; i++)
                if (i != R) ans.push_back(i);
            return ans;
        }

        // Case 3: Need to remove two numbers a, b such that a ^ b = R
        int a = -1, b = -1;
        for (int i = 1; i <= n; i++) {
            int j = i ^ R;
            if (j >= 1 && j <= n && j != i) {
                a = i;
                b = j;
                break;   // lexicographically smallest pair
            }
        }

        ans.reserve(n - 2);
        for (int i = 1; i <= n; i++) {
            if (i != a && i != b)
                ans.push_back(i);
        }

        return ans;
    }
};
