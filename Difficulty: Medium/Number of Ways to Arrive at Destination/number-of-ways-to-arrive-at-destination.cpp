class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int, int>>> adj(V);
        const long long INF = 1e18;

        // build adjacency list
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];   
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(V, INF);       
        vector<long long> ways(V, 0);          

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {                 
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, wt] : adj[u]) {
                long long newDist = d + wt;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                }
                else if (newDist == dist[v]) {
                    ways[v] += ways[u];
                }
            }
        }

        return ways[V - 1];
    }
};
