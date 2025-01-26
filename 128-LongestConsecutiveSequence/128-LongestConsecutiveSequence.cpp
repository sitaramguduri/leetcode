class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0){
            return 0;
        }
        int longest = 1;
        int curr = 1;
        int last_smallest = INT_MIN;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i] == last_smallest +1){
                curr++;
                last_smallest = nums[i];
                longest = max(longest, curr);
            }else if(nums[i] == last_smallest){
                
            }
            else{
                curr = 1;
                last_smallest = nums[i];
            }
        }
        return longest;
    }
};