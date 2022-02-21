class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(')
                st.push(')');
            else if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            else
            {
                if (!st.empty() && st.top() == c)
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.3 MB, less than 50.67% of C++ online submissions for Valid Parentheses.
// time complexity: O(n)
// space complexity: O(n)