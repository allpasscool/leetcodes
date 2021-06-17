class Solution {
    public boolean validPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;
        while (l <= r) {
            if (s.charAt(l) == s.charAt(r)) {
                l++;
                r--;
            } else {
                return isPalindrome(s, l, r - 1) || isPalindrome(s, l + 1, r);
            }
        }
        return true;
    }

    private boolean isPalindrome(String str, int s, int t) {
        while (s <= t) {
            if (str.charAt(s) == str.charAt(t)) {
                s++;
                t--;
            } else
                return false;
        }

        return true;
    }
}

// Runtime: 6 ms, faster than 76.78% of Java online submissions for Valid
// Palindrome II.
// Memory Usage: 39.2 MB, less than 91.08% of Java online submissions for Valid
// Palindrome II.
// time complexity: O(n)
// space complexity: O(1)
// https://leetcode.com/problems/valid-palindrome-ii/discuss/107716/Java-O(n)-Time-O(1)-Space