// Last updated: 17/07/2025, 20:51:34
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v;
        int i = 0;
        int j = 0;
        bool temp = true;
        int n = nums.size();
        // true means add positive integer else add negative
        while(i<n&&j<n){
            if(temp== true){
                //add a positive integer
                if(nums[i]>0){
                    v.push_back(nums[i]);
                }else{
                    while(nums[i]<0){
                        i++;
                    }
                    v.push_back(nums[i]);
                   

                }
                // cout<<": "<<nums[i]<<endl;
                 i++;
                temp = false;
            }else{
                if(nums[j]<0){
                    v.push_back(nums[j]);
                }else{
                    while(nums[j]>0){
                        j++;
                    }
                    v.push_back(nums[j]);
                }
                // cout<<"::"<<nums[j]<<endl;
                j++;
                temp = true;
            }
        }
        cout<<"j: "<<j<<"n: "<<v.size()<<endl;
        while(j<n && n!= v.size()){
            // cout<<"here??"<<nums[j]<<": "<<j<<endl;
            if(nums[j]<0){
                v.push_back(nums[j]);
            }else{
                while(nums[j]>0){
                    j++;
                }
                v.push_back(nums[j]);
            }
            
            j++;
        }
        while(i<n && n!= v.size()){
            if(nums[i]>0){
                v.push_back(nums[i]);
            }else{
                while(nums[i] < 0){
                    i++;
                }
            }
            v.push_back(nums[i]);
            i++;
        }
        return v;
    }
};