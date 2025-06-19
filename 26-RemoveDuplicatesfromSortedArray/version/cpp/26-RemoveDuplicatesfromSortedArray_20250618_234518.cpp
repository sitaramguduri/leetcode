// Last updated: 18/06/2025, 23:45:18
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // brute force 
        set<int> uniqueElements ;
        for(int i = 0; i< nums.size(); i++){
            uniqueElements.insert(nums[i]); // set insert takes log(N). So in total it takes O(NlogN)
        }
        int i = 0;
        for(auto it:uniqueElements){
            nums[i] = it;
            i++;
        }
        return uniqueElements.size();
    }
};