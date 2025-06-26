// Last updated: 26/06/2025, 12:28:03
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // hashset to find duplicates in rows and columns
       
        for(int i = 0; i< board.size(); i++){
            unordered_set<char> row;
            unordered_set<char> col;
            // bool result = true;
            for(int j = 0; j< board[0].size(); j++){
                if(board[i][j]!= '.'  && ( board[i][j] > '0' && board[i][j] <= '9')){
                    if(!row.contains(board[i][j])){
                    row.insert(board[i][j]);
                    }else{
                    // result = false;
                    return false;
                    }
                }else if (board[i][j] != '.'){
                    return false;
                }
                if(board[j][i] != '.' && (board[j][i] > '0' && board[j][i] <= '9')){
                    if(!col.contains(board[j][i])){
                    col.insert(board[j][i]);
                    }else{
                    // result = false;
                    return false;
                    }
                }else if (board[j][i] != '.'){
                    return false;
                }
                
                
            }
            // hashmap with pair as key and hashset as value
            
        }
        map<pair<int, int>, set<char>> mp;
            for(int i = 0; i< 9; i++){
                for(int j = 0; j< 9; j++){
                    if(board[i][j]!= '.'){
                        if(!mp[{i/3,j/3}].contains(board[i][j])){
                            mp[{i/3, j/3}].insert(board[i][j]);
                        }else{
                            return false;
                        }
                    }
                    

                }
            }
            return true;
    }
};