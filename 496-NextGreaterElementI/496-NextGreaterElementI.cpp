// Last updated: 17/07/2025, 20:52:03
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> res;
        // cout<<"hered";
        for(int i = nums2.size()-1 ; i>=0; i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            // cout<<"st:"<<st.size()<<endl;
            int element = st.empty()?-1:st.top();
            // cout<<"elem: "<< element<<endl;
            res[nums2[i]] = element;
            st.push(nums2[i]);
        }
        vector<int> r(nums1.size(),0);
        for(int i =0 ; i< nums1.size();i++){
            r[i] = res[nums1[i]];
        }
        return r;
    }
};