class Solution {
public:
    string removeDuplicates(string s, int k) {
        unordered_map<char, int> count;
        stack<char> st;
        int current_count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (st.empty()) {
                st.push(s[i]);
                current_count++;
            }
            else if (!st.empty() && st.top() == s[i]) {
                st.push(s[i]);
                current_count++;
            }
            else if (!st.empty() && st.top() != s[i]) {
                st.push(s[i]);
                current_count = 1;
            }
            
            if (current_count == k) {
                for (int j = 0; j < k; ++j) {
                    st.pop();
                }
                current_count = 0;
                
                stack<char> tmp;
                while (!st.empty()) {
                    current_count++;
                    char top = st.top();
                    st.pop();
                    tmp.push(top);
                    
                    if (st.empty()) {
                        break;
                    }
                    else if (st.top() != tmp.top()) {
                        break;
                    }
                }
                
                while (!tmp.empty()) {
                    char top = tmp.top();
                    tmp.pop();
                    st.push(top);
                }
            }
        }
        string output;
        
        while (!st.empty()) {
            char top = st.top();
            st.pop();
            output = top + output;
        }
        
        return output;
    }
};

// Runtime: 32 ms, faster than 24.12% of C++ online submissions for Remove All Adjacent Duplicates in String II.
// Memory Usage: 137.3 MB, less than 100.00% of C++ online submissions for Remove All Adjacent Duplicates in String II.
// time complexity: O(n^2)
// space complexity: O(n)