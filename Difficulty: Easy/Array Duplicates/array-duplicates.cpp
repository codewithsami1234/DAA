class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            int index = abs(arr[i]) - 1;
            if (arr[index] < 0) {
                // Already seen, so it's a duplicate
                result.push_back(abs(arr[i]));
            } else {
                // Mark as seen
                arr[index] = -arr[index];
            }
        }
        return result;
    }
};
