// Last updated: 17/07/2025, 20:51:42
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int level = 0; 
        // find the level from different rotten oranges 
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        // int vis[n][m];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int fresh = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    fresh ++;
                }
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int maxTime = 0;
        int rotten = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            int drow[4] = {-1,0,1,0};
            int dcol[4] = {0,1,0,-1};
            maxTime = max(maxTime, time);
            for(int i = 0; i< 4; i++){
                int nrow = row+drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow<n && ncol>= 0 && ncol < m
                 && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    rotten ++;
                    q.push({{nrow, ncol}, time+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        if(rotten != fresh){
            return -1;
        }
        return maxTime;
        
    }
};