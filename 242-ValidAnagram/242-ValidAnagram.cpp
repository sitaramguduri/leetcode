// Last updated: 17/07/2025, 20:52:14
class Solution {
public:
    bool isAnagram(string s, string t) {
        // use hashmap 
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        if (s.size()!= t.size()){
            return false;
        }
        for(int i = 0; i< s.size();i++){
            mps[s[i]]++;
        }
        for(int i = 0; i< t.size();i++){
            mpt[t[i]]++;
        }
        if(mps.size() != mpt.size()){
            return false;
        }
        return mps == mpt;
    }
};