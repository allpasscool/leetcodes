class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        min = stack.empty() ? x : std::min(x, min);
        stack.push_back(x);
    }
    
    void pop() {
        assert(!stack.empty());
        
        const int x = top();
        stack.pop_back();
        
        if (x == min && !stack.empty()) {
            min = *std::min_element(stack.begin(), stack.end());
        }
    }
    
    int top() {
        assert(!stack.empty());
        return stack.back();
    }
    
    int getMin() {
        assert(!stack.empty());
        return min;
    }
private:
    std::vector<int> stack;
    int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// Runtime: 32 ms, faster than 67.13% of C++ online submissions for Min Stack.
// Memory Usage: 16.7 MB, less than 100.00% of C++ online submissions for Min Stack.
// time complexity: O(log n) for pop and find min
// space complexity: O(n)