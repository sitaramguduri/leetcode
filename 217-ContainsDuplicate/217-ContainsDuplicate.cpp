// Last updated: 17/07/2025, 20:52:22
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> elements;
        for(auto it: nums){
            if(!elements.contains(it)){
                elements.insert(it);
            }else{
                return true;
            }
        }
        return false;
    }
};