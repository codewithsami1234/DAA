class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int prev1 = 0, prev2 =0;
        for(int i=1; i< height.size(); i++){
            int one = prev1 + abs(height[i] - height[i-1]);
            int two = INT_MAX;
            if(i > 1) two = prev2 + abs(height[i] - height[i-2]);
            int curr = min( one , two);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};