class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int max_compare = 0;
        for(int i = 1;i<prices.size();i++){
            if(prices[i] < min_val){
                min_val = prices[i];
            }
            else{
                max_compare = max(max_compare,prices[i]-min_val);
            }
        }
        return max_compare;
    }
};