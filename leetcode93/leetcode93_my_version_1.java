class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        StringBuilder cur = new StringBuilder();
        
        // special case
        if (s.equals(""))
        {
            return ans;
        }
        
        cur.append(s.charAt(0));
        
        backtracking(s, ans, cur, 0, s.charAt(0) - '0', 1);
        return ans;
    }
    
    private void backtracking(String s, List<String> ans, StringBuilder cur, int field, int sumOfField, int pos)
    {
        // ip only has four fields
        if (field >= 4)
        {
            return;
        }
        // ip range is 0 - 255
        else if (sumOfField > 255)
        {
            return;
        }
        // used up String s
        else if (pos == s.length() && field == 3)
        {
            ans.add(cur.toString());
            return;
        }
        // used up String s but there are less than 4 fields(0 - 3)
        else if (pos == s.length())
        {
            return;
        }
        
        int num = s.charAt(pos) - '0';
        
        // can't be 01.1.1.1
        // so if this field starts with 0, can't add number after it
        if (sumOfField != 0)
        {
            // num belong to cur field
            cur.append(String.valueOf(num));
            backtracking(s, ans, cur, field, sumOfField * 10 + num, pos + 1);
            // backtrack
            cur.deleteCharAt(cur.length() - 1);
        }
        
        // num belong to next field
        cur.append('.');
        cur.append(String.valueOf(num));
        backtracking(s, ans, cur, field + 1, num, pos + 1);
        // backtrack
        cur.deleteCharAt(cur.length() - 1);
        cur.deleteCharAt(cur.length() - 1);
    }
}

// Runtime: 1 ms, faster than 98.76% of Java online submissions for Restore IP Addresses.
// Memory Usage: 39.4 MB, less than 29.91% of Java online submissions for Restore IP Addresses.
// time complexity: O(2^n)
// space complexity: O(2^n)