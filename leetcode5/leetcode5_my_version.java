class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        String ans = s.substring(0, 1);

        for (int i = 0; i < n; i++) {
            // odd palindromic
            // bab
            ans = findLogestPalidr(s, ans, i - 1, i + 1);

            // even palindromic
            // baab
            ans = findLogestPalidr(s, ans, i, i + 1);
        }

        return ans;
    }

    private String findLogestPalidr(String s, String ans, int left, int right) {
        int n = s.length();
        while (left >= 0 && right < n) {
            if (s.charAt(left) == s.charAt(right)) {
                if (ans.length() < right - left + 1) {
                    ans = s.substring(left, right + 1);
                }
                right++;
                left--;
            } else {
                break;
            }
        }

        return ans;
    }
}

// Runtime: 26 ms, faster than 64.05% of Java online submissions for Longest
// Palindromic Substring.
// Memory Usage: 39.3 MB, less than 59.16% of Java online submissions for
// Longest Palindromic Substring.
// time complexity: O(n^2)
// space complexity: O(1)