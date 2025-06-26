// Last updated: 26/06/2025, 14:41:06
class Solution {
public:
    bool isPalindrome(string s) {
        // brute force
        string newStr = "";
        for(char c: s){
            if (isalnum(c)){
                newStr += tolower(c);
            }
        }
        return newStr == string(newStr.rbegin(), newStr.rend());
    }
};