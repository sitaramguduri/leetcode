// Last updated: 19/06/2025, 19:13:53
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> elements;
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