class Solution {
  public:
    vector<int> parent, rankv;

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(rankv[a] < rankv[b])
            parent[a] = b;
        else if(rankv[b] < rankv[a])
            parent[b] = a;
        else{
            parent[b] = a;
            rankv[a]++;
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        int E = edges.size();
        if(E < V - 1) return -1;

        parent.resize(V);
        rankv.resize(V, 0);

        for(int i = 0; i < V; i++)
            parent[i] = i;
        for(auto &e : edges) {
            unionSet(e[0], e[1]);
        }
        int components = 0;
        for(int i = 0; i < V; i++) {
            if(find(i) == i)
                components++;
        }
        return components - 1;
    }
};
