class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right = 0;
        for(int i = 0; i<n+m;i++){
            if(nums1[i] == 0 && right <n){
                nums1[i] = nums2[right];
                right++;
            }
        }
        sort(nums1.begin(),nums1.end());
    }
};