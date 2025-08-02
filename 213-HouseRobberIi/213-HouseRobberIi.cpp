// Last updated: 02/08/2025, 18:49:16
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int n){
        if(n == 0){
            dp[n] = nums[n];//;
            return nums[n];
        }
        if(n< 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int pick = helper(nums, dp, n-2) + nums[n];
        int notpick = helper(nums, dp, n-1);
        dp[n] = max(pick, notpick);
        return dp[n];
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            return nums[n-1];
        }
        vector<int>temp1;
        vector<int> temp2;
        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);
        for(int i = 0; i< n; i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!= n-1){
                temp2.push_back(nums[i]);
            }
        }

        int res1 = helper(temp1,dp1,temp1.size()-1);
        
        int res2 = helper(temp2,dp2,temp2.size()-1);
        // cout<<"res2: "<<res2<<endl;
       
        return max(res1,res2);

    }
};