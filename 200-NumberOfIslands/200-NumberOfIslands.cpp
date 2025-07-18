// Last updated: 17/07/2025, 20:52:25
class Solution {
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &visited,int row, int col){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q ;
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dx[4] = {-1,0,1,0};
            int dy[4] = {0,1,0,-1};
            for(int i =0;i<4;i++){
                // for(int j = 0 ;j<4;j++){
                    int rx = r+dx[i];
                    int cx = c+dy[i];
                    if(rx>=0 && rx<n && cx >=0 && cx<m && grid[rx][cx] == '1' && visited[rx][cx] == 0){
                        visited[rx][cx] = 1;
                        q.push({rx,cx});
                    }
                // }
            }
        }
        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    count++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }
};