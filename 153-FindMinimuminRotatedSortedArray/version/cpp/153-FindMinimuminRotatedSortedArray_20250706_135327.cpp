// Last updated: 06/07/2025, 13:53:27
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mini = INT_MAX;
        while(l <= r){
            if(nums[l] < nums[r]){
                mini = min(mini, nums[l]);
            }
            int m = (l+r)/2;

            if(nums[m] >= nums[l]){
                mini = min(mini, nums[m]);
                l = m+1;
            }else{
                mini = min(mini, nums[m]);
                r= m-1;
            }
        }
        return mini;
    }
};