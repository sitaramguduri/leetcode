class Solution {
public:
    bool isInDict(string s, vector<string>& d){
        return find(d.begin(),d.end(),s)!= d.end();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // if(s.empty()){
        //     return true;
        // }
        // for(int i = 0; i<= s.size();i++){
        //     string prefix = s.substr(0,i);
        //     if(find(wordDict.begin(),wordDict.end(),prefix) != wordDict.end() && wordBreak(s.substr(i),wordDict)){
        //         return true;
        //     }
        // }
        // return false;
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 0; i<= n;i++){
            for(int j = 0; j<i;j++){
                if(dp[j] && isInDict(s.substr(j,i-j),wordDict)){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};