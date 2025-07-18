// Last updated: 17/07/2025, 20:52:12
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        // cout << " slow: "<< slow<<endl;
        fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast){
                return slow;
            }
        }
        return slow;
    }
};