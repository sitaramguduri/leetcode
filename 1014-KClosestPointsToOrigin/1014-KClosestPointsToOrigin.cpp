// Last updated: 17/07/2025, 20:51:45
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap 
        priority_queue<pair<int, vector<int>>>maxHeap;
        // map<double,vector<int>> mp;
        for(vector<int> point: points ){
            int dist = (point[0]*point[0] + point[1]*point[1]);
            maxHeap.push({dist,point});
            // mp[dist] = point;
            if(maxHeap.size() > k){
                 maxHeap.pop();
            } 
        }
        vector<vector<int>> result;
        result.reserve(k);
        
        while(maxHeap.size() > 0){
            // pair<double, vector<int>> temp = maxHeap.top();
            // maxHeap.pop();
            result.push_back(maxHeap.top().second);
            maxHeap.pop();

        }
        return result;
    }
};