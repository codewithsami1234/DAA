class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        int n = s.size();
        int INF = 1e9;
        int charCost[26][26];
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                charCost[i][j] = (i == j ? 0 : INF);
            }
        }

        //  Add all direct transformations
        for(int i = 0; i < transform.size(); i++){
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            charCost[u][v] = min(charCost[u][v], cost[i]);
        }

        //  Floyd-Warshall (all-pairs shortest path)
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(charCost[i][k] < INF && charCost[k][j] < INF)
                        charCost[i][j] = min(charCost[i][j], charCost[i][k] + charCost[k][j]);
                }
            }
        }

        //  Calculate total minimum cost
        int totalCost = 0;
        for(int i = 0; i < n; i++){
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if(a == b) continue;

            int minPairCost = INF;
            for(int c = 0; c < 26; c++){
                if(charCost[a][c] < INF && charCost[b][c] < INF){
                    minPairCost = min(minPairCost, charCost[a][c] + charCost[b][c]);
                }
            }

            if(minPairCost == INF) return -1; 
            totalCost += minPairCost;
        }

        return totalCost;
    }
};
