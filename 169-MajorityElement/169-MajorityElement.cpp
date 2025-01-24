class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /// moore voting algorithm
        int count = 0; 
        int ele ;
        for(int i = 0; i<nums.size();i++){
            if(count == 0){
                ele = nums[i];
            }
             if(ele == nums[i]){
                count++;
            }
            if(ele!=nums[i]){
                count--;
            }
        }
        int final_count = 0;
        for(int i = 0;i<nums.size();i++){
            if(ele == nums[i]){
                final_count++;
            }
        }
        if(final_count>nums.size()/2){
            return ele;
        }  
        return -1;
    }
};