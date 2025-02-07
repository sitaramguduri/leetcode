class Solution {
public:
    void helper(int l, int r ,int n, vector<string>& v, string current){
        if(l>n || r > n || r>l){
            return;
        }
        if(l == n && r == n){
            v.push_back(current);
            return;
        }
        helper(l+1,r,n,v,current+"(");
        helper(l,r+1,n, v, current+")");
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v ;
        int l = 0; 
        int r = 0;
        string s = "";
        helper(l,r,n, v, s);
        return v;
    }
};