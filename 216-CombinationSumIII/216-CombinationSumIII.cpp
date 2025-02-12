class Solution {
public:
    void helper(int k , int n, vector<int>& temp, vector<vector<int>>& fin, int ind,int* arr){
        if( n == 0 & k==0){
            fin.push_back(temp);
            return;
        }
        if (n < 0 || k < 0) return;
        for(int i = ind; i< 10; i++){
            if(i>n){
                // continue;
                break;
            }
            temp.push_back(i);
            helper(k-1,n-i,temp,fin,i+1,arr);
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int* arr = new int[10];
        for(int i = 0; i< 10;i++){
            arr[i] = i;
        }
        vector<int> temp ;
        vector<vector<int>> fin;
        helper(k,n, temp, fin,1,arr);
        return fin;
    }
};