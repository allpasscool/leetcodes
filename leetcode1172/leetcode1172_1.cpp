class DinnerPlates {
public:
set<int> available;
vector<stack<int>> stac;
int cap;
    
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if (available.empty()) {
            stac.push_back(stack<int>());
            available.insert(stac.size() - 1);
        }
        
        int idx = *available.begin();
        stac[idx].push(val);
        
        if (stac[idx].size() == cap) {
            available.erase(available.begin());
        }
    }
    
    int pop() {
        if (stac.empty()) {
            return -1;
        }
        
        int output = stac.back().top();
        stac.back().pop();
        while (!stac.empty() && stac.back().empty()) {
            available.erase(stac.size() - 1);
            stac.pop_back();
        }
        if(!stac.empty() && stac.back().size() < cap) {
            available.insert(stac.size() - 1);
        }
        
        return output;
    }
    
    int popAtStack(int index) {
        if (index >= stac.size() || stac[index].empty()) {
            return -1;
        }
        
        if (index == stac.size() - 1) {
            return pop();
        }
        
        int output = stac[index].top();
        stac[index].pop();
        available.insert(index);
        return output;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// Runtime: 832 ms, faster than 27.51% of C++ online submissions for Dinner Plate Stacks.
// Memory Usage: 495.2 MB, less than 100.00% of C++ online submissions for Dinner Plate Stacks.
// time complexity: O(logn) access set bu BST
// space complexity: O(n)