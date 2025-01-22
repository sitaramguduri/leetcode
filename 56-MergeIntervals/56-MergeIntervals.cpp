class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back({intervals[0][0],intervals[0][1]});
        int n = intervals.size();

        for(int i = 1; i<n;i++){
            int start = res.back()[0];
            int end = res.back()[1];
            if(intervals[i][0] <= end){
                end = max(end,intervals[i][1]);
                res.pop_back();
                res.push_back({start,end});
            }else{
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return res;
    }
};