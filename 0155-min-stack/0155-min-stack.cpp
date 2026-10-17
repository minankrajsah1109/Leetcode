class MinStack {
public:
    // Method-2 : By using extra stack that will always have the same no.of elements as your given stack.
    stack<int> st;
    stack<int> helper;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(helper.size() == 0 || value < helper.top()){
            helper.push(value);
        }
        else{
            helper.push(helper.top());
        }
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */