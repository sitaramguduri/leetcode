// Last updated: 19/06/2025, 00:45:39
class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        // Optimal Approach
        k = k%nums.size();
        int j = nums.size() - k;
        vector<int> temp(nums.size(), 0);
        for(int i = 0; i < j; i++){
                temp[k+i] = nums[i];
        }
        for(int i = 0; i< k;i++){
            temp[i] = nums[j+i];
        }
        for(int i = 0; i< nums.size(); i++){
            nums[i] = temp[i];
        }
        return;
        
        
    }
};