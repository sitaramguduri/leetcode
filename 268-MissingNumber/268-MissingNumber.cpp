// Last updated: 17/07/2025, 20:52:13
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::map<int,int> mp;
        for(auto &i:nums){
            mp[i]++;
        }
        int res = 0;
        for(int i = 0;i<=nums.size();i++){
            if(mp[i]==0){
                res = i;
                // return i;
            }
        }
        return res;
    }
};