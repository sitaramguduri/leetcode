// Last updated: 03/07/2025, 23:31:06
class Solution {
public:
    void helper(int open,int close, string & stack,int n, vector<string> &result){
        if(open == n && close == n){
            result.push_back(stack);
            return ;
        }
        if(open < n){
            stack += '(';
            helper(open+1, close, stack, n, result);
            stack.pop_back();
        }
        if(close < open){
            stack += ')';
            helper(open , close + 1, stack, n, result);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string stack;
        helper(0,0,stack,n, result);
        return result;
    }
};