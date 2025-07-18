// Last updated: 17/07/2025, 20:52:02
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(),0));
        vector<vector<int>> dis(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {-1,0,1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = row+drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow<n && ncol >= 0 && ncol < m&& !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    dis[nrow][ncol] = dist + 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }

        }
        return dis;

        
    }
};