class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) {
            return result;
        }

        int start = nums[0];
        for (int i = 1; i <= n; i++) {
            // if end of array OR non-consecutive number
            if (i == n || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));  // single number
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));  // range
                }

                if (i < n) start = nums[i];  // start new range
            }
        }

        return result;
    }
};
