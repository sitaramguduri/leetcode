// Last updated: 22/07/2025, 13:53:22
class Solution {
public:
    int n, m;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& ocean){
        ocean[row][col] = true;
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow <n && ncol >=0 && ncol < m && !ocean[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]){
                dfs(nrow, ncol, heights, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pac(n, vector<bool>(m,false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for(int i = 0; i<n;i++){
            dfs(i,0,heights,pac);
            dfs(i,m-1,heights, atl);
        }
        for(int i = 0; i<m; i++){
            dfs(0,i, heights, pac);
            dfs(n-1, i , heights, atl);
        }
        vector<vector<int>> res;
        for(int i = 0; i<n; i++){
            for(int j = 0; j < m; j++){
                if(pac[i][j] && atl[i][j]){
                   res.push_back({i,j});
                }
            }
        }
        return res;
    }
};