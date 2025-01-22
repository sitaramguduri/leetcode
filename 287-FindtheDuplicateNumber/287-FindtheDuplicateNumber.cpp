class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sorting
        int result = -1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 1; i<n;i++){
            if(nums[i] == nums[i-1]){
                result = nums[i];
            }
        }
        return result;
    }
    
};