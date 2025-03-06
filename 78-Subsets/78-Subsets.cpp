class Solution {
public:
    void helper(vector<int>& nums, int i , vector<vector<int>> & res,vector<int> temp){
        if(i == nums.size() ){
            res.push_back(temp);
            return ;
        }
        // add the element to the temp
        
        helper(nums, i+1, res, temp);
        temp.push_back(nums[i]);
        helper(nums, i+1,res,temp);
        // temp.pop_back();
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res ;
        int i = 0;
        vector<int> temp;
        helper(nums,i,res, temp);
        return res;
    }
};