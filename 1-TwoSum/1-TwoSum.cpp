class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size();i++){
            int arr = nums[i];
            int needed = target - arr;
            if(mp.find(needed) != mp.end()){
                return {i,mp[needed]};
            }
            mp[arr] = i;
        }
        return {-1,-1};
    }
};