class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        String res = null;
        boolean[][] dpTable = new boolean[n][n];

        // p(i,i) = true, p(i, i+1) = (Si == Si+1)
        for (int i = 0; i < s.length(); i++) {
            dpTable[i][i] = true;

            if (i < s.length() - 1) {
                dpTable[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));
            }
        }

        int max_len = 1;
        int start = 0, end = 0;

        // fill dp table
        for (int i = s.length() - 2; i >= 0; i--) {
            for (int j = s.length() - 1; j > i; j--) {
                dpTable[i][j] = (dpTable[i + 1][j - 1] && (s.charAt(i) == s.charAt(j)));
                if (i + 1 > j - 1) {
                    dpTable[i][j] = (s.charAt(i) == s.charAt(j));
                }

                if (dpTable[i][j] == true && (j - i + 1 >= max_len)) {
                    start = i;
                    end = j;
                    max_len = j - i + 1;
                }
            }
        }

        return s.substring(start, (end + 1));
    }
}

// Runtime: 212 ms, faster than 31.71% of Java online submissions for Longest
// Palindromic Substring.
// Memory Usage: 42.7 MB, less than 29.36% of Java online submissions for
// Longest Palindromic Substring.
// time complexity: O(n^2)
// space complexity: O(n^2)