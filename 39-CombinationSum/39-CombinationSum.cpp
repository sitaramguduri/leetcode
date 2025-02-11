class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int> &res, int i, vector<vector<int>> &fin){
        // if(i == candidates.size()){
            if(target == 0){
                fin.push_back(res);
                return;
            }
        // }
        if(i >= candidates.size()||target<0 ){
            
            return ;
        }
        res.push_back(candidates[i]);
        
        helper(candidates, target-candidates[i], res,i, fin);
        res.pop_back();
        
        helper(candidates, target, res, i + 1, fin);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> res;
        vector<vector<int>> fin;
        helper(candidates, target, res, 0 ,fin);
        return fin;
    }
};