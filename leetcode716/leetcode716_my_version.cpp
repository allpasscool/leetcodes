class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        pq.push(x);
        st.push(x);
    }
    
    int pop() {
        int top = st.top();
        st.pop();
        vector<int> tmp;
        
        while (pq.top() != top) {
            tmp.push_back(pq.top());
            pq.pop();
        }
        pq.pop();
        
        for (int i = 0; i < tmp.size(); ++i) {
            pq.push(tmp[i]);
        }
        
        return top;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return pq.top();
    }
    
    int popMax() {
        int top = pq.top();
        pq.pop();
        
        stack<int> tmp;
        while (st.top() != top) {
            tmp.push(st.top());
            st.pop();
        }
        st.pop();
        
        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }
        
        return top;
    }
private:
    priority_queue<int> pq;
    stack<int> st;
};


// Runtime: 220 ms, faster than 5.12% of C++ online submissions for Max Stack.
// Memory Usage: 43.1 MB, less than 7.41% of C++ online submissions for Max Stack.
// time complexity: push O(1), pop O(n) top O(1) peekMax O(1) popMax O(n)
// space copmlexity: O(n)

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */