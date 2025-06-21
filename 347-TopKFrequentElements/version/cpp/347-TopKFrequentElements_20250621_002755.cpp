// Last updated: 21/06/2025, 00:27:55
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
        // use max heap 
        // and remove k top elements
        //max heap is priority queue
        priority_queue<std::pair<int, int>, vector<std::pair<int,int>>,greater<std::pair<int, int>> > heap;
        for(auto it: mp){
            heap.push({it.second, it.first});
            if(heap.size() > k){
                heap.pop();
            }
        }
        vector<int> result;
        for(int i = 0; i< k; i++){
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
        

    }
};