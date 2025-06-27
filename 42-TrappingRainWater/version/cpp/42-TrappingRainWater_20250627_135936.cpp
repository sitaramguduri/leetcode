// Last updated: 27/06/2025, 13:59:36
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxL = height[0];
        int maxR = height[height.size()-1];
        int i = min(height[0], height[height.size() -1]);
        int result = 0;
        while(l < r){
            if(height[l] <= height[r]){
                i = l;
            }else{
                i = r;
            }
            int minHeight = min(maxL, maxR);
            int water = minHeight - height[i];
            if (water < 0){
                water = 0;
            }
            result += water;
            maxL = max(maxL, height[i]);
            maxR = max(maxR, height[i]);
            if(height[l] <= height[r]){
                
                l++;
            }else{
                
                r--;
            }

        }
        return result;
    }
};