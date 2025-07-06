// Last updated: 06/07/2025, 15:30:02
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;
        int mid = (l + r )/2;
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[l] <= nums[mid]){
                if(target > nums[mid]){
                    l = mid+1;
                }else if(target < nums[mid]){
                    if(target >= nums[l]){
                        r = mid - 1;
                    }else{
                        l = mid+1;
                    }
                }
            }else{
                if(target < nums[mid]){
                    r = mid-1;
                }else if(target > nums[mid]){
                    if(target <= nums[r]){
                        l = mid+1;
                    }else{
                        r = mid-1;
                    }
                }
            }
            
        }
        return -1;
    }
};