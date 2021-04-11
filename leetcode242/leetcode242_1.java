class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        char[] s_arr = s.toCharArray();
        char[] t_arr = t.toCharArray();
        Arrays.sort(s_arr);
        Arrays.sort(t_arr);
        
        for (int i = 0; i < s.length(); i++) {
            if (s_arr[i] != t_arr[i])
                return false;
        }
        
        return true;
    }
}


// Runtime: 3 ms, faster than 67.61% of Java online submissions for Valid Anagram.
// Memory Usage: 39 MB, less than 73.67% of Java online submissions for Valid Anagram.
// time complexity: O(n log n)
// space complexity: O(n)