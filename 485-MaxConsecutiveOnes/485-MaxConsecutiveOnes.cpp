// Last updated: 17/07/2025, 20:52:04
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = INT_MIN;
        int count = 0;

        for(int i=0;i<nums.size();i++){
            // cout<<" :"<<nums[i]<<" i: "<<i<<": "<<count<<endl;
            if(nums[i] == 0){
                count = 0;
            }else{
                count+=1;
                maxi = max(maxi,count);
            }
        }
        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
    }
};