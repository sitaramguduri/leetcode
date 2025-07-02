// Last updated: 02/07/2025, 15:53:30
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch == '(' || ch== '[' || ch == '{'){
                st.push(ch);
            }else if(ch == ')'){
                // char temp = st.top();
                if(st.size() == 0 ||st.top() != '(' ){
                    return false; 
                }else{
                    st.pop();
                }
            }else if(ch == '}'){
                // char temp = st.top();
                if( st.size() == 0 ||st.top() != '{' ){
                    return false;
                }else{
                    st.pop();
                }
            }else if(ch == ']'){
                // char temp = st.top();
                if(st.size() == 0 || st.top() != '[' ){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        if(st.size() > 0){
            return false;
        }
        return true;
    }
};