class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = nums[0];
        for(int i = 1; i < n ; i++)
         g = gcd(g, nums[i]);
         if( g > 1) return -1;
         int ones = count(nums.begin() , nums.end() , 1);
         if(ones > 0) return n - ones;
         int minLen = INT_MAX;
          for(int i =0; i <n; i++){
            int curGCD = nums[i];
            for(int j = i+1 ; j < n; j++){
                curGCD = gcd(curGCD , nums[j]);
                if( curGCD == 1 ){
                    minLen = min(minLen , j - i +1);
                    break;
                }
            }
          }
        return n + minLen - 2;
    }
};