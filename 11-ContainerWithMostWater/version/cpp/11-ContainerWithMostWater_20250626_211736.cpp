// Last updated: 26/06/2025, 21:17:36
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; 
        int r = height.size()-1;
        int maxArea = INT_MIN;
        while(l < r){
            int h = min(height[l], height[r]);
            int area = (r-l)*h;
            maxArea = max(maxArea, area);
            if(height[l] <= height[r]){
                l++;
            }else if(height[r] < height[l]){
                r--;
            }
        }
        return maxArea;
    }
};