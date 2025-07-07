// Last updated: 07/07/2025, 17:47:45
class TimeMap {
public:
    map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        // we have to search for the timestamp using binary search
        if(!mp.contains(key)){
            // cout<< key<<endl;
            return "";
        }else{
            int l = 0; 
            int r = mp[key].size() - 1;
            int mid = (l+r)/2;
            string res = "";
            while(l <= r){
                mid = (l+r)/2;
                // cout<< mp[key][mid].second<<endl;
                if(mp[key][mid].second > timestamp){
                    r = mid - 1;
                }else if(mp[key][mid].second < timestamp){
                    res = mp[key][mid].first;
                    l = mid + 1;
                }else if(mp[key][mid].second == timestamp){
                    return mp[key][mid].first;
                }
            }
            return res;
        }

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */