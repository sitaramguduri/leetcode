class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n;i++){
            for(int j = 0; j<i;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
                // swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};