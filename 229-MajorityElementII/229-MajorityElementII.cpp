class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int cnt1 = 0; 
        int cnt2 = 0;
        for(int i = 0; i<nums.size();i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2++;
            }else if(ele1 == nums[i]){
                cnt1++;
            }else if(ele2 == nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        int f1 = 0; 
        int f2 = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(ele1 == nums[i]){
                f1++;
            }
            if(ele2 == nums[i]){
                f2++;
            }
        }
        int n = nums.size();
        cout<<ele1<<" "<<ele2<<endl;
        vector<int> v;
        if(f1> n/3){
             v.push_back(ele1);
        }
        if(f2 > n/3){
            v.push_back(ele2);
        }
        
       
        // v.push_back(ele2);
        return v;
    }
};