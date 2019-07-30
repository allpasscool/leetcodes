class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index_stack;
        int longest_valid = 0;
        
        index_stack.push(-1);// if first element ')', than we have something to pop, if the longest parentheses is s, than we will - (-1)
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                index_stack.push(i);
            } else {
                index_stack.pop();
                
                if (index_stack.empty()) {
                    index_stack.push(i);
                } else {
                    longest_valid = max(longest_valid, i - index_stack.top());
                }
            }
        }
        
        return longest_valid;
    }
};
// Runtime: 4 ms, faster than 96.87% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 9.5 MB, less than 57.97% of C++ online submissions for Longest Valid Parentheses.
// time complexity: O(n)
// space complexity: O(n)