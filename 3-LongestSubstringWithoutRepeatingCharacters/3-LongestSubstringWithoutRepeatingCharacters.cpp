class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int len = 0;
        set<char> mp ;
        while(l<n && r < n){
            if(mp.find(s[r]) == mp.end()){
                mp.insert(s[r]);
                len = max(len,r-l+1);
                r++;
            }else{
                mp.erase(s[l]);
                l++;
            }
            
            
        }
        return len;
    }
};