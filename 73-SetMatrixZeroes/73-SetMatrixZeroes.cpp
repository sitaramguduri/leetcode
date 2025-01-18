class Solution {
public:
    void helper(vector<vector<int>>&matrix, int n , int m){
        int * row = new int[n]();
        int * col = new int[m]();
        for(int i = 0; i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout<<row[i];
        // }
        // cout<<endl;
        // for(int j = 0; j< m; j++){
        //     cout<<col[j];
        // }
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(row[i]||col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        return helper(matrix,n, m );
    }
};