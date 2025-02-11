class Solution {
public:
    void helper(vector<int>& candidates, int target, int ind ,vector<int>& temp, vector<vector<int>>& res){
        if(target == 0 ){
            res.push_back(temp);
            return;
        }
        for(int i = ind; i< candidates.size();i++){
            if(i>ind && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            temp.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i+1, temp, res);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res ;
        vector<int> temp;
        helper(candidates, target,0, temp, res);
        return res;
    }
};