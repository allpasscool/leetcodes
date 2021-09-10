class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int popN = 0;
        
        for (int num : pushed)
        {
            st.push(num);
            while (!st.empty() && popN < n && st.top() == popped[popN])
            {
                st.pop();
                popN++;
            }
        }
        
        return st.empty() && popN == n;
    }
};

// solution 1
// Runtime: 12 ms, faster than 36.43% of C++ online submissions for Validate Stack Sequences.
// Memory Usage: 15.5 MB, less than 17.60% of C++ online submissions for Validate Stack Sequences.
// time complexity: O(n + n)
// space complexity: O(n)