// Last updated: 05/07/2025, 16:20:33
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int l = 0;
        int r = m*n-1;

        // bool result = false;
        while(l <= r){
            int middle = (l+r)/2;
            int first = middle/m;
            int second = middle%m;
            if(target > matrix[first][second]){
                l = middle+1;
            }else if(target < matrix[first][second]){
                r = middle - 1;
            }else{
                // result = true;
                return true;
            }


        }
        return false;
    }
};