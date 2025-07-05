// Last updated: 05/07/2025, 15:39:40
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;
        int left = 0;
        int right = nums.size() -1 ;
        while(left <= right){
            int middle = (left + right)/2;
            cout<< middle << endl;
            if(target < nums[middle] ){
                right = middle-1;
            }else if(target > nums[middle]){
                left = middle + 1;
            }else{
                result = middle;
                return result;
            }
        }
        return result;

    }
};