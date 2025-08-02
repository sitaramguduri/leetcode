// Last updated: 02/08/2025, 18:48:43
class Solution {
    int helper(vector<int>& cost, vector<int>& dp, int n){
        if(n ==0 || n == 1){
            dp[n] = 0;
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        // int right = INT_MAX;
        int left = helper(cost,dp,n-1) + cost[n-1];
        // if(n >1){
        int right = helper(cost, dp,n-2) + cost[n-2];
        // }
        dp[n] = min(left, right);
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        helper(cost,dp,n);
        return dp[n];

    }
};