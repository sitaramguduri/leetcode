// Last updated: 17/07/2025, 20:52:06
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        map<char, int> mp;
        int maxf = 0;
        int maxlen = 0;
        while(r < s.size()){
            mp[s[r]] ++;
            maxf = max(maxf, mp[s[r]]);
            if( (r - l + 1 ) - maxf >k){
                mp[s[l]]--;
                maxf = 0;
                // for(auto i: mp){
                //     maxf = max(maxf, i.second);
                // }
                l++;
            }else{
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};