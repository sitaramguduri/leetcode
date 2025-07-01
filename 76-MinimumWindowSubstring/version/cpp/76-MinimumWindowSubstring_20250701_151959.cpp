// Last updated: 01/07/2025, 15:19:59
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0; 
        int r = 0;
        map<char, int> mp;
        for(char ch: t){
            mp[ch]++;
        }
        int count = 0;
        int sIndex = -1;
        int minLength = INT_MAX;
        while( r < s.size()){
            if(mp[s[r]] > 0){
                count += 1;
            }
            mp[s[r]]--;
            while(count == t.size()){
                if(r - l + 1 < minLength){
                    sIndex = l;
                    minLength = r - l + 1;

                }
                // l++;
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    count --;
                }
                l++;
                
            }
            r++;
        }
        return sIndex == -1 ? "": s.substr(sIndex, minLength);
    }
};