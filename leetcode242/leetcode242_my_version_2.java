class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        
        HashMap<Character, Integer> alpha_count = new HashMap<>();
        
        // count s
        for(int i = 0; i < s.length(); i++) {
            char alpha = (char)(s.charAt(i) - 'a');
            alpha_count.put(alpha, alpha_count.getOrDefault(alpha, 0) + 1);
        }
        
        // used on t
        for(int i = 0; i < t.length(); i++) {
            char alpha = (char)(t.charAt(i) - 'a');
            
            if(alpha_count.containsKey(alpha))
                alpha_count.put(alpha, alpha_count.get(alpha)-1);
            else
                return false;
            
            if(alpha_count.get(alpha) < 0)
                return false;
        }
        
        return true;
    }
}


// Runtime: 13 ms, faster than 12.72% of Java online submissions for Valid Anagram.
// Memory Usage: 39.7 MB, less than 18.51% of Java online submissions for Valid Anagram.
// time complexity: O(n)
// spcae complexity: O(1)