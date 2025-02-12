class Solution {
public:
    void helper(vector<int> & nums, int ind, vector<int> & temp, vector<vector<int>>& fin){
        // if(ind == nums.size()-1){
            fin.push_back(temp);
            // return;
        // }
        for(int i = ind; i< nums.size();i++){
            if(i>ind && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            helper(nums, i+1, temp, fin);
            temp.pop_back();
            // helper(nums, i+1,temp, fin);
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> fin;
        vector<int> temp;
        helper(nums,0,temp,fin);
        return fin;
    }
};