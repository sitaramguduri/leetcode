// Last updated: 19/06/2025, 19:17:48
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