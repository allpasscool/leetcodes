class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        
        int[] alpha_count = new int[26];
        
        // count s
        for(int i = 0; i < s.length(); i++) {
            int alpha = s.charAt(i) - 'a';
            alpha_count[alpha]++;
        }
        
        // used on t
        for(int i = 0; i < t.length(); i++) {
            int alpha = t.charAt(i) - 'a';
            alpha_count[alpha]--;
            
            if(alpha_count[alpha] < 0)
                return false;
        }
        
        return true;
    }
}


// Runtime: 3 ms, faster than 67.61% of Java online submissions for Valid Anagram.
// Memory Usage: 38.8 MB, less than 93.57% of Java online submissions for Valid Anagram.
// time complexity: O(n)
// space complexity: O(1)