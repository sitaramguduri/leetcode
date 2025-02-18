class Solution {
public:
    void helper(string num, int target, vector<string>& result, int pos, string curExp,long long value,long long last){
        if(pos == num.size()){
            if(target == value){
                result.push_back(curExp);
            }
            
            return;
        }
        for(int i = pos; i<num.size();i++){
            if(i!=pos && num[pos] == '0'){
                break;
            }
            string part = num.substr(pos,i+1-pos);
            long long cur = stoll(part);
            if (pos == 0) {
                // First number, just pass it through
                helper(num, target, result, i + 1, part, cur, cur);
            } else {
                // Addition
                helper(num, target, result, i + 1, curExp + "+" + part, value + cur, cur);
                // Subtraction
                helper(num, target, result, i + 1, curExp + "-" + part, value - cur, -cur);
                // Multiplication
                helper(num, target, result, i + 1, curExp + "*" + part, value - last + last * cur, last * cur);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result; 
        helper(num, target, result,0," ",0,0);
        return result;
    }
};