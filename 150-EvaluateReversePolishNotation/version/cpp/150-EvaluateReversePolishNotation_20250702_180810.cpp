// Last updated: 02/07/2025, 18:08:10
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i< tokens.size(); i++){
            string ch =  tokens[i];
            if(ch == "+" || ch == "-" || ch == "*"|| ch == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(ch == "+"){
                    st.push(a+b);
                }else if(ch == "*"){
                    st.push(a*b);
                }else if(ch == "/"){
                    st.push(b/a);
                }else if(ch == "-"){
                    st.push(b - a);
                }
            }else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};