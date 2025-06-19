// Last updated: 19/06/2025, 19:43:49
class Solution {
public:
    bool isAnagram(string s, string t) {
        //Basic approach : O(N^2)
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0 ; i< s.size(); i++){
            int size = t.size();
            bool isfound = false;
            for(int j = 0; j< size; j++){
                if(s[i] == t[j]){
                    //remove the character
                    isfound = true;
                    t.erase(j,1);
                    break;
                }
            }
            if(isfound == false){
                return false;
            }
        }
        if(t.size() == 0){
            return true;
        }
        return false;
    }
};