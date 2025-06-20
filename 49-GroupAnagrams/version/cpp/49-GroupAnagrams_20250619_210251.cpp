// Last updated: 19/06/2025, 21:02:51
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //brute force
        unordered_map<string, vector<string>> res;
        for(auto &it: strs){
            string newString = it;
            sort(newString.begin(), newString.end());
            res[newString].push_back(it);
        }
        vector<vector<string>> finalResult;
        for(auto it:res){
            finalResult.push_back(it.second);
        }
        return finalResult;
    }
};