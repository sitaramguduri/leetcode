// Last updated: 27/06/2025, 14:21:00
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = i + 1;
        int result = 0;
        while( j < prices.size()){
            if(prices[i] <= prices[j]){
                result = max(result, prices[j] - prices[i]);
                j++;
            }else{
                i = j;
            }
        }
        return result;
    }
};