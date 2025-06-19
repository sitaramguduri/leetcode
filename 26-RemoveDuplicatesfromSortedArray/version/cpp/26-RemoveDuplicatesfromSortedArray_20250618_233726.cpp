// Last updated: 18/06/2025, 23:37:26
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // brute force 
        set<int> uniqueElements ;
        for(int i = 0; i< nums.size(); i++){
            uniqueElements.insert(nums[i]);
        }
        int i = 0;
        for(auto it:uniqueElements){
            nums[i] = it;
            i++;
        }
        return uniqueElements.size();
    }
};