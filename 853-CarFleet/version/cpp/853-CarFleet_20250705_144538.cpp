// Last updated: 05/07/2025, 14:45:38
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // vector<int> st;
        vector<pair<int, int>> combine;
        for(int i = 0; i< speed.size(); i++){
            combine.push_back({position[i], speed[i]});
        }
        sort(combine.rbegin(), combine.rend());
        vector<double> st;
        for(int i = 0; i< combine.size(); i++){
            double time = (double)(target - combine[i].first)/ combine[i].second;
            // cout<< "time: "<< time<< endl;
            if(st.empty()){
                st.push_back(time);
            }
            if(time > st.back()){
                st.push_back(time);
            }
        }
        // for(int i = 0 ; i< st.size(); i++){
        //     cout<< st[i] << endl;
        // }
        return st.size();
    }
};