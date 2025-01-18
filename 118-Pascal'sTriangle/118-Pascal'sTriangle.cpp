class Solution {
public:
    int ncr(int row,int col){
        long long int res = 1;
        for(int i = 0; i< col;i++){
            res = res*(row-i);
            res = res/(i+1);
        }
        return res;
    }
    vector<int> pascalTriangle(int row){
        long long int res = 1;
        vector<int> eachRow;
        eachRow.push_back(res);
        for(int i = 1;i<row;i++){
            res = res*(row-i);
            res = res/(i);
            // cout<<res<<" ";
            eachRow.push_back(res);
        }
        cout<<endl;
        return eachRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // for(int i = 0; i<numRows;i++){
        //     //for each row print all rows
        //     vector<int> eachRow ;
        //     for(int j = 0; j<=i;j++){
        //         int res = ncr(i,j);
        //         eachRow.push_back(res);
        //     }
        //     ans.push_back(eachRow);
        // }
        for(int i = 1;i<=numRows;i++){
           vector<int> res =  pascalTriangle(i);
           ans.push_back(res);
        }
        return ans;
    }
};