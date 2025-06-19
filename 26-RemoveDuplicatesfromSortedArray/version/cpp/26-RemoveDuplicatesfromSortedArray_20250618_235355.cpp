// Last updated: 18/06/2025, 23:53:55
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // optimal approach : Time complexity:O(N)
        int i = 0;
        int j = 1;
        while(j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
                continue;
            }else{
                nums[i+1] = nums[j];
                i++;
                 j++;
            }
        }
        return i+1;
        
    }
};