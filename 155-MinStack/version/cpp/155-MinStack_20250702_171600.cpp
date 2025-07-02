// Last updated: 02/07/2025, 17:16:00
class MinStack {
public:
    stack<long long> st;
    long long minVal;
    MinStack() {
        minVal = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            minVal = val;
            st.push(val);
        }else{
            if(val > minVal){
                st.push(val);
            }else{
                st.push(2LL*val - minVal);
                minVal = val;
                // st.push(temp);
            }
        }
    }
    
    void pop() {
        long long temp = st.top();
        st.pop();
        if(temp < minVal){
            minVal = 2*minVal - temp;
        }
        
    }
    
    int top() {
        if(st.top() < minVal){
            return minVal;
        }else{
            return st.top();
        }
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */