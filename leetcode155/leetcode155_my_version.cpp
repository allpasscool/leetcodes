class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        // update min_num vector
        if (min_num.empty()) {
            min_num.push_back(x);
        }
        else {
            int i = 0;
            for (; i < min_num.size(); i++) {
                if (x < min_num[i]) {
                    min_num.insert(min_num.begin() + i, x);
                    break;
                } 
            }
            if (i == min_num.size()) {
                min_num.push_back(x);
            }
        }
        s.push_back(x);
    }
    
    void pop() {
        if (s.empty()) {
            return;
        }
        
        int x = s[s.size() - 1];
        s.pop_back();
        // update min_num vector
        for (int i = 0; i < min_num.size(); i++) {
            if (min_num[i] == x) {
                min_num.erase(min_num.begin() + i);
            }
        }
        return;
    }
    
    int top() {
        return s[s.size() - 1];
    }
    
    int getMin() {
        if (min_num.empty()) {
            return NULL;
        }
        
        return min_num[0];
    }
private:
    vector<int> s;
    vector<int> min_num;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// Runtime: 68 ms, faster than 9.73% of C++ online submissions for Min Stack.
// Memory Usage: 17 MB, less than 65.45% of C++ online submissions for Min Stack.
// time complexity: O(n)
// space complexity: O(n)