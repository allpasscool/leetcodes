class Solution {
    public boolean validPalindrome(String s) {
        int n = s.length();
        int left = 0, right = n - 1;
        int removeLeft = 1;

        // if necessary, delete left
        while (left < right) {
            if (s.charAt(left) == s.charAt(right)) {
                left++;
                right--;
            } else {
                if (removeLeft == 0) {
                    break;
                }

                // remove s.charAt[left]
                removeLeft--;
                left++;

            }
        }

        if (left == right && s.charAt(left) == s.charAt(right))
            return true;
        else if (left > right)
            return true;

        left = 0;
        right = n - 1;
        removeLeft = 1;

        // if necessary, delete right
        while (left < right) {
            if (s.charAt(left) == s.charAt(right)) {
                left++;
                right--;
            } else {
                if (removeLeft == 0) {
                    break;
                }

                // remove s.charAt[left]
                removeLeft--;
                right--;

            }
        }

        if (left == right && s.charAt(left) == s.charAt(right))
            return true;
        else if (left > right)
            return true;

        return false;
    }
}

// Runtime: 5 ms, faster than 89.33% of Java online submissions for Valid
// Palindrome II.
// Memory Usage: 39.8 MB, less than 29.11% of Java online submissions for Valid
// Palindrome II.
// time complexity: O(n)
// space complexity: O(1)