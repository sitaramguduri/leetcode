// Last updated: 26/06/2025, 14:49:00
class Solution {
public:
    bool isalnum( char c){
        if((c >='a' && c <='z') || (c>='A' && c<= 'Z') ||(c>='0' && c<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            while( !isalnum(s[l]) && l<r ){
                l++;
            }
            while(!isalnum(s[r]) && l < r){
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};