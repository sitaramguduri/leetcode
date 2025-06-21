// Last updated: 21/06/2025, 00:08:32
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        // sorting : O(NlogN) and sorting approach
        // map is ordered by its keys
        // use sorting
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> arr;
        for(auto it: mp){
            arr.push_back({it.second,it.first});
        }
        // sort the above in descending order 
        sort(arr.rbegin(), arr.rend());
        vector<int> result;

        for(int i = 0; i< k; i++){
            result.push_back(arr[i].second);
        }
        return result;
        
    }
};