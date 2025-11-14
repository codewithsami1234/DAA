class Solution {
public:
vector<vector<int>>result;
vector<int>current;
vector<int>used;
 void backtrack(vector<int>&nums){
    if(current.size() == nums.size()){
        result.push_back(current);
        return;
    }
    for(int i =  0; i < nums.size(); i++){
        if(used[i])
        continue;
        if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
        continue;
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums);
        used[i] = false;
        current.pop_back();
    }
 }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        used.assign(nums.size(), false);
        backtrack(nums);
        return result;
    }
};