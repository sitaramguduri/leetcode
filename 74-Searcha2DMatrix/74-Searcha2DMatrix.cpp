class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int high = n*m-1;
        int low = 0;
        // cout<<"n: "<<n<< " m: "<<m<<endl;
        while(low <= high){
            int mid = (low + high)/2;
            // cout<<"mid: "<<mid<<" low: "<<low<<endl;
            int row = mid/m;
            int col = mid%m;
            // cout<<"row: "<<row<<"col: "<<col<<endl;
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col]<target){
                low = mid+1;
            }else{
                high = mid - 1;

            }
        }
        return false;
    }
};