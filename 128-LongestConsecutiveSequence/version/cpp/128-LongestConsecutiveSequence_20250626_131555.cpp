// Last updated: 26/06/2025, 13:15:55
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount = 1;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] - nums[i-1] == 1){
                count++;
                maxCount = max(maxCount, count);
            }else if(nums[i] - nums[i-1] > 1){
                count = 1;
            }
        }
        return maxCount;
    }
};