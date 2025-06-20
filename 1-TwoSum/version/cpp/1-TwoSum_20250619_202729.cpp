// Last updated: 19/06/2025, 20:27:29
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // optimal approach : using hashmap
        unordered_map<int, int> mp;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int isThere = target - nums[i];
            if(!mp.contains(isThere)){
                mp[nums[i]] = i;
            }else{
                result.push_back(i);
                result.push_back(mp[isThere]);
            }
        }
        return result;


    }
};