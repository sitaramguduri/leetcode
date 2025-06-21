// Last updated: 20/06/2025, 23:48:07
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        // map is ordered by its keys
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        map<int, vector<int>,std::greater<>> hp;
        for(auto i : mp){
            hp[i.second].push_back(i.first);
        }
        // for(auto i : hp){
        //     cout<< "hp: "<< i.first<<" ";//<< i.second;
        //     cout<<endl;
        //     for(auto it: i.second){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> result;
        int count = 0;
        for(auto it: hp){
            if(count >= k){
                break;
            }
            for(auto i: it.second){
                result.push_back(i);
                count++;
            }
        }
        return result;
    }
};