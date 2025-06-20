// Last updated: 19/06/2025, 20:09:23
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute force: O(N^2)
        vector<int> result;
        for(int i = 0; i< nums.size(); i++){
            for(int j = i+1; j< nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};