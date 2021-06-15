class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // no left parenthese
                if (st.isEmpty()) {
                    return false;
                } else if (c == ')') {
                    if (st.peek() != '(') {
                        return false;
                    }
                    // else
                    st.pop();
                } else if (c == ']') {
                    if (st.peek() != '[') {
                        return false;
                    }
                    // else
                    st.pop();
                } else if (c == '}') {
                    if (st.peek() != '{') {
                        return false;
                    }
                    // else
                    st.pop();
                }

            }
        }

        if (st.isEmpty())
            return true;
        else
            return false;
    }
}
// Runtime: 1 ms, faster than 98.70% of Java online submissions for Valid
// Parentheses.
// Memory Usage: 37.3 MB, less than 42.66% of Java online submissions for Valid
// Parentheses.
// time complexity: O(n)
// space complexity: O(n)