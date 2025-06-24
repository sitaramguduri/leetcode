// Last updated: 24/06/2025, 02:22:59
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // basic approach: O(N^2)
        int prefixProduct = 1;
        int suffixProduct = 1; 
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        for(int i = 0; i< nums.size(); i++){
            cout<<"prefix: "<< prefixProduct<<endl;
             prefix[i] = prefixProduct;
             prefixProduct *= nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
            cout<< " suffix: "<<suffixProduct<<endl;
             suffix[i] = suffixProduct;
             suffixProduct *= nums[i];
        }
        // for(int i = 0; i< n ; i++){
        //     cout<< prefix[i]<<" pre:"<< endl;
        //     cout<< suffix[n-i]<< " suffix: "<<endl;
        // }
        vector<int> result(n);
        for(int i = 0; i< nums.size(); i++){
            result[i] = prefix[i]*suffix[i];
        }
        return result;
    }
};