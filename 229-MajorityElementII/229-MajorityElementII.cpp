class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int f = floor(n/3);
        vector<int> v;
        for(auto i:m){
            if(i.second>f){
                v.push_back(i.first);
            }
        }
        return v;
    }
};