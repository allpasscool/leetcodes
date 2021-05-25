class Solution {
    public List<String> letterCombinations(String digits) {
        Map<Integer, char[]> numToAlph = new HashMap<>();
        // initalization
        numToAlph.put(2, new char[]{'a','b','c'});
        numToAlph.put(3, new char[]{'d', 'e', 'f'});
        numToAlph.put(4, new char[]{'g', 'h', 'i'});
        numToAlph.put(5, new char[]{'j', 'k', 'l'});
        numToAlph.put(6, new char[]{'m', 'n', 'o'});
        numToAlph.put(7, new char[]{'p', 'q', 'r', 's'});
        numToAlph.put(8, new char[]{'t', 'u', 'v'});
        numToAlph.put(9, new char[]{'w', 'x', 'y', 'z'});
        
        List<String> ans = new ArrayList<>();
        StringBuilder cur = new StringBuilder();
        
        // special case
        if (digits.length() == 0)
            return ans;
        
        backtracking(digits, numToAlph, ans, cur);
        
        return ans;
    }
    
    private void backtracking(String digits, Map<Integer, char[]> numToAlph, 
                              List<String> ans, StringBuilder cur)
    {
        int idx = cur.length();
        // valid answer
        if (digits.length() == idx)
        {
            ans.add(cur.toString());
            return;
        }
        
        // add "idx" th character in cur
        char digit = digits.charAt(idx);
        int num = digit - '0';
        for (char c : numToAlph.get(num))
        {
            cur.append(c);
            backtracking(digits, numToAlph, ans, cur);
            cur.deleteCharAt(idx);
        }
        
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 37.6 MB, less than 75.39% of Java online submissions for Letter Combinations of a Phone Number.
// time complexity: O(4^n) n is the length of digits
// space complexity: O(n)