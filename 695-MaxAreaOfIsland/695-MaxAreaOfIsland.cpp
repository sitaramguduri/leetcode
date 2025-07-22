// Last updated: 22/07/2025, 13:53:13
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int& area){
        vis[row][col] = 1;
        area += 1;
        // cout<<" area: "<< area<<endl;
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {-1,0,1,0};
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<4; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                dfs(grid, vis, nrow, ncol,area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>>vis(n, vector<int> (m, 0));
        int maxArea = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int area = 0;
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(grid, vis, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};