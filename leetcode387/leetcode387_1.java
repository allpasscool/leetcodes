class Solution {
    public int firstUniqChar(String s) {
        int[] alph_count = new int[26];
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int index = s.charAt(i) - 'a';
            alph_count[index]++;
        }
        
        for (int i = 0; i < n; i++) {
            int index = s.charAt(i) - 'a';
            if (alph_count[index] == 1) {
                return i;
            }
        }
        
        return -1;
    }
}

// Runtime: 7 ms, faster than 84.10% of Java online submissions for First Unique Character in a String.
// Memory Usage: 39.5 MB, less than 37.67% of Java online submissions for First Unique Character in a String.
// time complexity: O(n)
// space complexity: O(1)