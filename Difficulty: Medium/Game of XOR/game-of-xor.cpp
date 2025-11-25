class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        
        // If n is even 
        if (n % 2 == 0) return 0;
        
        // If n is odd 
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans ^= arr[i];
        }
        
        return ans;
    }
};
