class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder copy = new StringBuilder(s);
        copy = copy.reverse();
        int p1 = 0, p2 = 0;
        
        while (p1 < s.length() && p2 < copy.length()) {
            char c1 = s.charAt(p1);
            char c2 = copy.charAt(p2);
            
            // check c1 is alphabets and change to lower case
            if (Character.isAlphabetic(c1)) {
                c1 = Character.toLowerCase(c1);
            }
            // c1 is not alphabets nor digit
            else if (!Character.isDigit(c1)) {
                p1++;
                continue;
            }
            
            // check c2 is alphabets and change to lower case
            if (Character.isAlphabetic(c2)) {
                c2 = Character.toLowerCase(c2);
            }
            // c2 is not alphabets nor digit
            else if (!Character.isDigit(c2)) {
                p2++;
                continue;
            }
            
            if (c1 != c2) {
                return false;
            }
            
            p1++;
            p2++;
        }
        
        return true;
    }
}

// Runtime: 8 ms, faster than 30.43% of Java online submissions for Valid Palindrome.
// Memory Usage: 39.1 MB, less than 58.27% of Java online submissions for Valid Palindrome.
// time complexity: O(n)
// space complexity: O(n)