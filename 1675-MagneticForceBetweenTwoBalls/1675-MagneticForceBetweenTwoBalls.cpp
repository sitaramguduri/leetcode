// Last updated: 17/07/2025, 20:51:36
class Solution {
public:
    bool fitBalls(vector<int> nums, int k,int m){
        int n = nums.size();
        int last = nums[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(nums[i]-last>=k){
                count++;
                last = nums[i];
            }
        }
        if(count >= m){
            cout<<"True"<<endl;
            return true;
        }
        cout<<"False"<<endl;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[position.size()-1]-position[0];
        int n = position.size()-1;
        int mid = (low + mid)/2;
        
        while(low<= high){
            mid = (low+high)/2;
            cout <<" low: "<<low<<"::"<<mid<<"::"<<high<<endl;
            if(fitBalls(position,mid,m)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;
    }
};