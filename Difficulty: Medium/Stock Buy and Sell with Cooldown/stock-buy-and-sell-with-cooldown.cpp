class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> buy(n, 0), sell(n, 0), cool(n, 0);
        buy[0] = -arr[0];
        sell[0] = 0;
        cool[0] = 0;

        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], cool[i-1] - arr[i]);
            sell[i] = buy[i-1] + arr[i];
            cool[i] = max(cool[i-1], sell[i-1]);
        }

        return max(sell[n-1], cool[n-1]);
    }
};
