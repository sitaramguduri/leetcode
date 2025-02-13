class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int index, int row, int col,int n,int m){
        if(index == word.size()){
            return true;
        }
        if(row<0 || col < 0 || row == m || col == n || board[row][col] != word[index]){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '!';
        bool top = helper(board, word, index + 1,row-1, col,n, m );
        bool bottom = helper(board, word, index + 1, row+1, col, n, m);
        bool left = helper(board, word, index + 1, row, col -1 , n, m);
        bool right = helper(board, word, index + 1, row, col + 1, n, m);
        board [row][col] = temp;
        return top || bottom || left || right ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int index = 0;
        for(int i = 0 ; i< m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[index]){
                    if(helper(board, word, index,i, j ,n, m )){
                        return true;
                    }
                } 
            }
        }
        return false;
    }
};