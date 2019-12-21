class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push_front(x);
        seq[x].push_back(st.begin());
    }
    
    int pop() {
        int top = st.front();
        st.pop_front();
        seq[top].pop_back();
        
        if (seq[top].empty()) {
            seq.erase(top);
        }
        
        return top;
    }
    
    int top() {
        return st.front();
    }
    
    int peekMax() {
        return seq.rbegin()->first;
    }
    
    int popMax() {
        int max = seq.rbegin()->first;
        st.erase(seq.rbegin()->second.back());
        seq[max].pop_back();
        if (seq[max].empty()) {
            seq.erase(max);
        }
        
        return max;
    }
private:
    list<int> st;
    map<int, vector<list<int>::iterator>> seq;
};

// Runtime: 104 ms, faster than 27.27% of C++ online submissions for Max Stack.
// Memory Usage: 33.4 MB, less than 92.59% of C++ online submissions for Max Stack.
// time complexity: push O(1) pop O(log n) top O(1) peekMax O(1) popMax O(log n)
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

// class MaxStack {
// public:
//     /** initialize your data structure here. **/
//     MaxStack() {
        
//     }
    
//     void push(int x) {
//         st.push_front(x);
//         seq[x].push_back(st.begin());
//     }
    
//     int pop() {
//         int ret = st.front();
//         auto& pos = seq[ret];
//         pos.pop_back();
//         if (pos.empty()) {
//             seq.erase(ret);
//         }
//         st.pop_front();
//         return ret;
//     }
    
//     int top() {
//         return st.front();
//     }
    
//     int peekMax() {
//         return seq.crbegin()->first;
//     }
    
//     int popMax() {
//         int ret = seq.crbegin()->first;
//         auto& cont = seq.rbegin()->second;
//         st.erase(cont.back());
//         cont.pop_back();
//         if (cont.empty()) {
//             seq.erase(ret);
//         }
//         return ret;
//     }
// private:
//     list<int> st;
//     map<int, vector<list<int>::iterator>> seq;
// };