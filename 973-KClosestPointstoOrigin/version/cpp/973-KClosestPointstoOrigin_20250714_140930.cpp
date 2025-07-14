// Last updated: 14/07/2025, 14:09:30
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max heap 
        priority_queue<pair<double, vector<int>>>maxHeap;
        // map<double,vector<int>> mp;
        for(vector<int> point: points ){
            double dist = sqrt(point[0]*point[0] + point[1]*point[1]);
            maxHeap.push({dist,point});
            // mp[dist] = point;
            if(maxHeap.size() > k){
                 maxHeap.pop();
            } 
        }
        vector<vector<int>> result;
        while(maxHeap.size() > 0){
            // pair<double, vector<int>> temp = maxHeap.top();
            // maxHeap.pop();
            result.push_back(maxHeap.top().second);
            maxHeap.pop();

        }
        return result;
    }
};