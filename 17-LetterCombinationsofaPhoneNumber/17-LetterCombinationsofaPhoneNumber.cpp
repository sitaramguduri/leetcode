class Solution {
public:
    void helper(string &digits, int index,const vector<string>& digitToChars, string& path, vector<string>& result){
        if(index == digits.size()){
            result.push_back(path);
            return;
        }
        string letters = digitToChars[digits[index] -'0'];
        for(char letter: letters){
            path.push_back(letter);
            helper(digits, index+1,digitToChars, path, result);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> phoneMap = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string path;
        helper(digits, 0, phoneMap, path, result);
        return result;
    }
};