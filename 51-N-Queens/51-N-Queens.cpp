class Solution {
public:
    bool isSafe(vector<string> & board, int row, int col, int n ){
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row --;
            col --;
        }
        col = dupcol;
        row =  duprow;

        while(col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        col = dupcol;
        row =  duprow;
        while(row<n && col >=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string>> & ans,int n){
        if(col >= n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row< n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n );
                board[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i< n; i++){
            board[i] = s;
        }
        solve(0, board, ans,n);
        return ans;
    }
};