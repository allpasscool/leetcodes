class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        int max;
        if (max_st.empty() || x >= max_st.top()) {
            max = x;
        }
        else {
            max = max_st.top();
        }
        st.push(x);
        max_st.push(max);
    }
    
    int pop() {
        int top = st.top();
        st.pop();
        max_st.pop();
        
        return top;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return max_st.top();
    }
    
    int popMax() {
        stack<int> tmp_st;
        int max = max_st.top();
        
        while (st.top() != max) {
            tmp_st.push(st.top());
            st.pop();
            max_st.pop();
        }
        st.pop();
        max_st.pop();
        
        while (!tmp_st.empty()) {
            this->push(tmp_st.top());
            tmp_st.pop();
        }
        
        return max;
    }
private:
    stack<int> st, max_st;
};

// Runtime: 80 ms, faster than 97.44% of C++ online submissions for Max Stack.
// Memory Usage: 36.3 MB, less than 22.22% of C++ online submissions for Max Stack.
// time complexity: push O(1), pop O(1) top O(1) peekMax O(1) popMax O(n)
// space complexity: O(n)

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */