class Solution {
    // return all valid parenthesis with n pairs
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        if (n == 0)
        {
            ans.add("");
        } 
        else 
        {
            for (int c = 0; c < n; ++c)
            {
                // all possible cases in left
                for (String left: generateParenthesis(c))
                {
                    // all possible cases in right
                    for (String right: generateParenthesis(n-1-c))
                    {
                        ans.add("(" + left + ")" + right);
                    }
                }
            }
        }
        return ans;
    }
}

// Runtime: 15 ms, faster than 5.67% of Java online submissions for Generate Parentheses.
// Memory Usage: 39.9 MB, less than 5.63% of Java online submissions for Generate Parentheses.
// time complexity: O(2^2n)
// space complexity: O(n)