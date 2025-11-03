class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state) {
        if (state[node] != 0)
            return state[node] == 2; 
        
        state[node] = 1; 
        
        for (int nxt : adj[node]) {
            if (!dfs(nxt, adj, state))
                return false; // found cycle → unsafe
        }
        
        state[node] = 2; 
        return true;
    }

    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        // Build adjacency list
        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        vector<int> state(V, 0);
        vector<int> result;
        
        // Check each node
        for (int i = 0; i < V; i++) {
            if (dfs(i, adj, state))
                result.push_back(i);
        }
        
        return result;
    }
};
