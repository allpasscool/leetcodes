class Solution {
    public void reverseString(char[] s) {
        int n = s.length;
        
        for (int i = 0; i < s.length / 2; i++) {
            char tmp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = tmp;
        }
    }
}

// Runtime: 2 ms, faster than 7.45% of Java online submissions for Reverse String.
// Memory Usage: 52.5 MB, less than 5.28% of Java online submissions for Reverse String.
// time complexity: O(n)
// space complexity: O(1)