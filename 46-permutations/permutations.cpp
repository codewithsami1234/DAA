class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &result, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);               // choose
            backtrack(nums, result, start + 1);       // explore
            swap(nums[start], nums[i]);               // un-choose (backtrack)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};
