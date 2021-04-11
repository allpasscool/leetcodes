class Solution {
    public int firstUniqChar(String s) {
        // seen alpha
        boolean[] seen_alphbates = new boolean[26];
        
        for (int i = 0; i < s.length(); i++) {
            boolean duplicate = false;
            
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    duplicate = true;
                    break;
                }
            }
            
            if (!duplicate && !seen_alphbates[s.charAt(i) - 'a'])
                return i;
            
            seen_alphbates[s.charAt(i) - 'a'] = true;
        }
        
        return -1;
    }
}

// Runtime: 38 ms, faster than 6.22% of Java online submissions for First Unique Character in a String.
// Memory Usage: 39.4 MB, less than 50.75% of Java online submissions for First Unique Character in a String.
// time complexity: O(n^2)
// spcae complexity: O(1)