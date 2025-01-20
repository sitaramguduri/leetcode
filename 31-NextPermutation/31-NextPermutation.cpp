class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint = -1;
        int size = nums.size();

        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakpoint = i;
                break;
            }
        }
        cout << "breakpoint:" << breakpoint << endl;
        if (breakpoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // we need to find the element just larger than the one at breakpoint
        vector<int> temp;
        for (int i = breakpoint; i < size; i++) {
            if(nums[breakpoint]<nums[i])
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        int index = -1;
        for (int i = breakpoint + 1; i < size; i++) {
            if (nums[i] == temp[0]) {
                index = i;
            }
        }
        // cout<<"index:"<<index;
        swap(nums[breakpoint], nums[index]);

        vector<int> res;
        for (int i = breakpoint + 1; i < size; i++) {
            res.push_back(nums[i]);
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            nums[breakpoint + i + 1] = res[i];
        }
    }
};