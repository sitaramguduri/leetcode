// Last updated: 26/06/2025, 13:49:03
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> s;
        for(int i: nums){
            s.insert(i);
        }
        int maxCount = 1;
        for(auto i: s){
            if(s.contains(i-1)){

            }else{
                int search = i+1;
                int count = 1;

                while(s.contains(search)){
                    search +=1;
                    count++;
                    maxCount = max(maxCount , count);
                }
            }
        }
        return maxCount;
    }
};