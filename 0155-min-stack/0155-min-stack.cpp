class MinStack {
public:
    // Method - 4 (T.C = O(1) , S.C = O(1))

    stack<long long> st;
    long long min;
    MinStack() { // Constructor
       min = LLONG_MAX; 
    }
    
    void push(int value) { // O(1)
        long long x = (long long) value;
        if(st.size() == 0){
            st.push(x);
            min = x;
        }
        else if(x >= min) st.push(x);
        else{  // x < min
            st.push(2*x - min); // Fake value is pushed
            min = x;
        }
    }
    
    void pop() { // O(1)
        if(st.top() < min){ // means A Fake value is present 
        // So before popping make sure to retrieve the old min
        
        long long oldMin = 2* min - st.top();
        min = oldMin;
        }
        st.pop(); // will execute for both if and else condition
    }
    
    int top() { // O(1)
        if(st.top() < min) return (int)min;
        else return (int)st.top();
    }
    
    int getMin() {  // O(1)
        return (int)min;
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