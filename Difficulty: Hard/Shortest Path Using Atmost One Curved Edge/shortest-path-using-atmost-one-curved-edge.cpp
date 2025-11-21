class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {

        vector<vector<array<int,3>>> adj(V);

        // build adjacency list
        for(auto &e : edges){
            int x = e[0], y = e[1];
            int w1 = e[2], w2 = e[3];  
            adj[x].push_back({y, w1, w2});
            adj[y].push_back({x, w1, w2});
        }

        const int INF = 1e9;
        vector<vector<int>> dist(V, vector<int>(2, INF));

        // min-heap: {distance, node, usedCurved}
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;

        dist[a][0] = 0;
        pq.push({0, a, 0});  

        while(!pq.empty()) {
            auto [d, u, used] = pq.top();
            pq.pop();

            if(d != dist[u][used])
                continue;

            for(auto &ed : adj[u]) {
                int v  = ed[0];
                int w1 = ed[1];
                int w2 = ed[2];

                // straight edge
                if(d + w1 < dist[v][used]) {
                    dist[v][used] = d + w1;
                    pq.push({dist[v][used], v, used});
                }

                // curved edge (allowed only if used == 0)
                if(!used && d + w2 < dist[v][1]) {
                    dist[v][1] = d + w2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }

        int ans = min(dist[b][0], dist[b][1]);
        return ans >= INF ? -1 : ans;
    }
};
