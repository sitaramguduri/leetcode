class Solution {
public:
    bool binarySearch(vector<int> arr, int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] < target){
                low = mid+ 1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<matrix.size();i++){
            if(matrix[i][0]<= target && matrix[i][m-1]>=target ){
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};