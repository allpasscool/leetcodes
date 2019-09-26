class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (st.empty())
            front = x;
        
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> tmp;
        
        while (st.size() > 1) {
            int top = st.top();
            st.pop();
            tmp.push(top);
        }
        if (!tmp.empty())
            front = tmp.top();
        else 
            front = NULL;
        
        int output = st.top();
        st.pop();
        
        while (!tmp.empty()) {
            int top = tmp.top();
            tmp.pop();
            st.push(top);
        }
        
        return output;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
    
private:
    stack<int> st;
    int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// Runtime: 4 ms, faster than 54.19% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 8.9 MB, less than 90.91% of C++ online submissions for Implement Queue using Stacks.
// time complexity: empty, peek, push O(1), pop O(n)
// space complexity: O(n)