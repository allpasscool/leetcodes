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
        if (q.empty()) {
            while (!st.empty()) {
                int top = st.top();
                st.pop();
                q.push(top);
            }
        }
        
        int output = q.top();
        q.pop();
        return output;
    }
    
    /** Get the front element. */
    int peek() {
        if (!q.empty())
            return q.top();
        
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty() && q.empty();
    }
    
private:
    stack<int> st;
    stack<int> q; // queue, the top is the front
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
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Implement Queue using Stacks.
// time complexity: empty, push, peek O(1), pop is amortized O(1)
// space complexity: O(n)