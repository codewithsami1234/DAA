class Solution {
  public:
  
    unordered_map<int,int> parent;
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b) parent[b] = a;
    }
    
    int maxRemove(vector<vector<int>>& stones) {
        int OFFSET = 10001;  
        for(auto &s : stones){
            int r = s[0];
            int c = s[1] + OFFSET;
            
            if(!parent.count(r)) parent[r] = r;
            if(!parent.count(c)) parent[c] = c;
            
            unite(r, c);
        }
        
        // count connected components
        unordered_set<int> comps;
        for(auto &s : stones){
            comps.insert(find(s[0]));
        }
        
        return stones.size() - comps.size();
    }
};
