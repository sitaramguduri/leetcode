class Solution {
public:

    bool isPalindrome(string s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void helper(string s, int index, vector<string>& path, vector<vector<string>> & result){
        if(index == s.size()){
            result.push_back(path);
            return;
        }
        for(int i = index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                helper(s,i+1,path, result);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        helper(s,0,path, result);
        return result;
    }
};