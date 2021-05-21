class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        StringBuilder cur = new StringBuilder();
        
        backtracking(n, ans, 0, 0, cur);
        
        return ans;
    }
    
    private void backtracking(int n, List<String> ans, int left, int right, StringBuilder cur) {
        // invalid
        if (right > left)
            return;
        // cur is a valid answer
        else if (left == n && right == n) {
            ans.add(cur.toString());
            return;
        }
        // invalid. length is 2 * n, but cur is not a valid answer
        else if (left + right == 2 * n)
        {
            return;
        }
        
        // length is not 2 * n
        // try add (
        cur.append('(');
        backtracking(n, ans, left + 1, right, cur);
        // remove (
        cur.deleteCharAt(cur.length() - 1);
        
        // try add )
        cur.append(')');
        backtracking(n, ans, left, right + 1, cur);
        // remove )
        cur.deleteCharAt(cur.length() - 1);
    }
}

// Runtime: 1 ms, faster than 70.80% of Java online submissions for Generate Parentheses.
// Memory Usage: 40.4 MB, less than 5.63% of Java online submissions for Generate Parentheses.
// time complexity: O(2^2n)
// space complexity: O(n)