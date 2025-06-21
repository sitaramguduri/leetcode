// Last updated: 21/06/2025, 00:41:14
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size() + 1);
        for(int i = 0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            freq[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i = freq.size()-1; i>=0; i--){
            for(auto n: freq[i]){
                res.push_back(n);
            }
            if(res.size() == k){
                break;
            }
        }
        return res;
    }
};