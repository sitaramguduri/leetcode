// Last updated: 17/07/2025, 20:51:37
class Solution {
public:
    void rotate(vector<int> &arr){
        int n = arr.size();
        for(int i=0;i<1;i++){
            // int temp = arr[i];
            arr.push_back(arr[0]);
            arr.erase(arr.begin());

        }
    }
    bool check(vector<int>& nums) {
        // I can do it in n^2
       
        for(int i=0;i<nums.size();i++){
            rotate(nums);
            // for(auto & k: nums){
            //     cout<<"k: "<<k<<" ";
            // }
            // cout<<"here: ";
             bool flag = true;
            for(int j=1;j<nums.size();j++){
                if(nums[j] >= nums[j-1]){

                }else{
                    flag = false;
                    // return false;
                }
            }
            if(flag == true){
                return flag;
            }
        }
        return false;
    }
};