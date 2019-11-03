class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                // * means will be removed
                else
                    s[i] = '*';
            }
        }
        
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        // for example
        //      10 20 30 40 50 20 30
        // start ^
        // end                     ^
        // new_end = remove (s.begin(), s.end(), 20)
        //      10 30 40 50 30  ?  ?
        // start ^
        // new_end .            ^
        // end                     ^
        // so we need eraser those redundand '?'
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};


// Runtime: 28 ms, faster than 75.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// Memory Usage: 12.8 MB, less than 100.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// time complexity: O(n)
// space complexity: O(n)

// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/419402/JavaC%2B%2B-Stack

// string minRemoveToMakeValid(string s) {
//   stack<int> st;
//   for (auto i = 0; i < s.size(); ++i) {
//     if (s[i] == '(') st.push(i);
//     if (s[i] == ')') {
//       if (!st.empty()) st.pop();
//       else s[i] = '*';
//     }
//   }
//   while (!st.empty()) {
//     s[st.top()] = '*';
//     st.pop();
//   }
//   s.erase(remove(s.begin(), s.end(), '*'), s.end());
//   return s;
// }