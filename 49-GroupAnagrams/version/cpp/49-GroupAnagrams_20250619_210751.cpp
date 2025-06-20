// Last updated: 19/06/2025, 21:07:51
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //brute force: sorting causes O(nlogn) and have to iterate over all the vector strings which will 
        // in total cause O(nlog(n) * m) n is the average size of the string and m is the length of the vector.
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