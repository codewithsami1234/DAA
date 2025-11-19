class Solution {
  public:
  int n , m;

  bool canReach(vector<vector<int>>& mat, int mid) {

      vector<vector<int>> vis(n , vector<int>(m ,0));
      queue<pair<int , int>> q;

      q.push({0,0});
      vis[0][0] = 1;

      int dx[4] = {1, -1, 0, 0};
      int dy[4] = {0, 0, 1, -1};

      while(!q.empty()){
          auto p = q.front();
          q.pop();

          int x = p.first;   
          int y = p.second;  

          if(x == n-1 && y == m-1)
              return true;

          for(int k = 0; k < 4; k++){
              int nx = x + dx[k];
              int ny = y + dy[k];

              if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]){
                  if(abs(mat[x][y] - mat[nx][ny]) <= mid){
                      vis[nx][ny] = 1;
                      q.push({nx , ny});
                  }
              }
          }
      }
      return false;
  }

  int minCostPath(vector<vector<int>>& mat) {

      n = mat.size();
      m = mat[0].size();

      int low = 0, high = 1e6, ans = high;

      while(low <= high){

          int mid = (low + high) / 2;

          if(canReach(mat , mid)){
              ans = mid;
              high = mid - 1;
          } 
          else {
              low = mid + 1;
          }
      }

      return ans;
  }
};
