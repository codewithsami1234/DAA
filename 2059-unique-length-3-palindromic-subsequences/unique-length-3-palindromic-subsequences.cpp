class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int>first(26 , -1),last(26, -1);
        for(int i =0; i < n; i++){
            int c = s[i] - 'a';
            if(first[c] == -1) first[c] =i;
            last[c] =i;
        }
        int ans =0;
        for(int x =0; x < 26; x++){
            if(first[x] == -1 || first[x] == last[x])
            continue;
            int l = first[x];
            int r = last[x];
            unordered_set<char>mid;
            for(int i = l+1; i < r; i++){
                mid.insert(s[i]);
            }
            ans += mid.size();
        }
        return ans;
    }
};