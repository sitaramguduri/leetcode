class Solution {
public:
    int f(vector<int>&prices,int ind, int buy, int k,vector<vector<vector<int>>> &dp,int n){
        if(ind >=n||k==0){
            return 0;
        }
        if(dp[ind][buy][k] !=-1){
            return dp[ind][buy][k];
        }
        int op1 = INT_MIN;
        int op2 = INT_MIN;
        if(buy==0){
            //buy 
            op1 = 0 + f(prices,ind+1,0,k,dp,n);
            op2 = -prices[ind] + f(prices,ind+1,1,k,dp,n);
        }
        if(buy == 1){
            op1 = 0 + f(prices,ind+1,1,k,dp,n);
            op2 = prices[ind] + f(prices,ind+1,0,k-1,dp,n);
        }
        return dp[ind][buy][k] = max(op1,op2);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(prices,0,0,k,dp,n);
    }
};