class Solution {
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            char c1 = s.charAt(left);
            char c2 = s.charAt(right);
            
            // check c1 is alphabets and change to lower case
            if (Character.isAlphabetic(c1)) {
                c1 = Character.toLowerCase(c1);
            }
            // c1 is not alphabets nor digit
            else if (!Character.isDigit(c1)) {
                left++;
                continue;
            }
            
            // check c2 is alphabets and change to lower case
            if (Character.isAlphabetic(c2)) {
                c2 = Character.toLowerCase(c2);
            }
            // c2 is not alphabets nor digit
            else if (!Character.isDigit(c2)) {
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

// Runtime: 7 ms, faster than 31.42% of Java online submissions for Valid Palindrome.
// Memory Usage: 40.1 MB, less than 19.47% of Java online submissions for Valid Palindrome.
// time complexity: O(n)
// space complexity: O(1)