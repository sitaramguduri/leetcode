class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        int curr = 1;
        unordered_set<int> st;
        if(nums.size() == 0){
            return 0;
        }
        for(int i = 0; i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto &it:st){
            if(st.find(it-1)!=st.end()){
                // curr = 1;
            }else{
                int search = it+1;
                while(st.find(search)!= st.end()){
                    curr ++;
                    
                    search ++;
                }
                longest = max(longest,curr);
                curr=1;
            }
        }
        return longest;
    }
};