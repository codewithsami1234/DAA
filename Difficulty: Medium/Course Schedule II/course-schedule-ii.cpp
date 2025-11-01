class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        
        vector<int> adj[n]; 
        vector<int> indegree(n,0);
        
        for(auto &p : prerequisites){
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto next : adj[node]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        
        if(topo.size() != n)
            return {};
        
        return topo;
    }
};
