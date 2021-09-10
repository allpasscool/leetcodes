class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        return backtracking(pushed, 0, popped, 0, st);
    }
    
    bool backtracking(vector<int>& pushed, int pushNum, vector<int>& popped, int popNum, stack<int>& st)
    {
        if (!st.empty() && st.top() == popped[popNum])
        {
            int tmp = st.top();
            st.pop();
            if (backtracking(pushed, pushNum, popped, popNum + 1, st))
                return true;
            st.push(tmp);
        }
        
        
        for (int i = pushNum; i < pushed.size(); i++)
        {
            st.push(pushed[i]);
            
            if (st.top() == popped[popNum])
            {
                st.pop();
                if (backtracking(pushed, i + 1, popped, popNum + 1, st))
                    return true;
                st.push(pushed[i]);
            }
        }
        
        for (int i = pushNum; i < pushed.size(); i++)
        {
            st.pop();
        }
        
        if (st.empty() && pushNum == pushed.size() && popNum == popped.size())
            return true;
        
        return false;
    }
};

// Runtime: 99 ms, faster than 6.61% of C++ online submissions for Validate Stack Sequences.
// Memory Usage: 32.1 MB, less than 17.60% of C++ online submissions for Validate Stack Sequences.
// time complexity: O(m + n) m is len of pushed and n is len of popped
// space complexity: O(m + n)