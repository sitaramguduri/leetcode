// Last updated: 17/07/2025, 20:52:09
class Solution {
public:
    void reverseString(vector<char>& s) {
        cout<<s.size()/2;
        return rev(s,s.size()/2,0,s.size()-1);
    }
    void rev(vector<char>& s,int size,int start,int last){
        if(size == 0 ){
            return;
        }
        char temp = s[start];
        s[start] = s[last];
        s[last] = temp ;
        return rev(s,size-1,start+1,last-1);
    }
};
