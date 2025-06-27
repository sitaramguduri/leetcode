// Last updated: 27/06/2025, 15:08:04
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        set<char> st;
        int count = 0;
        while( r < s.size()){
            if(!st.contains(s[r])){
                st.insert(s[r]);
                r++;
                count = max(count, static_cast<int>(st.size()));
            }else{
                
                while(l< r){
                    
                    if(s[l] == s[r]){
                        st.erase(s[l]);
                        l++;
                        break;
                    }else{
                        st.erase(s[l]);
                        l++;
                    }
                }

            }
        }
        return count;
    }
};