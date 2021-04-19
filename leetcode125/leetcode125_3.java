class Solution {
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            char c1 = s.charAt(left);
            char c2 = s.charAt(right);
            
            // check c1 is alphabets or number change to lower case
            if (Character.isLetterOrDigit(c1)) {
                // change to lower case
                if (Character.isAlphabetic(c1))
                    c1 = Character.toLowerCase(c1);
            }
            // c1 is not alphabets nor digit
            else {
                left++;
                continue;
            }
            
            // check c1 is alphabets or number change to lower case
            if (Character.isLetterOrDigit(c2)) {
                // change to lower case
                if (Character.isAlphabetic(c2))
                    c2 = Character.toLowerCase(c2);
            }
            // c1 is not alphabets nor digit
            else {
                right--;
                continue;
            }
            
            if (c1 != c2) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
}

// Runtime: 5 ms, faster than 35.49% of Java online submissions for Valid Palindrome.
// Memory Usage: 40.3 MB, less than 12.17% of Java online submissions for Valid Palindrome.
// time complexity: O(n)
// space complexity: O(n)