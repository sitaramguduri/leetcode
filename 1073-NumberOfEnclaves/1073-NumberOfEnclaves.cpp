// Last updated: 17/07/2025, 20:51:41
class Solution {
public:
    void dfs(vector<vector<int>> & grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        for(int i = 0; i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(grid,vis,nrow, ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(grid,vis, i,0);

            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(grid, vis, i,m-1);
            }
        }

        for(int i = 0; i<m;i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(grid,vis, 0,i);

            }
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                dfs(grid, vis, n-1,i);
            }
        }
        int count = 0 ;
        for(int i = 0 ; i<n;i++){
            for(int j = 0; j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count ++;
                }
            }
        }
        return count;
    }
};