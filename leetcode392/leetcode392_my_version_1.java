class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        
        if (i == s.length())
            return true;
        
        return false;
    }
}


// Runtime: 1 ms, faster than 78.49% of Java online submissions for Is Subsequence.
// Memory Usage: 37 MB, less than 52.24% of Java online submissions for Is Subsequence.
// time complexity: O(n + m)
// space complexity: O(1)