// Last updated: 04/07/2025, 22:38:53
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> data;
        for(int i =  0; i< position.size(); i++){
            pair<int,int> p = {position[i], speed[i]};
            data.push_back(p);
        }
        sort(data.rbegin(), data.rend());
        stack<double> st; 
        for(int i = 0; i< data.size(); i++){
            double time = (double) (target - data[i].first)/data[i].second;
            st.push(time);

            if(st.size() >= 2){
                double first = st.top();
                st.pop();
                double second = st.top();
                st.pop();
                if(first <= second){
                    st.push(second);
                }else{
                    st.push(second);
                    st.push(first);
                }
            }
        }
        return st.size();
    }
};