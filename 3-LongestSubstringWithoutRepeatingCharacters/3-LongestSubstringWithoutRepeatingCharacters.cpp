class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int len = 0;
        map<char,int> mp;
        while(r<n ){
            if(mp.find(s[r]) == mp.end()){
                // len
                // cout<<"r: "<<r<<" l: "<<l<<endl; 
                int f = s[r];
                len = max(len, r-l+1);
                mp[s[r]] = r;
                r++;
            }else{
                l = max(l,mp[s[r]] +1);
                len = max(len, r-l+1);
                mp[s[r]] = r;
                
                r++;
            }
        }
        return len;

    }
};