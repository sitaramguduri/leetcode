// Last updated: 26/06/2025, 20:34:47
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size()-1; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i + 1;
            int r = nums.size()-1;
            while(l<r){
                // if(nums[i] == nums[l]){
                //     l++;
                // }
                int sum = nums[i] + nums[l] + nums[r];
                if(sum> 0){
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    result.push_back(temp);
                    
                    l++;
                    r--;
                    while(l< r && nums[l] == nums[l-1]){
                        l++;   
                    }
                }
            }
        }
        return result;
    }
};