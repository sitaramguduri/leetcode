class Solution {
int f(vector<int>&nums,int i , int j,vector<vector<int>>&dp){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int max_coins = INT_MIN;
    //assume each ballon bursts last
    for(int k = i;k<=j;k++){
        //find the value if the ballon k bursts last
        int coins = nums[i-1]*nums[k]*nums[j+1];
        int remainingCoins = f(nums,i,k-1,dp)+f(nums,k+1,j,dp);
        max_coins = max(max_coins,coins+remainingCoins);
    }
    return dp[i][j] = max_coins;
}
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return f(nums,1,n,dp);
    }
};