// Last updated: 15/07/2025, 17:34:38
class Solution {
public:
    void helper(vector<int>& arr, int target, int ind, vector<int>& temp, vector<vector<int>>& res){
        // if(ind >= arr.size()){
        //     return ;
        // }
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int i = ind; i< arr.size(); i++){
            if( i > ind && arr[i] == arr[i-1]){
                continue; 
            }
            if(arr[i] > target){
                break;
            }
            temp.push_back(arr[i]);
            helper(arr, target-arr[i], i+1, temp, res); 
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int ind = 0;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, ind, temp, res);
        return res;
    }
};