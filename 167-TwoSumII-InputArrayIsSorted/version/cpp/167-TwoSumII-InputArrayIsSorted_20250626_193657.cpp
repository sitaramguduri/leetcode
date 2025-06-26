// Last updated: 26/06/2025, 19:36:57
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> result;
        while(l<r){
            if(numbers[l] + numbers[r] > target){
                r--;
            }else if(numbers[l] + numbers[r] < target){
                l++;
            }else{
                // result.push_back(l+1);
                // result.push_back(r+1);
                return {l+1, r+1};
                // break;
            }
        }
        return result;
    }
};