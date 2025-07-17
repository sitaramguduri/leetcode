// Last updated: 17/07/2025, 16:23:59
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        // vector<vector<int>> vis(n, vector<int> (m,0));
        // do I need a new image? if I have to perform changes 
        int oldColor = image[sr][sc];
        if(oldColor == color){
            return image;
        }
        queue<pair<int, int>> q;
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0,1,0,-1};
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i< 4;i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && nrow<n && ncol >=0 && ncol< m && image[nrow][ncol] == oldColor){
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};