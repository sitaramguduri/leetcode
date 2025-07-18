// Last updated: 17/07/2025, 20:52:13
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int j = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }
        if(j == INT_MIN){
            return;
        }
        int n = arr.size();
        int i = j+1;
        while(i<n){
            if(arr[j]!=0){
                while(arr[j]!= 0 ){
                    j+=1;
                }
                i = j+1;
            }
            if(arr[i]!= 0 ){
                //swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j+=1;
                i +=1;
            }else{
                i+=1;
            }
        }

    }
};