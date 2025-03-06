class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int> &res, int i, vector<vector<int>> &fin,int sum){
        if(sum>target){
            return;
        }
        if(i == candidates.size()){
            if(target == sum){
                fin.push_back(res);
                // return;
            }
            return;
        }
        
        res.push_back(candidates[i]);
        
        helper(candidates, target, res,i, fin,sum+candidates[i]);
        res.pop_back();
        
        helper(candidates, target, res, i + 1, fin,sum);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> res;
        vector<vector<int>> fin;
        helper(candidates, target, res, 0 ,fin,sum);
        return fin;
    }
};