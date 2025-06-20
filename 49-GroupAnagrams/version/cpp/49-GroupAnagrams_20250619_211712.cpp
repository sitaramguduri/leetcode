// Last updated: 19/06/2025, 21:17:12
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // optimal approach: same characters in anagrams : create a hashmap using the characters and
        //  then store the strings in the hashmap and use the strings at the end to create another vector.
        unordered_map<string, vector<string>> mp;
        for(auto &s: strs){
            //create a hash table using the 26 characters
            vector<int> hashTable (26,0);
            for(auto &ch:s){
                hashTable[ch - 'a']++;
            }
            //now covert the hashtable to string
            string key = to_string(hashTable[0]);
            for(int i = 1; i<26; i++){
                key += ',' + to_string(hashTable[i]);
            }
            // now we have the key for the hashmap, 
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &it: mp){
            result.push_back(it.second);
        }
        return result;
    }
};